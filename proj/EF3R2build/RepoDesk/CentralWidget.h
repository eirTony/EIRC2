#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>

#include <QList>
#include <QIcon>
#include <QPair>
class QString;
class QTabWidget;

class CentralWidget : public QWidget
{
    Q_OBJECT
public:
    typedef QPair<QString, QWidget *> LabelPageEntry;

public:
    explicit CentralWidget(QWidget * parent=0);
    void addPage(QWidget * page,
                 const QString & label,
                 const QIcon & icon=QIcon());

signals:

public slots:

private:
    QTabWidget * mpCentralTabs = 0;
    QList<LabelPageEntry> mPageEntryList;
};

#endif // CENTRALWIDGET_H
