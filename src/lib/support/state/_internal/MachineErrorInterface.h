#ifndef MACHINEERRORINTERFACE_H
#define MACHINEERRORINTERFACE_H
#include "StateLib.h"

#include <QObject>

#include "StateInterface.h"

class STATESHARED_EXPORT MachineErrorInterface : public StateInterface
{
    Q_OBJECT
public:
    Q_INVOKABLE MachineErrorInterface(void);

public slots:
    virtual MetaName metaName(void) const;
};

#endif // MACHINEERRORINTERFACE_H
