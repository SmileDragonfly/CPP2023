#include "cconfig.h"
#include <QSettings>

CConfig::CConfig(QObject *parent)
    : QObject{parent}
{

}

void CConfig::InitConfigFile(QString sPath)
{
    QSettings settings(sPath, QSettings::IniFormat);
    // GROUP TIME
    settings.beginGroup("TIME");
    QStringList childKeys = settings.childKeys();
    foreach(const QString & childKey, childKeys)
    {
        if (childKey == "INTERVAL_SYMBOL_PRICE")
        {
            m_IntervalSymbolPrice = settings.value(childKey).toInt();
        }
    }
    settings.endGroup();

    // Group SQLITE
    settings.beginGroup("SQLITE");
    childKeys = settings.childKeys();
    foreach(const QString& childKey, childKeys)
    {
        if (childKey == "FILE_NAME")
        {
            m_SqliteDBName = settings.value(childKey).toString();
        }
    }
    settings.endGroup();
}

int CConfig::IntervalSymbolPrice() const
{
    return m_IntervalSymbolPrice;
}

void CConfig::setIntervalSymbolPrice(int newIntervalSymbolPrice)
{
    m_IntervalSymbolPrice = newIntervalSymbolPrice;
}

QString CConfig::SqliteDBName() const
{
    return m_SqliteDBName;
}

void CConfig::setSqliteDBName(QString newSqliteDBName)
{
    m_SqliteDBName = newSqliteDBName;
}
