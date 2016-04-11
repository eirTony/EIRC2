#ifndef BASICJOURNALINTERNAL_H
#define BASICJOURNALINTERNAL_H
#ifndef MODULE_NAME
# define MODULE_NAME "Internal"
#endif

#include <QDateTime>

#include "../JournalQueue.h"
#include "JournalEntry.h"
#include "JournalItem.h"
#include "BjutTypes.h"


#define _BJOURNAL (JournalQueue::instance())
#define _BJOURNAL_EXPR(expr) _BJOURNAL.expr
#define _BJOURNAL_ENQ(entry) _BJOURNAL_EXPR(enqueue(entry))

#define _BJENTRY(mac, cat) JournalEntry() \
            << JournalItem("TimeStamp", QDateTime::currentDateTime()) \
            << JournalItem("ModuleName", MODULE_NAME) \
            << JournalItem("PrettyFunction", Q_FUNC_INFO) \
            << JournalItem("SourceFileName", __FILE__) \
            << JournalItem("SourceFileLine", __LINE__) \
            << JournalItem("MacroName", mac) \
            << JournalItem("Category", cat) \

#define _BJOURNAL_BOOL1(expr, msg, mac, cat) \
            _BJOURNAL_ENQ(_BJENTRY(mac, cat) \
                << JournalItem("Expression", expr) \
                << JournalItem("ExprName", #expr) \
                << JournalItem("Message", msg) \
                )

#define _BJOURNAL_MSG(mac, cat, msg) \
            _BJOURNAL_ENQ(_BJENTRY(mac, cat) \
                << JournalItem("Message", msg) \
                )


#endif // BASICJOURNALINTERNAL_H
