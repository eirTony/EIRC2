#ifndef BOOLEAN_H
#define BOOLEAN_H
#include "TypeLib.h"

class TYPESHARED_EXPORT Boolean
{
public:
    Boolean(void);
    Boolean(const bool is);

private:
    bool mBool = false;
};

#endif // BOOLEAN_H
