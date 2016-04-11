/*! @file   BasicKey.cpp BaseLib BasicKey class definitions
 */
#include "BasicKey.h"

BasicKey::BasicKey(void) : mKeyU64(0) {;}

BasicKey::BasicKey(const quint64 key) : mKeyU64(key) {;}
