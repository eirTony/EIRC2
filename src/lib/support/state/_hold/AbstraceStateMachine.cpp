#include "AbstraceStateMachine.h"

#include <base/BasicJournal.h>

AbstraceStateMachine::AbstraceStateMachine(QObject * parent)
    : QState(parent)
{
    BOBJPTR(QObject, parent, "Invalid AbstraceStateMachine parent");
}
