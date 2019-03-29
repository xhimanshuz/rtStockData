#include "rtstockmainwindow.h"

RtStockMainWindow::RtStockMainWindow(QWidget *parent) : QWidget(parent)
{
    rtBackEnd = new RtStockBackend;
    connect(rtBackEnd, &RtStockBackend::blockAdded, [this](RtStockBlock *block){
        stockBlockLayout->addWidget(block);
    });
    rtBackEnd->createStockBlock("MSFT");
    rtBackEnd->createStockBlock("HON");
    rtBackEnd->createStockBlock("GOOG");

    mainLayout = new QVBoxLayout;
    subMainLayout = new QHBoxLayout;

    renderUi();
    mainLayout->addLayout(subMainLayout);
    this->setLayout(mainLayout);
}

RtStockMainWindow::~RtStockMainWindow()
{

}

void RtStockMainWindow::renderUi()
{
    stockBlockLayout = new QVBoxLayout;
    subMainLayout->addLayout(stockBlockLayout);
}

void RtStockMainWindow::createStockBlock(QString symbol)
{

}
