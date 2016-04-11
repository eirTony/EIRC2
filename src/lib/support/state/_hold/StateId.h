#ifndef STATEID_H
#define STATEID_H

#include <kii/AbstractId.h>

class StateId : public AbstractId
{
public:
    typedef QVector<StateId> Vector;

public:
    StateId(const QString & string=QString());
    StateId(const char * const chars);
};

#endif // STATEID_H
