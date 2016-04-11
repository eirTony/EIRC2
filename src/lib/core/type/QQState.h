#ifndef QQSTATE_H
#define QQSTATE_H
#include "TypeLib.h"

#include <QObject>
#include <QState>

#include <base/BasicId.h>
#include <base/BasicKey.h>

class TYPESHARED_EXPORT QQState : public QState
{
    Q_OBJECT
public:
    explicit QQState(QState * parent=0);

signals:

public slots:

private:
    BasicId mId;
    BasicKey mKey;
};

#endif // QQSTATE_H
