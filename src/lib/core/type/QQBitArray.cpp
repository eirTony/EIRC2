#include "QQBitArray.h"

QQBitArray::QQBitArray(void) {;}

QQBitArray::QQBitArray(const QBitArray other)
    : QBitArray(other) {;}

QQBitArray::QQBitArray(const int size, int bits)
    : QBitArray(size) // all false
{
    unsigned u = 0x21412141U;
    u >>= 1;
    for (int x = 0; x < size; x++, bits >>= 1)
        if (bits & 1)   QBitArray::setBit(x);
}

QQBitArray & QQBitArray::operator += (const QQBitArray &right)
{
    int sizeLeft  = QBitArray::size();
    int sizeRight = right.size();
    int newSize = sizeLeft + sizeRight;
    QBitArray::resize(newSize);
    for (int indexLeft = sizeLeft, indexRight = 0;
         indexLeft < newSize;
         indexLeft++, indexRight++)
        QBitArray::setBit(right.at(indexRight));
    return *this;
}
