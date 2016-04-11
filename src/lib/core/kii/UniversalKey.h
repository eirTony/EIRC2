#ifndef UNIVERSALKEY_H
#define UNIVERSALKEY_H
#include "KiiLib.h"

#include <QList.h>

#include <type/Unsigned.h>

class KIISHARED_EXPORT UniversalKey : public Unsigned64
{
public:
    typedef QList<UniversalKey> List;

public:
    UniversalKey(void);
};

typedef UniversalKey::List UniversalKeyList;

#endif // UNIVERSALKEY_H
