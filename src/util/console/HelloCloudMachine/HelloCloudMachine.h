#ifndef HELLOCLOUDMACHINE_H
#define HELLOCLOUDMACHINE_H

#include <QObject>
#include <exe/ConsoleApplication.h>

#include <type/Unsigned.h>
#include <state/EclipseStateMachine.h>

class QHttpServer;
class QHttpRequest;
class QHttpResponse;

class HelloCloudMachine : public ConsoleApplication
{
    Q_OBJECT
public:
    explicit HelloCloudMachine(void);

signals:

public slots:

protected slots:
    virtual void doInitialize(void);
    virtual void doSetup(void);
    virtual void doStart(void);

private slots:
    void handleRequest(QHttpRequest  * request,
                       QHttpResponse * response);

private:    // statics
    const static Unsigned16 csmDefaultHttpPort;

private:
    EclipseStateMachine * mpMachine = 0;
    Unsigned16 mHttpPort = csmDefaultHttpPort;
    QHttpServer * mpHttpServer = 0;
};

#endif // HELLOCLOUDMACHINE_H
