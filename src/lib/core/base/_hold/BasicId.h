/*! @file   BasicId.h   BaseLib: BasicId declaration
 */
#ifndef BASICID_H
#define BASICID_H
#include "pdzBase.h"

#include <QList>
#include <QMap>
#include <QString>
#include <QVariant>

#include "BasicName.h"
//#include "TestObject.h"



class PDZBASESHARED_EXPORT BasicId
{
public:
    typedef QList<BasicId> List;
    typedef QMap<BasicId, QVariant> VariantMap;

public:
    BasicId(void);
    BasicId(const BasicName & firstName,
            const BasicName & secondName=BasicName(),
            const BasicName & thirdName=BasicName(),
            const BasicName & fourthName=BasicName());
    BasicId(const QString & string, QChar delimiter=QChar());
    BasicId(const char * const chars);

    void set(const QString & string, QChar delimiter=QChar());
    void set(const int index, const BasicName name);
    QString toString(const QChar separator=QChar()) const;
    QString operator () (void) const;
    operator QString (void) const;
    BasicName at(const int index) const;
    BasicName name(void) const;
    BasicName parent(void) const;
    BasicId parents(void) const;
    int size(void) const;
    bool isNull(void) const;
    bool operator <  (const BasicId & rhs) const;
    bool operator == (const BasicId & rhs) const;
    BasicId & operator += (const BasicName name);

private:
    BasicId(const BasicNameList & otherList);
    void set(const BasicNameList & nameList);
    void append(const BasicName & name);

private: // static
    static QString toString (const BasicNameList &nameList,
                             QChar separator=QChar());

private:
    const static QChar csmDelimChar;
    BasicNameList mNameList;
};
/*! @class BasicId <core/BasicId.h.
 * @brief BasicId class provides a multipart identification string
 * @since BasicId was strted in v2.02
 * @ingroup BaseLib
 * @sa BasicName
 * @sa BasicKey
 *
 * BasicId instances are a sequence of BasicName instances separated
 * by a '/' segment delimtor.
 */
Q_DECLARE_TYPEINFO(BasicId, Q_PRIMITIVE_TYPE);

typedef BasicId::VariantMap BasicIdVariantMap;

#if 0
class BasicIdTest : public TestObject
{
    Q_OBJECT
public:
    BasicIdTest(QObject * parent=0);

private slots:
    void ctors(void);
    void set(void);
    void white(void);

private:
    BasicId nullId;
    BasicName oneName = BasicName("one");
    BasicName twoName = BasicName("two");
    BasicName treName = BasicName("tre");
    BasicName forName = BasicName("for");
    BasicId oneId = BasicId(oneName);
    BasicId twoId = BasicId(oneName, twoName);
    BasicId treId = BasicId(oneName, twoName, treName);
    BasicId forId = BasicId(oneName, twoName, treName, forName);
    QString idString = QString("this/is/a/test");
    BasicId stringId = BasicId(idString);
    BasicId charsId = BasicId("that/was/a/test");
};
#endif

#endif // BASICID_H
