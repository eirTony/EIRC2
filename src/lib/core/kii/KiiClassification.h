#ifndef KIICLASSIFICATION_H
#define KIICLASSIFICATION_H

#include <core/DualMap.h>

#include "KeySegment.h"
#include "KiiClassId.h"

class KiiClassification
{
public:
    KiiClassification(void);

private:
    DualMap<KiiClassId, KeySegment> mIdSegmentDMap;
};

#endif // KIICLASSIFICATION_H
