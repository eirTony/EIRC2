#ifndef BASESTATEBEHAVIOR_H
#define BASESTATEBEHAVIOR_H

#include <QObject>
#include <QString>
#include "StateLib.h"

#include <base/BasicId.h>
#include <base/MetaName.h>
class Result;

class BaseMachine;
class BaseState;

class StateInterface : public QObject
{
    Q_OBJECT

public: // static
    static StateInterface * fromName(MetaName metaName,
                                        BaseMachine * machine,
                                        BaseState * state);

private:
    explicit StateInterface(QObject * parent=0);
    StateInterface(BaseMachine * machine,
                      BaseState * state);

signals:

public slots:
    virtual void doCreate(void)     {;}
    virtual void doEnter(void)      {;}
    virtual void doState(void)      {;}
    virtual void doExit(void)       {;}
    virtual void doTerminate(void)  {;}
    virtual void doDestroy(void)    {;}
    virtual void doError(void)      {;}
    virtual void doMessage(void)    {;}
    virtual void doError(const Result & result)     {(void)result;}
    virtual void doMessage(const QString & message) {(void)message;}
    virtual BasicId id(void) const = 0;

private:
    BaseMachine * mpMachine = 0;
    BaseState * mpState = 0;
};

#endif // BASESTATEBEHAVIOR_H
