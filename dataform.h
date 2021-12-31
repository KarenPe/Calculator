#ifndef DATAFORM_H
#define DATAFORM_H

#include <QWidget>

namespace Ui {
class DataForm;
}

class DataForm : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief DiffForm конструктор для формы,
     * где будет выводиться информация о дифференцированном платеже
     */
    explicit DataForm(QWidget *parent = nullptr);

    void pushData(const QString& text);

    ~DataForm();

private:
    Ui::DataForm *ui;
};

#endif // DATAFORM_H
