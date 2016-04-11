#include "TestObject.h"

#include "Diagnostic.h"

QMap<QString, TestObject *> TestObject::smIdTestMap;

TestObject::TestObject(const QString & testId,
                       QObject * parent)
    : QObject(parent)
    , mTestId(testId)
{
    smIdTestMap.insert(testId, this);
}

QString TestObject::testId(void) const
{
    return mTestId;
}

int TestObject::exec(const QVariantMap & options,
                     const QStringList & arguments)
{
    mOptionMap = options;
    return QTest::qExec(this, arguments);
}

int TestObject::execAll(const QVariantMap & options,
                        const QStringList & arguments,
                        const bool andRemove)
{
    TRACE("TestObject::execAll() %1 elements", smIdTestMap.size());

    int fail = -1;

    QList<TestObject *> testObjectList(smIdTestMap.values());
    foreach (TestObject * tobj, testObjectList)
    {
        QStringList qsl(arguments);
        qsl.prepend("-silent");
        fail = tobj->exec(options, qsl);
        if (fail)
        {
            TRACE("*** Test %1 FAILED! [%2]",
                  tobj->testId(), fail);
            break; // -------------------------------
        }
        else
        {
            INFO("--- Test %1 passed", tobj->testId());
        }

    }

    if (andRemove) smIdTestMap.clear();
    return fail;
}
