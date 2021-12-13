#ifndef DIFFORM_H
#define DIFFORM_H

#include <QWidget>

namespace Ui {
class DifForm;
}

class DifForm : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief DiffForm конструктор для формы,
     * где будет выводиться информация о дифференцированном платеже
     */
    explicit DifForm(QWidget *parent = nullptr);
    /*!
     * \brief setData метод задает значения для полей вывода
     * (полная выплата, переплата и ежемесячный платеж)
     */
    void setData(double fullPay, int overPay, int payPerMonth);
    ~DifForm();

private:
    Ui::DifForm *ui;
};

#endif // DIFFORM_H
