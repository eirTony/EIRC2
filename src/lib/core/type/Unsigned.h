#ifndef UNSIGNED_H
#define UNSIGNED_H
#include "TypeLib.h"

template <class UINT> class Unsigned
{
public:
    Unsigned(void)  : mUnsigned(0) {}
    Unsigned(const UINT u) : mUnsigned(u) {}
    operator UINT (void) const { return mUnsigned; }
    UINT operator () (void) const { return mUnsigned; }
    UINT operator = (const UINT other) { return mUnsigned = other; }

private:
    UINT mUnsigned = 0;
};

typedef Unsigned<quint16> Unsigned16;
typedef Unsigned<quint64> Unsigned64;

#endif // UNSIGNED_H
