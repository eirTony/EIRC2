#include "KiiManager.h"

#include "KiiCutter.h"
#include "KiiRing.h"
#include "KiiTaxonomy.h"

KiiManager::KiiManager(QObject * parent)
    : QObject(parent)
    , cmpTaxonomy(new KiiTaxonomy(this))
    , cmpRing(new KiiRing(this))
    , cmpCutter(new KiiCutter(this)) {;}
