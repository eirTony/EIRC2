#include "BasicKeySegment.h"

BasicKeySegment::BasicKeySegment(void) : mSegU32(0) {;}

BasicKeySegment::BasicKeySegment(const BasicKeySegment & other)
    : mSegU32(other.mSegU32) {;}

BasicKeySegment::BasicKeySegment(const quint8 keyGroup,
                                 const uint keyValue)
    : mSegU32(keyValue << 8 | keyGroup) {;}
