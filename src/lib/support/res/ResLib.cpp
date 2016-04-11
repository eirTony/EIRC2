/*! @file   ResLib.cpp EclipseIR ResLib definitions
 */
#include "ResLib.h"
#include "Version.h"
#include <BranchVersion.h>
#include <CommonVersion.h>


#include <QtDebug>

DEFINE_SINGLETON(ResLib)
const ResLib * cgpRes = ResLib::pointer();

/*! @fn ResLib::ResLib(void)
 *
 * @brief ResLib::ResLib initializes the ResLib class.
 */
ResLib::ResLib(void)
    : ModuleInfo(MODULE_NAME)
{
    setVersion();
}
