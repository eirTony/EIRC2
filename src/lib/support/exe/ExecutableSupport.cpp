#include "ExecutableSupport.h"

#include <QCoreApplication>
#include <QString>

#include <base/_internal/ModuleManager.h>
#include <base/TestObject.h>

// protected
ExecutableSupport::ExecutableSupport(const ApplicationClass appClass,
                                     QObject * parent)
    : ModuleInfo(parent)
    , mApplicationClass(appClass)
{
    switch (mApplicationClass)
    {
    case Widget:    mpApplication = (QApplication *)qApp;       // fall thru
    case Gui:       mpGuiApplication = (QGuiApplication *)qApp; // fall thru
    case Serial:
    case Headless:  mpCoreApplication = qApp;
        mRawApplicationArguments = mpCoreApplication->arguments();
        mExeFileInfo.setFile(mRawApplicationArguments.first());
        if ( ! QObject::parent())
            QObject::setParent(mpCoreApplication);
        break;

    default:
        break;
    }

    setupConnections();
    TRACE("emit constructing()","");
    emit constructing();

    // Process Command Line
    mRawApplicationArguments = mpCoreApplication->arguments();
    QString exeArg = mRawApplicationArguments.takeFirst();
    mExeFileInfo.setFile(exeArg);
}

// private
void ExecutableSupport::setupConnections(void)
{
    TODO("CONNECT & EMIT diagnostic macros");
    TODO("move ModuleManager out of _internal");
    WARNNOT(connect(this, SIGNAL(constructing()),
                    ModuleManager::pointer(), SLOT(onConstruct())));
    WARNNOT(connect(this, SIGNAL(executing()),
                    ModuleManager::pointer(), SLOT(onExecute())));
    WARNNOT(connect(this, SIGNAL(testing()),
                    ModuleManager::pointer(), SLOT(onTest())));
    WARNNOT(connect(this, SIGNAL(initializing()),
                    ModuleManager::pointer(), SLOT(onInitialize())));
    WARNNOT(connect(this, SIGNAL(testing()),
                    ModuleManager::pointer(), SLOT(onTest())));
    WARNNOT(connect(this, SIGNAL(configuring()),
                    ModuleManager::pointer(), SLOT(onConfigure())));
    WARNNOT(connect(this, SIGNAL(starting()),
                    ModuleManager::pointer(), SLOT(onStart())));
    WARNNOT(connect(this, SIGNAL(stoping()),
                    ModuleManager::pointer(), SLOT(onStop())));
    WARNNOT(connect(this, SIGNAL(quiting()),
                    ModuleManager::pointer(), SLOT(onQuit())));

}

// protected
bool ExecutableSupport::event(QEvent * event)
{
    NOUSE(event);
    static bool first = true;
    if (first)
    {
        TRACE("emit executing()", "");
        emit executing();
        first = false;
    }
    return false;
}

QCoreApplication * ExecutableSupport::app(void) const
{
    return mpCoreApplication;
}

const QFileInfo & ExecutableSupport::exeFileInfo(void) const
{
    return mExeFileInfo;
}

QString ExecutableSupport::appName(void) const
{
    return app()->applicationName();
}

BasicName::VariantMap ExecutableSupport::initialization(void) const
{
    return mInitialization;
}

Configuration ExecutableSupport::configuration(void) const
{
    return mConfiguration;
}

void ExecutableSupport::initialize(void)
{
    TRACE("emit initializing()", "");
    TODO("Why TRACE macro ...args not working?");
    emit initializing();
    connect(this, SIGNAL(quiting()),
            mpCoreApplication, SLOT(quit()));
    // TestObject::execAll();
}

void ExecutableSupport::setup(void)
{
    // do stuff
}

void ExecutableSupport::start(void)
{
    TRACE("emit starting()", "");
    TODO("emit starting(void);");
    // do stuff
}

void ExecutableSupport::quit(void)
{
    TRACE("emit quitting()", "");
    TODO("Why TRACE macro ...args not working?");
    emit quiting();
}
