#ifndef ECLIPSESTATEBEHAVIOR_H
#define ECLIPSESTATEBEHAVIOR_H

#include <QObject>
#include "BaseStateBehavior.h"

class EclipseStateBehavior : public StateInterface
{
    Q_OBJECT
public:

protected:
  explicit EclipseStateBehavior(StateInterface * parent=0);

signals:

public slots:

};

#endif // ECLIPSESTATEBEHAVIOR_H
