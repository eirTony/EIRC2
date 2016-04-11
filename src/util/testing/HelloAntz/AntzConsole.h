#ifndef ANTZCONSOLE_H
#define ANTZCONSOLE_H

#include <exe/ConsoleApplication.h>

class AntzConsole : public ConsoleApplication
{
    Q_OBJECT
public:
    AntzConsole(void);
    virtual void doInitialize(void) {}
    virtual void doSetup(void) {}
    virtual void doStart(void);
};

#endif // ANTZCONSOLE_H
