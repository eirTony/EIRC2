#ifndef EMPTY_GLOBAL_H
#define EMPTY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CORE_LIBRARY)
#  define CORESHARED_EXPORT Q_DECL_EXPORT
#else
#  define CORESHARED_EXPORT Q_DECL_IMPORT
#endif
#ifndef MODULE_NAME
# define MODULE_NAME "eirCore"
#endif
#endif // EMPTY_GLOBAL_H
