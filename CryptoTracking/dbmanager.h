#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <QSqlDatabase>

class CDBManager : public QObject
{
    Q_OBJECT
public:
    explicit CDBManager(QObject *parent = nullptr);
    bool IsOpen();
    void SetDB(QString sPath);
    bool OpenDB();
    void CloseDB();
    QString Get1MinAgoPriceBUSD();
    QString Get5MinAgoPriceBUSD();
    QString Get10MinAgoPriceBUSD();
    QString Get15MinAgoPriceBUSD();
    QString Get30MinAgoPriceBUSD();
    QString Get60MinAgoPriceBUSD();
signals:

public slots:
    void slotInsertToTblBUSDPrice(QString sPrice);
    void slotInsert1MinBUSD(QString sPercent);
    void slotInsert5MinBUSD(QString sPercent);
    void slotInsert10MinBUSD(QString sPercent);
    void slotInsert15MinBUSD(QString sPercent);
    void slotInsert30MinBUSD(QString sPercent);
    void slotInsert60MinBUSD(QString sPercent);
private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
