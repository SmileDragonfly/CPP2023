#include "cdatalayer.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

CDataLayer::CDataLayer(QObject *parent)
    : QObject{parent}
{

}

void CDataLayer::slotSymbolPriceTicker(QString sPriceData)
{
    qDebug() << "CDataLayer::slotSymbolPriceTicker: sPriceData= " << sPriceData;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(sPriceData.toUtf8());
    QJsonArray jsonArr = jsonDoc.array();
    qDebug() << jsonArr[0].toObject()["symbol"];
    qDebug() << jsonArr[0].toObject()["price"];
}
