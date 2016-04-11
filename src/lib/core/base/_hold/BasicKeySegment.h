/*! @file   BasicKeySegment.h   BaseLib: BasicKeySegment declaration
 */
#ifndef BASICKEYSEGMENT_H
#define BASICKEYSEGMENT_H
#include "pdzBase.h"

class BasicKeySegment
{
public:
    BasicKeySegment(void);
    BasicKeySegment(const BasicKeySegment & other);
    BasicKeySegment(const quint8 keyGroup,
                    const uint keyValue);

public:
    union
    {
        quint32 mSegU32;
        struct
        {
            quint64 mSegValue   : 24,
                    mSegGroup   : 8;
        };
    };

};

#endif // BASICKEYSEGMENT_H
