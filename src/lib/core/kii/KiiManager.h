#ifndef KIIMANAGER_H
#define KIIMANAGER_H

#include <QObject>

#include "KiiClassKey.h"
class KiiCutter;
class KiiRing;
class KiiTaxonomy;

class KiiManager : public QObject
{
    Q_OBJECT
public:
    explicit KiiManager(QObject * parent=0);

signals:

public slots:

private:
    const KiiTaxonomy * cmpTaxonomy = 0;
    const KiiRing * cmpRing = 0;
    const KiiCutter * cmpCutter = 0;
    KiiClassKey mRootClassKey = KiiClassKey();
};

#endif // KIIMANAGER_H
