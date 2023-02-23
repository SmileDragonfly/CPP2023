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
    void setIntervalSymbolPrice(int newIIntervalSymbolPrice);

signals:
private:
    int m_IntervalSymbolPrice;
};

#endif // CCONFIG_H
