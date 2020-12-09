#include <QtTest/QtTest>
//This is inly supposed to be a demonstration of unit tests in QtCreator

class TestQString: public QObject
{
    Q_OBJECT
private slots:
    void toUpper();
    void toUpper_data();
};

void TestQString::toUpper()
{
    QFETCH(QString, string);
    QFETCH(QString, result);

    QCOMPARE(string.toUpper(), result);
}

/* The name ending with "_data" is important
 * This suffix indicates the use of the function without "_data" to
 * test many inputs and outputs. */
void TestQString::toUpper_data()
{
    QTest::addColumn<QString>("string");
    QTest::addColumn<QString>("result");

    QTest::newRow("all lower") << "hello" << "HELLO";
    QTest::newRow("mixed")     << "Hello" << "HELLO";
    QTest::newRow("all upper") << "HELLO" << "HELLO";
}


QTEST_MAIN(TestQString)
#include "testqstring.moc"
