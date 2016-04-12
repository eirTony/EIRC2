/*! @file   CoreLib.cpp EclipseIR CoreLib definitions
 */
#include "CoreLib.h"
#include "Version.h"
#include <BranchVersion.h>
#include <CommonVersion.h>


#include <QtDebug>

DEFINE_SINGLETON(CoreLib)
const CoreLib * cgpCore = CoreLib::pointer();

/*! @fn CoreLib::CoreLib(void)
 *
 * @brief CoreLib::CoreLib initializes the CoreLib class.
 */
CoreLib::CoreLib(void)
    : ModuleInfo(MODULE_NAME)
{
    setVersion();
}
