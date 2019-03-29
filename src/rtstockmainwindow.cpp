#include "rtstockmainwindow.h"

RtStockMainWindow::RtStockMainWindow(QWidget *parent) : QWidget(parent)
{
    rtBackEnd = new RtStockBackend;
    connect(rtBackEnd, &RtStockBackend::blockAdded, [this](RtStockBlock *block){
        stockBlockLayout->insertWidget( stockBlockLayout->count()-1, block);
    });

    mainLayout = new QVBoxLayout;
    subMainLayout = new QHBoxLayout;

    renderUi();
    mainLayout->addLayout(subMainLayout);
    this->setLayout(mainLayout);
    this->rtBackEnd->createStockBlock("HON");
    this->rtBackEnd->createStockBlock("BON");
    this->rtBackEnd->createStockBlock("MSFT");
}

RtStockMainWindow::~RtStockMainWindow()
{

}

void RtStockMainWindow::renderUi()
{
    createMenu();

    rtStockSearch = new RtStockSearch;
    connect(rtStockSearch, &RtStockSearch::selected, rtBackEnd, &RtStockBackend::createStockBlock);
    mainLayout->addWidget(rtStockSearch);
    stockBlockLayout = new QVBoxLayout;
    stockBlockLayout->addStretch();

    QGroupBox *gb = new QGroupBox("SomeOther Componenets");
    QWidget *stockBlockListWidget = new QWidget;
    stockBlockListWidget->setLayout(stockBlockLayout);
    subMainLayout->addWidget(gb,1);
    subMainLayout->addWidget(stockBlockListWidget, 1);
}

void RtStockMainWindow::createMenu()
{
    QAction *about = new QAction("&About");
    connect(about, &QAction::triggered, [this]{
        QMessageBox msgBox(QMessageBox::Information, QString("About"), QString("SSS"), QMessageBox::Ok, this);
        msgBox.setText("<h3>Qt Based Real Time Stock Data Viewer</h3>\n"
                       "<b>Library</b>: Qt\n"
                       "\n<b>Api: </b> alphavantage.co\n");
        msgBox.exec();
    });

    QMenuBar *bar = new QMenuBar;
    QMenu *aboutMenu = new QMenu("Help");
    bar->addMenu(aboutMenu);
    aboutMenu->addAction(about);

    mainLayout->setMenuBar(bar);

}
