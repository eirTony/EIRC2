#include "HelloCloudMachine.h"
#include "Version.h"
#include <CommonVersion.h>

#include <QTimer>

#include <base/BaseLib.h>
//#include <base/BasicKeyManager.h>
#include <base/Diagnostic.h>
#include <exe/ExecutableInitialization.h>
#include <qhttpserver/qhttpserver.h>

const Unsigned16 HelloCloudMachine::csmDefaultHttpPort = 27850;


HelloCloudMachine::HelloCloudMachine(const
                                     ExecutableInitialization &
                                            initialization)
    : ConsoleApplication(initialization)
{
    ModuleInfo::setVersion();
    INFO("HelloCloudMachine %1 constructed",
         ModuleInfo::version().toString(true));

    //-----Machine
    WARNNOT(connect(machine(), SIGNAL(initializedMachine()),
                    machine(), SLOT(start())));

    //-----Http
    mpHttpServer = new QHttpServer(this);
    TRACE("QHttpServer constructed", "");
    TODO("Why TRACE macro ...args not working?");

    mHttpPort = Unsigned16(initialization.value("PORT",
                        QVariant(csmDefaultHttpPort)).toUInt());

}

// private virtual
EclipseStateMachine * HelloCloudMachine::machine(void)
{
    return mpMachine;
}

void HelloCloudMachine::doInitialize(void)
{
    ExecutableInterface::doInitialize();

    CRITMSGNOT(mpHttpServer->listen(mHttpPort),
               "HelloCloudMachine failed to start HTTP server");
    CRITNOT(connect(mpHttpServer,
                    SIGNAL(newRequest(QHttpRequest *)),
                    this,
                    SLOT(handleRequest(QHttpRequest *))));
    INFO("HelloCloudMachine listening on port %1", mHttpPort());
}

void HelloCloudMachine::handleRequest(QHttpRequest  * request,
                   QHttpResponse * response)
{
    USE(request); USE(response);
    MUSTDO("Handle HTTP Request");
}
