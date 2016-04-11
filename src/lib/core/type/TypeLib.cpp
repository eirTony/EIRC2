#include "TypeLib.h"
#include "Version.h"
#include <BranchVersion.h>
#include <CommonVersion.h>


#include <QtDebug>

#include <base/BaseLib.h>

DEFINE_SINGLETON(TypeLib)
const TypeLib * cgpType = TypeLib::pointer();

TypeLib::TypeLib(void)
    : ModuleInfo(MODULE_NAME)
{
    setVersion();
}
