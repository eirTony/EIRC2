/*! @file   BjutLib.h   Eclipse BjutLib declaration
 */
#ifndef BjutLib_H
#define BjutLib_H
#include "bjut_global.h"

#include <core/Singleton.h>

/*! @class BjutLib
 * @brief The BjutLib is the base class in the eirBjut librarary.
 *
 */
class BJUTSHARED_EXPORT BjutLib
{
public:
    BjutLib(void);
//    virtual void executeUnitTest(void);
};

/*! @typedef Bjut
 *
 * @brief Is the Singleton instance of BjutLib
 */
//typedef StaticSingleton<BjutLib> Bjut;

#endif // BjutLib_H
