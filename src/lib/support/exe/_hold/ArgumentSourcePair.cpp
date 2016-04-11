#include "ArgumentSourcePair.h"

ArgumentSourcePair::ArgumentSourcePair(void) {}

ArgumentSourcePair::ArgumentSourcePair(const QString & argument,
                                       const QString & source)
    : StringPair(argument, source) {}

QString ArgumentSourcePair::argument(void) const
{
    return StringPair::first();
}

QString ArgumentSourcePair::source(void) const
{
    return StringPair::second();
}


