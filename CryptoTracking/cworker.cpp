#include "cworker.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

CWorker::CWorker(QObject *parent)
    : QObject{parent}
{
    m_pNetwork = new CBinanceNetwork();
    m_pDB = new CDBManager();
    m_pDB->OpenDB("crypto.db");
    m_pTimer = new QTimer();
    // Connect network and worker to get price for BUSD
    QObject::connect(m_pNetwork, &CBinanceNetwork::signalGetSymbolPriceTickerFinished, this, &CWorker::slotGetPriceBUSD);
    // Connect worker to DB to insert price in BUSD
    QObject::connect(this, &CWorker::signalGetPriceBUSBDone, m_pDB, &CDBManager::slotInsertToTblBUSDPrice);
    // Connect worker to DB to insert percent change in time
    QObject::connect(this, &CWorker::signalCalculate1MinDone, m_pDB, &CDBManager::slotInsert1MinBUSD);
    QObject::connect(this, &CWorker::signalCalculate5MinDone, m_pDB, &CDBManager::slotInsert5MinBUSD);
    QObject::connect(this, &CWorker::signalCalculate10MinDone, m_pDB, &CDBManager::slotInsert10MinBUSD);
    QObject::connect(this, &CWorker::signalCalculate15MinDone, m_pDB, &CDBManager::slotInsert15MinBUSD);
    QObject::connect(this, &CWorker::signalCalculate30MinDone, m_pDB, &CDBManager::slotInsert30MinBUSD);
    QObject::connect(this, &CWorker::signalCalculate60MinDone, m_pDB, &CDBManager::slotInsert60MinBUSD);
    // Connect timeout signal with worker to get all price
    QObject::connect(m_pTimer, &QTimer::timeout, this, &CWorker::slotGetAllPriceTimer);
}

void CWorker::Start(CConfig* pConfig)
{
    m_pConfig = pConfig;
    m_pNetwork->GetSymbolPriceTicker();
    m_pTimer->setInterval(m_pConfig->IntervalSymbolPrice() * 1000); // milli senconds
    m_pTimer->start();
}

// Input :[{"price":"310.60000000","symbol":"BNBBUSD"},
//          {"price":"23884.95000000","symbol":"BTCBUSD"},
//          {"price":"0.38880000","symbol":"XRPBUSD"}, ..]
// Output:[{"symbol": "BNBBUSD", "price": 300, "prevPrice": 301, "percent": 2},
//              {"symbol": "BNBBUSD", "price": 300, "prevPrice": 301, "percent": 2}]
QString CWorker::CalculatePercent(QString sCurPrice, QString sPrevPrice)
{
    QString sRet("");
    if (sCurPrice.isEmpty() || sPrevPrice.isEmpty())
    {
        return sRet;
    }
    else
    {
        QJsonDocument jsonDocCurr = QJsonDocument::fromJson(sCurPrice.toUtf8());
        QJsonDocument jsonDocPrev = QJsonDocument::fromJson(sPrevPrice.toUtf8());
        QJsonArray arrCurr = jsonDocCurr.array();
        QJsonArray arrPrev = jsonDocPrev.array();
        QJsonArray arrRet;
        foreach (auto it, arrCurr)
        {
            QJsonObject objRet;
            QJsonObject obj = it.toObject();
            QString sSymbol = obj.value("symbol").toString();
            double fCurPrice = obj.value("price").toDouble();
            foreach (auto itPrev, arrPrev)
            {
                QJsonObject objPrev = itPrev.toObject();
                QString sSymbolPrev = objPrev.value("symbol").toString();
                if (sSymbol == sSymbolPrev)
                {
                    double fPrevPrice = objPrev.value("price").toDouble();
                    double fPercent = (fCurPrice - fPrevPrice) / fPrevPrice;
                    objRet["symbol"] = sSymbol;
                    objRet["price"] = fCurPrice;
                    objRet["prevPrice"] = fPrevPrice;
                    objRet["percent"] = fPercent;
                    arrRet.append(objRet);
                }
            }
        }
        QJsonDocument jsonDocRet;
        jsonDocRet.setArray(arrRet);
        sRet = jsonDocRet.toJson(QJsonDocument::Compact);
        return sRet;
    }
}

