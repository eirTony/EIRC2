#ifndef KIIRING_H
#define KIIRING_H
#include "KiiLib.h"

#include "KiiRingPlugin.h"


#include "Id.h"
#include "Info.h"
#include "Key.h"
#include "Name.h"
class KiiManager;


class KIISHARED_EXPORT KiiRing : public KiiRingPlugin
{
public:
    KiiRing(KiiManager * manager);

public:
    Key key(const Id & id) const;

private:
    const KiiManager * cmpManager = 0;

};

#endif // KIIRING_H
