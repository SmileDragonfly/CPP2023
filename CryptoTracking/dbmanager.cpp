#include "dbmanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QJsonDocument>
#include <QJsonArray>
#include <QSqlDriver>
#include <QJsonObject>

CDBManager::CDBManager(QObject *parent)
    : QObject{parent}
{

}

bool CDBManager::IsOpen()
{
    return m_db.isOpen();
}

void CDBManager::SetDB(QString sPath)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(sPath);
}

bool CDBManager::OpenDB()
{
    if (!m_db.open())
    {
        qDebug() << "DBManager::OpenSQLite: Connection with database failed";
        return false;
    }
    else
    {
        qDebug() << "DBManager::OpenSQLite: Support transaction: " << m_db.driver()->hasFeature(QSqlDriver::Transactions);
        qDebug() << "DBManager::OpenSQLite: Connection ok";
        return true;
    }
}

void CDBManager::CloseDB()
{
    m_db.close();
}

QString CDBManager::Get1MinAgoPriceBUSD()
{
    QSqlQuery query;
    query.prepare("Select * from tblBUSDPrice where timestamp > Datetime('now', '-61 seconds') order by timestamp asc LIMIT 1");
    if (query.exec())
    {
        if (query.next())
        {
            qDebug() << "CDBManager::Get1MinAgoPriceBUSD: " << query.value(1).toString();
            QString price = query.value(2).toString();
            return price;
        }
    }
    else
    {
        qDebug() << "DBManager::Get1MinAgoPriceBUSD: " << query.lastError();
    }
    return "";
}

QString CDBManager::Get5MinAgoPriceBUSD()
{
    QSqlQuery query;
    query.prepare("Select * from tblBUSDPrice where timestamp > Datetime('now', '-301 seconds') order by timestamp asc LIMIT 1");
    if (query.exec())
    {
        if (query.next())
        {
            qDebug() << "CDBManager::Get5MinAgoPriceBUSD: " << query.value(1).toString();
            QString price = query.value(2).toString();
            return price;
        }
    }
    else
    {
        qDebug() << "DBManager::Get5MinAgoPriceBUSD: " << query.lastError();
    }
    return "";
}

QString CDBManager::Get10MinAgoPriceBUSD()
{
    QSqlQuery query;
    query.prepare("Select * from tblBUSDPrice where timestamp > Datetime('now', '-601 seconds') order by timestamp asc LIMIT 1");
    if (query.exec())
    {
        if (query.next())
        {
            qDebug() << "CDBManager::Get10MinAgoPriceBUSD: " << query.value(1).toString();
            QString price = query.value(2).toString();
            return price;
        }
    }
    else
    {
        qDebug() << "DBManager::Get10MinAgoPriceBUSD: " << query.lastError();
    }
    return "";
}

QString CDBManager::Get15MinAgoPriceBUSD()
{
    QSqlQuery query;
    query.prepare("Select * from tblBUSDPrice where timestamp > Datetime('now', '-901 seconds') order by timestamp asc LIMIT 1");
    if (query.exec())
    {
        if (query.next())
        {
            qDebug() << "CDBManager::Get15MinAgoPriceBUSD: " << query.value(1).toString();
            QString price = query.value(2).toString();
            return price;
        }
    }
    else
    {
        qDebug() << "DBManager::Get15MinAgoPriceBUSD: " << query.lastError();
    }
    return "";
}

QString CDBManager::Get30MinAgoPriceBUSD()
{
    QSqlQuery query;
    query.prepare("Select * from tblBUSDPrice where timestamp > Datetime('now', '-1801 seconds') order by timestamp asc LIMIT 1");
    if (query.exec())
    {
        if (query.next())
        {
            qDebug() << "CDBManager::Get30MinAgoPriceBUSD: " << query.value(1).toString();
            QString price = query.value(2).toString();
            return price;
        }
    }
    else
    {
        qDebug() << "DBManager::Get30MinAgoPriceBUSD: " << query.lastError();
    }
    return "";
}

