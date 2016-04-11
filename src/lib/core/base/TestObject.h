#ifndef TESTOBJECT_H
#define TESTOBJECT_H
#include "BaseLib.h"

#include <QObject>

#include <QtTest/QtTest>
#include <QMap>
#include <QString>

/*!
 * \brief The TestObject class
 *
 * Top of class under test .h files:
 * \code

class BasicKeyTest : public TestObject
{
    Q_OBJECT
public:
    BasicKeyTest(QObject * parent=0);

private slots:
    void setUpperLower(void);
};

 * \endcode
 *
 * Within class under test .cpp files:
 * \code
void BasicKeyTest::setUpperLower(void)
{
    BasicKey bk;
    QCOMPARE(bk.isNull(), true);
    QCOMPARE(bk.isZero(), true);
}
 * \endcode
 *
 * In library base class .h file: (for now)
 * \code
virtual void doExec(void);
 * \endcode
 *
 * In library base class .cpp file:
 * \code
void BaseLib::doExec(void) // later doTest();
{
    BasicKeyTest basicKeyTest; // for each class under test
    TestObject::execAll(); // once
}
 * \endcode
 */

class BASESHARED_EXPORT TestObject : public QObject
{
    Q_OBJECT
public:
    explicit TestObject(const QString & testId,
                        QObject * parent=0);
    QString testId(void) const;
    int exec(const QVariantMap & options,
             const QStringList & arguments);

public: // static
    static int execAll(const QVariantMap & options
                                =QVariantMap(),
                       const QStringList & arguments=QStringList(),
                       const bool andRemove=true);

signals:

public slots:

private slots: // tests live here

private:
    QString mTestId;
    QVariantMap mOptionMap;

private: // static
    static QMap<QString, TestObject *> smIdTestMap;
};


#define TESTOBJ(cls) { cls test; (void)test; }

#endif // TESTOBJECT_H
