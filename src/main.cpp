#include<QApplication>
#include<QNetworkAccessManager>
#include<QNetworkRequest>
#include<QNetworkReply>
#include<QJsonDocument>
#include<QJsonObject>
#include<QDebug>
#include<random>
#include<QTimer>

#include"rtstockmainwindow.h"
#include"rtStockBlock/rtstockblock.h"

int main(int c, char **v)
{
    QApplication app(c, v);
    RtStockMainWindow mw;
    mw.show();
    return app.exec();
}
