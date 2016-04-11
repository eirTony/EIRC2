#ifndef NIBBLEARRAY_H
#define NIBBLEARRAY_H

#include <QByteArray>

#include "QQBitArray.h"
#include "Unsigned.h"

class NibbleArray
{
private:

public:
    NibbleArray(void);

private:
    QQBitArray mBits;
};

#endif // NIBBLEARRAY_H
