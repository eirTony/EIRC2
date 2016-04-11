#ifndef ECLIPSEMESSAGE_H
#define ECLIPSEMESSAGE_H
#include "MsgLib.h"

//#include <var/VariableMap.h>
typedef QVariantMap VariableMap;

class MSGSHARED_EXPORT EclipseMessage : public VariableMap
{
public:
    EclipseMessage(void);
};

#endif // ECLIPSEMESSAGE_H
