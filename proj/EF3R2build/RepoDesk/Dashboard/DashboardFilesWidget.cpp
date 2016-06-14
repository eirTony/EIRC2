#include "DashboardFilesWidget.h"

//#include <QHBoxLayout>
//#include <QLabel>
#include <QVBoxLayout>

#include "DirWidget.h"

DashboardFilesWidget::DashboardFilesWidget(QWidget * parent)
    : QWidget(parent)
    , mpBaseDirWidget(new DirWidget("Base", this))
    , mpAccessDirWidget(new DirWidget("Access", this))
{
    setObjectName("DashboardFilesWidget");
    QVBoxLayout * pMainVBox = new QVBoxLayout(this);
    pMainVBox->addWidget(mpBaseDirWidget);
    pMainVBox->addWidget(mpAccessDirWidget);

#if 0
    QHBoxLayout * pBaseHBox = new QHBoxLayout(this);
    QHBoxLayout * pEffHBox = new QHBoxLayout(this);

    QLabel * pBaseLabel = new QLabel(this, "Base:");
    QLabel * pBaseEffectiveLabel = new QLabel(this, "Effective=");
    QLabel * pBaseDir = new QLabel(this)
#endif
}
