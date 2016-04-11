/*! @file   BaseLib.cpp BaseLib library class definitions
 */
#include "BaseLib.h"
#include "Version.h"
#include <CommonVersion.h>

#include <QtDebug>

//#include "BasicKey.h"
//#include "BasicKeyManager.h"
#include "BasicKeyManager.h"
#include "BasicName.h"
#include "Diagnostic.h"
#include "TestObject.h"
#include "_internal/ModuleManager.h"

DEFINE_SINGLETON(BaseLib)
const BaseLib * cgpBase = BaseLib::pointer();

/*! @fn BaseLib::BaseLib(void)
 *
 * @brief BaseLib::BaseLib() initializes the BaseLib class.
 */
BaseLib::BaseLib(void)
    : ModuleInfo(MODULE_NAME)
    , mSystemEnvironment(QProcessEnvironment::systemEnvironment())
{
    setVersion();

    WARNNOT(connect(ModuleManager::pointer(), SIGNAL(executing()),
                    this, SLOT(doExecute())));
    WARNNOT(connect(ModuleManager::pointer(), SIGNAL(executing()),
                    this, SLOT(doInitialize())));
}

QProcessEnvironment BaseLib::systemEnvironment(void) const
{
    return mSystemEnvironment;
}

QVariant BaseLib::systemEnvironmentValue(const QString & key,
                                         const QVariant & defaultValue) const
{
#if 1
    TRACE("key=<%1> defaultValue=<%2>", key, defaultValue);
    QVariant value = mSystemEnvironment.value(key, defaultValue.toString());
    bool contains = mSystemEnvironment.contains(key);
    TRACE("contains=%1 value=<%2>", contains, value.toString());
    return value;
#else
    return mSystemEnvironment.value(key, defaultValue);
#endif
}
QStringList BaseLib::systemEnvironmentKeys(const QString & startsWith) const
{
    QStringList rtn;
    QStringList keyList = mSystemEnvironment.keys();
    if (startsWith.isEmpty())
    {
        rtn = keyList;
    }
    else
    {
        foreach (QString key, keyList)
            if (key.startsWith(startsWith, Qt::CaseInsensitive))
                rtn << key;
    }
    return rtn;
}

QString BaseLib::formatMessage(const QString & format,
                               QVariantList vars)
{
    QString res = format;
    int k = 0;
    while ( ! vars.isEmpty())
    {
        QString key = QString("%%1").arg(++k);
        res.replace(key,
                    vars.takeFirst().toString());
    }
    return res;
}

void BaseLib::doExecute(void)
{
    TRACE("in BaseLib::doExecute()", 0);
}

void BaseLib::doInitialize(void)
{
    TRACE("We're %1", "there!");
#ifdef BUILD_TEST
    BasicIdTest bit;
    BasicKeyTest bkt;
    BasicKeyManagerTest bkmt;
    TestObject::execAll();
#endif
    TODO("RUN_TEST macros")
    TRACE("%1::%2()", "BaseLib", "doInitialize");
}

