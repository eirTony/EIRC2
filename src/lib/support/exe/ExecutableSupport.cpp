#include "ExecutableSupport.h"

#include <QCoreApplication>
#include <QString>

#include <base/_internal/ModuleManager.h>
#include <base/TestObject.h>
#include <state/EclipseStateMachine.h>

// protected
ExecutableSupport::ExecutableSupport(const ApplicationClass appClass,
                                     const BasicId::VariantMap & initialization,
                                     ExecutableSupport * parent)
    : ModuleInfo(parent)
    , ExecutableInterface(initialization)
    , mApplicationClass(appClass)
//    , mpMachine(new EclipseStateMachine(this))
{
    setMother(parent);
    mpMachine = new EclipseStateMachine(this);

    switch (mApplicationClass)
    {
    case Widget:    mpApplication = (QApplication *)qApp;
                    // fall thru
    case Gui:       mpGuiApplication = (QGuiApplication *)qApp;
                    // fall thru
    case Serial:
    case Headless:  mpCoreApplication = qApp;
        mRawApplicationArguments = mpCoreApplication->arguments();
        mExeFileInfo.setFile(mRawApplicationArguments.first());
        if ( ! QObject::parent())
            QObject::setParent(mpCoreApplication);
        break;

    case nullApplicationClass:  /* nada */  break;
    case sizeApplicationClass:  /* nada */  break;
    }

//    mpMotherExeObject->doConstruct();
    TRACE("emit constructing()","");
    emit constructing();



}

// protected
void ExecutableSupport::setMother(const ExecutableSupport * pMother)
{
    const ExecutableSupport * pXSup
            = qobject_cast<const ExecutableSupport *>(pMother);
    if (pXSup) mpMotherExeObject = pXSup;
}


// private
void ExecutableSupport::setupConnections(void)
{
    TODO("CONNECT & EMIT diagnostic macros");
    TODO("move ModuleManager out of _internal");
    connect(this, SIGNAL(quiting()),
            mpCoreApplication, SLOT(quit()));
#if 0
    WARNNOT(connect(this, SIGNAL(constructing()),
                    this, SLOT(initialize())));
    WARNNOT(connect((this, SIGNAL(initializing()),
                     this, SLOT(setup()))));

    WARNNOT(connect(this, SIGNAL(constructing()),
                    ModuleManager::pointer(), SLOT(onConstruct())));
    WARNNOT(connect(this, SIGNAL(executing()),
                    ModuleManager::pointer(), SLOT(onExecute())));
    WARNNOT(connect(this, SIGNAL(testing()),
                    ModuleManager::pointer(), SLOT(onTest())));
    WARNNOT(connect(this, SIGNAL(initializing()),
                    ModuleManager::pointer(), SLOT(onInitialize())));
    WARNNOT(connect(this, SIGNAL(configuring()),
                    ModuleManager::pointer(), SLOT(onConfigure())));
    WARNNOT(connect(this, SIGNAL(starting()),
                    ModuleManager::pointer(), SLOT(onStart())));
    WARNNOT(connect(this, SIGNAL(stoping()),
                    ModuleManager::pointer(), SLOT(onStop())));
    WARNNOT(connect(this, SIGNAL(quiting()),
                    ModuleManager::pointer(), SLOT(onQuit())));
#endif
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

void ExecutableSupport::machineCommand(const BaseMachine::Command cmd)
{
    mpMachine->command(cmd);
}

/*
void ExecutableSupport::initialize(void)
{
    WARNNOT(connect(this, SIGNAL(initializing()),
                    this, SLOT(gyse())));

    setupConnections();

    // Process Command Line
    mRawApplicationArguments = mpCoreApplication->arguments();
    QString exeArg = mRawApplicationArguments.takeFirst();
    mExeFileInfo.setFile(exeArg);

    TRACE("emit initializing()", "");
    TODO("Why TRACE macro ...args not working?");
    mpMotherExeObject->doInitialize();
    emit initializing();
}

void ExecutableSupport::gsye(void)
{
    //mpMachine->start();
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
*/
