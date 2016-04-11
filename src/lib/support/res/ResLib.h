/*! @file   ResLib.h   Eclipse ResLib declaration
 */
#ifndef ResLib_H
#define ResLib_H
#include "res_global.h"

#include <base/ModuleInfo.h>
#include <core/Singleton.h>

/*! @class ResLib
 * @brief The ResLib is the base class in the eirRes library.
 *
 * The ResLib is ...
 *
 */
class RESSHARED_EXPORT ResLib : public ModuleInfo
{
    DECLARE_SINGLETON(ResLib) // ctor & more
public:
};

#endif // ResLib_H
