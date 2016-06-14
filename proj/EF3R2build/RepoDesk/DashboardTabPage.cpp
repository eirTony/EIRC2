#include "DashboardTabPage.h"

#include <QVBoxLayout>

#include "./Dashboard/DashboardFilesWidget.h"

DashboardTabPage::DashboardTabPage(QWidget * parent)
    : QWidget(parent)
    , mpFiles(new DashboardFilesWidget(this))
{
    setObjectName("DashboardTabPage");

    QVBoxLayout * mainVLayout = new QVBoxLayout(this);
    mainVLayout->addWidget(mpFiles);
}
