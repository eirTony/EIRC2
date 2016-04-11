/*! @file   BasicId.cpp BaseLib BasicId class definitions
 */

#include "BasicId.h"

#include <QtDebug>
#include <QChar>
#include <QString>

#include "Diagnostic.h"

const QChar BasicId::csmDelimChar('/');

#ifdef BUILD_TEST                       ///////// TEST

BasicIdTest::BasicIdTest(QObject * parent)
    : TestObject("BaseLib/BasicId", parent) {;}

void BasicIdTest::ctors(void)
{
    QCOMPARE(nullId.isNull(), true);
    QCOMPARE(oneId.isNull(), false);
    QCOMPARE(twoId.isNull(), false);
    QCOMPARE(treId.isNull(), false);
    QCOMPARE(forId.isNull(), false);
    QCOMPARE(stringId.isNull(), false);
    QCOMPARE(charsId.isNull(), false);
    QCOMPARE(nullId.size(), 0);
    QCOMPARE(oneId.size(), 1);
    QCOMPARE(twoId.size(), 2);
    QCOMPARE(treId.size(), 3);
    QCOMPARE(forId.size(), 4);
    QCOMPARE(stringId.size(), 4);
    QCOMPARE(charsId.size(), 4);
    QCOMPARE(nullId.toString(),     QString());
    QCOMPARE(oneId.toString(),      QString("one"));
    QCOMPARE(twoId.toString('~'),   QString("one~two"));
    QCOMPARE(treId.toString(),      QString("one/two/tre"));
    QCOMPARE(forId.toString(' '),   QString("one two tre for"));
    QCOMPARE(forId.parents(),       treId);
    QCOMPARE(twoId.parent(),        BasicName("one"));

    QCOMPARE(stringId.toString(), idString);

    BasicName superName("0");
    BasicId superId(superName, "MachineInitial");
    QCOMPARE(superId.toString(), QString("0/MachineInitial"));
}
#endif                                  //\\\\\\\ test

BasicId::BasicId(void) {;}

BasicId::BasicId(const BasicName & firstName,
                 const BasicName & secondName,
                 const BasicName & thirdName,
                 const BasicName & fourthName)
{
//    qDebug() << "BasicId::ctor()" << firstName()
  //        << secondName() << thirdName() << fourthName();
    BasicNameList nameList;
    nameList.append(firstName);
    if ( ! secondName.isNull()) nameList.append(secondName);
    if ( ! thirdName.isNull())  nameList.append(thirdName);
    if ( ! fourthName.isNull()) nameList.append(fourthName);
    set(nameList);
    //qDebug() << "BasicId result {" << toString() << "}";
}


BasicId::BasicId(const QString & string, QChar delimiter)
{
    set(string, delimiter);
}

BasicId::BasicId(const char * const chars)
{
    set(QString::fromLocal8Bit(chars));
}

// private
BasicId::BasicId(const BasicNameList &otherList)
{
    set(otherList);
}

#ifdef BUILD_TEST                       ///////// TEST
void BasicIdTest::set(void)
{
    BasicId id;
    QCOMPARE(id.isNull(), true);

    id.set(idString);
    QCOMPARE(id.isNull(), false);
    QCOMPARE(id.size(), 4);
    QCOMPARE(id.at(2).size(), 1);
    QCOMPARE(id.at(3).size(), 4);

    id.set(1, "aint");
    QCOMPARE(id.at(1).size(), 4);
    id.set(4, "oops");
    QCOMPARE(id.toString(), QString("this/aint/a/test/oops"));
    id.set(7, "seven");
    QCOMPARE(id.toString(), QString("this/aint/a/test/oops"));

    BasicId keyId("Super/0/Sub/0");
    QCOMPARE(keyId.at(1), BasicName());
    QCOMPARE(keyId.at(1), BasicName(""));
}

void BasicIdTest::white(void)
{
    QString string = idString;
    string.replace('/', " \t\r\n    ");
    BasicId id(string, ' ');
    QCOMPARE(id.toString(), idString);
    QCOMPARE(id.toString(' '), QString("this is a test"));
}                                       // \\\\\ Test
#endif                                  //\\\\\\\ test

void BasicId::set(const QString & string, QChar delimiter)
{
    if (delimiter.isNull()) delimiter = csmDelimChar;
    BasicNameList nameList;
    QStringList qsl(string.simplified().split(delimiter));
    foreach (QString s, qsl)
        nameList.append(BasicName(s));
    set(nameList);
}

// private
void BasicId::set(const BasicNameList & nameList)
{
    mNameList.clear();
    foreach (BasicName name, nameList)
        mNameList.append("0" == name
                         ? BasicName()
                         : name);
}

void BasicId::set(const int index, const BasicName name)
{
    int size = mNameList.size();
    if (index == size)
        append(name);
    else if (index >= 0 && index < size)
        mNameList[index] = "0"==name ? BasicName() : name;
    // else nada
}

QString BasicId::toString(const QChar separator) const
{
    return toString(mNameList, separator);
}

// static
QString BasicId::toString(const BasicNameList & nameList,
                          QChar separator)
{
    QString string;
    if (separator.isNull()) separator = csmDelimChar;
    foreach (BasicName name, nameList)
    {
        string += string.isEmpty() ? QString() : QString(separator);
        string += name.isNull() ? "0" : QString(name);
    }
    return string;
}

QString BasicId::operator () (void) const
{
    return toString();
}

BasicId::operator QString (void) const
{
    return toString();
}

BasicName BasicId::at(const int index) const
{
    return (index >= 0 && index < size())
            ? mNameList.at(index)
            : BasicName();
}

BasicName BasicId::name(void) const
{
    return mNameList.last();
}

BasicName BasicId::parent(void) const
{
    int k = size();
    return (k > 1 && k < 5) ? at(k-2) : BasicName();
}

BasicId BasicId::parents(void) const
{
    BasicNameList resultNameList = mNameList;
    (void)resultNameList.takeLast();
    return resultNameList;
}

int BasicId::size(void) const
{
    return mNameList.size();
}

bool BasicId::isNull(void) const
{
    return mNameList.isEmpty();
}

BasicNameList BasicId::toList(void) const
{
    return mNameList;
}

bool BasicId::operator < (const BasicId & rhs) const
{
    return toString() < rhs.toString();
}

bool BasicId::operator == (const BasicId & rhs) const
{
    return toString() == rhs.toString();
}

// private
void BasicId::append(const BasicName & name)
{
    mNameList.append("0"==name ? BasicName() : name);
}

BasicId & BasicId::operator += (const BasicName name)
{
    append(name);
    return *this;
}
