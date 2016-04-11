/*! @file   BjutLib.cpp EclipseIR BjutLib definitions
 */
#include "BjutLib.h"
#include "Version.h"
#include <BranchVersion.h>
#include <CommonVersion.h>


#include <QtDebug>

#if 0
/*! @fn void executeUnitTest(void)
 *
 * @brief The executeUnitTest() function is global to BjutLib
 *
 * This global extern "C" function can be resolved and executed
 * after being loaded via QLibrary.
 */
extern "C" BJUTSHARED_EXPORT void executeUnitTest(void)
{
    Bjut::instance()->executeUnitTest();
}
#endif

/*! @fn BjutLib::BjutLib(void)
 *
 * @brief BjutLib::BjutLib initializes the BjutLib class.
 */
BjutLib::BjutLib(void)
{
}

#if 0
/*! @fn void BjutLib::executeUnitTest(void)
 *
 * @internal
 */
void BjutLib::executeUnitTest(void)
{
}
#endif
