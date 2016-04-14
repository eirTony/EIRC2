/*! @file   StoreLib.cpp   Eclipse StoreLib class definition
 */

#include "StoreLib.h"

#include "Version.h"
#include <CommonVersion.h>

DEFINE_SINGLETON(StoreLib)
const StoreLib * cgpStore = StoreLib::pointer();

StoreLib::StoreLib(void)
    : ModuleInfo(MODULE_NAME)
{
    setVersion();
}
/*! @fn StoreLib::StoreLib(void)
 *
 * @brief StoreLib::StoreLib initializes the StateLib class.
 */

