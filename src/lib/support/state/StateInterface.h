#ifndef BASESTATEBEHAVIOR_H
#define BASESTATEBEHAVIOR_H
#include "StateLib.h"

#include <QObject>
#include <QMap>
#include <QPointer>
#include <QString>

#include <base/BasicId.h>
#include <base/MetaName.h>
class Result;

class BaseMachine;
class BaseState;

class STATESHARED_EXPORT StateInterface : public QObject
{
    Q_OBJECT
public: // static
    static StateInterface * fromName(MetaName metaName,
                                     BaseMachine * machine,
                                     BaseState * state);
    BasicId id(void) const;

public:

protected:
    StateInterface(void);

protected:

private:
//    StateInterface(BaseMachine * machine,
  //                 BaseState * state);
    void setMachine(BaseMachine *machine);
    void setState(BaseState *state);
    void muster(void);

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
    virtual MetaName metaName(void) const = 0;

private:
    BaseMachine * mpMachine = 0;
    BaseState * mpState = 0;

private: // static
    static QMap<MetaName, const QMetaObject *> smNameMetaObjectMap;
};

#endif // BASESTATEBEHAVIOR_H
