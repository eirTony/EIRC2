#include "KiiRingPlugin.h"

#include "KiiRingBuiltin.h"

KiiRingPlugin::KiiRingPlugin(QObject * parent)
    : PluginObject(QString(),
                   "Kii/Ring",
                   new KiiRingPlugin(parent))
{
    QObject::setParent(parent);
}
