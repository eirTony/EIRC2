#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>

class QDir;

class Settings : public QSettings
{
    Q_OBJECT
public:
    explicit Settings(const QString & orgName,
                      const QString & appName,
            QObject * parent=0);
    QDir getBaseDir(void) const;
    void setBaseDir(const QDir & base);

signals:

public slots:

};

#endif // SETTINGS_H
