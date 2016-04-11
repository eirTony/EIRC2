#ifndef TYPE_GLOBAL_H
#define TYPE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TYPE_LIBRARY)
#  define TYPESHARED_EXPORT Q_DECL_EXPORT
#else
#  define TYPESHARED_EXPORT Q_DECL_IMPORT
#endif
#ifndef MODULE_NAME
# define MODULE_NAME "eirType"
#endif
#endif // TYPE_GLOBAL_H
