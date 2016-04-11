/*! @file   StateLib.cpp EclipseIR StateLib definitions
 */
#include "StateLib.h"
#include "Version.h"
#include <CommonVersion.h>

#include <QtDebug>

DEFINE_SINGLETON(StateLib)
const StateLib * cgpState = StateLib::pointer();

/*! @fn StateLib::StateLib(void)
 *
 * @brief StateLib::StateLib initializes the StateLib class.
 */
StateLib::StateLib(void)
    : ModuleInfo(MODULE_NAME)
{
    setVersion();
}

