#ifndef HELLOCLOUDCONSOLE_H
#define HELLOCLOUDCONSOLE_H

#include <QObject>
#include <exe/ConsoleApplication.h>

class EclipseWorkMessageMachine;

class HelloCloudConsole : public ConsoleApplication
{
public:
    HelloCloudConsole(void);

signals:

public slots:
    virtual void doInitialize(void);
    virtual void doSetup(void);
    virtual void doStart(void);

private slots:
    void quitting(void);

private:
    EclipseWorkMessageMachine * cmpMachine = 0;

};

#endif // HELLOCLOUDCONSOLE_H
