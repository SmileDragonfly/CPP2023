#ifndef CBINANCENETWORK_H
#define CBINANCENETWORK_H

#include <QObject>

class CBinanceNetwork : public QObject
{
    Q_OBJECT
public:
    explicit CBinanceNetwork(QObject *parent = nullptr);
public:
    void GetKLineData(QString sSymbol, QString sInterval, QObject* objUI);
signals:

};

#endif // CBINANCENETWORK_H
