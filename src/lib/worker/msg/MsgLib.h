/*! @file   MsgLib.h   Eclipse MsgLib declaration
 */
#ifndef MsgLib_H
#define MsgLib_H
#include "msg_global.h"

#include <QVariantMap>

#include <base/ModuleInfo.h>
#include <core/Singleton.h>

/*! @class MsgLib
 * @brief The MsgLib is the base class in the eirMsg library.
 *
 * The MsgLib is ...
 *
 */
class MSGSHARED_EXPORT MsgLib : public ModuleInfo
{
    DECLARE_SINGLETON(MsgLib) // ctor & more
public:
};

#endif // MsgLib_H
