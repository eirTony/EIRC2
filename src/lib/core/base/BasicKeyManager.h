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
    void clear(void);
    BasicKey key(const BasicId & id) const;
    BasicId id(const BasicKey key) const;
    bool contains(const BasicId & id) const;
    bool contains(const BasicKey key) const;
    BasicId::List ids(const BasicId & startsWith=BasicId()) const;
    BasicKey::List keys(const BasicId & startsWith=BasicId()) const;
    void trace(void) const;

    BasicKey add(const BasicId & id,
                 const BasicKey base=0);

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
    BasicKeyDMap mKeyIdDMap;
};

#ifdef BUILD_BASICKEYMANAGERINSTANCE
class BASESHARED_EXPORT BasicKeyManagerInstance
{
    DECLARE_BASICSINGLETON(BasicKeyManagerInstance) // ctor & more
public:
};
#define KEYMGR() gpBasicKeyManagerInstance
#endif

#ifdef BUILD_TEST                       ///////// TEST
#include "TestObject.h"
#include "BasicId.h"

class BASESHARED_EXPORT BasicKeyManagerTest : public TestObject
{
    Q_OBJECT
public:
    BasicKeyManagerTest(QObject * parent=0);

private slots:
    void add(void);

private:
    BasicKeyManager mKeys;

    BasicId id0 = BasicId("0");
    BasicId idS = BasicId("Super");
    BasicId idS0 = BasicId("Super/0");
    BasicId idS0s = BasicId("Super/0/sub");
    BasicId idS0s0 = BasicId("Super/0/sub/0");

    BasicKey current = BasicKey::newKey();
    BasicKey keyNoId = BasicKey(id0, current);
    BasicKey keyS = BasicKey(idS, current);
    BasicKey keyS0 = BasicKey(idS0, current);
    BasicKey keyS0s = BasicKey(idS0s, current);
    BasicKey keyS0s0 = BasicKey(idS0s0, current);

};
#endif                                  //\\\\\\\ test


#endif // BASICKEYMANAGER_H
