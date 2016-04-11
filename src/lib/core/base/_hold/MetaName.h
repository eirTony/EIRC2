/*! @file   MetaName.h   BaseLib: MetaName declaration
 */
#ifndef METANAME_H
#define METANAME_H
#include "pdzBase.h"

#include <QByteArray>
#include <QString>

class PDZBASESHARED_EXPORT MetaName : public QByteArray
{
public:
    MetaName(const QByteArray & name=QByteArray());
    MetaName(const QString & string);
    MetaName(const char * chars);
};
/*! @class MetaName MetaName.h <base/MetaName.h>
 * @brief MetaName contains a name in the QMetaObject facility
 * @since MetaName was introduced in v2.03
 * @ingroup BaseLib
 */

#endif // METANAME_H
