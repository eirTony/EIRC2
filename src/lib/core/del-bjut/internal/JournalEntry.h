#ifndef JournalEntry_H
#define JournalEntry_H
#include "../BjutLib.h"

#include <QList>
#include <QMap>
#include <QVariant.h>

class JournalItem;

#include "BjutTypes.h"

class BJUTSHARED_EXPORT JournalEntry : public QMap<BjutName, QVariant>
{
public:
    typedef QList<JournalEntry> List;

public:
    JournalEntry(void);
    void append(const JournalItem & item);

    inline JournalEntry & operator<< (const JournalItem & item)
    { append(item); return *this; }

};

//typedef QList<JournalEntry> JournalEntryList;

#endif // JournalEntry_H
