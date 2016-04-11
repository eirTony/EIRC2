#ifndef QQSTATEMACHINE_H
#define QQSTATEMACHINE_H
#include "TypeLib.h"

#include <QStateMachine>

class TYPESHARED_EXPORT QQStateMachine : public QStateMachine
{
    Q_OBJECT
public:
    explicit QQStateMachine(QObject *parent = 0);

signals:

public slots:

};

#endif // QQSTATEMACHINE_H
