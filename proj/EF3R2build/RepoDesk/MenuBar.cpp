#include "MenuBar.h"

#include "RepositoryMenu.h"
#include "ViewMenu.h"

MenuBar::MenuBar(QWidget * parent)
    : QMenuBar(parent)
    , cmpRepositoryMenu(new RepositoryMenu(this))
    , cmpViewMenu(new ViewMenu(this))
{
    setObjectName("MenuBar");
    addMenu(cmpRepositoryMenu);
    addMenu(cmpViewMenu);
}

ViewMenu * MenuBar::view(void) const
{
    return cmpViewMenu;
}
