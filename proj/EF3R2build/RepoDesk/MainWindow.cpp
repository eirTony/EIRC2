#include "MainWindow.h"

#include <QTimer>

#include "MenuBar.h"
#include "MiscActions.h"

// static
MainWindow * MainWindow::smpThis = 0;

MainWindow::MainWindow(QWidget * parent)
    : QMainWindow(parent)
    , mpMenuBar(new MenuBar(this))
    , mpMiscActions(new MiscActions(this))
{
    smpThis = this;
    QTimer::singleShot(10, this, SLOT(setup()));
}

MainWindow::~MainWindow() {;}

// static
const MainWindow * MainWindow::pointer(void)
{
    return smpThis;
}

QAction * MainWindow::quitAction(void) const
{
    return mpMiscActions->quitAction();
}

void MainWindow::setup(void)
{
    mpMiscActions->setup();
    mpMenuBar->setup();
    setMenuBar(mpMenuBar);
}
