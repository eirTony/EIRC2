#ifndef KEYBUILDER_H
#define KEYBUILDER_H

#include "KeySegment.h"

class KeyBuilder
{
public:
    KeyBuilder(void);

private:
    KeySegment::List mSegmentList;
};

#endif // KEYBUILDER_H
