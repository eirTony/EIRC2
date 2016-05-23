#ifndef EXECUTABLEINITIALIZATION_H
#define EXECUTABLEINITIALIZATION_H
#include "ExeLib.h"

#include <base/BasicId.h>

class EXESHARED_EXPORT ExecutableInitialization
        : public BasicId::VariantMap
{
public:
    ExecutableInitialization(void);
    ExecutableInitialization(const BasicId::VariantMap & other);
    virtual void initialize(void);
    BasicId::VariantMap vars(void) const;
    BasicId::VariantMap operator & (void) const;
};

#endif // EXECUTABLEINITIALIZATION_H
