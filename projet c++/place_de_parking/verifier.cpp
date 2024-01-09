#include "verifier.h"
#include "ui_verifier.h"
#include<QSqlQuery>
#include<QMessageBox>
#include<QDebug>
#include<QSqlError>

verifier::verifier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::verifier)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "my_connection_name");
    db.setDatabaseName("C:/Users/Original Shop/Desktop/projet c++/place.db");

}

verifier::~verifier()
{
    delete ui;
}

void verifier::on_pushButton_clicked()
{
    // Sélectionner les places disponibles dans la table 'place'
    QString selectAvailablePlacesQuery = "SELECT numplace FROM place WHERE disponibilite = 1";

    QSqlQuery queryAvailablePlaces;
    queryAvailablePlaces.prepare(selectAvailablePlacesQuery);

    if (queryAvailablePlaces.exec()) {
        QStringList availablePlaces;

        // Parcourir les résultats de la requête et ajouter les numéros de place à la liste
        while (queryAvailablePlaces.next()) {
            int numplace = queryAvailablePlaces.value("numplace").toInt();
            availablePlaces.append(QString::number(numplace));
        }

        // Afficher un message avec les places disponibles
        QString message;
        if (!availablePlaces.isEmpty()) {
            message = "Places disponibles : " + availablePlaces.join(", ");
            QMessageBox::information(this, "Places Disponibles", message);
        } else {
            message = "Aucune place disponible.";
            QMessageBox::information(this, "Places Disponibles", message);
        }
    } else {
        // Gérer les erreurs si la requête échoue
        qDebug() << "Erreur lors de la récupération des places disponibles:" << queryAvailablePlaces.lastError().text();
        qDebug() << "Query:" << queryAvailablePlaces.lastQuery();
    }




}

void verifier::on_pushButton_2_clicked()
{
    this->close();
}
