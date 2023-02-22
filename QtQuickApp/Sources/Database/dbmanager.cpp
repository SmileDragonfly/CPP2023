#include "dbmanager.h"
#include <QSqlQuery>
#include <QSqlError>

QSqlDatabase CDBManager::m_db;

CDBManager::CDBManager(QObject *parent)
    : QObject{parent}
{

}

bool CDBManager::IsOpen()
{
    return m_db.isOpen();
}

bool CDBManager::OpenDB(QString sPath)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(sPath);
    if (!m_db.open())
    {
        qDebug() << "DBManager::OpenSQLite: Connection with database failed";
        return false;
    }
    else
    {
        qDebug() << "DBManager::OpenSQLite: Connection ok";
        return true;
    }
}

bool CDBManager::InsertToTblPriceBUSD(QString sPrice)
{
    qDebug() << sPrice;
    if (!IsOpen())
    {
        return false;
    }
    QSqlQuery query;
    query.prepare("Insert into tblPriceBUSD (price) VALUES (:price)");
    query.bindValue(":price", sPrice);
    if (query.exec())
    {
        return true;
    }
    else
    {
        qDebug() << "DBManager::InsertToTblPriceBUSD: Insert price failed. Error=" << query.lastError();
        return false;
    }
}
