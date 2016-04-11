/*! @file   JournalWriter.cpp BjutLib JournalWriter class definitions
 */
#include "JournalWriter.h"

#include <QCoreApplication>
#include <QDir>
#include <QDateTime>
#include <QFileInfo>
#include <QTemporaryDir>
#include <QTextStream>
#include <QUrl>

#include "BasicJournalInternal.h"
#include "ParsedJournalEntry.h"

JournalWriter::JournalWriter(const QUrl & url)
{
    if ( ! parseUrl(url))                   return;
    if ( ! setFile(mUrl.path()))            return;
    if ( ! openFile())                      return;
    if ( ! startFile())                     return;
    mStarted = true;
}

bool JournalWriter::isWritable(void) const
{
    return mpFile && mpFile->isWritable() && mpStream;
}

void JournalWriter::write(JournalEntry entry)
{
   ParsedJournalEntry pe(entry);

   JournalQueue::MacroName mn = pe.macroName;
   if (JournalQueue::BToDo == mn
           || JournalQueue::BNeedDo == mn
           || JournalQueue::BMustDo == mn)
   {
       FunctionLinePair funcLine(pe.prettyFunction, pe.sourceFileLine);
       if (mFunctionLineSet.contains(funcLine))
           return;
       else
           mFunctionLineSet.insert(funcLine);
   }

    switch (mFormat)
    {
    case User:
    case Trace:     writeTextFile(pe);   break;

    case Csv:
    case Tsv:       writeDelimited(pe);  break;

    case nullFormat: // reserved format values
    case sizeFormat:    {;}
    }
}

QFile * JournalWriter::file(void) const
{
    return mpFile;
}

bool JournalWriter::parseUrl(const QUrl & url)
{
    if ( ! url.isValid() && ! url.isEmpty())    return false;
    mUrl = url;
    mQuery = QUrlQuery(mUrl);
    mScheme = mUrl.scheme().isEmpty() ? "txtfile" : mUrl.scheme();
    if ("txtfile" != mScheme)                   return false;

    mFormat         = parseFormat(mQuery.queryItemValue("Format"));
    mMinSeverity    = parseMinSev(mQuery.queryItemValue("MinSev"));
    mKeepFiles      = mQuery.queryItemValue("sKeepFiles").toInt();
    mKeepDays       = mQuery.queryItemValue("sKeepDays").toInt();
    return true;
}

JournalWriter::Format JournalWriter::parseFormat(const BjutName s)
{
    Format rtn = nullFormat;
    if (false)                          {;}
    else if (BjutName("Trace") == s)   rtn = Trace;
    else if (BjutName("User") == s)    rtn = User;
    else if (BjutName("Csv") == s)     rtn = Csv;
    else if (BjutName("Tsv") == s)     rtn = Tsv;
    else                                rtn = Tsv;
    return rtn;
}

JournalQueue::Category JournalWriter::parseMinSev(const BjutName s)
{
    JournalQueue::Category rtn = JournalQueue::nullCategory;
    if (BjutName("All") == s)
        rtn = JournalQueue::Debug;
    else
        rtn = JournalQueue::parseCategory(s);
    if (JournalQueue::nullCategory == rtn)
        rtn = JournalQueue::Debug;
    return rtn;
}

bool JournalWriter::setFile(const QString path)
{
#if 1
    // defaults
    QString baseName(QDateTime::currentDateTime()
                     .toString("DyyyyMMdd-Thhmmss"));
    QString suffix(fileSuffix());
    QDir fileDir("/Temp/log/EclipseIR");
    QString orgName(qApp->organizationName());
    QString appName(qApp->applicationName());

    if (path.isEmpty())
    {
        setFileName(fileDir, orgName, appName, baseName, suffix);
    }
    else
    {
        QFileInfo urlFI(path);
        if (urlFI.isDir())
        {
            fileDir = urlFI.dir();
        }
        else
        {
            baseName = urlFI.completeBaseName();
            suffix = urlFI.suffix();
            fileDir = urlFI.dir();
        }
        setFileName(fileDir, baseName, suffix);
    }
    return true;
#else
    // collect information
    QDir dir(QTemporaryDir().path());
    QString org = qApp->organizationName();
    QString app = qApp->applicationName();
    QFileInfo pathFI(path);
    QFileInfo outFI;
    QString sfx;
    switch (mFormat)
    {
    case User:      sfx = ".log";       break;
    case Trace:     sfx = ".trc";       break;
    case Csv:       sfx = ".csv";       break;
    case Tsv:       sfx = ".tsv";       break;
    case nullFormat:    case sizeFormat: ; // invalid values
    }

    if (path.isEmpty())
    {
        dir.mkpath("Antz/StartLog");    dir.cd("Antz/StartLog");
        dir.mkpath(org);                dir.cd(org);
        dir.mkpath(app);                dir.cd(app);
        outFI.setFile(dir.path() + "/"
                      + QDateTime::currentDateTime()
                        .toString("DyyyyMMddThhmmss")+sfx);

    }
    else if (pathFI.exists())
    {
        outFI = pathFI;
    }
    else if (pathFI.isDir())
    {
        outFI = QFileInfo(path + "/"
                          + QDateTime::currentDateTime()
                            .toString("DyyyyMMddThhmmss")+sfx);
    }
    else
    {
        return false;
    }

    mFilePath = outFI.absoluteFilePath();
    return true;
#endif
}

