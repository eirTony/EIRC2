/*! @file   VarLib.cpp EclipseIR VarLib definitions
 */
#include "VarLib.h"
#include "Version.h"
#include <CommonVersion.h>

#include <QtDebug>

DEFINE_SINGLETON(VarLib)
const VarLib * cgpVar = VarLib::pointer();


/*! @fn VarLib::VarLib(void)
 *
 * @brief VarLib::VarLib initializes the VarLib class.
 */
VarLib::VarLib(void)
    : ModuleInfo(MODULE_NAME)
{
    setVersion();
}
