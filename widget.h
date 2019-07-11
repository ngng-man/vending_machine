#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    int money{0};

    int calcQuotient(int n);

    void returnChange();

    void buttonStatus(int n);

    void changeMoney(int n);

private slots:
    void on_pb_10_clicked();

    void on_pb_50_clicked();

    void on_pb_100_clicked();

    void on_pb_500_clicked();

    void on_pbCoffee_clicked();

    void on_pbTea_clicked();

    void on_pbMilk_clicked();

    void on_pbReturn_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
