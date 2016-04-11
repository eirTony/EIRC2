/*! @file ModuleInfo.cpp Definitions for ModuleInfo class
 *
 */
#include "ModuleInfo.h"

#include <QtDebug>

#include <QStringList>
#include <QTimer>

#include "Diagnostic.h"
#include "_internal/ModuleManager.h"

/*! @class ModuleInfo
 *
 * @brief ModuleInfo class stores information about each library.
 *
 * The ModuleInfo also stores pointers to each of its instances
 * that are available within the other libraries or applicaitons.
 */

ModuleInfo::ModuleInfo(void) {;}

/*! @fn ModuleInfo::ModuleInfo(const QString & name)
 *
 * @brief Collects module info and keeps a pointer to each instance.
 * @param name QString containing the name of the library.
 *
 * Typically the name of library is a defined macro in the myclass_global.h
 * file supplied by QtCreator when a new library skeleton is created.
 */
ModuleInfo::ModuleInfo(const QString & name)
    : mName(name)
    , mpManager(ModuleManager::pointer())
{
    Q_ASSERT(mpManager);
    mpManager->muster(this);
}

ModuleInfo::ModuleInfo(QObject * parent)
    : QObject(parent) {;}


bool ModuleInfo::isNull(void) const
{
    return mName.isEmpty();
}

/*! @fn void ModuleInfo::setVersion(void)
 *
 * @brief Sets the VersionInfo class data.
 *
 * Typically the Version.h and CommonVersion.h are included in the
 * base class .cpp file that defines the values expected by
 * the VersionInfo::setAll() function.
 *
 * @warning The local Version.h must be included before the
 *      common CommonVersion.h file.
 */
void ModuleInfo::setVersion(void)
{
    mVI.setAll();
}

/*! @fn QString ModuleInfo::name(void) const
 * @brief ModuleInfo::name returns the name of this library.
 * @return QString name
 *
 *
 */
QString ModuleInfo::name(void) const
{
    return mName;
}

/*!
 * \fn VersionInfo ModuleInfo::version(void) const
 * \brief ModuleInfo::version returns the version information data.
 * \return VersionInfo structure for this library
 */
VersionInfo ModuleInfo::version(void) const
{
    return mVI;
}

void ModuleInfo::doConstruct(void) {TRACE("in ModuleInfo::%1() for %2", "doConstruct", mName);}
void ModuleInfo::doExecute(void) {TRACE("in ModuleInfo::%1 for %2", "doExecute", mName);}
void ModuleInfo::doTest(void) {TRACE("in ModuleInfo::%1 for %2", "doTest", mName);}
void ModuleInfo::doInitialize(void) {TRACE("in ModuleInfo::%1 for %2", "doInitialize", mName);}
void ModuleInfo::doConfigure(void) {TRACE("in ModuleInfo::%1 for %2", "doConfigure", mName);}
void ModuleInfo::doStart(void) {TRACE("in ModuleInfo::%1 for %2", "doStart", mName);}
void ModuleInfo::doStop(void) {TRACE("in ModuleInfo::%1 for %2", "doStop", mName);}
void ModuleInfo::doQuit(void) {TRACE("in ModuleInfo::%1 for %2", "doQuit", mName);}
