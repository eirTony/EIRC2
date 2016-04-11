#ifndef ParsedJournalEntry_H
#define ParsedJournalEntry_H

#include <QDateTime>

#include "BasicJournalInternal.h"
#include "JournalQueue.h"
#include "JournalWriter.h"

class ParsedJournalEntry
{
public:
    explicit ParsedJournalEntry(const JournalEntry & entry);
    QString formatted(void) const;

public: // access
    const JournalEntry mEntry;
    const QDateTime timeStamp;
    const JournalQueue::MacroName macroName;
    const JournalQueue::Category category;
    const QString message;
    const QVariant expression; // value
    const QString exprName;
    const QString objectName;
//    const QVariant value;
    const QVariant var1;
    const QVariant var2;
    const QVariant var3;
    const QVariant var4;
    const QString prettyFunction;
    const QString sourceFileName;
    const int sourceFileLine;
};

#endif // ParsedJournalEntry_H
