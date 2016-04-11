/*! @file   BasicId.cpp BaseLib BasicId class definitions
 */
#include "BasicId.h"

BasicId::BasicId(const QString & string) : QString(string) {}

BasicId::BasicId(const char * const chars) : QString(chars) {}
