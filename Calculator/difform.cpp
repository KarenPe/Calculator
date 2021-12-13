#include "difform.h"
#include "ui_difform.h"

DifForm::DifForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DifForm)
{
    ui->setupUi(this);
}

DifForm::~DifForm()
{
    delete ui;
}

void DifForm::setData(double fullPay, int overPay, int payPerMonth) {
    ui->lineEdit_fullPay->setText(QString::number(fullPay));
    ui->lineEdit_overPay->setText(QString::number(overPay));
    ui->lineEdit_perMonth->setText(QString::number(payPerMonth));
}
