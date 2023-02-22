#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <QSqlDatabase>

class CDBManager : public QObject
{
    Q_OBJECT
public:
    explicit CDBManager(QObject *parent = nullptr);
    static bool IsOpen();
    static bool OpenDB(QString sPath);
    static bool InsertToTblPriceBUSD(QString sPrice);
signals:

private:
    static QSqlDatabase m_db;
};

#endif // DBMANAGER_H
