#include "StateId.h"

StateId::StateId(void)                                          {;}
StateId::StateId(const Id & other)      : Id(other)     {;}
StateId::StateId(const BasicId & other)     : Id(other)     {;}
StateId::StateId(const QString & string)    : Id(string)    {;}
StateId::StateId(const char * const chars)  : Id(chars)     {;}

