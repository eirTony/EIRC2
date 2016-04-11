#ifndef CLASSUNITTEST_H
#define CLASSUNITTEST_H

#include "UnitTestMetaObject.h"

class ClassUnitTest : public UnitTestMetaObject
{
    Q_OBJECT
public:
    explicit ClassUnitTest(QObject * parent=0);

signals:

public slots:

};

#endif // CLASSUNITTEST_H
