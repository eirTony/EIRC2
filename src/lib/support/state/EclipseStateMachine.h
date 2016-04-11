#ifndef ECLIPSESTATEMACHINE_H
#define ECLIPSESTATEMACHINE_H
#include "StateLib.h"

#include <QObject>
#include "BaseMachine.h"

class STATESHARED_EXPORT EclipseStateMachine : public BaseMachine
{
    Q_OBJECT
public:
    explicit EclipseStateMachine(QObject * parent=0);

signals:

public slots:
    void initializeMachine(void);

};

#endif // ECLIPSESTATEMACHINE_H
