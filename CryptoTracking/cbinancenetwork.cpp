#include "cbinancenetwork.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>

CBinanceNetwork::CBinanceNetwork(QObject *parent)
    : QObject{parent}
{
    m_pNetworkManager = new QNetworkAccessManager();
    m_pNetworkRequest = new QNetworkRequest();
    QObject::connect(m_pNetworkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slotGetSymbolPriceTickerFinished(QNetworkReply*)));
    QSslConfiguration config = QSslConfiguration::defaultConfiguration();
    m_pNetworkRequest->setSslConfiguration(config);
}

void CBinanceNetwork::GetSymbolPriceTicker(QString sSymbol)
{
    QString sUrl = QString("https://api.binance.com/api/v3/ticker/price");
    if (!sSymbol.isEmpty())
    {
        sUrl = QString("https://api.binance.com/api/v3/ticker/price?symbol=%1").arg(sSymbol);
    }
    m_pNetworkRequest->setUrl(sUrl);
    m_pNetworkManager->get(*m_pNetworkRequest);
}

void CBinanceNetwork::slotGetSymbolPriceTickerFinished(QNetworkReply* reply)
{
    if (reply->error()) {
        qDebug() << reply->errorString();
        return;
    }
    QString answer = reply->readAll();
    // qDebug() << "CBinanceNetwork::slotGetSymbolPriceTickerFinished: Answer= " << answer;
    emit signalGetSymbolPriceTickerFinished(answer);
}
