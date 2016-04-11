#ifndef KII_H
#define KII_H
#include "KiiLib.h"

#include "Id.h"
#include "Info.h"
#include "Key.h"

class KIISHARED_EXPORT Kii
{
public:
    Kii(void);
    Kii(const Key key,
                 const Id id,
                 const Info info=Info());
    bool isNull(void) const;
    void clear(void);
    Key key(void) const;
    Id id(void) const;
    Info info(void) const;
    void set(const Key key,
             const Id id,
             const Info info=Info());
    void set(const Key key);
    void set(const Id id);
    void set(const Info info=Info());

private:
    Key  mKey;
    Id   mId;
    Info mInfo;
};

#endif // KII_H
