#ifndef EXECUTABLESUPPORT_H
#define EXECUTABLESUPPORT_H
#include "ExeLib.h"

#include <QObject>
#include <base/ModuleInfo.h>

#include <QFileInfo>
#include <QStringList>

#include <cfg/Configuration.h>

#include <QFileInfo>
#include <QStringList>
class QApplication;
class QGuiApplication;
class QCoreApplication;


class EXESHARED_EXPORT ExecutableSupport
        : public ModuleInfo
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
    BasicName::VariantMap initialization(void) const;
    Configuration configuration(void) const;

protected:
    explicit ExecutableSupport(const ApplicationClass appClass,
                               QObject * parent=0);
    virtual bool event(QEvent * event);

signals:
    void constructing(void);
    void executing(void);
    void initializing(void);
    void configuring(void);
    void testing(void);
    void starting(void);
    void stoping(void);
    void quiting(void);

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
    QStringList mRawApplicationArguments;
    QFileInfo mExeFileInfo;
    Configuration mConfiguration;
    BasicName::VariantMap mInitialization;
};

#endif // EXECUTABLESUPPORT_H
