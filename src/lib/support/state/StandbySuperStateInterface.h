#ifndef ECLIPSESTATEBEHAVIOR_H
#define ECLIPSESTATEBEHAVIOR_H

#include <QObject>
#include "StateInterface.h"

class StandbySuperStateInterface : public StateInterface
{
    Q_OBJECT
public:

protected:
  explicit StandbySuperStateInterface(StateInterface * parent=0);

signals:

public slots:

};

#endif // ECLIPSESTATEBEHAVIOR_H
