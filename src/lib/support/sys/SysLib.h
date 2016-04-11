/*! @file   SysLib.h   Eclipse SysLib declaration
 */
#ifndef SysLib_H
#define SysLib_H
#define MODULE_NAME "eirSys"
#include "sys_global.h"

#include <base/ModuleInfo.h>
#include <core/Singleton.h>

/*! @class SysLib
 * @brief The SysLib is the base class in the eirSys library.
 *
 * The SysLib is...
 *
 */
class SYSSHARED_EXPORT SysLib : public ModuleInfo
{
    DECLARE_SINGLETON(SysLib) // ctor & more
public:
};

#endif // SysLib_H
