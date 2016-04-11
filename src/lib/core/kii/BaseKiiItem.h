#ifndef BASEKII_H
#define BASEKII_H
#include "KiiLib.h"

#include "BaseId.h"
#include "BaseInfo.h"
#include "BaseKey.h"
class BaseIdBehavior;
class BaseInfoBehavior;
class BaseKeyBehavior;

class BaseKiiItem
{
public:
    typedef BaseKey  Key;
    typedef BaseId   Id;
    typedef BaseInfo Info;

public:
    BaseKiiItem(void); // Null

protected:
    BaseKiiItem(BaseKeyBehavior  * keyBehavior,
                BaseIdBehavior   * idBehavior,
                BaseInfoBehavior * infoBehavior=0);

private:
    BaseKeyBehavior  * mpKeyBehavior  = 0;
    BaseIdBehavior   * mpIdBehavior   = 0;
    BaseInfoBehavior * mpInfoBehavior = 0;
    BaseKey  mKey;
    BaseId   mId;
    BaseInfo mInfo;
};

#endif // BASEKII_H
