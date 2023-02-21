#include "cconnector.h"

CConnector::CConnector(QObject *parent)
    : QObject{parent}
{

}

void CConnector::ConnectBinanceNetWorkAndDataLayer(CBinanceNetwork* pBinanceNetwork, CDataLayer* pDataLayer)
{
    QObject::connect(pBinanceNetwork, &CBinanceNetwork::signalGetSymbolPriceTickerFinished,
            pDataLayer, &CDataLayer::slotSymbolPriceTicker);
}
