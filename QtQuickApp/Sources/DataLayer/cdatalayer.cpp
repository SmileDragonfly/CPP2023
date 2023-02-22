#include "cdatalayer.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include "Sources/Database/dbmanager.h"

CDataLayer::CDataLayer(QObject *parent)
    : QObject{parent}
{

}

void CDataLayer::slotSymbolPriceTicker(QString sPriceData)
{
    //qDebug() << "CDataLayer::slotSymbolPriceTicker: sPriceData= " << sPriceData;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(sPriceData.toUtf8());
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
    qDebug() << jsonArrBUSD;
    qDebug() << jsonDocBUSD;
    CDBManager::InsertToTblPriceBUSD(jsonDocBUSD.toJson(QJsonDocument::Compact));
    //qDebug() << jsonArrBUSD.size();
}