QString JournalWriter::fileSuffix(void) const
{
    QString sfx;
    switch (mFormat)
    {
    case User:      sfx = ".log";       break;
    case Trace:     sfx = ".trace";     break;
    case Csv:       sfx = ".csv";       break;
    case Tsv:       sfx = ".tsv";       break;
    case nullFormat:    case sizeFormat: ; // invalid values
    }
    return sfx;
}

void JournalWriter::setFileName(const QDir & dir,
                                     const QString & org,
                                     const QString & app,
                                     const QString & base,
                                     const QString & suffix)
{
    QDir fileDir = dir;
    fileDir.mkpath(".");
    if ( ! org.isEmpty())   { fileDir.mkpath(org);    fileDir.cd(org); }
    if ( ! app.isEmpty())   { fileDir.mkpath(app);    fileDir.cd(app); }
    mFilePath = fileDir.absoluteFilePath(base + suffix);
}

void JournalWriter::setFileName(const QDir & dir,
                                     const QString & base,
                                     const QString & suffix)
{
    mFilePath = dir.absoluteFilePath(base + "." + suffix);
}

bool JournalWriter::openFile(void)
{
    mpFile = new QFile(mFilePath, this);
    Q_ASSERT(mpFile);
    mpFile->open(QIODevice::Text | QIODevice::WriteOnly);

    mpStream = new QTextStream(mpFile);
    Q_ASSERT(mpStream);
    return mpFile->isWritable();
}

bool JournalWriter::startFile(void)
{
    Q_ASSERT (mpStream);
#if true // why???
    write(_BJENTRY("BINFO", "Info") \
            << JournalItem("Message", "Basic Journal started: %1") \
            << JournalItem("Var1", QDate::currentDate().toString()));
#endif
    return true;
}

void JournalWriter::writeTextFile(const ParsedJournalEntry & pe)
{
    Q_ASSERT(mpStream);
    QString catName = pe.mEntry.value("Category").toString();
    QString macName = pe.mEntry.value("MacroName").toString();
    QString trace;
    QString user(QString("%1 %3 %2")
                .arg(pe.timeStamp.toString("hh:mm:ss.zzz"))
                .arg(pe.formatted(), mFormatWidth)
                .arg(catName, 8)
                .arg(macName, 12));
    if (Trace == mFormat)
        trace = QString("%4 [%1, %2] %3")
                .arg(pe.sourceFileName)
                .arg(pe.sourceFileLine)
                .arg(pe.prettyFunction)
                .arg(macName, 12);
    *mpStream << user << trace << endl;
}

void JournalWriter::writeDelimited(const ParsedJournalEntry & pe)
{
    Q_ASSERT(mpStream);
    static QString  left(Tsv ? ""   : "\"");
    static QString right(Tsv ? ""   : "\"");
    static QString delim(Tsv ? "\t" : ",");
    QString catName = pe.mEntry.value("Category").toString();
    QString macName = pe.mEntry.value("MacroName").toString();
    QString timeStamp = pe.timeStamp.toString("hh:mm:ss.zzz");
    QString formattedAndPadded = QString("%1").arg(pe.formatted(), - mFormatWidth);

    *mpStream << left << timeStamp                      << right << delim
              << left << catName                        << right << delim
              << left << formattedAndPadded             << right << delim
              << left << macName                        << right << delim
              << left << pe.prettyFunction              << right << delim
              << left << pe.sourceFileName              << right << delim
              << left << pe.sourceFileLine              << right << delim
              << endl;
}
