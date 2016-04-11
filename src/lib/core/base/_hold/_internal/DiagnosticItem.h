#ifndef DIAGNOSTICITEM_H
#define DIAGNOSTICITEM_H
#include "../pdzBase.h"

#include <QtDebug>
#include <QDateTime>
#include <QList>
#include <QSet>
#include <QString>

class QFile;
class QFileInfo;

#include "../BasicId.h"

class PDZBASESHARED_EXPORT DiagnosticItem
{
public:
    enum Command
    {
        BeginTest,
        EndTest,
        ReportTodo,
        ReportTest,
    };

public:
    DiagnosticItem(void);
    DiagnosticItem(const QtMsgType msgtype,
                   const QString & function,
                   const QString & fileName,
                   const int fileLine,
                   const QString & format,
                   const QVariant & var1=QVariant(),
                   const QVariant & var2=QVariant(),
                   const QVariant & var3=QVariant(),
                   const QVariant & var4=QVariant());
    DiagnosticItem(const Command cmd,
                   const QVariant var);

public: // static
    static void boolean(const QtMsgType msgtype,
                        const QString & function,
                        const QString & fileName,
                        const int fileLine,
                        const bool expectation,
                        const bool actual,
                        const QString expression,
                        const QString & message = QString());
    static void todo(const QtMsgType msgtype,
                     const QString & function,
                     const QString & fileName,
                     const int fileLine,
                     const QString & message,
                     const QString & expression);
    static void beginTest(const BasicId & testId);
    static void endTest(const BasicId & testId);
    static bool inTest(void);
    static bool reportTodo(QIODevice * iod=0);
    static bool reportTest(QIODevice * iod=0);
    static void exec(const QString & orgName,
                     const QString & appName);

private:
    QString createMessage(void) const;
    void handleTest(const QtMsgType msgtype,
                    const QString & message);
    void sendMessage(const QtMsgType msgtype,
                     const QString & message);

private: // static
    static BasicId lineId(const QString & fileName,
                          const int fileLine, const QString &expr);
    static QString formatMessage(const QString & format,
                                 QVariantList vars);
    static void startTodoFile(const QFileInfo & fi);
    static void startLogFile(const QFileInfo & fi);
    static void execTodo(const QString & todoMsg);
    static void execLog(const DiagnosticItem & di);

private:
    const QDateTime     cmTimestamp;
    const QtMsgType     cmMsgType = QtDebugMsg;
    const QString       cmFunction;
    const QString       cmFileName;
    const int           cmFileLine = 0;
    const BasicId       cmLineId;
    const QString       cmFormat;
    const QVariantList  cmVarList;

private: // static
    static bool smExec;
    static QList<DiagnosticItem>    smItemList;
    static QMap<BasicId, QString>     smTodoLineMessageMap;
    static QMap<BasicId, QString>     smTestLineMessageMap;
    static QList<BasicId> smTestIdList;
    static QSet<BasicId> smCompletedTestIdSet;
    static QFile * smpTodoFile;
    static QFile * smpLogFile;
};

#define TRACE_PFX   ">Trace: "
#define INFO_PFX    "-Info:  "
#define WARN_PFX    "+Warn:  "
#define CRIT_PFX    "*Crit:  "
#define FATAL_PFX   "#Fatal: "
#define DO_PFX      "DO-->"
#define USE_PFX     "USE->"

#define __DIAGITEM(typ, msg, args...) \
        { DiagnosticItem di(typ, Q_FUNC_INFO, \
                            __FILE__, __LINE__, msg ,##args); } \

#define __BOOLITEM(typ, tru, act, msg) \
        { DiagnosticItem::boolean(typ, Q_FUNC_INFO, \
                                  __FILE__, __LINE__, \
                                  tru, act, #act, msg); }\

#define __TODOITEM(typ, msg, exp) \
        { DiagnosticItem::todo(typ, Q_FUNC_INFO, \
                                __FILE__, __LINE__, msg, exp); } \

#define _FMTITEM(typ, pfx, fmt, args...) \
        __DIAGITEM(typ, pfx fmt ,##args) \




#endif // DIAGNOSTICITEM_H
