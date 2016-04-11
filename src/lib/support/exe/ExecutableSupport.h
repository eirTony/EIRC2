#ifndef EXECUTABLESUPPORT_H
#define EXECUTABLESUPPORT_H
#include "ExeLib.h"

#include <QObject>
#include <base/ModuleInfo.h>
#include <type/QQFileInfo.h>
#include <type/QQStringList.h>
#include <cfg/Configuration.h>

#include <QFileInfo>
#include <QStringList>
class QApplication;
class QGuiApplication;
class QCoreApplication;


class EXESHARED_EXPORT ExecutableSupport
        : public QObject, public ModuleInfo
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

protected:
    explicit ExecutableSupport(const ApplicationClass appClass,
                               QObject * parent=0);


signals:
    void quitApp(void);

protected slots:
    void initialize(void);
    void setup(void);
    void start(void);
    void quit(void);

private:
    ApplicationClass mApplicationClass = nullApplicationClass;
    QApplication * mpApplication = 0;
    QGuiApplication * mpGuiApplication = 0;
    QCoreApplication * mpCoreApplication = 0;
    QQStringList mRawApplicationArguments;
    QQFileInfo mExeFileInfo;
    Configuration mConfiguration;
    BasicName::VariantMap mInitialization;
};

#endif // EXECUTABLESUPPORT_H
