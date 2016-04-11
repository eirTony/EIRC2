/*! @file   BasicJournalWriter.h   BaseLib: BasicJournalWriter declaration
 */
#ifndef BASICJOURNALWRITER_H
#define BASICJOURNALWRITER_H

#include <QObject>

#include <QPair>
#include <QSet>
#include <QUrl>
#include <QUrlQuery>
class QDir;
class QFile;
class QTextStream;

#include "BasicJournalInternal.h"
#include "JournalQueue.h"
class ParsedJournalEntry;

class JournalWriter : public QObject
{
    Q_OBJECT
private:
    enum Format
    {
        nullFormat = 0,
        Trace,
        User,
        Csv,
        Tsv,
        sizeFormat
    };
    typedef QPair<QString, int> FunctionLinePair;

public:
    explicit JournalWriter(const QUrl & url);
    bool isWritable(void) const;
    QFile * file(void) const;

public slots:
    void write(JournalEntry entry);

private:
    bool parseUrl(const QUrl & url);
    Format parseFormat(const BjutName s);
    JournalQueue::Category parseMinSev(const BjutName s);
    bool setFile(const QString path);
    QString fileSuffix(void) const;
    void setFileName(const QDir & dir,
                     const QString & org,
                     const QString & app,
                     const QString & base,
                     const QString & suffix);
    void setFileName(const QDir & dir,
                     const QString & base,
                     const QString & suffix);
    bool openFile(void);
    bool startFile(void);
    void writeTextFile(const ParsedJournalEntry &pe);
    void writeDelimited(const ParsedJournalEntry &pe);

private:
    QUrl mUrl;
    QUrlQuery mQuery;
    QString mScheme;
    Format mFormat;
    int mFormatWidth = 60;
    QString mFilePath;
    JournalQueue::Category mMinSeverity;
    int mKeepFiles = 0;
    int mKeepDays = 0;
    QFile * mpFile = 0;
    QTextStream * mpStream = 0;
    bool mStarted = false;
    QSet<FunctionLinePair> mFunctionLineSet;
};

#endif // BASICJOURNALWRITER_H
