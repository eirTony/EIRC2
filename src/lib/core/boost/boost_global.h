#ifndef BOOST_GLOBAL_H
#define BOOST_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(BOOST_LIBRARY)
#  define BOOSTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define BOOSTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // BOOST_GLOBAL_H
