/*! @file   KiiLib.cpp EclipseIR KiiLib definitions
 */
#include "KiiLib.h"
#include "Version.h"
#include <CommonVersion.h>

#include <QtDebug>

DEFINE_SINGLETON(KiiLib)
const KiiLib * cgpKii = KiiLib::pointer();

/*! @fn KiiLib::KiiLib(void)
 *
 * @brief KiiLib::KiiLib initializes the KiiLib class.
 */
KiiLib::KiiLib(void)
    : ModuleInfo(MODULE_NAME)
{
    setVersion();
}
