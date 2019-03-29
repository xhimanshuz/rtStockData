#include "rtstockblock.h"

RtStockBlock::RtStockBlock(QString nameString, QString symb, QWidget *parent): QWidget(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->nameStr = nameString;
    this->symb = symb;
    mainLayout = new QVBoxLayout;
    renderUi();
    this->setLayout(mainLayout);
    this->setStyleSheet("background: white;");
}

void RtStockBlock::renderUi()
{
    mainLayout->setMargin(0);
    QWidget *titleWidget = new QWidget;
    titleWidget->setStyleSheet("background: #01579B");
    name = new QLabel(tr("<b>%1</b>").arg(nameStr));
    name->setStyleSheet("color: white");
    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addWidget(name);
    titleWidget->setLayout(hbox);
    mainLayout->addWidget(titleWidget);

    QVBoxLayout *subMainLayout = new QVBoxLayout;
    subMainLayout->setMargin(10);

    price = new QLabel;
    price->setMargin(0);
    change = new QLabel;
    change->setStyleSheet("color: green;");
    changePerc = new QLabel;
    changePerc->setStyleSheet("color: green;");
    hbox = new QHBoxLayout;
    hbox->setMargin(0);
    hbox->addWidget(price);
    hbox->addWidget(change);
    hbox->addWidget(changePerc);
    hbox->addStretch();

    symbol = new QLabel(symb);
    latestTradingDaete = new QLabel;
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->setMargin(0);
    vbox->addLayout(hbox);
    vbox->addWidget(symbol);
    vbox->addWidget(latestTradingDaete);

    alphabet = new QLabel(nameStr.at(0));
    alphabet->setStyleSheet("font-size: 60px");
    hbox = new QHBoxLayout;
    hbox->addLayout(vbox);
    hbox->addWidget(alphabet);
    subMainLayout->addLayout(hbox);

    hbox = new QHBoxLayout;
    vbox = new QVBoxLayout;
    open = new QLabel;
    open->setAlignment(Qt::AlignRight);
    hbox->addWidget(new QLabel("Open"));
    hbox->addWidget(open);
    vbox->addLayout(hbox);

    previousClose = new QLabel;
    previousClose->setAlignment(Qt::AlignRight);
    hbox = new QHBoxLayout;
    hbox->addWidget(new QLabel("Prec Close"));
    hbox->addWidget(previousClose);
    vbox->addLayout(hbox);

    QHBoxLayout *openClodeHbox = new QHBoxLayout;
    openClodeHbox->addLayout(vbox);
    vbox = new QVBoxLayout;

    high = new QLabel;
    high->setAlignment(Qt::AlignRight);
    hbox = new QHBoxLayout;
    hbox->addWidget(new QLabel("High "));
    hbox->addWidget(high);
    vbox->addLayout(hbox);

    low = new QLabel;
    low->setAlignment(Qt::AlignRight);
    hbox = new QHBoxLayout;
    hbox->addWidget(new QLabel("Low "));
    hbox->addWidget(low);
    vbox->addLayout(hbox);
    openClodeHbox->addLayout(vbox);
    subMainLayout->addLayout(openClodeHbox);

    mainLayout->addLayout(subMainLayout);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

void RtStockBlock::setValues(QString change, QString changePerc, QString price, QString latestTradingDate, QString open, QString close, QString high, QString low)
{
    this->price->setText(QString("%1 %2 USD%3").arg("<h1>").arg(price).arg("</h1>"));
    if(!change.contains('-'))
    {
        this->change->setText(tr("<b>+%1</b>").arg(change));
        this->change->setStyleSheet("color: green;");
        this->changePerc->setText(tr("<b>(+%1)</b>").arg(changePerc));
        this->changePerc->setStyleSheet("color: green;");
    }
    else
    {
        this->change->setText(tr("<b>%1</b>").arg(change));
        this->change->setStyleSheet("color: red;");
        this->changePerc->setText(tr("<b>(%1)</b>").arg(changePerc));
        this->changePerc->setStyleSheet("color: red;");
    }

    this->latestTradingDaete->setText(tr("At Close <b>%1</b> 00.00 UTC+0000").arg(latestTradingDate));
    this->open->setText(open);
    this->previousClose->setText(close);
    this->high->setText(high);
    this->low->setText(low);
}
