/*! @file   KiiLib.cpp EclipseIR KiiLib definitions
 */
#include "KiiLib.h"
#include "Version.h"
#include <CommonVersion.h>

#include <QtDebug>

KiiLib * gpKid = &(Kii::instance());

/*! @fn KiiLib::KiiLib(void)
 *
 * @brief KiiLib::KiiLib initializes the KiiLib class.
 */
KiiLib::KiiLib(void)
    : ModuleInfo(MODULE_NAME)
{
    setVersion();
}

#if 0
/*! @fn void executeUnitTest(void)
 *
 * @brief The executeUnitTest() function is global to KiiLib
 *
 * This global extern "C" function can be resolved and executed
 * after being loaded via QLibrary.
 */
extern "C" KIISHARED_EXPORT void executeUnitTest(void)
{
    Kid::instance()->executeUnitTest();
}

/*! @fn void KiiLib::executeUnitTest(void)
 *
 * @internal
 */
void KiiLib::executeUnitTest(void)
{
    QUT_FUNCTION();
    QUT_EXPECTEQ(VER_MAJOR, Kid::instance()->version().getMajor());
    //QUT_INSTANCE(AnyOtherClasses);
}
#endif
