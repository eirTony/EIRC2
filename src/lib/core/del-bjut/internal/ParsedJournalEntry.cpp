/*! @file   ParsedJournalEntry.cpp BjutLib ParsedJournalEntry class definitions
 */
#include "ParsedJournalEntry.h"

#include "JournalEntry.h"

ParsedJournalEntry::ParsedJournalEntry(const JournalEntry & entry)
    : mEntry(entry)
    , timeStamp(entry.value("TimeStamp").toDateTime())
    , macroName(JournalQueue::parseMacroName
                        (entry.value("MacroName").toString()))
    , category(JournalQueue::parseCategory
                        (entry.value("Category").toString()))
    , message(entry.value("Message").toString())
    , expression(entry.value("Expression"))
    , exprName(entry.value("ExprName").toString())
    , objectName(entry.value("ObjectName").toString())
    , var1(entry.value("Var1"))
    , var2(entry.value("Var2"))
    , var3(entry.value("Var3"))
    , var4(entry.value("Var4"))
    , prettyFunction(entry.value("PrettyFunction").toString())
    , sourceFileName(entry.value("SourceFileName").toString())
    , sourceFileLine(entry.value("SourceFileLine").toInt())
{
}

QString ParsedJournalEntry::formatted(void) const
{
    QString rtn(message);

    switch (macroName)
    {
    case JournalQueue::BWarn:
    case JournalQueue::BError:
    case JournalQueue::BFatal:
    case JournalQueue::BTrace:
    case JournalQueue::BInfo:
        rtn.replace("%1", var1.toString());
        rtn.replace("%2", var2.toString());
        rtn.replace("%3", var3.toString());
        rtn.replace("%4", var4.toString());
        break;

    case JournalQueue::BToDo:
    case JournalQueue::BNeedDo:
    case JournalQueue::BMustDo:
        rtn = mEntry.value("MacroName").toString() + ": " + rtn;
        break;

    case JournalQueue::BWarnIf:
    case JournalQueue::BErrorIf:
    case JournalQueue::BFatalIf:
        rtn = QString("Failed: %1 (%2) <%3>")
                .arg(exprName).arg(expression.toString()).arg(message);
        break;

    case JournalQueue::BWarnNot:
    case JournalQueue::BErrorNot:
    case JournalQueue::BFatalNot:
        rtn = QString("Failed NOT: %1 (%2)")
                .arg(exprName).arg(expression.toString());
        break;

    case JournalQueue::BDump:
        rtn = QString("%1 = (%2)")
                .arg(exprName).arg(expression.toString());
        break;

    case JournalQueue::BObjPtr:
    case JournalQueue::BNulPtr:
        // TBD
        break;

    case JournalQueue::nullMacroName: // reserved values
    case JournalQueue::sizeMacroName: {;}
    }

    return rtn;
} // formatted()
