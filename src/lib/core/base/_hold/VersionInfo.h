#ifndef VERSIONINFO_H
#define VERSIONINFO_H

#include <QIcon>
#include <QString>

#include "BasicSingleton.h"

class VersionInfo
{
    DECLARE_BASICSINGLETON(VersionInfo) // ctor & more
public:
    QIcon icon(void) const;
    QString string(void) const;
    QString toString(void) const;

private:
    const QString   cmString;
    const QString   cmBString;
    const int       cmMajor;
    const int       cmMinor;
    const int       cmBranch;
    const int       cmRelease;
    const int       cmBuild;
    const QString   cmCopyright;
    const QStringList cmLegal;
    const QString   cmProduct;
    const QString   cmCompany;
    const QString   cmOrgName;
    const QString   cmIconFilePath;

    QIcon mIcon;
};

#endif // VERSIONINFO_H
