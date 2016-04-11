#ifndef HELLOCLOUDMACHINE_H
#define HELLOCLOUDMACHINE_H

#include <QObject>
#include <exe/ConsoleApplication.h>
#include <exe/ExecutableInitialization.h>
#include <type/Unsigned.h>
#include <state/EclipseStateMachine.h>

class QHttpServer;
class QHttpRequest;
class QHttpResponse;

class HelloCloudMachine : public ConsoleApplication
{
    Q_OBJECT
public:
    explicit HelloCloudMachine(const ExecutableInitialization &
                    initialization=ExecutableInitialization());

    EclipseStateMachine * machine(void);

signals:

public slots:

private slots:
    void handleRequest(QHttpRequest  * request,
                       QHttpResponse * response);

private slots: // virutal (overrides of protected above)
    virtual void doInitialize(void);

private:    // statics
    const static Unsigned16 csmDefaultHttpPort;

private:
    EclipseStateMachine * mpMachine = 0;
    Unsigned16 mHttpPort = csmDefaultHttpPort;
    QHttpServer * mpHttpServer = 0;
};

#endif // HELLOCLOUDMACHINE_H
