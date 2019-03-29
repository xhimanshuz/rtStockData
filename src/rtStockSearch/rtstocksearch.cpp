#include "rtstocksearch.h"
#include<QDebug>

RtStockSearch::RtStockSearch(QWidget *parent): QWidget (parent)
{
    manager = new QNetworkAccessManager;
    mainLayout = new QHBoxLayout;
    renderUi();
    this->setLayout(mainLayout);
}

void RtStockSearch::addItem(QString symbol, QString name)
{
    item = new QStandardItem(tr("%1 (%2)").arg(name).arg(symbol));
    model->appendRow(item);
}

void RtStockSearch::apiToModel(QString symbol)
{
    manager->clearAccessCache();
    QUrl url(QString("https://www.alphavantage.co/query?function=SYMBOL_SEARCH&keywords=%1&apikey=ZUBQGD297UWTKTL1").arg(symbol));
    connect(manager, &QNetworkAccessManager::finished, [this](QNetworkReply *reply){
        QByteArray bArray = reply->readAll();
        QJsonDocument jdoc = QJsonDocument::fromJson(bArray);
        QJsonArray jArray = jdoc.object()["bestMatches"].toArray();
        for(auto i=jArray.begin(); i!=jArray.end(); ++i)
        {
            QJsonObject jobj = i->toObject();
            qDebug()<< jobj["1. symbol"].toString() << jobj["2. name"].toString();
            this->addItem(jobj["1. symbol"].toString(), jobj["2. name"].toString());
        }
    });
    manager->get(QNetworkRequest(url));
}

void RtStockSearch::renderUi()
{
    model = new QStandardItemModel;
    completor = new QCompleter(this);
    completor->setCaseSensitivity(Qt::CaseInsensitive);
    completor->setModel(model);
    completor->setCaseSensitivity(Qt::CaseInsensitive);
//    connect(completor, QOverload<const QString&>::of(&QCompleter::activated), [this](QString act){
//        this->selected(this->extractSymbol(act));
//    });

    searchBox = new QLineEdit;
    connect(searchBox, &QLineEdit::textEdited, [this](QString text){
        if(text.size()<3)
            return;
        this->apiToModel(text);
    });
    searchBox->setStyleSheet("QLineEdit::drop-down{background: yellow};");
    searchBox->setCompleter(completor);
    searchBox->setStyleSheet("font-size: 25px;");
    searchBox->setFixedHeight(35);
    addButton = new QPushButton("+");

    addButton->setFixedHeight(35);
    connect(addButton, &QPushButton::clicked, [this]{
        this->selected(this->extractSymbol(this->searchBox->text()));
    });
    mainLayout->addWidget(searchBox);
    mainLayout->addWidget(addButton);
}

QString RtStockSearch::extractSymbol(QString string)
{
    int start = string.indexOf('(');
    QString str = string.mid(start+1);
    str.chop(1);
    return  str;
}
