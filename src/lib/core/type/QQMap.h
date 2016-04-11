#ifndef QQMap_H
#define QQMap_H

#include <QMap>

template <class KEY, class T>
    class QQMap : public QMap<KEY, T>
{
public:
    QQMap(void) {}
    QQMap(const QMap<KEY, T> ktMap) : QMap<KEY, T>(ktMap) {}
};

#endif // QQMap_H
