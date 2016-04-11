#ifndef KEYSEGMENT_H
#define KEYSEGMENT_H

#include <QBitArray>
#include <QList>

class KeySegment
{
public:
    typedef QList<KeySegment> List;

public:
    KeySegment(void);

private:
    QBitArray mBits;
};

#endif // KEYSEGMENT_H
