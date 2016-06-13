#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>

class RepositoryMenu;
class ViewMenu;

class MenuBar : public QMenuBar
{
    Q_OBJECT
public:
    explicit MenuBar(QWidget * parent=0);
    ViewMenu * view(void) const;

signals:

public slots:

private:
    RepositoryMenu * cmpRepositoryMenu = 0;
    ViewMenu * cmpViewMenu = 0;
};

#endif // MENUBAR_H
