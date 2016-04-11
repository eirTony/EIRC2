/*! @file   MetaName.h   BaseLib: MetaName declaration
 */
#ifndef METANAME_H
#define METANAME_H
#include "BaseLib.h"

#include <QByteArray>
#include <QString>

class BASESHARED_EXPORT MetaName
{
public:
    MetaName(void);
    MetaName(const char * chars);
    MetaName(const QString & string);
    MetaName(const QByteArray & name);

    bool isEmpty(void) const;
    void set(const QString & string);

    const char * name(void) const;
    operator const char * (void) const;
    QString toString(void) const;
    operator QString (void) const;
    QString operator () (void) const;
    bool operator < (const MetaName & other);

private:
    QByteArray mChars;
};
/*! @class MetaName MetaName.h <base/MetaName.h>
 * @brief MetaName contains a name in the QMetaObject facility
 * @since MetaName was introduced in v2.03
 * @ingroup BaseLib
 */

extern BASESHARED_EXPORT bool operator < (const MetaName & left,
                                          const MetaName & right);

#endif // METANAME_H
