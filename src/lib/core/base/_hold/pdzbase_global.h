#ifndef PDZBASE_GLOBAL_H
#define PDZBASE_GLOBAL_H

#ifndef LIBRARY_NAME
#  define LIBRARY_NAME "pdzBase"
#endif

#include <QtCore/qglobal.h>

#if defined(PDZBASE_LIBRARY)
#  define PDZBASESHARED_EXPORT Q_DECL_EXPORT
#else
#  define PDZBASESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // PDZBASE_GLOBAL_H
