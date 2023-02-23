#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "NetWork/cbinancenetwork.h"
#include "Connector/cconnector.h"
#include <QSslSocket>
#include "Database/dbmanager.h"
#include "CConfig.h"
#include <QThread>
#include <QTimer>


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

    // Load config file
    CConfig config;
    config.InitConfigFile("Config.ini");

    // Create thread to get binance data
    CBinanceNetwork* binanceNetwork = new CBinanceNetwork();
    CDataLayer* dataLayer = new CDataLayer();
    CConnector::ConnectBinanceNetWorkAndDataLayer(binanceNetwork, dataLayer);
    CDBManager::OpenDB("crypto.db");

    QTimer* dataTimer = new QTimer();
    QObject::connect(dataTimer, SIGNAL(timeout()), binanceNetwork, SLOT(slotGetSymbolPriceTickerOnTimer()));
    dataTimer->setInterval(config.IntervalSymbolPrice() * 1000);
    dataTimer->start();

    //QList<QObject*> lObj = engine.rootObjects();
    //binanceNetwork.GetSymbolPriceTicker();
    //for(QObject* obj:lObj)
    //{
    //    qDebug() << "Root Object name:" << obj->objectName();
    //    QObject* childObject = obj->findChild<QObject*>("ColumnLayout");
    //    binanceNetwork.SetUIObject(childObject);

    //    qDebug() << "Support ssl: " << QSslSocket::supportsSsl();
    //    QList<QString> lBackends = QSslSocket::availableBackends();
    //    for (const QString &sBackend : qAsConst(lBackends))
    //    {
    //        qDebug() << "Back end: " << sBackend;
    //    }

    //    qDebug() << "SSL version: " << QSslSocket::sslLibraryBuildVersionString();
    //    binanceNetwork.GetKLineData("BNBUSDT", "1m");
    //}
    return app.exec();
}
