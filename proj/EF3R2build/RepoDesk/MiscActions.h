#ifndef MISCACTIONS_H
#define MISCACTIONS_H

#include <QObject>

class QAction;

class MiscActions : public QObject
{
    Q_OBJECT
public:
    explicit MiscActions(QObject * parent=0);
    QAction * quitAction(void) const;

signals:

public slots:

private:
    QAction * cmpQuitAction = 0;

};

#endif // MISCACTIONS_H
