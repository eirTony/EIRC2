/*! @file   AbstractPlugin.cpp BaseLib AbstractPlugin class definitions
 */
#include "AbstractPlugin.h"

#include "Diagnostic.h"

AbstractPlugin::AbstractPlugin(const BasicId & prefix,
                               const BasicName & name, /*
                               const EightCCList &schemata, */
                               const MetaName &meta)
{
    USE(prefix); USE(name); /*USE(schemata);*/ USE(meta);
    TODO("create and register expected QFileInfo");
}
