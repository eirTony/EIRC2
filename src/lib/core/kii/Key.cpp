#include "Key.h"

#include <base/Diagnostic.h>

Key::Key(void) {;}

Key::Key(const int width, int value) { set(width, value); }

Key::Key(const QBitArray & bits) { set(bits); }

Key::Key(const Key & other) { set(other); }

void Key::set(const int width, int value)
{
    unsigned widthBits = width >> 4;
    unsigned valueWidth = widthBits << 4;
    WARNMSGIF(valueWidth > sizeof(value), "bit overflow");
    mKeyBits = QQBitArray(4, widthBits);
    mKeyBits += QQBitArray(valueWidth, value);
}

void Key::set(const QBitArray & bits)
{
    mKeyBits = QQBitArray(bits);
}

void Key::set(const Key & other)
{
    mKeyBits = other.mKeyBits;
}


bool Key::operator < (const Key & other) const
{
    USE(other);
    MUSTDO("bit by bit?");
    return true;
}
