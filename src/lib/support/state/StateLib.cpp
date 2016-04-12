/*! @file   StateLib.cpp   Eclipse StateLib class definition
 */

#include "StateLib.h"
#include "Version.h"
#include <BranchVersion.h>
#include <CommonVersion.h>


#include <QtDebug>

#include <base/Diagnostic.h>

DEFINE_SINGLETON(StateLib)
const StateLib * cgpState = StateLib::pointer();

StateLib::StateLib(void)
    : ModuleInfo(MODULE_NAME)
{
    setVersion();
}
/*! @fn StateLib::StateLib(void)
 *
 * @brief StateLib::StateLib initializes the StateLib class.
 */

void StateLib::doConstruct(void)
{
}
