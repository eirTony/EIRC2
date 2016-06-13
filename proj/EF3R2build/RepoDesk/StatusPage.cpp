#include "StatusPage.h"

#include <QDateTime>

StatusPage::StatusPage(QWidget * parent)
    : QPlainTextEdit(parent)
{
    setObjectName("StatusPage");

    int minWidth = tabStopWidth() * 10;

    setReadOnly(true);
    setMinimumWidth(minWidth);;
    appendPlainText(QString("Started %1")
                    .arg(QDateTime::currentDateTime().toString()));
}
