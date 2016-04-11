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

#define TRACEIF(act, msg)  __BOOLITEM(QtDebugMsg,    true,  act, msg)
#define WARNIF(act, msg)   __BOOLITEM(QtWarningMsg,  true,  act, msg)
#define CRITIF(act, msg)   __BOOLITEM(QtCriticalMsg, true,  act, msg)

#define CRITNOT(act, msg)  __BOOLITEM(QtCriticalMsg, false, act, msg)
#define FATALNOT(act, msg) __BOOLITEM(QtCriticalMsg, false, act, msg)
#define TRACEIF(act, msg)  __BOOLITEM(QtDebugMsg,    true,  act, msg)
#define ERRORIF(act, msg)  __BOOLITEM(QtCriticalMsg, true,  act, msg)

#define WARNNOT(act, msg)  __BOOLITEM(QtWarningMsg,  false, act, msg)
#define ERRORNOT(act, msg) __BOOLITEM(QtCriticalMsg, false, act, msg)

#endif // DIAGNOSTIC
