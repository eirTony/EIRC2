#ifndef SERIALEXECUTABLE_H
#define SERIALEXECUTABLE_H
#include "ExeLib.h"

#include "ExecutableSupport.h"

class BaseSerialStream;

class EXESHARED_EXPORT SerialExecutable
        : public ExecutableSupport
{
    Q_OBJECT
public:
    void setStream(BaseSerialStream * textStream);
    BaseSerialStream * stream(void);
    QString readLine(void);
    bool writeLine(const QString & line);
    bool writeError(const QString & error);

protected:
    explicit SerialExecutable(BaseSerialStream * serialStream,
                              ExecutableInitialization
                                    & initialization);

private:
    BaseSerialStream * mpSerialStream = 0;
};

#endif // SERIALEXECUTABLE_H
