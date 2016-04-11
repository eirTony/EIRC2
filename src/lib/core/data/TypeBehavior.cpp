/*! @file TypeBehavior.cpp Definitions for TypeBehavior base class
*
*/
#include "TypeBehavior.h"

#include <QDomElement>
#include <QVariant>
#include <QVector>

#include <base/Diagnostic.h>

QVector<int> TypeBehavior::size_digits_i_vec
    = QVector<int>() << -1 << 3 << 5 << 8 << 10 << 0 << 0 << 0 << 20;
/*                       0    1    2    3     4    5    6    7     8 */

TypeBehavior::TypeBehavior(void)
{
}

QString TypeBehavior::readable(const QVariant & var)
{
    CRITNOT(var.canConvert(QVariant::String));
    return var.toString();
}

QString TypeBehavior::sortable(const QVariant & var)
{
    CRITNOT(var.canConvert(QVariant::String));
    return var.toString().toLower();
}

QStringList TypeBehavior::hexdump(const QVariant & var,
                            const QString & title)
{
    USE(var);
    USE(title);
    MUSTDO("hexdump()");
    return QStringList();
}

QString TypeBehavior::parsable(const QVariant & var)
{
    USE(var);
    MUSTDO("parsable()");
    return QString();
}


QVariant TypeBehavior::parsed(const int dtype,
                              const QString & s)
{
    USE(s);
    USE(dtype);
    NEEDDO("parsed()");
    return QVariant();
}


QDomElement TypeBehavior::domVariant(const QVariant & var)
{
    USE(var);
    MUSTDO("domVariant()");
    return QDomElement();
}


QVariant TypeBehavior::variantDom(const int dtype,
                                  const QDomElement & de)
{
    USE(dtype);
    USE(de);
    MUSTDO("variantDom()");
    return QVariant();
}


QStringList TypeBehavior::binaryEncoded(const int dtype,
                                        const QByteArray & ba)
{
    USE(dtype);
    USE(ba);
    MUSTDO("binaryEncoded()");
    return QStringList();
}


QByteArray TypeBehavior::binaryDecoded(const int dtype,
                                       const QStringList & qsl)
{
    USE(dtype);
    (void)qsl;
    MUSTDO("binaryDecoded()");
    return QByteArray();
}


QByteArray TypeBehavior::baVariant(const QVariant & var)
{
    USE(var);
    MUSTDO("baVariant()");
    return QByteArray();
}


QVariant TypeBehavior::variantBA(const int dtype, const QByteArray & ba)
{
    USE(dtype);
    USE(ba);
    MUSTDO("variantBA()");
    return QVariant();
}