QString CDBManager::Get60MinAgoPriceBUSD()
{
    QSqlQuery query;
    query.prepare("Select * from tblBUSDPrice where timestamp > Datetime('now', '-3601 seconds') order by timestamp asc LIMIT 1");
    if (query.exec())
    {
        if (query.next())
        {
            qDebug() << "CDBManager::Get60MinAgoPriceBUSD: " << query.value(1).toString();
            QString price = query.value(2).toString();
            return price;
        }
    }
    else
    {
        qDebug() << "DBManager::Get60MinAgoPriceBUSD: " << query.lastError();
    }
    return "";
}

// sPercent:
// Json array: [{"symbol": "BNBBUSD", "price": 300, "prevPrice": 301, "percent": 2},
//              {"symbol": "BNBBUSD", "price": 300, "prevPrice": 301, "percent": 2}]
void CDBManager::slotInsert1MinBUSD(QString sPercent)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(sPercent.toUtf8());
    QJsonArray arrData = jsonDoc.array();
    if (arrData.size() == 0)
    {
        qDebug() << __FUNCTION__;
        return;
    }

    // Begin db transaction
    m_db.transaction();
    QSqlQuery query;
    query.prepare("Delete from tblBUSD1MinPercent");
    query.exec();
    query.prepare("Insert into tblBUSD1MinPercent (symbol, price, prevPrice, percent) VALUES (:symbol, :price, :prevPrice, :percent)");
    foreach(auto it, arrData)
    {
        QJsonObject obj = it.toObject();
        QString symbol = obj.value("symbol").toString();
        float price = obj.value("price").toDouble();
        float prevPrice = obj.value("prevPrice").toDouble();
        float percent = obj.value("percent").toDouble();
        query.bindValue(":symbol", symbol);
        query.bindValue(":price", price);
        query.bindValue(":prevPrice", prevPrice);
        query.bindValue(":percent", percent);
        query.exec();
    }
    m_db.commit();
}

void CDBManager::slotInsert5MinBUSD(QString sPercent)
{

    QJsonDocument jsonDoc = QJsonDocument::fromJson(sPercent.toUtf8());
    QJsonArray arrData = jsonDoc.array();
    if (arrData.size() == 0)
    {
        qDebug() << __FUNCTION__;
        return;
    }
    // Begin db transaction
    m_db.transaction();
    QSqlQuery query;
    query.prepare("Delete from tblBUSD5MinPercent");
    query.exec();
    query.prepare("Insert into tblBUSD5MinPercent (symbol, price, prevPrice, percent) VALUES (:symbol, :price, :prevPrice, :percent)");
    foreach(auto it, arrData)
    {
        QJsonObject obj = it.toObject();
        QString symbol = obj.value("symbol").toString();
        double price = obj.value("price").toDouble();
        double prevPrice = obj.value("prevPrice").toDouble();
        double percent = obj.value("percent").toDouble();
        query.bindValue(":symbol", symbol);
        query.bindValue(":price", price);
        query.bindValue(":prevPrice", prevPrice);
        query.bindValue(":percent", percent);
        query.exec();
    }
    m_db.commit();
}

void CDBManager::slotInsert10MinBUSD(QString sPercent)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(sPercent.toUtf8());
    QJsonArray arrData = jsonDoc.array();
    if (arrData.size() == 0)
    {
        qDebug() << __FUNCTION__;
        return;
    }
    // Begin db transaction
    m_db.transaction();
    QSqlQuery query;
    query.prepare("Delete from tblBUSD10MinPercent");
    query.exec();
    query.prepare("Insert into tblBUSD10MinPercent (symbol, price, prevPrice, percent) VALUES (:symbol, :price, :prevPrice, :percent)");
    foreach(auto it, arrData)
    {
        QJsonObject obj = it.toObject();
        QString symbol = obj.value("symbol").toString();
        double price = obj.value("price").toDouble();
        double prevPrice = obj.value("prevPrice").toDouble();
        double percent = obj.value("percent").toDouble();
        query.bindValue(":symbol", symbol);
        query.bindValue(":price", price);
        query.bindValue(":prevPrice", prevPrice);
        query.bindValue(":percent", percent);
        query.exec();
    }
    m_db.commit();
}

