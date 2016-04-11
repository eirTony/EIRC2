#ifndef LIBRARYINFO_H
#define LIBRARYINFO_H
#include "pdzbase_global.h"

#include <QString>

#include "VersionInfo.h"

class PDZBASESHARED_EXPORT LibraryInfo
{
public:
    LibraryInfo(const QString & libraryName);

private:
    const QString cmName;
};

#endif // LIBRARYINFO_H
