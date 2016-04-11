#ifndef STATEKEY_H
#define STATEKEY_H

#include <kii/Key.h>

class StateKey : public Key
{
public:
    StateKey(void);
    StateKey(const Key & other);
};

#endif // STATEKEY_H
