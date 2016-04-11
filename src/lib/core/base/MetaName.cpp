/*! @file   MetaName.cpp BaseLib MetaName class definitions
 */
#include "MetaName.h"

/*
MetaName::MetaName(const QByteArray & name) : QByteArray(name) {}

MetaName::MetaName(const QString & string) : QByteArray(string.toLocal8Bit()) {}

MetaName::MetaName(const char * chars) : QByteArray(chars) {}
*/

MetaName::MetaName(void) {;}

MetaName::MetaName(const char * chars)
    : mChars(chars) {;}

MetaName::MetaName(const QString & string)
    : mChars(string.toLocal8Bit()) {;}

bool MetaName::isEmpty(void) const
{
    return mChars.isEmpty();
}

void MetaName::set(const QString & string)
{
    mChars.clear();
    mChars.append(string);
}

const char * MetaName::name(void) const
{
    return mChars.constData();
}

MetaName::operator const char * (void) const
{
    return name();
}

QString MetaName::toString(void) const
{
    return QString::fromLocal8Bit(mChars);
}

MetaName::operator QString (void) const
{
    return toString();
}

QString MetaName::operator () (void) const
{
    return toString();
}

bool MetaName::operator < (const MetaName & other)
{
    return name() < other.name();
}

bool operator < (const MetaName & left, const MetaName & right)
{
    return left.name() < right.name();
}

