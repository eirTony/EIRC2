#ifndef ARGUMENTSOURCEPAIR_H
#define ARGUMENTSOURCEPAIR_H

#include <type/StringPair.h>

#include <QList>
#include <QString>

class ArgumentSourcePair : public StringPair
{
public:
    typedef QList<StringPair> List;

public:
    ArgumentSourcePair(void);
    ArgumentSourcePair(const QString & argument,
                       const QString & source);
    QString argument(void) const;
    QString source(void) const;
};

#endif // ARGUMENTSOURCEPAIR_H
