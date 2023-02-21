#ifndef CDATALAYER_H
#define CDATALAYER_H

#include <QObject>

class CDataLayer : public QObject
{
    Q_OBJECT
public:
    explicit CDataLayer(QObject *parent = nullptr);

signals:
public slots:
    void slotSymbolPriceTicker(QString sPriceData);
};

#endif // CDATALAYER_H
