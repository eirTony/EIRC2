#include "BasicKeyManager.h"

#include "Diagnostic.h"

BasicKeyManager::BasicKeyManager(void) {;}

BasicKey BasicKeyManager::key(const BasicId & id) const
{
    return mKeyValueDMap.at(id);
}

BasicId BasicKeyManager::id(const BasicKey key) const
{
    return mKeyValueDMap.at(key);
}

bool BasicKeyManager::contains(const BasicId & id) const
{
    return mKeyValueDMap.contains(id);
}

bool BasicKeyManager::contains(const BasicKey key) const
{
    return mKeyValueDMap.contains(key);
}

BasicKey BasicKeyManager::add(const BasicId & id)
{
    BasicKey answer;
    WARNNOT(answer.isZero(), "BasicKey() should be zero");
    if ( ! mKeyValueDMap.contains(id))
        switch(id.size())
        {
        case 1: answer = addUpperGroup(id);    break;
        case 2: answer = addUpperValue(id);    break;
        case 3: answer = addLowerGroup(id);      break;
        case 4: answer = addLowerValue(id);      break;
        default:    /* leave null */            break;
        }
    return answer;
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
    if (mKeyValueDMap.contains(completeId)) return BasicKey();

    BasicKey answer = mKeyValueDMap.at(prefixId);
    if (answer.isNull()) return BasicKey();

    NEEDDO("Catch hard loop");
    do answer.set(part, BasicKey::newKey());
    while (mKeyValueDMap.contains(answer));
    mKeyValueDMap.insertUnique(answer, completeId);
    return answer;
}

DEFINE_BASICSINGLETON(BasicKeyManagerInstance)
BasicKeyManagerInstance::BasicKeyManagerInstance(void) {;}
BasicKeyManagerInstance * gpBasicKeyManagerInstance
                    = BasicKeyManagerInstance::pointer();
