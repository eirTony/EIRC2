#ifndef STORELIB_H
#define STORELIB_H
#define MODULE_NAME "eirStore"
#include "store_global.h"

#include <base/ModuleInfo.h>
#include <core/Singleton.h>

class STORELIBSHARED_EXPORT StoreLib : public ModuleInfo
{
    DECLARE_SINGLETON(StoreLib) // ctor & more
public:
};
/*! @class StoreLib
 * @brief The StoreLib is the base class in the eirStore library.
 *
 * The StoreLib supplies generic access to various
 * data-stores, such as MySQL and NoSQL.
 *
 */

#endif // STORELIB_H
