#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::setData(double fullPay, int overPay, int payPerMonth) {
    ui->lineEdit_fullPay->setText(QString::number(fullPay));
    ui->lineEdit_overPay->setText(QString::number(overPay));
    ui->lineEdit_perMonth->setText(QString::number(payPerMonth));
}
