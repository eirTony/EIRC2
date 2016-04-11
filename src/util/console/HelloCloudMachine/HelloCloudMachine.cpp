#include "HelloCloudMachine.h"
#include "Version.h"
#include <CommonVersion.h>

#include <QTimer>

#include <base/BaseLib.h>
#include <base/Diagnostic.h>
#include <qhttpserver/qhttpserver.h>

const Unsigned16 HelloCloudMachine::csmDefaultHttpPort = 27850;

HelloCloudMachine::HelloCloudMachine(void)
{
    ModuleInfo::setVersion();
    INFO("HelloCloudMachine %1 constructed",
         ModuleInfo::version().toString(true));

    //-----Machine
    mpMachine = new EclipseStateMachine(this);

    //-----Http
    mpHttpServer = new QHttpServer(this);
    TRACE("QHttpServer constructed", "");
    TODO("Why TRACE macro ...args not working?");

    mHttpPort = BaseLib::reference()
            .systemEnvironmentValue("PORT",
                                    QVariant(mHttpPort)).toUInt();
    CRITMSGNOT(mpHttpServer->listen(mHttpPort),
               "HelloCloudMachine failed to start HTTP server");
    CRITNOT(connect(mpHttpServer, SIGNAL(newRequest(QHttpRequest*,
                                                    QHttpResponse*)),
                    this, SLOT(handleRequest(QHttpRequest*,
                                             QHttpResponse*))));
    //INFO("HelloCloudMachine listening on port %1", mHttpPort);
}

void HelloCloudMachine::doInitialize(void)
{
    TODO("HelloCloudMachine::doInitialize(void)")
}

void HelloCloudMachine::doSetup(void)
{
    TODO("HelloCloudMachine::doSetup(void)")
}

void HelloCloudMachine::doStart(void)
{
    TODO("HelloCloudMachine::doStart(void)")

    QTimer::singleShot(5000, this, SLOT(quit()));
}

void HelloCloudMachine::handleRequest(QHttpRequest  * request,
                   QHttpResponse * response)
{
    USE(request); USE(response);
    MUSTDO("Handle HTTP Request");
}
