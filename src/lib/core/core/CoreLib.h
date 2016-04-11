/*! @file   CoreLib.h   Eclipse CoreLib declaration
 */
#ifndef CoreLib_H
#define CoreLib_H
#include "core_global.h"

#include <base/ModuleInfo.h>
#include <core/Singleton.h>

/*! @class CoreLib
 * @brief The CoreLib is the base class in the eirCore library.
 *
 * The CoreLib is...
 *
 */
class CORESHARED_EXPORT CoreLib : public ModuleInfo
{
    DECLARE_SINGLETON(CoreLib) // ctor & more
public:
};

#endif // CoreLib_H
