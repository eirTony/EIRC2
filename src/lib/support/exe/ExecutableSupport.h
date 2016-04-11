#ifndef EXECUTABLESUPPORT_H
#define EXECUTABLESUPPORT_H
#include "ExeLib.h"

#include <QObject>
#include <base/ModuleInfo.h>
#include "ExecutableInterface.h"

#include <QFileInfo>
#include <QStringList>
class QApplication;
class QGuiApplication;
class QCoreApplication;

#include <cfg/Configuration.h>
#include <res/Result.h>
#include <state/EclipseStateMachine.h>

class EXESHARED_EXPORT ExecutableSupport
        : public ModuleInfo, protected ExecutableInterface
{
    Q_OBJECT

public:
    enum ApplicationClass
    {
        nullApplicationClass = 0,
        Headless,
        Serial,
        Gui,
        Widget,
        sizeApplicationClass
    };

public:
    QCoreApplication * app(void) const;
    const QFileInfo & exeFileInfo(void) const;
    QString appName(void) const;

public slots:

protected slots:
    void machineCommand(EclipseStateMachine::Command cmd);

protected:
    explicit ExecutableSupport(const ApplicationClass appClass,
                                 const BasicId::VariantMap &
                                    initialization,
                                 ExecutableSupport * parent=0);
    void setMother(const ExecutableSupport * pMother);
    virtual bool event(QEvent * event);
    void initialize(void);

    EclipseStateMachine * mpMachine = 0;

private:
    void setupConnections(void);
    ExecutableSupport * mother(void);

signals:
    void constructing(void);
    void executing(void);
    void initializing(void);
    void configuring(void);
    void testing(void);
    void starting(void);
    void stoping(void);
    void quiting(void);


private:
    ApplicationClass mApplicationClass = nullApplicationClass;
    QApplication * mpApplication = 0;
    QGuiApplication * mpGuiApplication = 0;
    QCoreApplication * mpCoreApplication = 0;
    QStringList mRawApplicationArguments;
    QFileInfo mExeFileInfo;
    const ExecutableSupport * mpMotherExeObject = 0;
};

#endif // EXECUTABLESUPPORT_H
