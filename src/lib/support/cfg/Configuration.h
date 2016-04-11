#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include "CfgLib.h"

#include <base/BasicId.h>
#include <base/BasicName.h>
#include <base/Diagnostic.h>
//#include <var/VariableMap.h>

class CFGSHARED_EXPORT Configuration // : public VariableMap
{
public:
    Configuration(void);
    Configuration(const Configuration & other);
    Configuration(const BasicId::VariantMap & bivm) {USE(bivm);}
    BasicId::VariantMap extract(const BasicId & sectionId) const
    {USE(sectionId); NEEDDO("extract") return BasicId::VariantMap();}
    void set(const Configuration & cfg) {USE(cfg); NEEDDO("config")}

private:
    BasicId::VariantMap mConfig;
};

#endif // CONFIGURATION_H
