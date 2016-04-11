#include "ExecutableSupport.h"

#include <QCoreApplication>

#include <type/QQString.h>

ExecutableSupport::ExecutableSupport(const ApplicationClass appClass,
                                     QObject * parent)
    : QObject(parent)
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


    // Process Command Line
    mRawApplicationArguments = mpCoreApplication->arguments();
    QQString exeArg = mRawApplicationArguments.takeFirst();
    mExeFileInfo.setFile(exeArg);
}

const QFileInfo & ExecutableSupport::exeFileInfo(void) const
{
    return mExeFileInfo;
}


void ExecutableSupport::initialize(void)
{
    connect(this, SIGNAL(quitApp()),
            mpCoreApplication, SLOT(quit()));
}

void ExecutableSupport::setup(void)
{
    // do stuff
}

void ExecutableSupport::start(void)
{
    // do stuff
}

void ExecutableSupport::quit(void)
{
    emit quitApp();
}
