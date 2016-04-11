#ifndef UNITTESTRUNNER_H
#define UNITTESTRUNNER_H
#include "ExeLib.h"

#include "ConsoleApplication.h"

#include <bjut/BasicUnitTest.h>

class EXESHARED_EXPORT UnitTestRunner : public ConsoleApplication
{
    Q_OBJECT
public:
    explicit UnitTestRunner(void);

signals:

public slots:

private:
    UnitTestLevel mTestLevel = UnitTestLevel::nullTestLevel;

};

#endif // UNITTESTRUNNER_H
