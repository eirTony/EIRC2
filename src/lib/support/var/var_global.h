#ifndef VAR_GLOBAL_H
#define VAR_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(VAR_LIBRARY)
#  define VARSHARED_EXPORT Q_DECL_EXPORT
#else
#  define VARSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // VAR_GLOBAL_H
