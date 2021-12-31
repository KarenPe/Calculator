#include "dataform.h"
#include "ui_dataform.h"

DataForm::DataForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataForm)
{
    ui->setupUi(this);
    this->setWindowTitle("Дифференцированный платеж");
}

void DataForm::pushData(const QString& text) {
    ui->listWidget->addItem(text);
}

DataForm::~DataForm()
{
    delete ui;
}
