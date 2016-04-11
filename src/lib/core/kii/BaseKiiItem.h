#ifndef BASEKII_H
#define BASEKII_H
#include "KiiLib.h"

#include "Id.h"
#include "Info.h"
#include "Key.h"
class BaseIdBehavior;
class BaseInfoBehavior;
class BaseKeyBehavior;

class BaseKiiItem
{
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
    Key  mKey;
    Id   mId;
    Info mInfo;
};

#endif // BASEKII_H
