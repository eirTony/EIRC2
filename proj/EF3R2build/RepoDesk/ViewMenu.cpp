#include "ViewMenu.h"

ViewMenu::ViewMenu(QWidget * parent)
    : QMenu(parent)
    , cmpPageMenu(new QMenu(this))
{
    setObjectName("ViewMenu");
    setTitle("View");

    cmpPageMenu->setObjectName("ViewPageMenu");
    cmpPageMenu->setTitle("Page");

    addMenu(cmpPageMenu);
}

void ViewMenu::addPage(const QString & label,
             const QIcon & icon)
{
    QAction * pageAction = new QAction(icon, label, this);
    mLabelActionMap.insert(label, pageAction);
    mActionLabelMap.insert(pageAction, label);
    cmpPageMenu->addAction(pageAction);
    connect(pageAction, SIGNAL(triggered()),
            this, SLOT(pageTriggered()));
}

void ViewMenu::pageTriggered(void)
{
    QObject * senderObject = sender();
    QAction * senderAction = qobject_cast<QAction*>(senderObject);
    QString senderLabel = mActionLabelMap.value(senderAction);
    if ( ! senderLabel.isEmpty())
        emit pageSelected(senderLabel);
}
