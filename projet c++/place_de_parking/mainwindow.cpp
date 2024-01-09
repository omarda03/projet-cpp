#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reserver.h"
#include "verifier.h"
#include "liberer.h"
#include<QMessageBox>
#include<QPixmap>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Original Shop/Desktop/projet c++/dispo.jpg");
    QPixmap npix("C:/Users/Original Shop/Desktop/projet c++/images.png");
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label->setPixmap(npix.scaled(w,h,Qt::KeepAspectRatio));
    ui->label_2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->label_3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->label_4->setPixmap(npix.scaled(w,h,Qt::KeepAspectRatio));
    ui->label_5->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->label_6->setPixmap(npix.scaled(w,h,Qt::KeepAspectRatio));
    ui->label_7->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->label_8->setPixmap(npix.scaled(w,h,Qt::KeepAspectRatio));
    ui->label_9->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->label_10->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->label_11->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->label_12->setPixmap(npix.scaled(w,h,Qt::KeepAspectRatio));
    ui->label_13->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->label_14->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->label_15->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->label_16->setPixmap(npix.scaled(w,h,Qt::KeepAspectRatio));
    ui->label_17->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->label_18->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));



    // Dans la méthode où vous souhaitez établir la connexion à la base de données (par exemple, le constructeur de votre classe principale).
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Original Shop/Desktop/projet c++/place.db");

    // Vérifiez si la base de données est ouverte avec succès
    if (!db.open()) {
        QMessageBox::critical(nullptr, "Erreur de connexion", "Impossible de se connecter à la base de données.");
        return;
    }else {
        ui->label_status->setText("DataBase connected...");
        //QMessageBox::information(this, "Connexion faite", "La base de donnees est connecter. ");

}
    //void mettreAJourLabel(int numeroPlace, QLabel *label, const QPixmap &imageDisponible, const QPixmap &imageNonDisponible, const QString &requeteSQL);
   //checkDisponibiliteQuery2 = "SELECT disponibilite FROM place WHERE numplace = :numplace";

     //mettreAJourLabel(3, ui->label_3, pix, npix, checkDisponibiliteQuery2);
     //mettreAJourLabel(4, ui->label_4, pix, npix, checkDisponibiliteQuery2);

        }




MainWindow::~MainWindow()
{

    delete ui;
}

//le boutton reserver
void MainWindow::on_pushButton_clicked()
{
    reserver bt_resrever ;
    bt_resrever.setModal(true);
    bt_resrever.exec();

}
//boutton verifier
void MainWindow::on_pushButton_3_clicked()
{
    verifier bt_verifier ;
    bt_verifier.setModal(true);
    bt_verifier.exec();
}
//boutton liberer
void MainWindow::on_pushButton_2_clicked()
{
    liberer bt_liberer ;
    bt_liberer.setModal(true);
    bt_liberer.exec();
}
