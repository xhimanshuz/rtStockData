#ifndef RTSTOCKCURRENTUI_H
#define RTSTOCKCURRENTUI_H

#include<QWidget>
#include<QLabel>
#include<QVBoxLayout>
#include<QHBoxLayout>

class RtStockCurrentUi: public QWidget
{
public:
    RtStockCurrentUi(QString name, QString symbol, QWidget *parent = nullptr);
    void setValues(QString change, QString changePerc, QString price, QString latestTradingDate, QString open, QString close, QString high, QString low);
    void renderUi();

private:
//    void styleSheetConfig();

    QString nameStr;
    QString symb;
    QVBoxLayout *mainLayout;
    QVBoxLayout *subMainLayout;
    QLabel *alphabet;
    QLabel *symbol;
    QLabel *name;
    QLabel *price;
    QLabel *open;
    QLabel *high;
    QLabel *low;
    QLabel *volume;
    QLabel *latestTradingDaete;
    QLabel *previousClose;
    QLabel *change;
    QLabel *changePerc;
};

#endif // RTSTOCKCURRENTUI_H
