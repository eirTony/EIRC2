#ifndef ECLIPSESTATEMACHINE_H
#define ECLIPSESTATEMACHINE_H
#include "StateLib.h"

#include "AbstraceStateMachine.h"

#include <base/BasicId.h>
#include <base/BasicName.h>

//#include "MachineBuilder.h"
#include "StateMachineConfiguration.h"

#define ECLIPSE_MACHINESTATES(NPF) /* name, parent, flags */ \
    NPF(Extant,         this,       Initial) \
    NPF(Active,         this,       Parent) \
    NPF(Initialized,    Active,     Initial) \
    NPF(Ready,          Active,     0) \
    NPF(Running,        Active,     0) \
    NPF(Working,        Active,     0) \
    NPF(Inactive,       Active,     Final) \
    NPF(Final,          this,       Final) \

class STATESHARED_EXPORT EclipseStateMachine : public AbstractStateMachine
{
    Q_OBJECT

//    STATEMACHINE_DECLARESTATES(ECLIPSE_MACHINESTATES)
  //  STATEMACHINE_DECLAREKEYS(ECLIPSE_MACHINESTATES)

public:
    explicit EclipseStateMachine(QObject * parent=0);
    virtual bool initialize(const BasicName::VariantMap init
                                =BasicName::VariantMap());
    virtual bool configure(const StateMachineConfiguration & config
                                =StateMachineConfiguration());
    void setExitCode(const int code);

signals:
    void active(void);
    void terminating(void);
    void terminated(void);

public slots:
    void start(void);
    void terminate(void);
    void terminate(const int exitCode);

private slots:
    void enterFinal(void);

private:
    int mExitCode = 0;
};

#endif // ECLIPSESTATEMACHINE_H
