#ifndef ECLIPSEWORKMESSAGEMACHINE_H
#define ECLIPSEWORKMESSAGEMACHINE_H
#include "WorkLib.h"
#if 1
#include <QObject>

#include <base/BasicId.h>
#include <base/BasicName.h>
#include <cfg/Configuration.h>

class EclipseStateMachine;
class EclipseMessageQueue;

class WORKSHARED_EXPORT EclipseWorkMessageMachine : public QObject
{
    Q_OBJECT
public:
    explicit EclipseWorkMessageMachine(QObject * parent=0);
    bool initialize(const BasicName::VariantMap & init
                            =BasicName::VariantMap());
    bool configure(const Configuration & config
                            =Configuration());
    const EclipseStateMachine * machine(void) const;
    const EclipseMessageQueue * queue(void) const;

signals:

public slots:
    void start(void);

private:
    const EclipseStateMachine * cmpMachine = 0;
    const EclipseMessageQueue * cmpQueue = 0;
};
#endif
#endif // ECLIPSEWORKMESSAGEMACHINE_H
