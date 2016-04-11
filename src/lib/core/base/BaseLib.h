/*! @file   BaseLib.h   Eclipse BaseLib declaration
 */
#ifndef BASELIB_H
#define BASELIB_H
#include "base_global.h"

/*! @defgroup BaseLib
 *
 * The BaseLib contains any classes that would cause a
 * circular dependency in the foundations libraries above.
 */

#include <QProcessEnvironment>
#include <QStringList>
#include <QVariant>

#include <core/Singleton.h>
#include "ModuleInfo.h"

typedef void * VoidPtr;

class BASESHARED_EXPORT BaseLib : public ModuleInfo
{
    DECLARE_SINGLETON(BaseLib) // ctor & more
public:
    QProcessEnvironment systemEnvironment(void) const;
    QVariant systemEnvironmentValue(const QString & key,
                               const QVariant &defaultValue=QVariant()) const;
    QStringList systemEnvironmentKeys(const QString & startsWith=QString()) const;

public: // static
    static QString formatMessage(const QString & format,
                                 QVariantList vars);
public: // virtual
    virtual void doExecute(void);
    virtual void doInitialize(void);

private:
    QProcessEnvironment mSystemEnvironment;
};
/*! @class BaseLib BaseLib.h <base/BaseLib.h>
 * @brief The BaseLib is the base class in the eirBase library.
 * @ingroup BaseLib
 * @since BaseLib was started in v2.02
 * @remark { Note: As with all library class files,
 * BaseLib is implemented as a Singleton
 * and is used to provide static constructors
 * needed for its classes. }
 */

#endif // BASELIB_H
