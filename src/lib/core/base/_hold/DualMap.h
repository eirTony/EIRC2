#ifndef DUALMAP_H
#define DUALMAP_H

#include <QMap>

template <class T1, class T2> class DualMap
{
public:
    DualMap(void) {}
    void clear(void)
    { mOneToTwoMap.clear(), mTwoToOneMap.clear(); }
    bool isEmpty(void) const
    { return mOneToTwoMap.isEmpty() || mTwoToOneMap.isEmpty(); }
    int size(void) const
    { return qMin(mOneToTwoMap.size(), mTwoToOneMap.size()); }
    bool contains(const T1 & key) const
    { return mOneToTwoMap.contains(key); }
    bool contains(const T2 & key) const
    { return mTwoToOneMap.contains(key); }
    T2 at(const T1 & key) const
    {	return contains(key) ? mOneToTwoMap.value(key) : T2(); }
    T1 at(const T2 & key) const
    {	return contains(key) ? mTwoToOneMap.value(key) : T1(); }
    QList<T1> all(const T1 & key) const
    { (void)key; return mOneToTwoMap.keys(); }
    QList<T2> all(const T2 & key) const
    { (void)key; return mTwoToOneMap.keys(); }

    bool remove(const T1 & key)
    {
        if (contains(key))
        {
            T2 value = at(key);
            mOneToTwoMap.remove(key);
            if (contains(value))
            {
                mTwoToOneMap.remove(value);
                return true;
            }
        }
        return false;
    } // remove(T1)

    bool remove(const T2 & key)
    {
        if (contains(key))
        {
            T1 value = at(key);
            mTwoToOneMap.remove(key);
            if (contains(value))
            {
                mOneToTwoMap.remove(value);
                return true;
            }
        }
        return false;
    } // remove(T1)

    bool insertUnique(const T1 & t1, const T2 & t2)
    {
        if (contains(t1) || contains(t2))
            return false;
        mOneToTwoMap.insert(t1, t2);
        mTwoToOneMap.insert(t2, t1);
        return true;
    }

private:
    QMap<T1,T2> mOneToTwoMap;
    QMap<T2,T1> mTwoToOneMap;
}; // class DualMap

#endif // DUALMAP_H
