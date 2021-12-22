#include "mainwindow.h"
#include "ui_mainwindow.h"

Calculator::Calculator(double sum, int percent, int months) : sum(sum), percent(percent), months(months) {}

AnnuityCalculator::AnnuityCalculator(double sum, int percent, int months) : Calculator(sum, percent, months) {}

double AnnuityCalculator::sumPerMonthOutput() const {
    double monthPercent = double(percent) / (100 * 12);
    return sum * (monthPercent / (1 - pow(1 + monthPercent, -months)));
}

double AnnuityCalculator::resultSum() const {
    return months * sumPerMonthOutput();
}

double AnnuityCalculator::overPayment() const {
    return resultSum() - sum;
}

AnnuityCalculator::~AnnuityCalculator() = default;


DifCalculator::DifCalculator(double sum, int percent, int months) : Calculator(sum, percent, months) {}

double DifCalculator::sumPerMonthOutput() const {
    return sum / months + sum * percent / 100 * 30/ 365;
}

double DifCalculator::resultSum() const {
    double fixedSum = sum / months;
    double result = sum;
    double tmpSum = sum;
    for (int i = 0; i < months; ++i) {
        result += tmpSum * percent / 100 * 30 / 365;
        tmpSum -= fixedSum;
    }
    return result;
}

double DifCalculator::overPayment() const {
    return resultSum() - sum;
}

DifCalculator::~DifCalculator() = default;


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), file("output.txt") {
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::saveData(const QString& FIO, double resultSum, double overPayment, double sumPerMonthOutput, bool anFlag)
{
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream fout(&file);
        if (anFlag) {
            fout << QString("Аннуитетный платеж\n");
        } else {
            fout << QString("Дифференцированный платеж\n");
        }
        fout << QString("Фамилия Имя Отчество: ") << FIO << '\n';
        fout << QString("Полная выплата: ") << resultSum << '\n';
        fout << QString("Переплата: ") << overPayment << '\n';
        fout << QString("Ежемесячный платеж: ") << sumPerMonthOutput << '\n' << '\n';
    }

    file.close();
}

void MainWindow::on_AnButton_clicked()
{
    bool flag = true;
    double sum;
    int percent, months;

    if (ui->lineEdit_sum->text().toInt()) {
        sum = ui->lineEdit_sum->text().toInt();
    } else {
        flag = false;
        QMessageBox::about(this, "Ошибка", "Введены некорректные данные в поле Сумма");
    }

    if (ui->lineEdit_percent->text().toInt()) {
        percent = ui->lineEdit_percent->text().toInt();
    } else {
        flag = false;
        QMessageBox::about(this, "Ошибка", "Введены некорректные данные в поле Процентная ставка");
    }

    if (ui->lineEdit_months->text().toInt()) {
        months= ui->lineEdit_months->text().toInt();
    } else {
        flag = false;
        QMessageBox::about(this, "Ошибка", "Введены некорректные данные в поле Срок");
    }




    if (flag) {
        AnnuityCalculator calculator(sum, percent, months);

        QString fio = ui->lineEdit_FIO->text();
        form.setData(calculator.resultSum(), calculator.overPayment(), calculator.sumPerMonthOutput());

        saveData(fio, calculator.resultSum(), calculator.overPayment(), calculator.sumPerMonthOutput(), true);

        form.show();
    }
}


void MainWindow::on_DifButton_clicked()
{
    bool flag = true;
    double sum;
    int percent, months;

    if (ui->lineEdit_sum->text().toInt()) {
        sum = ui->lineEdit_sum->text().toInt();
    } else {
        flag = false;
        QMessageBox::about(this, "Ошибка", "Введены некорректные данные в поле Сумма");
    }

    if (ui->lineEdit_percent->text().toInt()) {
        percent = ui->lineEdit_percent->text().toInt();
    } else {
        flag = false;
        QMessageBox::about(this, "Ошибка", "Введены некорректные данные в поле Процентная ставка");
    }

    if (ui->lineEdit_months->text().toInt()) {
        months= ui->lineEdit_months->text().toInt();
    } else {
        flag = false;
        QMessageBox::about(this, "Ошибка", "Введены некорректные данные в поле Срок");
    }




    if (flag) {
        DifCalculator calculator(sum, percent, months);

        QString fio = ui->lineEdit_FIO->text();

        difForm.setData(calculator.resultSum(), calculator.overPayment(), calculator.sumPerMonthOutput());

        saveData(fio, calculator.resultSum(), calculator.overPayment(), calculator.sumPerMonthOutput(), false);

        difForm.show();
    }
}
