#include "CentralWidget.h"

#include <QTabWidget>

#include "MainWindow.h"
#include "MenuBar.h"
#include "ViewMenu.h"
#include "DashboardTabPage.h"
#include "StatusPage.h"

CentralWidget::CentralWidget(QWidget * parent)
    : QWidget(parent)
    , mpCentralTabs(new QTabWidget(this))
{
    setObjectName("CentralWidget");

    connect(this, SIGNAL(addedPage(QString,QIcon)),
            MainWindow::pointer()->menu()->view(),
            SLOT(addPage(QString,QIcon)));
    connect(MainWindow::pointer()->menu()->view(),
            SIGNAL(pageSelected(QString)),
            this, SLOT(selectPage(QString)));


    addPage(new DashboardTabPage(this), "Dashboard");
    addPage(new StatusPage(this), "Status");
    show();
}

void CentralWidget::addPage(QWidget * page,
             const QString & label,
             const QIcon & icon)
{
    if (icon.isNull())
        mpCentralTabs->addTab(page, label);
    else
        mpCentralTabs->addTab(page, icon, label);
    mLabelPageMap.insert(label, page);
    emit addedPage(label, icon);
}

void CentralWidget::selectPage(const QString & label)
{
    QWidget * page = mLabelPageMap.value(label);
    if (page && mpCentralTabs)
        mpCentralTabs->setCurrentWidget(page);
}
