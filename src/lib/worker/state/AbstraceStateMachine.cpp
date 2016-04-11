#include "AbstraceStateMachine.h"

#include <base/BasicJournal.h>

AbstraceStateMachine::AbstraceStateMachine(QObject * parent)
    : QQState(parent)
{
    BOBJPTR(QObject, parent, "Invalid AbstraceStateMachine parent");
}
