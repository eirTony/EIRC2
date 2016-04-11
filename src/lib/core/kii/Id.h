#ifndef BASEID_H
#define BASEID_H
#include "KiiLib.h"
#include <base/BasicId.h>

class KIISHARED_EXPORT Id : public BasicId
{
public:
    Id(const QString & string=QString());
    Id(const char * const chars);
    Id(const BasicId & other);
};

#endif // BASEID_H
