/*! @file   BasicKey.cpp BaseLib BasicKey Group definitions
 */
#include "BasicKey.h"

#include "Diagnostic.h"

const quint64 BasicKey::csmMasks[] = { 0,
                             0x00000000000000FF,
                             0x00000000FFFFFF00,
                             0x000000FF00000000,
                             0xFFFFFF0000000000,
                             0xFFFFFFFFFFFFFFFF
                                     };

BasicKey::BasicKey(void) : mKeyU64(0) {;}

BasicKey::BasicKey(const quint64 other) : mKeyU64(other) {;}

BasicKey::BasicKey(const quint8 upperGroup,
         const uint upperValue,
         const quint8 lowerGroup,
         const uint lowerValue)
{
    setUpper(upperGroup, upperValue);
    setLower(lowerGroup, lowerValue);
}

#if 0
BasicKeyTest::BasicKeyTest(QObject * parent)
    : TestObject("BaseLib/BasicKey", parent)
{
    TRACE("in BasicKeyTest ctor", "");
}
#endif

void BasicKey::set(const Part part,
                   const BasicKey other)
{
    quint64 mask =csmMasks[part];
    quint64 u64 = mKeyU64;
    u64 &= ~ mask;
    u64 |= other.masked(mask)();
}

#if 0
void BasicKeyTest::setUpperLower(void)
{
    BasicKey bk;
    QCOMPARE(bk.isNull(), true);
    QCOMPARE(bk.isZero(), true);

    bk.setUpper(0x12, 0x345678);
    QCOMPARE(bk.isNull(), false);
    QCOMPARE(bk.isZero(), false);
    QCOMPARE(bk.isUpper(), true);

    bk.setLower(0x9A, 0xBCDEF0);
    QCOMPARE(bk.isNull(), false);
    QCOMPARE(bk.isZero(), false);
    QCOMPARE(bk.isUpper(), false);

    QCOMPARE(int(bk.upperGroup()), 0x12);
    QCOMPARE(int(bk.upperValue()), 0x345678);
    QCOMPARE(int(bk.lowerGroup()), 0x9A);
    QCOMPARE(int(bk.lowerValue()), 0xBCDEF0);
    QCOMPARE(bk(), 0xBCDEF09A34567812LLU);
}
#endif

void BasicKey::setUpper(const quint8 keyGroup,
                         const uint keyValue)
{
    mUpperGroup = keyGroup, mUpperValue = keyValue;
}

void BasicKey::setLower(const quint8 keyGroup,
                       const uint keyValue)
{
    mLowerGroup = keyGroup, mLowerValue = keyValue;
}

bool BasicKey::isNull(void) const
{
    return 0 == mUpperGroup && 0 == mLowerGroup;
}

bool BasicKey::isZero(void) const
{
    return ! mKeyU64;
}

bool BasicKey::isUpper(void) const
{
    return 0 == mLowerSegment;
}

bool BasicKey::operator < (const BasicKey rhs) const
{
    return mKeyU64 < rhs.mKeyU64;
}

quint64 BasicKey::operator() (void) const
{
    return mKeyU64;
}

uint BasicKey::lowerValue(void) const
{
    return mLowerValue;
}

quint8 BasicKey::lowerGroup(void) const
{
    return mLowerGroup;
}

uint BasicKey::upperValue(void) const
{
    return mUpperValue;
}

quint8 BasicKey::upperGroup(void) const
{
    return mUpperGroup;
}


BasicKey BasicKey::get(const BasicKey::Part part)
{
    return masked(csmMasks[part]);
}

BasicKey BasicKey::masked(const quint64 mask) const
{
    return BasicKey(mKeyU64 & mask);
}

// static
BasicKey BasicKey::newKey(void)
{
    quint64 u64 = 0;
    quint32 u32 = quint32(QDateTime::currentMSecsSinceEpoch());
    int shift = u32 & 0x1F;
    u64 |= quint64(u32) << (32 + shift);
    u64 |= quint64(u32) << shift;
    u64 |= quint64(u32) >> (32 - shift);
    return BasicKey(u64);
}
