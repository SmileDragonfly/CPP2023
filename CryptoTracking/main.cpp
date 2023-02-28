#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "cworker.h"
#include "cconfig.h"
#include <QThread>

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QCoreApplication app(argc, argv);

    //QQmlApplicationEngine engine;
    //engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    //if (engine.rootObjects().isEmpty())
    //    return -1;
    // Load config and start worker
    CConfig config;
    config.InitConfigFile("Config.ini");
    CWorker worker;
    QThread workerThread;
    worker.moveToThread(&workerThread);
    workerThread.start();
    worker.Start(&config);

    return app.exec();
}
