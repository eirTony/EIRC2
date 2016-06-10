#ifndef REPOSITORYMENU_H
#define REPOSITORYMENU_H

#include <QMenu>

class RepositoryMenu : public QMenu
{
    Q_OBJECT
public:
    explicit RepositoryMenu(QWidget * parent=0);

signals:

public slots:
    void setup(void);

};

#endif // REPOSITORYMENU_H
