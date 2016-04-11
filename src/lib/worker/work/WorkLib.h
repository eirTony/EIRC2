/*! @file   WorkLib.h   Eclipse WorkLib declaration
 */
#ifndef WORKLIB_H
#define WORKLIB_H
#include "work_global.h"

#include <base/ModuleInfo.h>
#include <core/Singleton.h>

/*! @class WorkLib
 * @brief The WorkLib is the base class in the eirWork library.
 *
 * The WorkLib is...
 *
 */
class WORKSHARED_EXPORT WorkLib : public ModuleInfo
{
    DECLARE_SINGLETON(WorkLib) // ctor & more
public:
};

#endif // WORKLIB_H
