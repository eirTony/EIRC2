#include "SerialExecutable.h"

#include <base/Diagnostic.h>

#include "BaseSerialStream.h"

SerialExecutable::SerialExecutable(BaseSerialStream *
                                        serialStream,
                                   ExecutableInitialization
                                        & initialization)
    : ExecutableSupport(ExecutableSupport::Serial,
                        initialization,
                        this)
    , mpSerialStream(serialStream)
{
    setObjectName("SerialExecutable");
}

void SerialExecutable::setStream(BaseSerialStream * textStream)
{
    mpSerialStream = textStream;
}

BaseSerialStream *SerialExecutable::stream(void)
{
    return mpSerialStream;
}

QString SerialExecutable::readLine(void)
{
    return mpSerialStream ? mpSerialStream->readLine() : QString();
}

bool SerialExecutable::writeLine(const QString & line)
{
    TRACE("SerialExecutable::writeLine(%1)", line);
    return mpSerialStream ? mpSerialStream->writeLine(line) : false;
}

bool SerialExecutable::writeError(const QString & error)
{
    return mpSerialStream ? mpSerialStream->writeError(error) : false;
}
