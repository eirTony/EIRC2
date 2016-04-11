#include "Id.h"

Id::Id(const QString & string)
{
    set(string);
}

Id::Id(const char * const chars)
{
    set(QString(chars));
}

Id::Id(const BasicId & other)
{
    set(QString(other));
}
