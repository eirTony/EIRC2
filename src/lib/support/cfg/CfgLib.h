/*! @file   CfgLib.h   Eclipse CfgLib declaration
 */
#ifndef CfgLib_H
#define CfgLib_H
#ifndef MODULE_NAME
# define MODULE_NAME "eirCfg"
#endif
#include "cfg_global.h"

#include <base/ModuleInfo.h>
#include <core/Singleton.h>

/*! @class CfgLib
 * @brief The CfgLib is the base class in the eirCfg library.
 *
 * The CfgLib is an Cfg Eclipse library from which new
 * libraries can be based.
 *
 */
class CFGSHARED_EXPORT CfgLib : public ModuleInfo
{
    DECLARE_SINGLETON(CfgLib) // ctor & more
public:
};

#endif // CfgLib_H
