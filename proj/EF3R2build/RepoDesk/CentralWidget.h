#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>

#include <QList>
#include <QMap>
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
    void addedPage(QString,QIcon);

public slots:
    void selectPage(const QString & label);

private:
    QTabWidget * mpCentralTabs = 0;
    QList<LabelPageEntry> mPageEntryList;
    QMap<QString, QWidget *> mLabelPageMap;
};

#endif // CENTRALWIDGET_H
