#include "StringPair.h"

StringPair::StringPair(void) {}

StringPair::StringPair(const QString & first,
                       const QString & second)
    : Base(first, second) {}

QString StringPair::first(void)  const
{
    return first();
}

QString StringPair::second(void) const
{
    return second();
}


