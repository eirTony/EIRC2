#include "BaseTransition.h"

#include <base/Diagnostic.h>

BaseTransition::BaseTransition(QState * sourceState)
    : QAbstractTransition(sourceState) {;}

bool BaseTransition::eventTest(QEvent *event)
{
    NOUSE(event);
    return true;
}

void BaseTransition::onTransition(QEvent *event)
{
    NOUSE(event);
}
