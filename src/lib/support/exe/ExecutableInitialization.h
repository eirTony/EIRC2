#ifndef EXECUTABLEINITIALIZATION_H
#define EXECUTABLEINITIALIZATION_H
#include "ExeLib.h"

#include <base/BasicId.h>

class EXESHARED_EXPORT ExecutableInitialization
        : public BasicId::VariantMap
{
public:
    ExecutableInitialization(void);
    BasicId::VariantMap initVarMap(void) const;
};

#endif // EXECUTABLEINITIALIZATION_H
