/*! @file   MsgLib.cpp EclipseIR MsgLib definitions
 */
#include "MsgLib.h"
#include "Version.h"
#include <BranchVersion.h>
#include <CommonVersion.h>


#include <QtDebug>

DEFINE_SINGLETON(MsgLib)
const MsgLib * cgpMsg = MsgLib::pointer();

/*! @fn MsgLib::MsgLib(void)
 *
 * @brief MsgLib::MsgLib initializes the MsgLib class.
 */
MsgLib::MsgLib(void)
    : ModuleInfo(MODULE_NAME)
{
    setVersion();
}
