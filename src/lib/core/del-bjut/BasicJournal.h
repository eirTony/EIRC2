/*! @file   BasicJournal.h   BaseLib: BasicJournal macro declarations
 */
#ifndef BASICJOURNAL_H
#define BASICJOURNAL_H
#include "./internal/BasicJournalInternal.h"
                                        // mac cat msg
#define BTRACE(msg)     {_BJOURNAL_MSG("BTRACE", "Debug", msg);}
#define BTODO(msg)      {_BJOURNAL_MSG("BTODO", "Trace", msg);}
#define BINFO(msg)      {_BJOURNAL_MSG("BINFO", "Info", msg);}
#define BWARN(msg)      {_BJOURNAL_MSG("BWARN",     "Warning",  msg);}
#define BNEEDDO(msg)    {_BJOURNAL_MSG("BNEEDDO", "Warning", msg);}
#define BERROR(msg)     {_BJOURNAL_MSG("BERROR",    "Error",    msg);}
#define BFATAL(msg)     {_BJOURNAL_MSG("BFATAL",    "Fatal",    msg);}
#define BMUSTDO(msg)    {_BJOURNAL_MSG("BMUSTDO", "Fatal", msg);}

#define BWARNIF(expr)    {if(!!expr) _BJOURNAL_BOOL1(expr, "", "BWARNIF",  "Warning");}
#define BWARNNOT(expr)   {if(!expr)  _BJOURNAL_BOOL1(expr, "", "BWARNNOT", "Warning");}
#define BERRORIF(expr)   {if(!!expr) _BJOURNAL_BOOL1(expr, "", "BERRORIF", "Error");}
#define BERRORNOT(expr)  {if(!expr)  _BJOURNAL_BOOL1(expr, "", "BERRORNOT","Error");}
#define BFATALIF(expr)   {if(!!expr) _BJOURNAL_BOOL1(expr, "", "BFATALIF", "Fatal");}
#define BFATALNOT(expr)  {if(!expr)  _BJOURNAL_BOOL1(expr, "", "BFATALNOT","Fatal");}
#define BWARNIF1(expr, msg)    {if(!!expr) _BJOURNAL_BOOL1(expr, msg, "BWARNIF",  "Warning");}
#define BWARNNOT1(expr, msg)   {if(!expr)  _BJOURNAL_BOOL1(expr, msg, "BWARNNOT", "Warning");}
#define BERRORIF1(expr, msg)   {if(!!expr) _BJOURNAL_BOOL1(expr, msg, "BERRORIF", "Error");}
#define BERRORNOT1(expr, msg)  {if(!expr)  _BJOURNAL_BOOL1(expr, msg, "BERRORNOT","Error");}
#define BFATALIF1(expr, msg)   {if(!!expr) _BJOURNAL_BOOL1(expr, msg, "BFATALIF", "Fatal");}
#define BFATALNOT1(expr, msg)  {if(!expr)  _BJOURNAL_BOOL1(expr, msg, "BFATALNOT","Fatal");}

#define BNULPTR1(ptr, msg)      {if(!ptr) _BJOURNAL_BOOL1(qptrdiff(ptr), msg, "BNULPTR", "Fatal");}

// ToDo: BDUMP(expr)

#define BTRACE1(msg, var1) \
            _BJENTRY("BTRACE", "Debug") \
            << JournalItem("Message", msg) \
            << JournalItem("Var1", var1) \

#define BTRACE2(msg, var1, var2) \
            _BJENTRY("BTRACE", "Debug") \
            << JournalItem("Message", msg) \
            << JournalItem("Var1", var1) \
            << JournalItem("Var2", var2) \

#define BTRACE3(msg, var1, var2, var3) \
            _BJENTRY("BTRACE", "Debug") \
            << JournalItem("Message", msg) \
            << JournalItem("Var1", var1) \
            << JournalItem("Var2", var2) \
            << JournalItem("Var3", var3) \

#define BTRACE4(msg, var1, var2, var3, var4) \
            _BJENTRY("BTRACE", "Debug") \
            << JournalItem("Message", msg) \
            << JournalItem("Var1", var1) \
            << JournalItem("Var2", var2) \
            << JournalItem("Var3", var3) \
            << JournalItem("Var4", var4) \

#define BINFO1(msg, var1) \
            _BJENTRY("BINFO", "Info") \
            << JournalItem("Message", msg) \
            << JournalItem("Var1", var1) \

#define BINFO2(msg, var1, var2) \
            _BJENTRY("BINFO", "Info") \
            << JournalItem("Message", msg) \
            << JournalItem("Var1", var1) \
            << JournalItem("Var2", var2) \

#define BINFO3(msg, var1, var2, var3) \
            _BJENTRY("BINFO", "Info") \
            << JournalItem("Message", msg) \
            << JournalItem("Var1", var1) \
            << JournalItem("Var2", var2) \
            << JournalItem("Var3", var3) \

#define BINFO4(msg, var1, var2, var3, var4) \
            _BJENTRY("BINFO", "Info") \
            << JournalItem("Message", msg) \
            << JournalItem("Var1", var1) \
            << JournalItem("Var2", var2) \
            << JournalItem("Var3", var3) \
            << JournalItem("Var4", var4) \

#define BDUMP(expr) _BJENTRY("BDUMP", "Debug") \
            << JournalItem("Expression", #expr) \
            << JournalItem("Value", expr) \



/* #define BOBJPTR(otyp, expr, msg) {if(!!qobject_cast<otyp>(expr)) _BJOURNAL_BOOL1(expr, msg, "BOBJPTR", "Fatal");} */

#endif // BASICJOURNAL_H
