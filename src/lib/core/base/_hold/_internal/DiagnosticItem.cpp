#include "DiagnosticItem.h"

#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QTime>

bool DiagnosticItem::smExec = false;
QList<DiagnosticItem> DiagnosticItem::smItemList;
QMap<BasicId, QString> DiagnosticItem::smTodoLineMessageMap;
QMap<BasicId, QString>     DiagnosticItem::smTestLineMessageMap;
QList<BasicId> DiagnosticItem::smTestIdList;
QSet<BasicId> DiagnosticItem::smCompletedTestIdSet;
QFile * DiagnosticItem::smpTodoFile = 0;
QFile * DiagnosticItem::smpLogFile = 0;

DiagnosticItem::DiagnosticItem(void) {;}

DiagnosticItem::DiagnosticItem(const QtMsgType msgtype,
                               const QString & function,
                               const QString & fileName,
                               const int fileLine,
                               const QString & format,
                               const QVariant & var1,
                               const QVariant & var2,
                               const QVariant & var3,
                               const QVariant & var4)
    : cmTimestamp(QDateTime::currentDateTime())
    , cmMsgType(msgtype)
    , cmFunction(function)
    , cmFileName(fileName)
    , cmFileLine(fileLine)
    , cmLineId(lineId(fileName, fileLine, format))
    , cmFormat(format)
    , cmVarList(QVariantList() << var1 << var2 << var3 << var4)
{
    QString message = createMessage();
    if (inTest())
    {
        smTestLineMessageMap.insert(cmLineId, message);
    }
    else
    {
        sendMessage(cmMsgType, message);
        smItemList.append(*this);
        if (smExec) execLog(*this);
    }
}

QString DiagnosticItem::createMessage(void) const
{
    QString message = formatMessage(cmFormat, cmVarList);
    QFileInfo fi(cmFileName);
    return QString("%1 %2 %3[%4], %5")
            .arg(QTime::currentTime().toString("hh:mm:ss.zzz"))
            .arg(message, -64)
            .arg(fi.completeBaseName(), 16)
            .arg(cmFileLine, 3)
            .arg(cmFunction);
}

void DiagnosticItem::sendMessage(const QtMsgType msgtype,
                                 const QString & message)
{
    switch (msgtype)
    {
    default: //    qDebug("%s", qPrintable(string()));

    case QtDebugMsg:    qDebug("%s", qPrintable(message));    break;
#if (QT_VERSION >= QT_VERSION_CHECK(5,5,0))
    case QtInfoMsg:     qInfo("%s", qPrintable(message));     break;
#endif
    case QtWarningMsg:  qWarning("%s", qPrintable(message));  break;
    case QtCriticalMsg: qCritical("%s", qPrintable(message)); break;
    case QtFatalMsg:    qFatal("%s", qPrintable(message));    break;
    }
}

void DiagnosticItem::boolean(const QtMsgType msgtype,
                             const QString & function,
                             const QString & fileName,
                             const int fileLine,
                             const bool expectation,
                             const bool actual,
                             const QString expression,
                             const QString & message)
{
    if (expectation == actual)
        DiagnosticItem di(msgtype,
                          function,
                          fileName,
                          fileLine,
                          QString("%1%2%3%4").arg(CRIT_PFX)
                                             .arg(expectation
                                                          ? ""
                                                          : "NOT ")
                                             .arg(expression)
                                             .arg(message.isEmpty()
                                                  ? QString()
                                                  : " {"+message+"}"));
}

void DiagnosticItem::todo(const QtMsgType msgtype,
                          const QString & function,
                          const QString & fileName,
                          const int fileLine,
                          const QString & message,
                          const QString & expression)
{
    if (smTodoLineMessageMap
            .contains(lineId(fileName, fileLine, expression)))
        return;                         //-------------------

    DiagnosticItem di(msgtype, function, fileName, fileLine,
                      message + ": " + expression);
    QString msg = di.createMessage();
    smTodoLineMessageMap.insert(di.cmLineId, msg);
    if (smExec) execTodo(msg);
}

void DiagnosticItem::beginTest(const BasicId & testId)
{
    smTestIdList.append(testId);
}

void DiagnosticItem::endTest(const BasicId & testId)
{
    smTestIdList.removeAll(testId);
}

bool DiagnosticItem::inTest(void)
{
    return ! smTestIdList.isEmpty();
}

// static
void DiagnosticItem::exec(const QString & orgName,
                          const QString & appName)
{
    QFileInfo todoFI(QString("./todo/%1-%2.txt")
                 .arg(orgName).arg(appName));
    startTodoFile(todoFI);

    QFileInfo logFI(QString("./log/%1-%2-%3.txt")
                    .arg(orgName).arg(appName)
                    .arg(QDateTime::currentDateTime()
                          .toString("DyyyyMMdd-Thhmmsszzz")));
    startLogFile(logFI);
    smExec = true;
}

void DiagnosticItem::startTodoFile(const QFileInfo & fi)
{
    Q_ASSERT(fi.absoluteDir().mkpath("."));
    smpTodoFile = new QFile(fi.absoluteFilePath());
    smpTodoFile->open(QIODevice::WriteOnly
                        | QIODevice::Text
                        | QIODevice::Truncate);
    if ( ! smpTodoFile->isOpen())
    {
        qDebug("File Error #%i - %s",
               smpTodoFile->error(),
               qPrintable(smpTodoFile->errorString()));

    }
    foreach(QString todoString, smTodoLineMessageMap.values())
        execTodo(todoString);
}

// static
void DiagnosticItem::startLogFile(const QFileInfo & fi)
{
    Q_ASSERT(fi.absoluteDir().mkpath("."));
    smpLogFile = new QFile(fi.absoluteFilePath());
    smpLogFile->open(QIODevice::WriteOnly
                        | QIODevice::Text
                        | QIODevice::Truncate);
    if ( ! smpLogFile->isOpen())
    {
        qDebug("File Error #%i - %s",
               smpLogFile->error(),
               qPrintable(smpLogFile->errorString()));

    }
    foreach(DiagnosticItem di, smItemList)
        execLog(di);
}

// static
BasicId DiagnosticItem::lineId(const QString & fileName,
                               const int fileLine,
                               const QString & expr)
{
    return BasicId(fileName,
                   QString::number(fileLine),
                   expr);
}

// static
QString DiagnosticItem::formatMessage(const QString & format,
                               QVariantList vars)
{
    QString res = format;
    int k = 0;
    while ( ! vars.isEmpty())
    {
        QString key = QString("%%1").arg(++k);
        res.replace(key,
                    vars.takeFirst().toString());
    }
    return res;
}

// static
void DiagnosticItem::execTodo(const QString & todoMsg)
{
    if (smpTodoFile)
    {
        smpTodoFile->write(qPrintable(todoMsg));
        smpTodoFile->write("\r\n");
        smpTodoFile->flush();
    }
}

// static
void DiagnosticItem::execLog(const DiagnosticItem & di)
{
    if (smpLogFile)
    {
        QString msg = di.createMessage();
        smpLogFile->write(qPrintable(msg));
        smpLogFile->write("\r\n");
        smpLogFile->flush();
    }
}
