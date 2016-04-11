#include "DiagnosticItem.h"

#include <QtDebug>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QTime>

QList<DiagnosticItem> DiagnosticItem::smItemList;
QMap<BasicId, QString> DiagnosticItem::smTodoLineMessageMap;
QMap<BasicId, QString>     DiagnosticItem::smTestLineMessageMap;
QList<BasicId> DiagnosticItem::smTestIdList;
QSet<BasicId> DiagnosticItem::smCompletedTestIdSet;

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
    , cmLineId(lineId(fileName, fileLine))
    , cmFormat(format)
    , cmVarList(QVariantList() << var1 << var2 << var3 << var4)
{
    QString message = createMessage(cmFormat, cmVarList);
    if (inTest())
    {
        smTestLineMessageMap.insert(cmLineId, message);
    }
    else
    {
        sendMessage(cmMsgType, message);
        smItemList.append(*this);
    }
}

QString DiagnosticItem::createMessage(const QString & format,
                                      const QVariantList & varList)
{
    QString message = BaseLib::formatMessage(format, varList);
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
    default:
    case QtDebugMsg:    qDebug(qPrintable(message));    break;
#if (QT_VERSION >= QT_VERSION_CHECK(5,5,0))
    case QtInfoMsg:     qInfo(qPrintable(message));     break;
#endif
    case QtWarningMsg:  qWarning(qPrintable(message));  break;
    case QtCriticalMsg: qCritical(qPrintable(message)); break;
    case QtFatalMsg:    qFatal(qPrintable(message));    break;
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
    if (smTodoLineMessageMap.contains(lineId(fileName, fileLine))) return;

    DiagnosticItem di(msgtype, function, fileName, fileLine,
                      message + ": " + expression);
    smTodoLineMessageMap.insert(di.cmLineId, di.createMessage(di.cmFormat, di.cmVarList));
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
BasicId DiagnosticItem::lineId(const QString & fileName,
                               const int fileLine)
{
    return BasicId(fileName, QString::number(fileLine));
}

// static
bool DiagnosticItem::todoReport(const QString & filename)
{
    QIODevice::OpenMode mode = QIODevice::WriteOnly
                                | QIODevice::Text
                                | QIODevice::Truncate;
    QFile * pFile = new QFile();
    Q_ASSERT(pFile);
    if (filename.isEmpty())
    {
        pFile->open(stdout, mode);
    }
    else
    {
        pFile->setFileName(filename);
        pFile->open(mode);
        QFileInfo fi(*pFile);
        _QDEBUGNOT(fi.absoluteDir().mkpath("."));
        if ( ! pFile->isWritable()) qDebug() << pFile->errorString();
    }
    _QDEBUGNOT(pFile->isWritable());
    return pFile->isWritable()
            ? reportTodo(pFile)
            : false;
}

// static
bool DiagnosticItem::reportTodo(QIODevice * iod)
{
    if ( ! iod) return false;                       //----------
    QTextStream * pStream = new QTextStream(iod);
    Q_ASSERT(pStream);

    foreach (QString msg, smTodoLineMessageMap.values())
        *pStream << msg << endl;

    pStream->flush();
    iod->close();
    return true;
}
