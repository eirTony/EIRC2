#include "DirWidget.h"

#include <QGridLayout>
#include <QLabel>

DirWidget::DirWidget(const QString & dirName,
                     QWidget * parent)
    : QWidget(parent)
    , mDirName(dirName)
    , mpGrid(new QGridLayout(this))
    , mpRelativeLabel(new QLabel(this))
    , mpAbsoluteLabel(new QLabel(this))
{
    setObjectName("DirWidget:" + mDirName);
    setup();
    set(QDir("."));
}

void DirWidget::setup(void)
{
//    mpGrid = new QGridLayout(this);
    mpGrid->addWidget(new QLabel(mDirName), 0, 0, 1, 2);
    mpGrid->addWidget(new QLabel("Base:"), 1, 0);
    mpGrid->addWidget(mpRelativeLabel, 1, 1);
    mpGrid->addWidget(new QLabel("Absolute:"), 2, 0);
    mpGrid->addWidget(mpAbsoluteLabel, 2, 1);
//    QWidget::setLayout(mpGrid);
}

void DirWidget::set(const QDir & base, const QDir & dir)
{
    QDir effective(base);

//    QString baseAbsolute = base.absolutePath();
    if (dir == QDir())
    {
        mRelativePath = base.path();
    }
    else
    {
        mRelativePath = dir.path();
        effective.mkpath(mRelativePath);
        effective.cd(mRelativePath);
    }
    effective.makeAbsolute();
    mAbsolutePath = effective.absolutePath();

    mpRelativeLabel->setText(mRelativePath);
    mpAbsoluteLabel->setText(mAbsolutePath);

    emit changed(effective);
}
