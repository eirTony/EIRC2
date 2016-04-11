#include "StringBehavior.h"

#include <QDomElement>

#include <base/Diagnostic.h>
#include <base/BasicId.h>

//#include "Hexdump.h"

StringBehavior * StringBehavior::instance_p = 0;

StringBehavior * StringBehavior::instance(void)
{
    if ( ! instance_p) instance_p = new StringBehavior;
    return instance_p;
}

StringBehavior::StringBehavior(void)
{
}

QString StringBehavior::sortable(const QVariant & var)
{
    return var.toString().toLower();
}

QStringList StringBehavior::hexdump(const QVariant & var,
                                     const QString & title)
{
    USE(title);
    QString s = var.toString();
    QByteArray ba = s.toLocal8Bit();
    TODO("QStringList result(Hexdump::from(ba, title));");
    return QStringList();
}

QString StringBehavior::parsable(const QVariant & var)
{
    return QString("%1 %2")
            .arg(DataType::name(QMetaType::type("BasicId")))
            .arg(var.toString());
}

QVariant StringBehavior::parsed(const QString & s)
{
    QString is = s.simplified();
    int x = is.indexOf(' ');
    if (x > 0) is = is.mid(x+1);
    return QVariant(is);
}

QDomElement StringBehavior::domVariant(const QVariant & var)
{
    QDomDocument tempDoc;
    QDomElement result = tempDoc.createElement(DataType::elementTag_s);
    result.setAttribute(DataType::attribute_s,
                        QMetaType::typeName(QMetaType::type("BasicId")));
    QString text = var.toString();
    QDomText textNode = result.ownerDocument().createTextNode(text);
    result.appendChild(textNode);
    return result;
}

QVariant StringBehavior::variantDom(const QDomElement & de)
{
    WARNNOT(QMetaType::typeName(QMetaType::type("BasicId"))
                  == de.attribute(DataType::attribute_s));
    QString s = de.text();
    return QVariant(s);
}
