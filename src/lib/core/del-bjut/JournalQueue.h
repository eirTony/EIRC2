/*! @file   JournalQueue.h   BjutLib: JournalQueue declaration
 */
#ifndef JOURNALQUEUE_H
#define JOURNALQUEUE_H
#include "BjutLib.h"

#include <QObject>

#include <QList.h>
#include <QQueue>
#include <QUrl>
class QFile;

#include <core/Singleton.h>

#include "internal/JournalEntry.h"

class JournalWriter;

class BJUTSHARED_EXPORT JournalQueue : public QObject // StaticSingleton
{
    Q_OBJECT
public:
    enum Category // for now until Qt5.4 QMessageLogger understood
    {
        nullCategory = 0,
        Debug,
        Info,
        Warning,
        Critical,
        Fatal,
        sizeCategory
    };
    enum MacroName
    {
        nullMacroName = 0,
//        BEnter,
        BTrace,
        BDump,
        BToDo,
        BInfo,
        BWarnIf,
        BWarnNot,
        BWarn,
        BNeedDo,
        BErrorIf,
        BErrorNot,
        BError,
        BMustDo,
        BFatalIf,
        BFatalNot,
        BObjPtr,
        BNulPtr,
        BFatal,
        sizeMacroName
    };

public: // static
    static JournalQueue & instance(void);

public:
    void startup(const QUrl & url=QUrl());
    bool isStartup(void) const;
    bool isWritable(void) const;
    QString writerFileName(void) const;
    void endStartup(void);

    void enqueue(const JournalEntry & entry);
    JournalEntry dequeue(void);
    JournalEntry::List dequeue(const int count=0);
    JournalEntry::List dequeueAll(void);

private:
    QFile * writerFile(void) const;

public: // static
    static Category parseCategory(const BjutName & s);
    static MacroName parseMacroName(const BjutName & s);

signals:
    void enqueued(void);
    void enqueued(JournalEntry);
    void enqueuedStartup(JournalEntry);
    void queueSize(int);
    void empty(void);

public slots:

private:
    JournalQueue(void);
    ~JournalQueue() {}

private slots:
    void handleStartupEnqueue(JournalEntry entry);
    void cleanStartupDir(void) {}
    void removeStartupFile(void) {}

private:
    JournalWriter * mpWriter = 0;
    QQueue<JournalEntry> mEntryQueue;
    QStringList mOldFileNameList; // or Queue?

private: // static
    static JournalQueue * smpInstance;
};

//typedef PointerSingleton<JournalQueue> BasicJournalInstance;

#endif // JournalQueue_H
