#include<QApplication>
#include<QNetworkAccessManager>
#include<QNetworkRequest>
#include<QNetworkReply>
#include<QJsonDocument>
#include<QJsonObject>
#include<QDebug>
#include<random>
#include<QTimer>


#include"rtstockcurrentui.h"

void jsonToUi(RtStockCurrentUi &ui)
{
    qDebug()<< Q_FUNC_INFO;

}

int main(int c, char **v)
{
    QApplication app(c, v);

    RtStockCurrentUi ui("Advanced Micro Devices, Inc.", "NCM");
    QNetworkAccessManager manager;
    QNetworkRequest request(QUrl("https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol=HON&apikey=ZUBQGD297UWTKTL1"));

    QObject::connect(&manager, &QNetworkAccessManager::finished, [&ui](QNetworkReply *reply){
        QByteArray bArray = reply->readAll();
        QJsonDocument jDoc = QJsonDocument::fromJson(bArray);
        QJsonObject jObj = jDoc.object()["Global Quote"].toObject();
        if(jObj.isEmpty())
            return;
        QString symbol = jObj["01. symbol"].toString();
        QString open = jObj["02. open"].toString();
        QString close = jObj["08. previous close"].toString();
        QString price = jObj["05. price"].toString();
        QString change = jObj["09. change"].toString();
        QString changePerc = jObj["10. change percent"].toString();
        QString lastTradingPrice = jObj["07. latest trading day"].toString();
        QString high = jObj["03. high"].toString();
        QString low = jObj["04. low"].toString();
        qDebug()<< change << changePerc;
        ui.setValues(change, changePerc, price, lastTradingPrice, open, close, high, low);
    });
    manager.get(request);
    ui.show();

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&manager, &request]{
        manager.get(request);
    });
    timer.start(1000);
    return app.exec();
}
