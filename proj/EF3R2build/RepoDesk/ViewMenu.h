#ifndef VIEWMENU_H
#define VIEWMENU_H

#include <QMenu>

class ViewMenu : public QMenu
{
    Q_OBJECT
public:
    explicit ViewMenu(QWidget * parent=0);

signals:
    void pageSelected(QString);

public slots:
    void addPage(const QString & label,
                 const QIcon & icon=QIcon());
    void pageTriggered(void);

private:
    QMenu * cmpPageMenu;
    QMap<QString, QAction *> mLabelActionMap;
    QMap<QAction *, QString> mActionLabelMap;
};

#endif // VIEWMENU_H
