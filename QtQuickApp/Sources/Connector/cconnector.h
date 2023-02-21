#ifndef CCONNECTOR_H
#define CCONNECTOR_H

#include <QObject>
#include "Sources/NetWork/cbinancenetwork.h"
#include "Sources/DataLayer/cdatalayer.h"

class CConnector : public QObject
{
    Q_OBJECT
public:
    explicit CConnector(QObject *parent = nullptr);
public:
    static void ConnectBinanceNetWorkAndDataLayer(CBinanceNetwork* pBinanceNetwork, CDataLayer* pDataLayer);

signals:

};

#endif // CCONNECTOR_H
