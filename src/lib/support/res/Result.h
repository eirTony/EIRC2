#ifndef RESULT_H
#define RESULT_H
#include "ResLib.h"

#include <QList>

class RESSHARED_EXPORT Result
{
public:
    typedef QList<Result> List;

public:
    Result(void);
};

typedef Result::List Results;

#endif // RESULT_H