void CWorker::Calculate1MinPercentBUSD(QString sCurPrice, QString sPrevPrice)
{
    QString sPercent = CalculatePercent(sCurPrice, sPrevPrice);
    if (sPercent.isEmpty())
    {
        qDebug() << __FUNCTION__;
    }
    // Emit signal to insert percent to DB
    emit signalCalculate1MinDone(sPercent);
}

void CWorker::Calculate5MinPercentBUSD(QString sCurPrice, QString sPrevPrice)
{
    QString sPercent = CalculatePercent(sCurPrice, sPrevPrice);
    if (sPercent.isEmpty())
    {
        qDebug() << __FUNCTION__;
    }
    // Emit signal to insert percent to DB
    emit signalCalculate5MinDone(sPercent);
}

void CWorker::Calculate10MinPercentBUSD(QString sCurPrice, QString sPrevPrice)
{
    QString sPercent = CalculatePercent(sCurPrice, sPrevPrice);
    if (sPercent.isEmpty())
    {
        qDebug() << __FUNCTION__;
    }
    // Emit signal to insert percent to DB
    emit signalCalculate10MinDone(sPercent);
}

void CWorker::Calculate15MinPercentBUSD(QString sCurPrice, QString sPrevPrice)
{
    QString sPercent = CalculatePercent(sCurPrice, sPrevPrice);
    if (sPercent.isEmpty())
    {
        qDebug() << __FUNCTION__;
    }
    // Emit signal to insert percent to DB
    emit signalCalculate15MinDone(sPercent);
}

void CWorker::Calculate30MinPercentBUSD(QString sCurPrice, QString sPrevPrice)
{
    QString sPercent = CalculatePercent(sCurPrice, sPrevPrice);
    if (sPercent.isEmpty())
    {
        qDebug() << __FUNCTION__;
    }
    // Emit signal to insert percent to DB
    emit signalCalculate30MinDone(sPercent);
}

void CWorker::Calculate60MinPercentBUSD(QString sCurPrice, QString sPrevPrice)
{
    QString sPercent = CalculatePercent(sCurPrice, sPrevPrice);
    if (sPercent.isEmpty())
    {
        qDebug() << __FUNCTION__;
    }
    // Emit signal to insert percent to DB
    emit signalCalculate60MinDone(sPercent);
}

void CWorker::slotGetAllPriceTimer()
{
    m_pNetwork->GetSymbolPriceTicker();
}

void CWorker::slotGetPriceBUSD(QString sAllPrice)
{
    QString sBUSDPrice;
    // Process json data to get current price in BUSD
    QJsonDocument jsonDoc = QJsonDocument::fromJson(sAllPrice.toUtf8());
    QJsonArray jsonArr = jsonDoc.array();
    QJsonArray jsonArrBUSD;
    for (QJsonArray::iterator it = jsonArr.begin(); it != jsonArr.end(); it++)
    {
        if (it->toObject().value("symbol").toString().contains(QRegularExpression("BUSD$")))
        {
            jsonArrBUSD.push_back(*it);
        }
    }
    QJsonDocument jsonDocBUSD;
    jsonDocBUSD.setArray(jsonArrBUSD);
    sBUSDPrice = jsonDocBUSD.toJson(QJsonDocument::Compact);
    // Get previous price
    QString sPrice1MinAgo = m_pDB->Get1MinAgoPriceBUSD();
    QString sPrice5MinAgo = m_pDB->Get5MinAgoPriceBUSD();
    QString sPrice10MinAgo = m_pDB->Get10MinAgoPriceBUSD();
    QString sPrice15MinAgo = m_pDB->Get15MinAgoPriceBUSD();
    QString sPrice30MinAgo = m_pDB->Get30MinAgoPriceBUSD();
    QString sPrice60MinAgo = m_pDB->Get60MinAgoPriceBUSD();
    Calculate1MinPercentBUSD(sBUSDPrice, sPrice1MinAgo);
    Calculate5MinPercentBUSD(sBUSDPrice, sPrice5MinAgo);
    Calculate10MinPercentBUSD(sBUSDPrice, sPrice10MinAgo);
    Calculate15MinPercentBUSD(sBUSDPrice, sPrice15MinAgo);
    Calculate30MinPercentBUSD(sBUSDPrice, sPrice30MinAgo);
    Calculate60MinPercentBUSD(sBUSDPrice, sPrice60MinAgo);
    // Emit signal to insert current price to DB
    emit signalGetPriceBUSBDone(sBUSDPrice);
}
