/*! @file   BasicKey.h   BaseLib: BasicKey declaration
 */
#ifndef BASICKEY_H
#define BASICKEY_H
#include "BaseLib.h"

#include <QList>
#include <QSet>

#include "BasicId.h"
#include "TestObject.h"

class BasicKeySegment;

class BASESHARED_EXPORT BasicKey
{
public:
    enum Part
    {
        NoParts = 0,
        UpperGroup,
        UpperValue,
        LowerGroup,
        LowerValue,
        AllParts,
        sizePart
    };
    typedef QSet<Part> PartSet;
    typedef QList<BasicKey> List;

public:
    BasicKey(void);
    BasicKey(const quint64 other);
    BasicKey(const quint8 upperGroup,
             const uint upperValue,
             const quint8 lowerGroup,
             const uint lowerValue);
    BasicKey(const BasicId & id,
             const BasicKey other=BasicKey());

    void clear(void);
    void set(const quint64 other);
    void set(const Part part,
             const BasicKey other);
    void set(const quint8 upperGroup,
             const uint upperValue,
             const quint8 lowerGroup,
             const uint lowerValue);
    void set(const BasicId & id,
             const BasicKey other);
    void setUpper(const quint8 keyGroup,
                   const uint keyValue);
    void setLower(const quint8 keyGroup,
                 const uint keyValue);

    bool isNull(void) const; // both Groups zero
    bool isZero(void) const; // entire value is zero
    bool isValid(void) const;
    PartSet parts(void) const;
    bool overlaps(const BasicKey other) const;
    BasicKey unionWith(const BasicKey other);
    BasicKey operator |= (const BasicKey other);
    bool operator < (const BasicKey rhs) const;
    quint64 toU64(void) const;
    quint64 operator() (void) const;
    bool isUpper(void) const;
    BasicKeySegment lower(void) const;
    BasicKeySegment upper(void) const;
    uint lowerValue(void) const;
    quint8 lowerGroup(void) const;
    uint upperValue(void) const;
    quint8 upperGroup(void) const;
    BasicKey get(const BasicKey::Part part) const;
    BasicKey masked(const quint64 mask) const;

public:
    static BasicKey newKey(void);
    static BasicKey::Part part(const BasicId & id);

private:
    union
    {
        quint64 mKeyU64;
        struct
        {
            quint32 mUpperSegment;
            quint32 mLowerSegment;
        };
        struct
        {
            quint64 \
                    mUpperGroup : 8,
                    mUpperValue : 24,
                    mLowerGroup   : 8,
                    mLowerValue   : 24;
        };
    };
    const static quint64 csmMasks[sizePart];
};

#ifdef BUILD_TEST                       ///////// TEST
#include "TestObject.h"
#include "BasicId.h"

class BasicKeyTest : public TestObject
{
    Q_OBJECT
public:
    BasicKeyTest(QObject * parent=0);

private slots:
    void setBasicId(void);
    void setUpperLower(void);

private:
    BasicKey noKey;
    BasicId id0 = BasicId("0");
    BasicId idS = BasicId("Super");
    BasicId idS0 = BasicId("Super/0");
    BasicId idS0s = BasicId("Super/0/sub");
    BasicId idS0s0 = BasicId("Super/0/sub/0");

    BasicKey current = BasicKey::newKey();
    BasicKey keyNoId = BasicKey("", current);
    BasicKey keyS = BasicKey(idS, current);
    BasicKey keyS0 = BasicKey(idS0, current);
    BasicKey keyS0s = BasicKey(idS0s, current);
    BasicKey keyS0s0 = BasicKey(idS0s0, current);

};
#endif                                  //\\\\\\\ test

#endif // BASICKEY_H
