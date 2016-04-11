#ifndef QQBITARRAY_H
#define QQBITARRAY_H
#include "TypeLib.h"

#include <QBitArray>

#include "Unsigned.h"

class TYPESHARED_EXPORT QQBitArray : public QBitArray
{
public:
    QQBitArray(void);
    QQBitArray(const QBitArray other);
    QQBitArray(const int size, int bits);
    QQBitArray & operator += (const QQBitArray & right);
};

#endif // QQBITARRAY_H
