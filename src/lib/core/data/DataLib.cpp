/*! @file   DataLib.cpp EclipseIR DataLib definitions
 */
#include "DataLib.h"
#include "Version.h"
#include <CommonVersion.h>

#include <QtDebug>

DEFINE_SINGLETON(DataLib)
const DataLib * cgpData = DataLib::pointer();

/*! @fn DataLib::DataLib(void)
 *
 * @brief DataLib::DataLib initializes the DataLib class.
 */
DataLib::DataLib(void)
    : ModuleInfo(MODULE_NAME)
{
    setVersion();
}
