/*! @file   CfgLib.cpp EclipseIR CfgLib definitions
 */
#include "CfgLib.h"
#include "Version.h"
#include <CommonVersion.h>

#include <QtDebug>

DEFINE_SINGLETON(CfgLib)
const CfgLib * cgpCfg = CfgLib::pointer();

/*! @fn CfgLib::CfgLib(void)
 *
 * @brief CfgLib::CfgLib initializes the CfgLib class.
 */
CfgLib::CfgLib(void)
    : ModuleInfo(MODULE_NAME)
{
    setVersion();
}

