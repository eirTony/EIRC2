#ifndef UNITTESTMETAOBJECT_H
#define UNITTESTMETAOBJECT_H

#include <QObject>

class UnitTestMetaObject : public QObject
{
    Q_OBJECT
public:
    explicit UnitTestMetaObject(QObject * parent=0);

signals:

public slots:

};

#endif // UNITTESTMETAOBJECT_H
