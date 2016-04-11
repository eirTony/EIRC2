/*! @file   WorkLib.cpp EclipseIR WorkLib definitions
 */
#include "WorkLib.h"
#include "Version.h"
#include <CommonVersion.h>

#include <QtDebug>

DEFINE_SINGLETON(WorkLib)
const WorkLib * cgpWork = WorkLib::pointer();

/*! @fn WorkLib::WorkLib(void)
 *
 * @brief WorkLib::WorkLib initializes the WorkLib class.
 */
WorkLib::WorkLib(void)
    : ModuleInfo(MODULE_NAME)
{
    setVersion();
}
