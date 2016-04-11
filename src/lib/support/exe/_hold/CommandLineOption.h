/*! @file   CommandLineOption.h   AntWorkz ExeLib CommandLineOption definition
 */
#ifndef COMMANDLINEOPTION_H
#define COMMANDLINEOPTION_H
#include "ExeLib.h"

#include <QChar>
#include <QString>
#include <QVariant>

#include <base/BasicName.h>
#include <type/DProperty.h>
#include <data/DataType.h>

#define COMMANDLINEOPTION_DATAPROPS(TND) \
    TND(BasicName,      OptionName,     BasicName()) \
    TND(QChar,         SingleChar,     QChar()) \
    TND(BasicNameList,  NameList,       BasicNameList()) \
    TND(QString,       Description,    QString()) \
    TND(QVariant,      DefaultValue,   QVariant()) \
    TND(int,            DataType,       0) \
    TND(QString,       Syntax,         QString()) \
    TND(int,            Position,       0) \
    TND(QVariant,      Value,          QVariant()) \

class CommandLineOptionData : public QSharedData
{
    DECLARE_CHILD_DATAPROPS(COMMANDLINEOPTION_DATAPROPS)
public:
    CommandLineOptionData(void)
    {
        DEFINE_DATAPROPS_CTORS(COMMANDLINEOPTION_DATAPROPS)
    }
};
/*! @class CommandLineOptionData CommandLineOption.h "exe/CommandLineOption.h"
 * @internal
 */

class EXESHARED_EXPORT CommandLineOption
{
public:
    DECLARE_PARENT_DATAPROPS(COMMANDLINEOPTION_DATAPROPS)
    DECLARE_DATAPROPS(CommandLineOption, CommandLineOptionData)

public:
    void Positional(const DataType dt,
                    const BasicName & argName,
                    const QString & syntax,
                    const QString & description=QString());
    void Option(const DataType dt,
                const QChar singleChar,
                const BasicNameList &optNames,
                const QString & description=QString(),
                const BasicName & valueName=BasicName(),
                const QVariant & defaultValue=QVariant());
    void Option(const DataType dt,
                const BasicName & optName,
                const QString & description=QString(),
                const BasicName & valueName=BasicName(),
                const QVariant & defaultValue=QVariant());
    bool isValid(void) const;
};
/*! @class CommandLineOption CommandLineOption.h "exe/CommandLineOption.h"
 * @breif The CommandLineOption class contains each for CommandLineProcessing
 * @todo Change DataType from int to DataLib:DataType when it matures.
 * @since ExeLib version 2.03
 *
 * Each item can represent one of:
 *  * Positional Argument
 *  * Named Argument
 *  * Command Line Option with optional single char or multiple name options
 *  * Special Option, like Help and Version
 *
 *
 */

#endif // COMMANDLINEOPTION_H
