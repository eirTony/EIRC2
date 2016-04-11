#ifndef CONSOLEEXECUTABLE_H
#define CONSOLEEXECUTABLE_H
#include "ExeLib.h"

#include "SerialExecutable.h"

#include <base/BasicName.h>
#include <base/BasicId.h>

#include "ExecutableInitialization.h"

class StandardStream;

class EXESHARED_EXPORT ConsoleApplication
        : public SerialExecutable
{
    Q_OBJECT
public:
    explicit ConsoleApplication(const ExecutableInitialization &
                                            initialization
                                            =ExecutableInitialization());
    ~ConsoleApplication();

signals:
    void initialized(void);
    void setuped(void);
    void started(void);

private:
    StandardStream * mpStream = 0;
};

#endif // CONSOLEEXECUTABLE_H
