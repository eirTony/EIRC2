#include "RepositoryMenu.h"


#include "MainWindow.h"

RepositoryMenu::RepositoryMenu(QWidget * parent)
    : QMenu(parent)
{
    setObjectName("RepositoryMenu");
    setTitle("&Repository");
    addAction(MainWindow::pointer()->quitAction());
}

