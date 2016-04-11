#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <QDir>
#include <QList>

#include <base/AbstractPlugin.h>
#include <base/BasicId.h>
#include <base/BasicName.h>
#include <type/CharCode.h>

class LogOutputPlugin;


class PluginManager
{
public:
    typedef QList<QDir> DirList;

public:
    PluginManager(void);
    BasicId::List classList(void) const;
    EightCCList classSchemata(void) const;
    bool Enumerate(const DirList & additionalPaths=DirList());
    AbstractPlugin * classPlugin(const BasicId & pluginClass);
    LogOutputPlugin * logoutputPlugin(const EightCC schema,
          const BasicName::VariantMap & init=BasicName::VariantMap(),
          const BasicName::VariantMap & config=BasicName::VariantMap());
    LogOutputPlugin * logoutputPlugin(const EightCC schema,
                                      const QUrl & url);
    // can we template<LogOutputPlugin *> ?

private:
    bool mAutoEnumerate = false;
};

#endif // PLUGINMANAGER_H
