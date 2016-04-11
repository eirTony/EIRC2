#include "KiiRing.h"

#include <base/Diagnostic.h>

#include "KiiManager.h"

KiiRing::KiiRing(KiiManager * manager) : cmpManager(manager) {;}

Key KiiRing::key(const Id & id) const
{
    USE(id);
    NEEDDO("static key from id");
    return Key();
}
