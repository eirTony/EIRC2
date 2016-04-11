/*! @file   VarLib.h   Eclipse VarLib declaration
 */
#ifndef VarLib_H
#define VarLib_H
#ifndef MODULE_NAME
# define MODULE_NAME "eirVar"
#endif
#include "var_global.h"

#include <base/ModuleInfo.h>
#include <core/Singleton.h>

/*! @class VarLib
 * @brief The VarLib is the base class in the eirVar library.
 *
 * The VarLib is an Var Eclipse library from which new
 * libraries can be based.
 *
 */
class VARSHARED_EXPORT VarLib : public ModuleInfo
{
    DECLARE_SINGLETON(VarLib) // ctor & more
public:
};

#endif // VarLib_H
