#ifndef ABSTRACESTATEMACHINE_H
#define ABSTRACESTATEMACHINE_H

#include <QState>

//< for now
#include <base/BasicId.h>
#include <base/BasicKey.h>
typedef BasicKey StateKey;
typedef BasicId StateId;
//<

class AbstractStateMachine : public QState
{
    Q_OBJECT
public:
    explicit AbstractStateMachine(QObject * parent=0);

signals:
    void StateChanged(const StateKey toKey, const StateKey fromKey);
    void StateChanged(const StateId & toId, const StateId & fromId);
public slots:

private:
//    KiiManager * mpKidManager = 0;
};

#endif // ABSTRACESTATEMACHINE_H
