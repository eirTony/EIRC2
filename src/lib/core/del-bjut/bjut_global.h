#ifndef BJUT_GLOBAL_H
#define BJUT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(BJUT_LIBRARY)
#  define BJUTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define BJUTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // BJUT_GLOBAL_H
