#ifndef LIBERER_H
#define LIBERER_H

#include <QDialog>

namespace Ui {
class liberer;
}

class liberer : public QDialog
{
    Q_OBJECT

public:
    explicit liberer(QWidget *parent = nullptr);
    ~liberer();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::liberer *ui;
};

#endif // LIBERER_H
