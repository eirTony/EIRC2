#ifndef STATEMACHINECONFIGURATION_H
#define STATEMACHINECONFIGURATION_H

#include <cfg/Configuration.h>

class StateMachineConfiguration : public Configuration
{
public:
    StateMachineConfiguration(void);
    StateMachineConfiguration(const BasicId::VariantMap & bivm)
        : Configuration(bivm) {}

};

#endif // STATEMACHINECONFIGURATION_H
