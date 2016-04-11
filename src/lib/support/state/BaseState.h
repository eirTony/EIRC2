#ifndef BASESTATE_H
#define BASESTATE_H

#include <QState>

#include <QString>

#include <base/BasicId.h>
#include <base/BasicKey.h>

//#include <var/VariablePack.h>
#include <res/Result.h>

class BaseMachine;
class StateInterface;

class BaseState : public QState
{
    Q_OBJECT
public:
    BaseState(const BasicId id,
              StateInterface * interface,
              BaseMachine * machine,
              QState * parent=0);
    ~BaseState();
    BasicKey key(void) const;
    BasicId id(void) const;

signals:
    void creating(BaseState * p, BasicKey key);
    void entering(BaseState * p, BasicKey key);
    void doing(BaseState * p, BasicKey key);
    void done(BaseState * p, BasicKey key);
    void leaving(BaseState * p, BasicKey key);
    void terminating(BaseState * p, BasicKey key);
    void destroying(BaseState * p, BasicKey key);
    void error(BaseState * p, BasicKey key, Result result);
    void message(BaseState * p, BasicKey key, QString message);

public slots:
    void onCreate(void);
    void onEnter(void);
    void onWork(void);
    void onLeave(void);
    void onTerminate(void);
    void onDestroy(void);
    void handleError(const Result result);
    void handleMessage(const QString & string);

protected:

private:
    void setupConnections(void);

private:
    BasicKey mKey;
    BasicId mId;
    StateInterface * mpInterface;
    BaseMachine * mpMachine;
    BaseState * mpParent;
};

#endif // BASESTATE_H
