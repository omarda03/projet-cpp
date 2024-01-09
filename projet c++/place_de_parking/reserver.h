#ifndef RESERVER_H
#define RESERVER_H

#include <QDialog>

namespace Ui {
class reserver;
}

class reserver : public QDialog
{
    Q_OBJECT

public:
    explicit reserver(QWidget *parent = nullptr);
    ~reserver();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::reserver *ui;
};

#endif // RESERVER_H
