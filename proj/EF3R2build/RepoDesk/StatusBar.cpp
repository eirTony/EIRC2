#include "StatusBar.h"

StatusBar::StatusBar(QWidget *parent)
    : QStatusBar(parent)
{
    setObjectName("StatusBar");
    showMessage("OK");
}
