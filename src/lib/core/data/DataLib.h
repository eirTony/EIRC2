/*! @file   DataLib.h   Eclipse DataLib declaration
 */
#ifndef DataLib_H
#define DataLib_H
#include "data_global.h"

#include <base/ModuleInfo.h>
#include <core/Singleton.h>

/*! @class DataLib
 * @brief The DataLib is the base class in the eirData library.
 *
 * The DataLib is ...
 *
 */
class DATASHARED_EXPORT DataLib : public ModuleInfo
{
    DECLARE_SINGLETON(DataLib) // ctor & more
public:
};

#endif // DataLib_H
