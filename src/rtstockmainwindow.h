#ifndef RTSTOCKMAINWINDOW_H
#define RTSTOCKMAINWINDOW_H

#include <QMainWindow>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include"rtStockBlock/rtstockblock.h"
#include"rtStockBackend/rtstockbackend.h"

class RtStockMainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit RtStockMainWindow(QWidget *parent = nullptr);
    ~RtStockMainWindow();
private:
    void renderUi();
    void createStockBlock(QString symbol);
    QVBoxLayout *mainLayout;
    QHBoxLayout *subMainLayout;
    QVBoxLayout *stockBlockLayout;
    RtStockBackend *rtBackEnd;
};

#endif // RTSTOCKMAINWINDOW_H
