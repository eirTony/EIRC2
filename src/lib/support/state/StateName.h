#ifndef STATENAME_H
#define STATENAME_H

#include <kii/Name.h>

class StateName : public Name
{
public:
    StateName(void);
    StateName(const Name & other);
    StateName(const BasicName & other);
};

#endif // STATENAME_H
