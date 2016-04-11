#ifndef BASEINTERFACE_H
#define BASEINTERFACE_H

#include "StateInterface.h"

class BaseInterface : public StateInterface
{
    Q_OBJECT
public:
    Q_INVOKABLE BaseInterface(void);
    virtual MetaName metaName(void) const;

signals:

public slots:

};

#endif // BASEINTERFACE_H
