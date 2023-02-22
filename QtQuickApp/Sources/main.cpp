#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "NetWork/cbinancenetwork.h"
#include "Connector/cconnector.h"
#include <QSslSocket>
#include "Database/dbmanager.h"


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

    //QList<QObject*> lObj = engine.rootObjects();
    CBinanceNetwork binanceNetwork;
    CDataLayer dataLayer;
    CConnector::ConnectBinanceNetWorkAndDataLayer(&binanceNetwork, &dataLayer);
    CDBManager::OpenDB("crypto.db");
    binanceNetwork.GetSymbolPriceTicker();
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
