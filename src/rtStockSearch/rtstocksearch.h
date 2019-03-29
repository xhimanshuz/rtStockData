#ifndef RTSTOCKSEARCH_H
#define RTSTOCKSEARCH_H

#include<QWidget>
#include<QPushButton>
#include<QLineEdit>
#include<QCompleter>
#include<QHBoxLayout>
#include<QStandardItemModel>
#include<QStandardItem>
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QNetworkRequest>
#include<QJsonDocument>
#include<QJsonArray>
#include<QJsonObject>

class RtStockSearch:public QWidget
{
    Q_OBJECT
public:
    RtStockSearch(QWidget *parent = nullptr);
    void addItem(QString symbol, QString name);
signals:
    void selected(QString symbol);
private:
    void apiToModel(QString symbol  );
    void renderUi();
    QString extractSymbol(QString string);
    QHBoxLayout *mainLayout;
    QLineEdit *searchBox;
    QPushButton *addButton;
    QStandardItemModel *model;
    QNetworkAccessManager *manager;
    QStandardItem *item;
    QCompleter *completor;
};

#endif // RTSTOCKSEARCH_H
