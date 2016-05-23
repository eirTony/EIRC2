#include "ExecutableInitialization.h"

ExecutableInitialization::ExecutableInitialization(void) {;}
ExecutableInitialization::ExecutableInitialization(const BasicId::VariantMap & other)
    : BasicId::VariantMap(other) {;}

// virtual
void ExecutableInitialization::initialize(void) {;}

BasicId::VariantMap ExecutableInitialization::vars(void) const
{
    return *(BasicId::VariantMap *)(this);
}

BasicId::VariantMap ExecutableInitialization::operator & (void) const
{
    return vars();
}

