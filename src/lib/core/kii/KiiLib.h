/*! @file   KiiLib.h KiiLib class declaration
 */
#ifndef KIILIB_H
#define KIILIB_H
#define MODULE_NAME "eirKii"
#include "kii_global.h"

#include <base/ModuleInfo.h>
#include <core/Singleton.h>

/*! @class KiiLib
 * @brief The KiiLib is the base class in the eirKid library.
 *
 * The KiiLib is an Kid Eclipse library from which new
 * libraries can be based.
 *
 */
class KIISHARED_EXPORT KiiLib : public ModuleInfo
{
public:
    KiiLib(void);
    //virtual void executeUnitTest(void);
};

/*! @typedef Kii
 *
 * @brief Is the StaticSingleton instance of KiiLib
 */
typedef StaticSingleton<KiiLib> Kii;

#endif // KIILIB_H
