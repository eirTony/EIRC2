#include "Configuration.h"

Configuration::Configuration(void) {;}

Configuration::Configuration(const Configuration & other)
{
    set(other);
}
