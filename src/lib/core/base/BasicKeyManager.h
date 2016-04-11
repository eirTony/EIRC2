#ifndef BASICKEYMANAGER_H
#define BASICKEYMANAGER_H
#include "BaseLib.h"

class QDomElement;

#include "BasicId.h"
#include "BasicKey.h"
#include "BasicSingleton.h"
#include "DualMap.h"

class BASESHARED_EXPORT BasicKeyManager
{
public:
    BasicKeyManager(void);
    BasicKey key(const BasicId & id) const;
    BasicId id(const BasicKey key) const;
    bool contains(const BasicId & id) const;
    bool contains(const BasicKey key) const;
    BasicId::List ids(const BasicId & startsWith=BasicId()) const;
    BasicKey::List keys(const BasicId & startsWith=BasicId()) const;

    BasicKey add(const BasicId & id);

    bool load(const QDomElement & de);
    QDomElement & save(void);

protected:
    typedef DualMap<BasicKey, BasicId> BasicKeyDMap;

protected:
    BasicKeyDMap & valueMap(void) const;

protected:
    BasicKey addUpperGroup(const BasicId & id);
    BasicKey addUpperValue(const BasicId & id);
    BasicKey addLowerGroup(const BasicId & id);
    BasicKey addLowerValue(const BasicId & id);
    BasicKey newKey(const BasicId & prefixId,
                    const BasicKey::Part part,
                    const BasicName & newName);

protected:
    BasicKeyDMap mKeyValueDMap;
};

class BASESHARED_EXPORT BasicKeyManagerInstance
{
    DECLARE_BASICSINGLETON(BasicKeyManagerInstance) // ctor & more
public:
};

#define KEYMGR() gpBasicKeyManagerInstance

#endif // BASICKEYMANAGER_H
