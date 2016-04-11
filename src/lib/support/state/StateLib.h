/*! @file   StateLib.h   Eclipse StateLib declaration
 */
#ifndef STATELIB_H
#define STATELIB_H
#include "state_global.h"

#include <base/ModuleInfo.h>
#include <core/Singleton.h>

class STATESHARED_EXPORT StateLib : public ModuleInfo
{
    DECLARE_SINGLETON(StateLib) // ctor & more
public:

public: // virtual
    virtual void doConstruct(void);
};
/*! @class StateLib
 * @brief The StateLib is the base class in the eirState library.
 *
 * The StateLib supplies a code generation mechanism
 * for an abstract, nearly-pure virtual finite state machine.
 * In addition, the EclipseMachine and its suport
 * classes allow other Support-level Eclipse libraries
 * to have a standardized initialize-configure-start-etc.
 * interface as state machines.
 *
 */

#endif // STATELIB_H
