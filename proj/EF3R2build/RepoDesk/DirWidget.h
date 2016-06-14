#ifndef DIRWIDGET_H
#define DIRWIDGET_H

#include <QWidget>

#include <QDir>
#include <QGridLayout>
class QLabel;

class DirWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DirWidget(const QString & dirName,
                       QWidget * parent=0);

protected:
    void setup(void);

signals:
    void changed(QDir);

public slots:
    void set(const QDir & base, const QDir & dir=QDir());

private:
    QString mDirName;
    QGridLayout * mpGrid;
    QLabel * mpRelativeLabel;
    QLabel * mpAbsoluteLabel;
    QString mRelativePath;
    QString mAbsolutePath;
};

#endif // DIRWIDGET_H
