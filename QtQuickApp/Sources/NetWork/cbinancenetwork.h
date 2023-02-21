#ifndef CBINANCENETWORK_H
#define CBINANCENETWORK_H

#include <QObject>
#include <QNetworkReply>

class CBinanceNetwork : public QObject
{
    Q_OBJECT
private:
    QNetworkAccessManager* m_pNetworkManager;
    QNetworkRequest*  m_pNetworkRequest;
public:
    explicit CBinanceNetwork(QObject *parent = nullptr);
public:
    void GetKLineData(QString sSymbol, QString sInterval);
    void GetSymbolPriceTicker(QString sSymbol = "");
signals:
    void signalGetSymbolPriceTickerFinished(QString reply);
public slots:
    void slotGetKLineDataFinished(QNetworkReply* reply);
    void slotGetSymbolPriceTickerFinished(QNetworkReply* reply);
};

#endif // CBINANCENETWORK_H
