#ifndef CWORKER_H
#define CWORKER_H

#include <QObject>

class CWorker : public QObject
{
    Q_OBJECT
public:
    explicit CWorker(QObject *parent = nullptr);

signals:
    void signalCalculatePricePercentComplete(QString sPercent);
public slots:
    void slotCalculatePricePercent(QString sCurPrice, QString sPrevPrice);
};

#endif // CWORKER_H
