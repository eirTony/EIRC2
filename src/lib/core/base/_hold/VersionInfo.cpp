#include "VersionInfo.h"

#include <QtDebug>

#include "LibraryVersion.h"
#include "../../../BranchVersion.h"
#include "../../../CommonVersion.h"

DEFINE_BASICSINGLETON(VersionInfo)

VersionInfo::VersionInfo(void)
    : cmString(VER_STRING)
    , cmBString(VER_BSTRING)
    , cmMajor(VER_MAJOR)
    , cmMinor(VER_MINOR)
    , cmBranch(VER_BRANCH)
    , cmRelease(VER_RELEASE)
    , cmBuild(VER_MAJOR)
    , cmCopyright(VER_COPYRIGHT)
#ifdef VER_LEGAL
    , cmLegal(QString(VER_LEGAL).split("{~}"))
#endif
    , cmProduct(VER_PRODNAME)
    , cmCompany(VER_COMPANY)
    , cmOrgName(VER_ORGNAME)
    , cmIconFilePath(VER_ICON)
{
    mIcon = QIcon(cmIconFilePath);
    qDebug("%s", qPrintable(string()));
}

QString VersionInfo::string(void) const
{
    return cmString+cmBString;
}
