#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include "CfgLib.h"

#include <base/BasicId.h>
#include <base/BasicName.h>
#include <var/VariableMap.h>

class CFGSHARED_EXPORT Configuration : public VariableMap
{
public:
    Configuration(void);
    Configuration(const BasicId::VariantMap & bivm) {}
    BasicName::VariantMap extract(const BasicId & sectionId)
    { return BasicName::VariantMap(); }
};

#endif // CONFIGURATION_H
