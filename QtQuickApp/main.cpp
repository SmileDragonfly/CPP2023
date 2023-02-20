#include <QGuiApplication>
#include <QQmlApplicationEngine>


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    QList<QObject*> lObj = engine.rootObjects();
    for(QObject* obj:lObj)
    {
        qDebug() << "Root Object name:" << obj->objectName();
        QObject* childObject = obj->findChild<QObject*>("ColumnLayout");
        qDebug() << "Child Object name:" << childObject->objectName();
        QMetaObject::invokeMethod(childObject, "updateBalance",
                Q_ARG(QString, "1000"));
    }

    return app.exec();
}
