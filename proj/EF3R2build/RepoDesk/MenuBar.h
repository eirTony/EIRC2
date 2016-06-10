#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>

class RepositoryMenu;

class MenuBar : public QMenuBar
{
    Q_OBJECT
public:
    explicit MenuBar(QWidget * parent=0);

signals:

public slots:
    void setup(void);

private:
    RepositoryMenu * cmpRepositoryMenu = 0;
};

#endif // MENUBAR_H
