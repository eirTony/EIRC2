#ifndef MODULEMANAGER_H
#define MODULEMANAGER_H
#include "../BaseLib.h"

#include <QObject>

#include <QList>
#include <QTimer>

#include <core/Singleton.h>

#include "../ModuleInfo.h"

class BASESHARED_EXPORT ModuleManager : public QObject
{
    Q_OBJECT
public:
    typedef QList<ModuleInfo *> ModuleInfoList;

    DECLARE_SINGLETON(ModuleManager) // ctor & more
public:
    QStringList moduleNames(void);
    ModuleInfo * module(const QString & name);
    void dumpVersions(void);
    void muster(ModuleInfo * pModule);
    ModuleInfoList modules(void) const;

public slots:
    void onConstruct(void);
    void onExecute(void);
    void onTest(void);
    void onInitialize(void);
    void onConfigure(void);
    void onStart(void);
    void onStop(void);
    void onQuit(void);

signals:
    void constructing(void);
    void executing(void);
    void testing(void);
    void initializing(void);
    void configuring(void);
    void starting(void);
    void stoping(void);
    void quiting(void);

private:
    QMap<QString, ModuleInfo *> mNamePtrMap;
};

#endif // MODULEMANAGER_H
