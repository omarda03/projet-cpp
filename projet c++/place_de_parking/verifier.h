#ifndef VERIFIER_H
#define VERIFIER_H

#include <QDialog>

namespace Ui {
class verifier;
}

class verifier : public QDialog
{
    Q_OBJECT

public:
    explicit verifier(QWidget *parent = nullptr);
    ~verifier();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::verifier *ui;
};

#endif // VERIFIER_H
