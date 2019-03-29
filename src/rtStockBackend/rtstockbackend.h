#ifndef RTSTOCKCURRENTBACKEND_H
#define RTSTOCKCURRENTBACKEND_H

#include <QObject>
#include<QJsonArray>
#include<QJsonDocument>
#include<QJsonObject>
#include<QNetworkAccessManager>
#include<QNetworkRequest>
#include<QNetworkReply>
#include"rtStockBlock/rtstockblock.h"

class RtStockBackend:public QObject
{
    Q_OBJECT
public:
    RtStockBackend();
    ~RtStockBackend();
    QStringList jsonToStringList(QJsonObject jObj);
    void fetchData(QString symbol);
    void createStockBlock(QString symbol);
signals:
    void blockAdded(RtStockBlock *block);
private slots:
    QJsonObject apiToJson(QNetworkReply *reply);
private:
    QString nameFetcher(QString symbol);

    QString symbol;
    QString symbolName;
    QString open;
    QString close;
    QString change;
    QString changePerc;
    QString preClose;
    QString price;
    QString latestTradingPrice;
    QString priceStandard;
    QString high;
    QString low;
    QMap<QString, RtStockBlock*> *stockBlockMap;
    QStringList *stockBlockList;
    QNetworkAccessManager *manager;

};

#endif // RTSTOCKCURRENTBACKEND_H
