#ifndef BASEKEY_H
#define BASEKEY_H
#include "KiiLib.h"

#include <type/QQBitArray.h>
#include <type/Unsigned.h>

class KIISHARED_EXPORT Key
{
public:
    Key(void); // Null
    Key(const int width, int value);
    Key(const QBitArray & bits);
    Key(const Key & other);
    void set(const int width, int value);
    void set(const QBitArray & bits);
    void set(const Key & other);
    bool operator < (const Key & other) const;

private:
    QQBitArray mKeyBits;
};

#endif // BASEKEY_H
