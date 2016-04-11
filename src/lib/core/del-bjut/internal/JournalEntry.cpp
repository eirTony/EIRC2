#include "JournalEntry.h"

#include "JournalItem.h"

JournalEntry::JournalEntry(void)
{
}

void JournalEntry::append(const JournalItem & item)
{
    insert(item.first, item.second);
}
