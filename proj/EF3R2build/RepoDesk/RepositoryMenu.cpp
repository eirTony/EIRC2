#include "RepositoryMenu.h"


#include "MainWindow.h"

RepositoryMenu::RepositoryMenu(QWidget * parent)
    : QMenu(parent)
{
}

void RepositoryMenu::setup(void)
{
    setTitle("&Repository");
    addAction(MainWindow::pointer()->quitAction());
}
