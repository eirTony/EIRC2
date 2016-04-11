#ifndef MACHINEFINALINTERFACE_H
#define MACHINEFINALINTERFACE_H
#include "StateLib.h"

#include <QObject>

#include "StateInterface.h"

class STATESHARED_EXPORT MachineFinalInterface : public StateInterface
{
    Q_OBJECT
public:
    Q_INVOKABLE MachineFinalInterface(void);

public slots:
    virtual MetaName metaName(void) const;
};

#endif // MACHINEFINALINTERFACE_H
