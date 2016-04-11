#include "ModuleManager.h"

#include <QCoreApplication>

#include "Diagnostic.h"

DEFINE_SINGLETON(ModuleManager)

ModuleManager::ModuleManager(void) {;}

/*! @fn QStringList ModuleInfo::moduleNames(void) // static
 * @brief ModuleInfo::moduleNames
 * @return QStringList module names
 *
 * Returns each of the names of the modules that have
 * been created in this process.
 */
QStringList ModuleManager::moduleNames(void) // static
{
    return mNamePtrMap.keys();
}

/*! @fn void ModuleInfo::debugVersions(void) // static
 * @internal
 * @brief ModuleInfo::debugVersions writes to QtDebug for each registered library.
 */
void ModuleManager::dumpVersions(void) // static
{
    foreach (ModuleInfo * p, mNamePtrMap.values())
        TRACE("%1 - %2 [%3]", p->name(), p->version().toString(true));
}

void ModuleManager::muster(ModuleInfo * pModule)
{
    CRITNOT(pModule);
    if (pModule) mNamePtrMap.insert(pModule->name(), pModule);
    WARNNOT(connect(this, SIGNAL(constructing()),
                    pModule, SLOT(doConstruct())));
    WARNNOT(connect(this, SIGNAL(executing()),
                    pModule, SLOT(doExecute())));
    WARNNOT(connect(this, SIGNAL(testing()),
                    pModule, SLOT(doTest())));
    WARNNOT(connect(this, SIGNAL(initializing()),
                    pModule, SLOT(doInitialize())));
    WARNNOT(connect(this, SIGNAL(testing()),
                    pModule, SLOT(doTest())));
    WARNNOT(connect(this, SIGNAL(configuring()),
                    pModule, SLOT(doConfigure())));
    WARNNOT(connect(this, SIGNAL(starting()),
                    pModule, SLOT(doStart())));
    WARNNOT(connect(this, SIGNAL(stoping()),
                    pModule, SLOT(doStop())));
    WARNNOT(connect(this, SIGNAL(quiting()),
                    pModule, SLOT(doQuit())));

}

/* ======================================= SLOTs ========== */

void ModuleManager::onConstruct(void)
{
//    foreach (ModuleInfo * p, mNamePtrMap.values())
  //      QTimer::singleShot(10, p, SLOT(doConstruct()));
    emit constructing();
}

void ModuleManager::onExecute(void)
{
//    foreach (ModuleInfo * p, mNamePtrMap.values())
  //      QTimer::singleShot(10, p, SLOT(doExecute()));
    emit executing();
}

void ModuleManager::onTest(void)
{
//    foreach (ModuleInfo * p, mNamePtrMap.values())
  //      QTimer::singleShot(10, p, SLOT(doTest()));
    emit testing();
}

void ModuleManager::onInitialize(void)
{
//    foreach (ModuleInfo * p, mNamePtrMap.values())
  //      QTimer::singleShot(10, p, SLOT(doInitialize()));
    emit initializing();
}

void ModuleManager::onConfigure(void)
{
//    foreach (ModuleInfo * p, mNamePtrMap.values())
  //      QTimer::singleShot(10, p, SLOT(doConfigure()));
    emit configuring();
}

void ModuleManager::onStart(void)
{
//    foreach (ModuleInfo * p, mNamePtrMap.values())
  //      QTimer::singleShot(10, p, SLOT(doStart()));
    emit starting();
}

void ModuleManager::onStop(void)
{
//    foreach (ModuleInfo * p, mNamePtrMap.values())
  //      QTimer::singleShot(10, p, SLOT(doStop()));
    emit stoping();
}

void ModuleManager::onQuit(void)
{
//    foreach (ModuleInfo * p, mNamePtrMap.values())
  //      QTimer::singleShot(10, p, SLOT(doQuit()));
    emit quiting();
}

