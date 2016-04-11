#ifndef BASETRANSITION_H
#define BASETRANSITION_H

#include <QAbstractTransition>

class BaseTransition : public QAbstractTransition
{
    Q_OBJECT
public:
    explicit BaseTransition(QState * sourceState);

signals:

public slots:

protected:
    virtual bool eventTest(QEvent *event);
    virtual void onTransition(QEvent *event);


};

#endif // BASETRANSITION_H
