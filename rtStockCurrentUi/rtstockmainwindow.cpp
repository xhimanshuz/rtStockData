#include "rtstockmainwindow.h"

RtStockMainWindow::RtStockMainWindow(QWidget *parent) : QWidget(parent)
{
    rtBackEnd = new RtStockBackend;
    connect(rtBackEnd, &RtStockBackend::blockAdded, [this](RtStockCurrentUi *block){
        stockBlockLayout->addWidget(block);
        stockBlockLayout->addStretch();
    });
    rtBackEnd->createStockBlock("MSFT");
    rtBackEnd->createStockBlock("HON");
    rtBackEnd->createStockBlock("GOOG");

    mainLayout = new QHBoxLayout;
    renderUi();
    this->setLayout(mainLayout);
}

RtStockMainWindow::~RtStockMainWindow()
{

}

void RtStockMainWindow::renderUi()
{
    stockBlockLayout = new QVBoxLayout;
    mainLayout->addLayout(stockBlockLayout);
}

void RtStockMainWindow::createStockBlock(QString symbol)
{

}
