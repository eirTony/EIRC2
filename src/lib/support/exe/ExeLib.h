/*! @file   ExeLib.h   Eclipse ExeLib declaration
 */
#ifndef ExeLib_H
#define ExeLib_H
#ifndef MODULE_NAME
# define MODULE_NAME "eirExe"
#endif
#include "exe_global.h"

#include <base/ModuleInfo.h>
#include <core/Singleton.h>

/*! @class ExeLib
 * @brief The ExeLib is the base class in the eirExe library.
 *
 * The ExeLib is...
 *
 */
class ExeLib : public ModuleInfo
{
    DECLARE_SINGLETON(ExeLib) // ctor & more
public:
};

#endif // ExeLib_H
