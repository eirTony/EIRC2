#ifndef STATEKEY_H
#define STATEKEY_H

#include <type/Unsigned.h>

typedef Unsigned64 UniversalKey;

class StateKey : public UniversalKey
{
public:
    typedef QVector<StateKey> Vector;

public:
    StateKey(void);
};

#endif // STATEKEY_H
