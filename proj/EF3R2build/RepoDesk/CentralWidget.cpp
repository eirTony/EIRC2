#include "CentralWidget.h"

#include <QTabWidget>

#include <DashboardTabPage.h>
#include <StatusPage.h>

CentralWidget::CentralWidget(QWidget * parent)
    : QWidget(parent)
    , mpCentralTabs(new QTabWidget(this))
{
    addPage(new DashboardTabPage(this), "Dashboard");
    addPage(new StatusPage(this), "Status");
}

void CentralWidget::addPage(QWidget * page,
             const QString & label,
             const QIcon & icon)
{
    if (icon.isNull())
        mpCentralTabs->addTab(page, label);
    else
        mpCentralTabs->addTab(page, icon, label);
}
