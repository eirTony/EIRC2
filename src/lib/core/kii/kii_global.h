#ifndef EMPTY_GLOBAL_H
#define EMPTY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(KID_LIBRARY)
#  define KIISHARED_EXPORT Q_DECL_EXPORT
#else
#  define KIISHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // EMPTY_GLOBAL_H
