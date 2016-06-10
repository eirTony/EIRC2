#include "MenuBar.h"

#include "RepositoryMenu.h"

MenuBar::MenuBar(QWidget * parent)
    : QMenuBar(parent)
    , cmpRepositoryMenu(new RepositoryMenu(this))
{
}

void MenuBar::setup(void)
{
    cmpRepositoryMenu->setup();
    addMenu(cmpRepositoryMenu);
}
