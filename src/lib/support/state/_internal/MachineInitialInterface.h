#ifndef MACHINEINITIALINTERFACE_H
#define MACHINEINITIALINTERFACE_H
#include "StateLib.h"

#include <QObject>

#include "StateInterface.h"

class STATESHARED_EXPORT MachineInitialInterface : public StateInterface
{
    Q_OBJECT
public:
    Q_INVOKABLE MachineInitialInterface(void);

public slots:
    virtual MetaName metaName(void) const;
};

#endif // MACHINEINITIALINTERFACE_H
