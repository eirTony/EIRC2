/*! @file ModuleInfo.h  BaseLib ModuleInfo class declarations
*/
#ifndef MODULE_H
#define MODULE_H
#include "base_global.h"

#include <QObject>

#include <QMap>
#include <QString>

#include "VersionInfo.h"
class ModuleManager;

/*! @class ModuleInfo
 *
 * @brief The ModuleInfo class manages the overall EIRC library collection.
 *
 */
class BASESHARED_EXPORT ModuleInfo : public QObject
{
    Q_OBJECT
public:
    ModuleInfo(void);
    ModuleInfo(const QString & name);
    ModuleInfo(QObject * parent);
    bool isNull(void) const;
    void setVersion(void);
    QString name(void) const;
    VersionInfo version(void) const;

public slots: // virtual
    virtual void doConstruct(void);
    virtual void doExecute(void);
    virtual void doTest(void);
    virtual void doInitialize(void);
    virtual void doConfigure(void);
    virtual void doStart(void);
    virtual void doStop(void);
    virtual void doQuit(void);

private:
    QString mName;
    VersionInfo mVI;
    ModuleManager * mpManager = 0;
};
Q_DECLARE_TYPEINFO(ModuleInfo, Q_PRIMITIVE_TYPE);

#endif // MODULE_H
