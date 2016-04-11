#ifndef EMPTY_GLOBAL_H
#define EMPTY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DATA_LIBRARY)
#  define DATASHARED_EXPORT Q_DECL_EXPORT
#else
#  define DATASHARED_EXPORT Q_DECL_IMPORT
#endif
#ifndef MODULE_NAME
# define MODULE_NAME "eirData"
#endif
#endif // EMPTY_GLOBAL_H
