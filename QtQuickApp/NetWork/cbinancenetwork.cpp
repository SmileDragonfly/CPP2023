#include "cbinancenetwork.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>

CBinanceNetwork::CBinanceNetwork(QObject *parent)
    : QObject{parent}
{

}

void CBinanceNetwork::GetKLineData(QString sSymbol, QString sInterval, QObject* objUI)
{
    QNetworkAccessManager * manager = new QNetworkAccessManager();
    QNetworkRequest request;

    QSslConfiguration config = QSslConfiguration::defaultConfiguration();
    request.setSslConfiguration(config);

    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    QObject::connect(manager, SIGNAL(sslErrors(QNetworkReply*,QList<QSslError>)), this, SLOT(replySslErrors(QNetworkReply*,QList<QSslError>)));
    QString sUrl = QString("https://api.binance.com/api/v3/klines?symbol=%1&interval=%2").arg(sSymbol, sInterval);
    request.setUrl(sUrl);
    manager->get(request);
}

void CBinanceNetwork::replyFinished(QNetworkReply* reply)
{
    if (reply->error()) {
        qDebug() << reply->errorString();
        return;
    }

    QString answer = reply->readAll();

    qDebug() << answer;
    //QMetaObject::invokeMethod(objUI, "updateKLineChart", Q_ARG(QString, answer));
}

void CBinanceNetwork::replySslErrors(QNetworkReply *reply, const QList<QSslError> &errors)
{
    if (reply->error()) {
        qDebug() << reply->errorString();
        return;
    }

    QString answer = reply->readAll();

    qDebug() << answer;
}
