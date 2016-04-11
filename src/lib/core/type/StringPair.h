#ifndef STRINGPAIR_H
#define STRINGPAIR_H
#include "TypeLib.h"

#include <QPair>
#include <QString>

class TYPESHARED_EXPORT StringPair : public QPair<QString, QString>
{
public:
    typedef QPair<QString, QString> Base;

public:
    StringPair(void);
    StringPair(const QString & first,
               const QString & second);
    QString first(void)  const;
    QString second(void) const;
};

#endif // STRINGPAIR_H
