#include "MiscActions.h"

#include <QApplication>
#include <QAction>

MiscActions::MiscActions(QObject * parent)
    : QObject(parent)
    , cmpQuitAction(new QAction("&Quit", this))
{
}

QAction * MiscActions::quitAction(void) const
{
    return cmpQuitAction;
}

void MiscActions::setup(void)
{
    connect(cmpQuitAction, SIGNAL(triggered(bool)),
            qApp, SLOT(quit()));
}
