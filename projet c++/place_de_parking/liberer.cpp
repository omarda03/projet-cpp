#include "liberer.h"
#include "ui_liberer.h"
#include<QMessageBox>
#include<QSqlQuery>
#include<QDebug>
#include<QSqlError>
liberer::liberer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::liberer)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "my_connection_name");
    db.setDatabaseName("C:/Users/Original Shop/Desktop/projet c++/place.db");

}

liberer::~liberer()
{
    delete ui;
}

void liberer::on_pushButton_clicked()
{
      int Nplace;
      QString Matricule = ui->lineEdit->text();

      // Suppression dans la table 'vehicule'
      QString deleteVehiculeQuery = "DELETE FROM vehicule WHERE matricule = :matricule";

      QSqlQuery queryDeleteVehicule;
      queryDeleteVehicule.prepare(deleteVehiculeQuery);
      queryDeleteVehicule.bindValue(":matricule", Matricule.toInt());

      // Mise à jour dans la table 'place'
      QString updatePlaceQuery = "UPDATE place SET disponibilite = true WHERE numplace = :numplace";

      QSqlQuery queryUpdatePlace;
      queryUpdatePlace.prepare(updatePlaceQuery);
      queryUpdatePlace.bindValue(":numplace", Nplace);

      // Commencer une transaction
      QSqlDatabase::database().transaction();

      // Exécuter les requêtes dans une transaction
      bool success = queryDeleteVehicule.exec() && queryUpdatePlace.exec();

      if (success) {
          // Valider la transaction si tout s'est bien passé
          QSqlDatabase::database().commit();
          qDebug() << "Suppression et mise à jour réussies!";

      } else {
          // Annuler la transaction en cas d'erreur
          QSqlDatabase::database().rollback();
          qDebug() << "Erreur lors de la suppression ou de la mise à jour.";
          qDebug() << "Suppression - Query:" << queryDeleteVehicule.lastQuery() << ", Error:" << queryDeleteVehicule.lastError().text();
          qDebug() << "Mise à jour - Query:" << queryUpdatePlace.lastQuery() << ", Error:" << queryUpdatePlace.lastError().text();
      }
}

void liberer::on_pushButton_2_clicked()
{
    this->close();
}
