#include "Name.h"

Name::Name(void) {}
Name::Name(const BasicName & other) : BasicName(other) {;}

Name::Name(const QString & name)
{
    set(name);
}

Name::Name(const char * const name)
{
    set(QString(name));
}


void Name::set(const QString & name)
{
    BasicName::set(name);
}
