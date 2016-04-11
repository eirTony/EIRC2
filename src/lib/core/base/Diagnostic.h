#ifndef DIAGNOSTIC
#define DIAGNOSTIC

#include "_internal/DiagnosticItem.h"

// todo: consider compare support e.g. EXPECTEQ

#define TRACE(msg, args...) _FMTITEM(QtDebugMsg, TRACE_PFX, msg, args)
#if (QT_VERSION >= QT_VERSION_CHECK(5,5,0))
#define INFO(msg, args...)  _FMTITEM(QtInfoMsg,  INFO_PFX,  msg, args)
#else
#define INFO(msg, args...)  _FMTITEM(QtDebugMsg, INFO_PFX,  msg, args)
#endif

#define TODO(msg)   __TODOITEM(QtDebugMsg,    TRACE_PFX DO_PFX,  #msg)
#define NEEDDO(msg) __TODOITEM(QtWarningMsg,  WARN_PFX  DO_PFX,  #msg)
#define MUSTDO(msg) __TODOITEM(QtCriticalMsg, CRIT_PFX  DO_PFX,  #msg)
#define NOUSE(var)  {(void)var;}
#define USE(var)    __TODOITEM(QtDebugMsg,    TRACE_PFX USE_PFX, #var); NOUSE(var)

#define TRACEMSGIF(act, msg)  __BOOLITEM(QtDebugMsg,    true,  act, msg)
#define WARNMSGIF(act, msg)   __BOOLITEM(QtWarningMsg,  true,  act, msg)
#define CRITMSGIF(act, msg)   __BOOLITEM(QtCriticalMsg, true,  act, msg)
#define WARNMSGNOT(act, msg)  __BOOLITEM(QtWarningMsg,  false, act, msg)
#define CRITMSGNOT(act, msg)  __BOOLITEM(QtCriticalMsg, false, act, msg)
#define FATALMSGNOT(act, msg) __BOOLITEM(QtCriticalMsg, false, act, msg)

#define TRACEIF(act)  __BOOLITEM(QtDebugMsg,    true,  act, "")
#define WARNIF(act)   __BOOLITEM(QtWarningMsg,  true,  act, "")
#define CRITIF(act)   __BOOLITEM(QtCriticalMsg, true,  act, "")
#define WARNNOT(act)  __BOOLITEM(QtWarningMsg,  false, act, "")
#define CRITNOT(act)  __BOOLITEM(QtCriticalMsg, false, act, "")
#define FATALNOT(act) __BOOLITEM(QtCriticalMsg, false, act, "")


#endif // DIAGNOSTIC
