#include "HelloCloudConsole.h"

#include <QTimer>

#include <base/Diagnostic.h>
#include <work/EclipseWorkMessageMachine.h>

HelloCloudConsole::HelloCloudConsole(void)
//    : cmpMachine(new EclipseWorkMessageMachine(this))
{
    setVersion();
    NEEDDO("Why VersionInfo.isNull()?");
    INFO("HelloCloudConsole %1 started",
         ModuleInfo::version().toString(true));
    QObject::setObjectName("HelloCloudConsole");
    WARNNOT(connect(app(), &QCoreApplication::aboutToQuit,
                    this, &HelloCloudConsole::quitting));
}

void HelloCloudConsole::doInitialize(void)
{
    bool initialized = false; // mpMachine->initialize(ExecutableSupport::initialization());
    TRACEMSGIF(initialized, "HelloCloudConsole's machine is initialized");
    CRITMSGNOT(initialized, "HelloCloudConsle failed initialization");
}

void HelloCloudConsole::doSetup(void)
{
//    ERRORNOT(mpMachine->configure(ExecutableSupport::configuration()),
  //           "HelloCloudConsole failed to configure");
}

void HelloCloudConsole::doStart(void)
{
    SerialExecutable::writeLine("HelloCloudConsole ready");
#if 0
    TODO("Why not in private slot quitting()");
    WARNNOT(DiagnosticItem::todoReport("./log/"
                               + ExecutableSupport::appName()
                               + ".todo"));
#endif
    QTimer::singleShot(5000, this, SLOT(quit()));
}

// private slot
void HelloCloudConsole::quitting(void)
{
    TRACE("HelloCloudConsole::quitting(void)", 0)
    WARNNOT(DiagnosticItem::todoReport("./log/"
                               + ExecutableSupport::appName()
                               + ".todo"));
}
