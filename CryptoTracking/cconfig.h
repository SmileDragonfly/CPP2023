#ifndef CCONFIG_H
#define CCONFIG_H

#include <QObject>

class CConfig : public QObject
{
    Q_OBJECT
public:
    explicit CConfig(QObject *parent = nullptr);
    void InitConfigFile(QString sPath);

    int IntervalSymbolPrice() const;
    void setIntervalSymbolPrice(int newIntervalSymbolPrice);
    QString SqliteDBName() const;
    void setSqliteDBName(QString newSqliteDBName);

signals:
private:
    int m_IntervalSymbolPrice;
    QString m_SqliteDBName;
};

#endif // CCONFIG_H
