#ifndef SYS_GLOBAL_H
#define SYS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SYS_LIBRARY)
#  define SYSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define SYSSHARED_EXPORT Q_DECL_IMPORT
#endif
#ifndef MODULE_NAME
# define MODULE_NAME "eirSys"
#endif
#endif // SYS_GLOBAL_H
