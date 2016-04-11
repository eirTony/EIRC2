/*! @file   BasicKey.h   BaseLib: BasicKey declaration
 */
#ifndef BASICKEY_H
#define BASICKEY_H
#include "BaseLib.h"

#include <QList>


class BasicKeySegment;

#ifdef BUILD_TEST
#include "TestObject.h"

class BasicKeyTest : public TestObject
{
    Q_OBJECT
public:
    BasicKeyTest(QObject * parent=0);

private slots:
    void setUpperLower(void);
};
#endif

class BASESHARED_EXPORT BasicKey
{
public:
    enum Part
    {
        nullPart = 1,
        UpperGroup,
        UpperValue,
        LowerGroup,
        LowerValue,
        sizePart
    };
    typedef QList<BasicKey> List;

public:
    BasicKey(void);
    BasicKey(const quint64 other);
    BasicKey(const quint8 upperGroup,
             const uint upperValue,
             const quint8 lowerGroup,
             const uint lowerValue);

    void clear(void);
    void set(const quint64 other);
    void set(const Part part,
             const BasicKey other);
    void set(const quint8 upperGroup,
             const uint upperValue,
             const quint8 lowerGroup,
             const uint lowerValue);
    void setUpper(const quint8 keyGroup,
                   const uint keyValue);
    void setLower(const quint8 keyGroup,
                 const uint keyValue);

    bool isNull(void) const; // both Groups zero
    bool isZero(void) const;
    bool operator < (const BasicKey rhs) const;
    quint64 operator() (void) const;
    bool isUpper(void) const;
    BasicKeySegment lower(void) const;
    BasicKeySegment upper(void) const;
    uint lowerValue(void) const;
    quint8 lowerGroup(void) const;
    uint upperValue(void) const;
    quint8 upperGroup(void) const;
    BasicKey get(const BasicKey::Part part);
    BasicKey masked(const quint64 mask) const;

public:
    static BasicKey newKey(void);

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

#endif // BASICKEY_H
