/*! @file   StateLib.h   Eclipse StateLib declaration
 */
#ifndef StateLib_H
#define StateLib_H
#include "state_global.h"

#include <base/ModuleInfo.h>
#include <core/Singleton.h>


/*! @class StateLib
 * @brief The StateLib is the base class in the eirState library.
 *
 * The StateLib is ....
 *
 */
class STATESHARED_EXPORT StateLib : public ModuleInfo
{
    DECLARE_SINGLETON(StateLib) // ctor & more
public:
};

#endif // StateLib_H
