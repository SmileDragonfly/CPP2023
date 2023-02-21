#ifndef CBINANCENETWORK_H
#define CBINANCENETWORK_H

#include <QObject>
#include <QNetworkReply>

class CBinanceNetwork : public QObject
{
    Q_OBJECT
public:
    explicit CBinanceNetwork(QObject *parent = nullptr);
public:
    void GetKLineData(QString sSymbol, QString sInterval, QObject* objUI);
public slots:
    void replyFinished(QNetworkReply* reply);
    void replySslErrors(QNetworkReply *reply, const QList<QSslError> &errors);
};

#endif // CBINANCENETWORK_H
