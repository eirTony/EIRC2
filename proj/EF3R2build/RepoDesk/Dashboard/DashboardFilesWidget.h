#ifndef DASHBOARDFILESWIDGET_H
#define DASHBOARDFILESWIDGET_H

#include <QWidget>

class DirWidget;

class DashboardFilesWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DashboardFilesWidget(QWidget * parent=0);
    void refresh(void);

signals:

public slots:

private:
    DirWidget * mpBaseDirWidget;
    DirWidget * mpAccessDirWidget;
};

#endif // DASHBOARDFILESWIDGET_H
