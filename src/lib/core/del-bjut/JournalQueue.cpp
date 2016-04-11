/*! @file   JournalQueue.cpp BjutLib JournalQueue class definitions
 */
#include "JournalQueue.h"

#include <QtDebug>
#include <QFile>
#include <QTimer>

#include "internal/JournalEntry.h"
#include "internal/JournalWriter.h"
#include "internal/ParsedJournalEntry.h"

JournalQueue * JournalQueue::smpInstance = 0;

JournalQueue::JournalQueue(void)
{
    Q_ASSERT(connect(this, SIGNAL(enqueuedStartup(JournalEntry)),
            this, SLOT(handleStartupEnqueue(JournalEntry))));
}

#if 0
JournalQueue::~JournalQueue()
{
    if (mpWriter)   delete mpWriter;
}
#endif

JournalQueue & JournalQueue::instance(void) // static
{
    if ( ! smpInstance)
        smpInstance = new JournalQueue;
    return *smpInstance;
}

void JournalQueue::startup(const QUrl & url)
{
    if (isStartup())    endStartup();
    JournalWriter * writer = new JournalWriter(url);
    if ( ! writer->isWritable()) return;

    // success
    mpWriter = writer;
    connect(this, SIGNAL(enqueued(JournalEntry)),
            mpWriter, SLOT(write(JournalEntry)));
    QTimer::singleShot(60000, this, SLOT(cleanStartupDir()));
}

bool JournalQueue::isStartup(void) const
{
#if true
    if ( ! mpWriter) return true;
    if ( ! mpWriter->isWritable()) return true;
    return false;
#else
    return !! mpWriter && mpWriter->isWritable();
#endif
}

bool JournalQueue::isWritable(void) const
{
    return ! isStartup();
}

QString JournalQueue::writerFileName(void) const
{
    return (mpWriter && mpWriter->file())
            ? mpWriter->file()->fileName()
            : QString();
}

QFile * JournalQueue::writerFile(void) const
{
    return isStartup() ? mpWriter->file() : 0;
}

void JournalQueue::endStartup(void)
{
   if (mpWriter)
   {
       delete mpWriter;
       mpWriter = 0;
   }
}

void JournalQueue::enqueue(const JournalEntry & entry)
{
    mEntryQueue.enqueue(entry);
    emit enqueued();
    emit enqueued(entry);
    emit queueSize(mEntryQueue.size());
    if (isStartup()) emit enqueuedStartup(entry);
}

JournalEntry JournalQueue::dequeue(void)
{
    JournalEntry entry;
    if ( ! mEntryQueue.isEmpty())
        entry = mEntryQueue.dequeue();
    emit queueSize(mEntryQueue.size());
    if (mEntryQueue.isEmpty())
        emit empty();
    return entry;
}

JournalEntry::List JournalQueue::dequeue(const int count)
{
    JournalEntry::List list;
    if ( !! count)
    {
        list = mEntryQueue;
    }
    else
    {
        int k = 0;
        while (count && ++k < count && ! mEntryQueue.isEmpty())
            list.append(mEntryQueue.dequeue());
    }
    emit queueSize(mEntryQueue.size());
    if (mEntryQueue.isEmpty())
        emit empty();
    return list;
}

JournalEntry::List JournalQueue::dequeueAll(void)
{
    return dequeue(0);
}

JournalQueue::Category
        JournalQueue::parseCategory(const BjutName & s) // static
{
    Category rtn = nullCategory;
    if (false)  {;}
    else if (BjutName("Debug") == s)           rtn = Debug;
    else if (BjutName("Info") == s)            rtn = Info;
    else if (BjutName("Warning") == s)         rtn = Warning;
    else if (BjutName("Critical") == s)        rtn = Critical;
    else if (BjutName("Fatal") == s)           rtn = Fatal;
    else {;}
    return rtn;
}

JournalQueue::MacroName
        JournalQueue::parseMacroName(const BjutName & s) // static
{
    // ToDo: bool BjutName::is(string/other)
    BjutName mac = s.toLower();
    MacroName rtn = nullMacroName;
    if (false)  {;}
    else if (mac == BjutName("BTrace").toLower())          rtn = BTrace;
    else if (mac == BjutName("BDump").toLower())           rtn = BDump;
    else if (mac == BjutName("BToDo").toLower())           rtn = BToDo;
    else if (mac == BjutName("BInfo").toLower())           rtn = BInfo;
    else if (mac == BjutName("BWarnIf").toLower())         rtn = BWarnIf;
    else if (mac == BjutName("BWarnNot").toLower())        rtn = BWarnNot;
    else if (mac == BjutName("BWarn").toLower())           rtn = BWarn;
    else if (mac == BjutName("BNeedDo").toLower())         rtn = BNeedDo;
    else if (mac == BjutName("BErrorIf").toLower())        rtn = BErrorIf;
    else if (mac == BjutName("BErrorNot").toLower())       rtn = BErrorNot;
    else if (mac == BjutName("BError").toLower())          rtn = BError;
    else if (mac == BjutName("BMustDo").toLower())         rtn = BMustDo;
    else if (mac == BjutName("BFatalIf").toLower())        rtn = BFatalIf;
    else if (mac == BjutName("BFatalNot").toLower())       rtn = BFatalNot;
    else if (mac == BjutName("BObjPtr").toLower())         rtn = BObjPtr;
    else if (mac == BjutName("BNulPtr").toLower())         rtn = BNulPtr;
    else if (mac == BjutName("BFatal").toLower())          rtn = BFatal;
    else   {;}
    return rtn;
}

void JournalQueue::handleStartupEnqueue(JournalEntry entry) // private slot
{
    ParsedJournalEntry pje(entry);
    Category cat = pje.category;

    if (cat >= Category::Fatal) qFatal(qPrintable(pje.formatted()));
    else if (cat >= Category::Critical) qCritical(qPrintable(pje.formatted()));
    else if (cat >= Category::Warning) qWarning(qPrintable(pje.formatted()));
    else qDebug(qPrintable(pje.formatted()));
}
