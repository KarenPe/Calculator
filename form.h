#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief Form конструктор для формы,
     * где будет выводиться информация об аннуитетном платеже
     */

    explicit Form(QWidget *parent = nullptr);
    /*!
     * \brief setData метод задает значения для полей вывода
     * (полная выплата, переплата и ежемесячный платеж)
     */
    void setData(double fullPay, int overPay, int payPerMonth);
    ~Form();

private:
    Ui::Form *ui;
};

#endif // FORM_H
