#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget) {
    ui->setupUi(this);
}

Widget::~Widget() {
    delete ui;
}

int Widget::calcQuotient(int n) {
    int result = money / n;
    money = money - n * result;
    return result;
}

void Widget::returnChange() {
    QMessageBox msg;

    if(money <= 0) {
        msg.information(nullptr, "return change", "non change");
    } else {
        int a = calcQuotient(500);
        int b = calcQuotient(100);
        int c = calcQuotient(50);
        int d = calcQuotient(10);

        msg.information(nullptr, "return change", "500won : " + QString::number(a) + "\n 100won : " + QString::number(b) + "\n 50won : " + QString::number(c) + "\n 10won : " + QString::number(d));
        changeMoney(money);
    }
}

void Widget::buttonStatus(int n) {
    if(n < 100) {
        ui->pbMilk->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbCoffee->setEnabled(false);
    } else if(n < 150) {
        ui->pbMilk->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbCoffee->setEnabled(true);
    } else if(n < 200) {
        ui->pbMilk->setEnabled(false);
        ui->pbTea->setEnabled(true);
        ui->pbCoffee->setEnabled(true);
    } else {
        ui->pbMilk->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbCoffee->setEnabled(true);
    }
}

void Widget::changeMoney(int n) {
    money += n;
    ui->lcdNumber->display(QString::number(money));
    buttonStatus(money);

    //ui->pbCoffee->setEnabled(false);
    //QMessageBox msg;
    //msg.information(nullptr, "title", "text");
}

void Widget::on_pb_10_clicked() {
    changeMoney(10);
}

void Widget::on_pb_50_clicked() {
    changeMoney(50);
}

void Widget::on_pb_100_clicked() {
    changeMoney(100);
}

void Widget::on_pb_500_clicked() {
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked() {
    changeMoney(-100);
}

void Widget::on_pbTea_clicked() {
    changeMoney(-150);
}

void Widget::on_pbMilk_clicked() {
    changeMoney(-200);
}

void Widget::on_pbReturn_clicked()
{
    returnChange();
}
