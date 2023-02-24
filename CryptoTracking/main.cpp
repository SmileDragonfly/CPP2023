#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "cworker.h"
#include "cconfig.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    // Load config and start worker
    CConfig config;
    config.InitConfigFile("Config.ini");
    CWorker worker;
    worker.Start(&config);

    return app.exec();
}
