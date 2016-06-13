#include "RepositoryMenu.h"


#include "MainWindow.h"

RepositoryMenu::RepositoryMenu(QWidget * parent)
    : QMenu(parent)
{
    setTitle("&Repository");
    addAction(MainWindow::pointer()->quitAction());
}

