/*! @file   CommandLineResult.h   AntWorkz ExeLib CommandLineOption definition
 */
#ifndef COMMANDLINERESULT_H
#define COMMANDLINERESULT_H
#include "ExeLib.h"

#include <QStringList>

#include <base/BasicNameMap.h>
class Configuration;

#include "ArgumentSourcePair.h"
#include "CommandLineOption.h"

class EXESHARED_EXPORT CommandLineResult
{
public:
    CommandLineResult(void);
    bool ingestOption(const CommandLineOption & option);
    Configuration & configuration(void) const;

private:
    QStringList mRawArgumentList;
    ArgumentSourcePair::List mExpandedArgumentSourceList;
    BasicNameMap<int> mPositionalNameIndexMap;
    QStringList mPositionalArgumentList;
    QStringList mOtherArgumentList;
    BasicNameMap<int> mOptionNameIndexMap;
    QStringList mSpecifiedOptionMap;
    QStringList mDefaultOptionMap;
};

#endif // COMMANDLINERESULT_H
