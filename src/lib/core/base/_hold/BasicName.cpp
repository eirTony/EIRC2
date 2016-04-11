/*! @file   BasicName.cpp BaseLib BasicName class definitions
 */

#include "BasicName.h"

#include "Diagnostic.h"

const QString BasicName::csmAllowedChars =
        "0123456789_" \
        "abcdefghijklmnopqrstuvwxyz" \
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

BasicName::BasicName(void) {}

BasicName::BasicName(const QString & name)
{
    set(name);
}

BasicName::BasicName(const char * const chars)
{
    set(QString::fromLocal8Bit(chars));
}

bool BasicName::isNull(void) const
{
    return mName.isNull();
}

bool BasicName::isEmpty(void) const
{
    return mName.isEmpty();
}

void BasicName::clear(void)
{
    mName.clear();
}

int BasicName::size(void) const
{
    return mName.size();
}

void BasicName::set(const QString & name)
{
    mName.clear();
    foreach (QChar c, name)
        if (csmAllowedChars.contains(c))
            mName.append(c);
}

QString BasicName::sortable(void) const
{
    // Future:  refactor op== op< with CaseInsensitive .compare()
    //          and/or class InsensitiveString
    return mName.toLower();
}

bool BasicName::operator == (const BasicName & other) const
{
    return sortable() == other.sortable();
}

bool BasicName::operator <  (const BasicName & other) const
{
    return sortable() <  other.sortable();
}

QString BasicName::operator () (void) const
{
    return mName;
}

BasicName::operator QString (void) const
{
    return mName;
}

BasicName::operator int (void) const
{
    return qHash(mName);
}
