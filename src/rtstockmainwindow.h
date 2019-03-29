#ifndef RTSTOCKMAINWINDOW_H
#define RTSTOCKMAINWINDOW_H

#include"rtStockBlock/rtstockblock.h"
#include"rtStockBackend/rtstockbackend.h"
#include"rtStockSearch/rtstocksearch.h"

#include <QMainWindow>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QScrollArea>
#include<QMenuBar>
#include<QMenu>
#include<QAction>
#include<QMessageBox>
#include<QGroupBox>

class RtStockMainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit RtStockMainWindow(QWidget *parent = nullptr);
    ~RtStockMainWindow();
private:
    void renderUi();
    void createMenu();

    QVBoxLayout *mainLayout;
    QHBoxLayout *subMainLayout;
    QVBoxLayout *stockBlockLayout;
    RtStockBackend *rtBackEnd;
    RtStockSearch *rtStockSearch;
};

#endif // RTSTOCKMAINWINDOW_H