void CDBManager::slotInsert15MinBUSD(QString sPercent)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(sPercent.toUtf8());
    QJsonArray arrData = jsonDoc.array();
    if (arrData.size() == 0)
    {
        qDebug() << __FUNCTION__;
        return;
    }
    // Begin db transaction
    m_db.transaction();
    QSqlQuery query;
    query.prepare("Delete from tblBUSD15MinPercent");
    query.exec();
    query.prepare("Insert into tblBUSD15MinPercent (symbol, price, prevPrice, percent) VALUES (:symbol, :price, :prevPrice, :percent)");
    foreach(auto it, arrData)
    {
        QJsonObject obj = it.toObject();
        QString symbol = obj.value("symbol").toString();
        double price = obj.value("price").toDouble();
        double prevPrice = obj.value("prevPrice").toDouble();
        double percent = obj.value("percent").toDouble();
        query.bindValue(":symbol", symbol);
        query.bindValue(":price", price);
        query.bindValue(":prevPrice", prevPrice);
        query.bindValue(":percent", percent);
        query.exec();
    }
    m_db.commit();
}

void CDBManager::slotInsert30MinBUSD(QString sPercent)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(sPercent.toUtf8());
    QJsonArray arrData = jsonDoc.array();
    if (arrData.size() == 0)
    {
        qDebug() << __FUNCTION__;
        return;
    }
    // Begin db transaction
    m_db.transaction();
    QSqlQuery query;
    query.prepare("Delete from tblBUSD30MinPercent");
    query.exec();
    query.prepare("Insert into tblBUSD30MinPercent (symbol, price, prevPrice, percent) VALUES (:symbol, :price, :prevPrice, :percent)");
    foreach(auto it, arrData)
    {
        QJsonObject obj = it.toObject();
        QString symbol = obj.value("symbol").toString();
        double price = obj.value("price").toDouble();
        double prevPrice = obj.value("prevPrice").toDouble();
        double percent = obj.value("percent").toDouble();
        query.bindValue(":symbol", symbol);
        query.bindValue(":price", price);
        query.bindValue(":prevPrice", prevPrice);
        query.bindValue(":percent", percent);
        query.exec();
    }
    m_db.commit();
}

void CDBManager::slotInsert60MinBUSD(QString sPercent)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(sPercent.toUtf8());
    QJsonArray arrData = jsonDoc.array();
    if (arrData.size() == 0)
    {
        qDebug() << __FUNCTION__;
        return;
    }
    // Begin db transaction
    m_db.transaction();
    QSqlQuery query;
    query.prepare("Delete from tblBUSD60MinPercent");
    query.exec();
    query.prepare("Insert into tblBUSD60MinPercent (symbol, price, prevPrice, percent) VALUES (:symbol, :price, :prevPrice, :percent)");
    foreach(auto it, arrData)
    {
        QJsonObject obj = it.toObject();
        QString symbol = obj.value("symbol").toString();
        double price = obj.value("price").toDouble();
        double prevPrice = obj.value("prevPrice").toDouble();
        double percent = obj.value("percent").toDouble();
        query.bindValue(":symbol", symbol);
        query.bindValue(":price", price);
        query.bindValue(":prevPrice", prevPrice);
        query.bindValue(":percent", percent);
        query.exec();
    }
    m_db.commit();
}

void CDBManager::slotInsertToTblBUSDPrice(QString sPrice)
{
    QSqlQuery query;
    query.prepare("Insert into tblBUSDPrice (price) VALUES (:price)");
    query.bindValue(":price", sPrice);
    if (!query.exec())
    {
        qDebug() << "DBManager::InsertTotblBUSDPrice: Insert price failed. Error=" << query.lastError();
        return;
    }
}
