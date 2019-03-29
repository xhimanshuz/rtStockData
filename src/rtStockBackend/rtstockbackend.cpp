#include "rtstockbackend.h"

RtStockBackend::RtStockBackend()
{
    stockBlockMap = new QMap<QString, RtStockBlock*>;
    stockBlockList = new QStringList;

}

QJsonObject RtStockBackend::apiToJson(QNetworkReply *reply)
{
    QByteArray bArray = reply->readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(bArray);
    QJsonObject jObj = jsonDoc.object().begin()->toObject();
    return jObj;
}

QString RtStockBackend::nameFetcher(QString sym)
{
    qDebug()<< sym;
    QUrl url = (QString("https://www.alphavantage.co/query?function=SYMBOL_SEARCH&keywords=%1&apikey=ZUBQGD297UWTKTL1").arg(sym));
    qDebug()<< url.toString();
    QNetworkRequest request(url);
    QNetworkAccessManager *man = new QNetworkAccessManager;
    connect(man, &QNetworkAccessManager::finished, [this, sym](QNetworkReply *reply){
        QJsonDocument jDoc = QJsonDocument::fromJson(reply->readAll());
        QJsonObject jObj = jDoc.object()["bestMatches"].toArray()[0].toObject();
        QString symbolName = jObj.value("2. name").toString();
        qDebug()<<":"<<  symbolName;
        this->stockBlockMap->value(sym)->name->setText(QString("<b>%1</b>").arg(symbolName));
    });
    man->get(request);
    return symbolName;
}

RtStockBackend::~RtStockBackend()
{

}

QStringList RtStockBackend::jsonToStringList(QJsonObject jObj)
{
    symbol = jObj["01. symbol"].toString();
    open = jObj["02. open"].toString();
    high = jObj["03. high"].toString();
    low = jObj["04. low"].toString();
    price = jObj["05. price"].toString();
    latestTradingPrice = jObj["07. latest trading day"].toString();
    change = jObj["09. change"].toString();
    changePerc = jObj["10. change percent"].toString();
//    preClose = jObj["08. previous close"].toString();

    return QStringList()<< change << changePerc << price << latestTradingPrice << open << close << high << low;
}

void RtStockBackend::fetchData(QString symbol)
{
    QUrl url(QString("https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol=%1&apikey=ZUBQGD297UWTKTL1").arg(symbol));
    QNetworkRequest *request= new QNetworkRequest(url);
    manager = new QNetworkAccessManager;
    QObject::connect(manager, &QNetworkAccessManager::finished, [this, symbol](QNetworkReply *reply){
        QStringList sList = this->jsonToStringList(this->apiToJson(reply));
        qDebug()<< sList;
        if(sList[0].isEmpty())
            return;
        stockBlockMap->value(symbol)->setValues(sList[0], sList[1], sList[2], sList[3], sList[4], sList[5], sList[6], sList[7]);
        nameFetcher(symbol);
        emit this->blockAdded(stockBlockMap->value(symbol));
    });
    manager->get(*request);
}

void RtStockBackend::createStockBlock(QString symbol)
{
    RtStockBlock *block = new RtStockBlock(symbol, "");
    block->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    stockBlockMap->insert(symbol, block);
    stockBlockList->append(symbol);
    this->fetchData(symbol);
}
