#include "MiscActions.h"

#include <QApplication>
#include <QAction>

MiscActions::MiscActions(QObject * parent)
    : QObject(parent)
    , cmpQuitAction(new QAction("&Quit", this))
{
    setObjectName("MiscActions");
    connect(cmpQuitAction, SIGNAL(triggered(bool)),
            qApp, SLOT(quit()));
}

QAction * MiscActions::quitAction(void) const
{
    return cmpQuitAction;
}
