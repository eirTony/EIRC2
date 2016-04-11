#include "SerialExecutable.h"

#include "BaseSerialStream.h"

SerialExecutable::SerialExecutable(BaseSerialStream *
                                        serialStream,
                                   const BasicId::VariantMap
                                        initialization)
    : ExecutableSupport(ExecutableSupport::Serial,
                        initialization,
                        this)
    , mpSerialStream(serialStream)
{
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
    return mpSerialStream ? mpSerialStream->writeLine(line) : false;
}

bool SerialExecutable::writeError(const QString & error)
{
    return mpSerialStream ? mpSerialStream->writeError(error) : false;
}
