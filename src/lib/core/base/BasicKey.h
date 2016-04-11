/*! @file   BasicKey.h   BaseLib: BasicKey declaration
 */
#ifndef BASICKEY_H
#define BASICKEY_H
#include "BaseLib.h"

class BASESHARED_EXPORT BasicKey
{
public:
    BasicKey(void);
    BasicKey(const quint64 key);

private:
    quint64 mKeyU64;
};

#endif // BASICKEY_H
