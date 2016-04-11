#ifndef STATEID_H
#define STATEID_H

#include <kii/Id.h>

class StateId : public Id
{
public:
    StateId(void);
    StateId(const Id & other);
    StateId(const BasicId & other);
    StateId(const QString & string);
    StateId(const char * const chars);

};

#endif // STATEID_H
