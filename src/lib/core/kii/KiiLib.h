/*! @file   KiiLib.h KiiLib class declaration
 */
#ifndef KIILIB_H
#define KIILIB_H
#include "kii_global.h"

#include <base/ModuleInfo.h>
#include <core/Singleton.h>

/*! @class KiiLib
 * @brief The KiiLib is the base class in the eirKii library.
 *
 * The KiiLib is ...
 *
 */
class KIISHARED_EXPORT KiiLib : public ModuleInfo
{
    DECLARE_SINGLETON(KiiLib) // ctor & more
public:
};

#endif // KIILIB_H
