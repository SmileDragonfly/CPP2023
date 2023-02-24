#ifndef CWORKER_H
#define CWORKER_H

#include <QObject>
#include "cbinancenetwork.h"
#include "dbmanager.h"
#include <QTimer>
#include "cconfig.h"

class CWorker : public QObject
{
    Q_OBJECT
public:
    explicit CWorker(QObject *parent = nullptr);
    void Start(CConfig* pConfig);
private:
    CBinanceNetwork* m_pNetwork;
    CDBManager* m_pDB;
    CConfig* m_pConfig;
    QTimer* m_pTimer;
    QString CalculatePercent(QString sCurPrice, QString sPrevPrice);
    void Calculate1MinPercentBUSD(QString sCurPrice, QString sPrevPrice);
    void Calculate5MinPercentBUSD(QString sCurPrice, QString sPrevPrice);
    void Calculate10MinPercentBUSD(QString sCurPrice, QString sPrevPrice);
    void Calculate15MinPercentBUSD(QString sCurPrice, QString sPrevPrice);
    void Calculate30MinPercentBUSD(QString sCurPrice, QString sPrevPrice);
    void Calculate60MinPercentBUSD(QString sCurPrice, QString sPrevPrice);
signals:
    // DB signals
    void signalCalculate1MinDone(QString sPercent);
    void signalCalculate5MinDone(QString sPercent);
    void signalCalculate10MinDone(QString sPercent);
    void signalCalculate15MinDone(QString sPercent);
    void signalCalculate30MinDone(QString sPercent);
    void signalCalculate60MinDone(QString sPercent);
    void signalGetPriceBUSBDone(QString sPrice);
public slots:
    // network slot
    void slotGetPriceBUSD(QString sAllPrice);
    // timer slot
    void slotGetAllPriceTimer();
};

#endif // CWORKER_H
