#include "MainWindow.h"

#include <QApplication>
#include <QTimer>

#include "MenuBar.h"
#include "ViewMenu.h"
#include "MiscActions.h"
#include "CentralWidget.h"
#include "StatusBar.h"

// static
MainWindow * MainWindow::smpThis = 0;

MainWindow::MainWindow(QWidget * parent)
    : QMainWindow(parent)
    , mpMiscActions(new MiscActions(this))
    , mpSettings(new Settings("EclipseIR","RepoDesk",this))
{
    setObjectName("MainWindow");
    QTimer::singleShot(10, this, SLOT(setup()));
}

MainWindow::~MainWindow() {;}

// static
MainWindow * MainWindow::pointer(void)
{
    if ( ! smpThis) smpThis = new MainWindow(0);
    return smpThis;
}

MenuBar * MainWindow::menu(void) const
{
    return mpMenuBar;
}

Settings & MainWindow::settings(void) const
{
    return &mpSettings;
}

QAction * MainWindow::quitAction(void) const
{
    return mpMiscActions->quitAction();
}

void MainWindow::setup(void)
{
    mpMenuBar = new MenuBar(this);
    mpCentralWidget = new CentralWidget(this);
    mpStatusBar = new StatusBar(this);

    setCentralWidget(mpCentralWidget);
    setMenuBar(mpMenuBar);
    setStatusBar(mpStatusBar);
}
