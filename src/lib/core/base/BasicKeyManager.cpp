#include "BasicKeyManager.h"

#include "Diagnostic.h"

#ifdef BUILD_TEST                       ///////// TEST
BasicKeyManagerTest::BasicKeyManagerTest(QObject * parent)
    : TestObject("BaseLib/BasicKeyManager", parent)
{
    TRACE("in BasicKeyManagerTest ctor", "");
}
#endif                                  //\\\\\\\ test

BasicKeyManager::BasicKeyManager(void) {;}

void BasicKeyManager::clear(void)
{
    mKeyIdDMap.clear();
}

BasicKey BasicKeyManager::key(const BasicId & id) const
{
    return mKeyIdDMap.at(id);
}

BasicId BasicKeyManager::id(const BasicKey key) const
{
    return mKeyIdDMap.at(key);
}

bool BasicKeyManager::contains(const BasicId & id) const
{
    return mKeyIdDMap.contains(id);
}

bool BasicKeyManager::contains(const BasicKey key) const
{
    return mKeyIdDMap.contains(key);
}

BasicKey::List BasicKeyManager::keys(const BasicId & startsWith) const
{
    BasicKey::List keys;
    if (startsWith.isNull())
    {
        keys.append(mKeyIdDMap.all(BasicKey()));
    }
    else
    {
        MUSTDO("startsWith");
    }
    return keys;
}

void BasicKeyManager::trace(void) const
{
    foreach (BasicKey k, keys())
        TRACE("%1 = %2", QString("0x%1").arg(k(),16,16,QChar('0')),
              id(k)());
}

#ifdef BUILD_TEST                       ///////// TEST
void BasicKeyManagerTest::add(void)
{
    mKeys.clear();
    BasicKey keyAddS = mKeys.add(idS, current);
    QCOMPARE(keyS(), keyAddS());
    BasicKey keyAddS0 = mKeys.add(idS0, current);
    QCOMPARE(keyS0(), keyAddS0());
}
#endif                                  //\\\\\\\ test

BasicKey BasicKeyManager::add(const BasicId & id,
                              const BasicKey base)
{
#if 1
    TRACE("BKM:add(%1(%3), 0x%2)", id(),
          QString::number(base(),16).toUpper(), id.size());
    BasicKey basicKey;
    BasicKey key = base.isNull() ? BasicKey::newKey() : base;
    WARNNOT(basicKey.isZero());
    WARNIF(id.isNull());
    WARNIF(mKeyIdDMap.contains(id));
    if (mKeyIdDMap.contains(id))
        return mKeyIdDMap.at(id);    //-------------

    BasicId parents = id.parents();
    WARNNOT(mKeyIdDMap.contains(parents) && id.size() > 1);
    BasicKey parentKey = mKeyIdDMap.at(parents);
    TRACE("Parents: %1 0x%2", parents(),
          QString::number(parentKey(),16).toUpper());
    if (id.name().isEmpty())
    {
        basicKey = parentKey;
    }
    else if (id.size() > 1 && parentKey.isValid())
    {
        basicKey |= parentKey;
        basicKey.set(BasicKey::part(id), key);
    }
    else if (1 == id.size())
    {
        basicKey.set(BasicKey::Part::UpperGroup, key);
    }
    mKeyIdDMap.insertUnique(basicKey, id);
    TRACE("Result: %1 0x%2", id(),
          QString::number(basicKey(),16).toUpper());
    trace();
    return basicKey;
#else
    BasicKey answer;
    WARNMSGNOT(answer.isZero(), "BasicKey() should be zero");
    if ( ! mKeyValueDMap.contains(id))
        switch(id.size())
        {
        case 1: answer = addUpperGroup(id);    break;
        case 2: answer = addUpperValue(id);    break;
        case 3: answer = addLowerGroup(id);    break;
        case 4: answer = addLowerValue(id);    break;
        default:    /* leave null */           break;
        }
    return answer;
#endif
}

BasicKey BasicKeyManager::addUpperGroup(const BasicId & id)
{
    return newKey(BasicId(),
                  BasicKey::LowerGroup,
                  id.at(0));
}

BasicKey BasicKeyManager::addUpperValue(const BasicId & id)
{
    return newKey(id.at(0),
                  BasicKey::LowerGroup,
                  id.at(1));
}

BasicKey BasicKeyManager::addLowerGroup(const BasicId & id)
{
    BasicId prefixId(id.at(0));
    prefixId += BasicName("0");
    return newKey(prefixId,
                  BasicKey::LowerGroup,
                  id.at(2));
}

BasicKey BasicKeyManager::addLowerValue(const BasicId & id)
{
    BasicId prefixId(id.at(0));
    prefixId += id.at(1);
    prefixId += id.at(2);
    return newKey(prefixId,
                  BasicKey::LowerGroup,
                  id.at(3));
}

BasicKey BasicKeyManager::newKey(const BasicId & prefixId,
                                 const BasicKey::Part part,
                                 const BasicName & newName)
{
    BasicId completeId = prefixId;
    completeId += newName;
    if (mKeyIdDMap.contains(completeId)) return BasicKey();

    BasicKey answer = mKeyIdDMap.at(prefixId);
    if (answer.isNull()) return BasicKey();

    NEEDDO("Catch hard loop");
    do answer.set(part, BasicKey::newKey());
    while (mKeyIdDMap.contains(answer));
    mKeyIdDMap.insertUnique(answer, completeId);
    return answer;
}

bool BasicKeyManager::load(const KeyIdPairList & list)
{
    clear();
    foreach (KeyIdPair pair, list)
        mKeyIdDMap.insertUnique(pair.first, pair.second);
    return true;
}


#ifdef BUILD_BASICKEYMANAGERINSTANCE
DEFINE_BASICSINGLETON(BasicKeyManagerInstance)
BasicKeyManagerInstance::BasicKeyManagerInstance(void) {;}
BasicKeyManagerInstance * gpBasicKeyManagerInstance
                    = BasicKeyManagerInstance::pointer();
#endif
