#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextStream>
#include <QFile>
#include <cmath>
#include "form.h"
#include "difform.h"
#include <QMessageBox>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief MainWindow конструктор для главной формы
     */
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:

    /*!
     * \brief on_Pressbutton_clicked метод нажатия
     * на кнопку рассчета аннуитетного платежа
     */
    void on_AnButton_clicked();

    /*!
     * \brief on_pushButton_clicked метод нажатия
     * на кнопку рассчета дифференцированного платежа
     */
    void on_DifButton_clicked();

    void saveData(const QString& FIO, double resultSum, double overPayment, double sumPerMonthOutput, bool anFlag);

private:
    Ui::MainWindow *ui;
    Form form;
    DifForm difForm;
    QFile file;
};


class Calculator {
protected:
    double sum;
    int percent;
    int months;
public:
    /*!
     * \brief Calculator конструктор для калькулятора
     */
    Calculator(double sum, int percent, int months);

    /*!
     * \brief resultSum метод рассчета итоговой выплаты
     */
    virtual double resultSum() const = 0;

    /*!
     * \brief overPayment метод рассчета итоговой переплаты
     */
    virtual double overPayment() const = 0;

    /*!
     * \brief sumPerMonthOutput метод рассчета ежемесячной выплаты
     */
    virtual double sumPerMonthOutput() const = 0;

};


class AnnuityCalculator : public Calculator {
public:
    AnnuityCalculator(double sum, int percent, int months);

    /*!
     * \brief sumPerMonthOutput переопределенный метод
     * из базового класса
     */
    double sumPerMonthOutput() const override;

    /*!
     * \brief resultSum переопределенный метод
     * из базового класса
     */
    double resultSum() const override;

    /*!
     * \brief overPayment переопределенный метод
     * из базового класса
     */
    double overPayment() const override;

    ~AnnuityCalculator();
};


class DifCalculator : public Calculator {
public:
    DifCalculator(double sum, int percent, int months);

    /*!
     * \brief sumPerMonthOutput переопределенный метод
     * из базового класса
     */
    double sumPerMonthOutput() const override;

    /*!
     * \brief resultSum переопределенный метод
     * из базового класса
     */
    double resultSum() const override;

    /*!
     * \brief overPayment переопределенный метод
     * из базового класса
     */
    double overPayment() const override;

    ~DifCalculator();
};



#endif // MAINWINDOW_H
