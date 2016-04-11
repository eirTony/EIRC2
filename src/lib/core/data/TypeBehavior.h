/*! @file TypeBehavior.h Declarations for TypeBehavior template
*
*/
#ifndef TYPEBEHAVIOR_H
#define TYPEBEHAVIOR_H
#include "DataLib.h"

#include <QVector>

#include "DataType.h"

class QDomElement;

typedef QVector<int> IntVector;

class DATASHARED_EXPORT TypeBehavior
{
public:
    virtual QString readable(const QVariant & var);
    virtual QString sortable(const QVariant & var);
    virtual QStringList hexdump(const QVariant & var,
                                const QString & title=QString());
    virtual QString parsable(const QVariant & var);
    virtual QVariant parsed(const int dtype,
                            const QString & s);
    virtual QDomElement domVariant(const QVariant & var);
    virtual QVariant variantDom(const int dtype,
                                const QDomElement & de);
    virtual QStringList binaryEncoded(const int dtype,
                                      const QByteArray & ba);
    virtual QByteArray binaryDecoded(const int dtype,
                                     const QStringList & qsl);
    virtual QByteArray baVariant(const QVariant & var);
    virtual QVariant variantBA(const int dtype,
                               const QByteArray & ba);

protected:
    TypeBehavior(void);
    static IntVector size_digits_i_vec;
};

#endif // TYPEBEHAVIOR_H
