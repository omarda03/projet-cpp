#include "reserver.h"
#include "ui_reserver.h"
#include<QString>
#include <QComboBox>
#include<QSqlQuery>
#include<QDebug>
#include<QSqlError>
#include<QMessageBox>

reserver::reserver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reserver)
{
    ui->setupUi(this);
    ui->comboBox_type->addItem("Moto");
    ui->comboBox_type->addItem("Voiture");
    ui->comboBox_type->addItem("Camion");

    // Dans la méthode où vous souhaitez établir la connexion à la base de données (par exemple, le constructeur de votre classe principale).
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "my_connection_name");
    db.setDatabaseName("C:/Users/Original Shop/Desktop/projet c++/place.db");

    // Vérifiez si la base de données est ouverte avec succès
    if (!db.open()) {
        QMessageBox::critical(nullptr, "Erreur de connexion", "Impossible de se connecter à la base de données.");
        return;
    }else {
        ui->label_status->setText("DataBase connected...");
        //QMessageBox::information(this, "Connexion faite", "La base de donnees est connecter. ");

}
}

reserver::~reserver()
{
    delete ui;
}

void reserver::on_pushButton_clicked()
{
    //QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "my_connection_name");
    int Nplace;
    QString Matricule ,Model ,Type ,et;
    //QComboBox Type;
    Matricule = ui->lineEdit_rmat->text();
    Model = ui->lineEdit_rmod->text();
    Type = ui->comboBox_type->currentText();
    Nplace = ui->lineEdit_numplace->text().toInt();

    // Supposons que vous ayez déjà une connexion à la base de données nommée 'db'.



    QString connectionName = "my_connection_name";

    if (!QSqlDatabase::contains(connectionName)) {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
        db.setDatabaseName("C:/place.db");

        if (!db.open()) {
            qDebug() << "Unable to open database:" << db.lastError().text();
            return;  // Handle the error appropriately
        } else {
            qDebug() << "Database opened successfully!";
        }
    } else {
        qDebug() << "Connection 'my_connection_name' already exists.";
    }



    QString insertVehiculeQuery = "INSERT INTO vehicule (matricule, model, type_vehicule, numplace) "
                                  "VALUES (:matricule, :model, :type_vehicule, :numplace)";

    QSqlQuery queryVehicule;
    queryVehicule.prepare(insertVehiculeQuery);
    queryVehicule.bindValue(":matricule", Matricule.toInt());
    queryVehicule.bindValue(":model", Model.toInt());
    queryVehicule.bindValue(":type_vehicule", Type);
    queryVehicule.bindValue(":numplace", Nplace);

    if (!queryVehicule.exec()) {
        qDebug() << "Erreur lors de l'insertion dans la table vehicule:" << queryVehicule.lastError().text();
        qDebug() << "Query:" << queryVehicule.lastQuery();
    } else {
        qDebug() << "Insertion into vehicule successful!";
    }
    if (!queryVehicule.exec()) {
        qDebug() << "Erreur lors de l'insertion dans la table vehicule:" << queryVehicule.lastError().text();
        qDebug() << "Query:" << queryVehicule.lastQuery();
    }

if(Nplace < 6 && Nplace > 0){
    et="1";}
if(Nplace < 12 && Nplace > 6){
    et="2";}
if(Nplace < 18 && Nplace > 12){
    et="3";}


     //Insertion dans la table 'place'
        // Insertion dans la table 'place'
        QString insertPlaceQuery = "INSERT INTO place (numplace, type, etage, disponibilite) "
                                   "VALUES (:numplace, :type, :etage, :disponibilite)";

        QSqlQuery queryPlace;
        queryPlace.prepare(insertPlaceQuery);
        queryPlace.bindValue(":numplace", Nplace);
        queryPlace.bindValue(":type", Type);
        queryPlace.bindValue(":etage", et);  // Si 'etage' est de type TEXT, utilisez une chaîne de caractères
        queryPlace.bindValue(":disponibilite", 0);

        if (!queryPlace.exec()) {
            qDebug() << "Erreur lors de l'insertion dans la table place:" << queryPlace.lastError().text();
            qDebug() << "Query:" << queryPlace.lastQuery();
        }

    }



    //traitement de base de donnee


void reserver::on_pushButton_2_clicked()
{
    this->close();
}
