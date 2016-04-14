/*! @file   ExeLib.cpp EclipseIR ExeLib definitions
 */
#include "ExeLib.h"
#include "Version.h"
#include <CommonVersion.h>

#include <QtDebug>

DEFINE_SINGLETON(ExeLib)
const ExeLib * cgpExe = ExeLib::pointer();

/*! @fn ExeLib::ExeLib(void)
 *
 * @brief ExeLib::ExeLib initializes the ExeLib class.
 */
ExeLib::ExeLib(void)
    : ModuleInfo(MODULE_NAME)
{
    setVersion();
}
