#ifndef BASENAME_H
#define BASENAME_H
#include "KiiLib.h"

#include <base/BasicName.h>

class KIISHARED_EXPORT Name : public BasicName
{
public:
    Name(void);
    Name(const QString & name);
    Name(const char * const chars);
    Name(const BasicName & other);
    void set(const QString & name);

};

#endif // BASENAME_H
