#include "cconfig.h"
#include <QSettings>

CConfig::CConfig(QObject *parent)
    : QObject{parent}
{

}

void CConfig::InitConfigFile(QString sPath)
{
    QSettings settings(sPath, QSettings::IniFormat);
    // Get group time
    settings.beginGroup("TIME");
    const QStringList childKeys = settings.childKeys();
    foreach(const QString & childKey, childKeys)
    {
        if (childKey == "INTERVAL_SYMBOL_PRICE")
        {
            m_IntervalSymbolPrice = settings.value(childKey).toInt();
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
