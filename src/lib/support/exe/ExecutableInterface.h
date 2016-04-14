#ifndef EXECUTABLEINTERFACE_H
#define EXECUTABLEINTERFACE_H
#include "ExeLib.h"

#include <base/BasicId.h>

class EXESHARED_EXPORT ExecutableInterface
{
public:
    ExecutableInterface(const BasicId::VariantMap  & initialization
                                =BasicId::VariantMap());

protected: // virtual
    virtual void doConstruct(void);
    virtual void doInitialize(void);
    virtual void doSetup(const BasicId::VariantMap & settings
                                =BasicId::VariantMap());
    virtual void doStart(void);
    virtual void doQuit(void);
    virtual void doDestruct(void);

protected slots:
    void initialize(void);
    void gyse(void);
    void quit(void);

protected:
    BasicId::VariantMap  initialization(void) const;
    BasicId::VariantMap  settings(void) const;

private:
    BasicId::VariantMap  mInitialization;
    BasicId::VariantMap  mSettings;  // later SettingsStack;
};

#endif // EXECUTABLEINTERFACE_H
