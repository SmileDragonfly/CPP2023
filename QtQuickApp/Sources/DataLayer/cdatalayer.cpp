#include "cdatalayer.h"
#include <QDebug>

CDataLayer::CDataLayer(QObject *parent)
    : QObject{parent}
{

}

void CDataLayer::slotSymbolPriceTicker(QString sPriceData)
{
    qDebug() << "CDataLayer::slotSymbolPriceTicker: sPriceData= " << sPriceData;
}
