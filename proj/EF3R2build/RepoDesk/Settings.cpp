#include "Settings.h"

#include <QDir>

const QString baseDirKey("Dirs/BaseDir");

Settings::Settings(const QString & orgName,
                   const QString & appName,
                   QObject * parent)
    : QSettings(orgName, appName, parent)
{
    setObjectName("Settings");
}

QDir Settings::getBaseDir(void) const
{
    return QDir(value(baseDirKey).toString());
}

void Settings::setBaseDir(const QDir & base)
{
    setValue(baseDirKey, base.path());
}
