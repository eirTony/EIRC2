#ifndef DASHBOARDTABPAGE_H
#define DASHBOARDTABPAGE_H

#include <QWidget>

class DashboardFilesWidget;

class DashboardTabPage : public QWidget
{
    Q_OBJECT
public:
    explicit DashboardTabPage(QWidget * parent=0);

signals:

public slots:

private:
    DashboardFilesWidget * mpFiles;

};

#endif // DASHBOARDTABPAGE_H
