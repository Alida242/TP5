#include "widget.h" //inclusion du fichier d'en-tête
#include "ui_widget.h"

#include <QApplication> //librairies qui gères= les ressources de l'application
#include <QtSql/QSqlDatabase> //connexion à la base de données
#include <QtDebug> //débogage
#include <QtSql/QSqlQuery> //requete à une base de données
#include <QSqlError>
#include <QSqlTableModel>
#include <QTableView>
#include <QHBoxLayout>
#include <QWidget> // classe pour tous les objets
#include <QPushButton> // génère un bouton sur lequel on peut cliquer, appuyer


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w; //création d'une fenetre
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");   //sous linux le connecteur est bien un QMYSQL de base
    db.setDatabaseName("test");  // nom de ma base de données

    db.setUserName( "student"); // nom  d'utilisateur(login)
    db.setPassword("crif2024sn"); //mot de passe
    if(db.open())  //verification de la connexion à la base de données
    {
        qDebug() <<"Vous êtes maintenant connecté à" <<db.hostName(); // le message s'affiche si le programme marche et après il affiche la base de données
        QSqlQuery query;

        query.exec("SELECT * FROM jeu "); // exécution d'une requete sql et nom de ma table
        while(query.next())
        {
            QString id= query.value(0).toString();
            QString nom= query.value(1).toString();
            QString club= query.value(2).toString();   // nombre de lignes et colonnes- nom des champs
            //QString attaque= query.value(3).toString();
            //QString defense= query.value(3).toString();
            //QString vitesse= query.value(3).toString();
            qDebug()<<"\t|--------------------------------";  //affichage des résultats dans la console
            qDebug()<<"\t|"<<id <<"\t|"<<nom <<"|"<<club <<"|";
            //qDebug()<<"\t|"<<id <<"\t|"<<nom<<"\t|"<<bonus_de_vie<<"\t|"<<attaque<<"\t|"<<defense<<"\t|"<<vitesse<<"\t|";
        }
        qDebug()<<"\t|--------------------------------";
        qDebug()<<"Requete ok ! :)" ;
    }
    else
    {
        qDebug()<<"La connexion a échouée, désolé"<<db.lastError().text(); // le message s'affiche en cas d'échec de la connexion
    }

    QSqlTableModel table; //instance de QSqlTableModel est crée
    table.clear();
    table.setTable("jeu");
    QTableView view;
    QPushButton afficher("Affiche"), note("Notes"); //création de deux boutons
    QHBoxLayout layout; //création d'un layout
    layout.addWidget(&view);
    layout.addWidget(&afficher);
    layout.addWidget(&note);
    w.setLayout(&layout);


    QObject::connect(&afficher, &QPushButton::clicked,[&]() // le code à exécuter lorsque le bouton est cliqué
{
    view.setModel(&table);
    view.setColumnHidden(0,false); //affichage de la première colonne
    view.setColumnHidden(1,false); //affichage de la deuxième colonne
    view.setColumnHidden(2,false); //affichage de la troisième colonne
    view.setColumnHidden(3,false); //affichage de la quatrième colonne
    view.setColumnHidden(4,false); //affichage de la cinquième colonne
    view.setColumnHidden(5,false); //affichage de la sixième colonne
    table.setHeaderData(0, Qt::Horizontal,"id"); //Définition des en-têtes de colonnes
    table.setHeaderData(1, Qt::Horizontal,"nom");
    table.setHeaderData(2, Qt::Horizontal,"club");
    table.setHeaderData(3, Qt::Horizontal,"age");
    table.setHeaderData(4, Qt::Horizontal,"notes");
    table.select(); // Exécution de la requête SQL qui selectionne les lignes de la table
});


    QObject::connect(&note, &QPushButton::clicked,[&]()
{
     view.setModel(&table);
     view.setColumnHidden(0,false);
     view.setColumnHidden(1,false);
     view.setColumnHidden(2,false);
     view.setColumnHidden(3,false);
     view.setColumnHidden(4,false);
     view.setColumnHidden(5,false);
     table.setHeaderData(0, Qt::Horizontal,"id");
     table.setHeaderData(1, Qt::Horizontal,"nom");
     table.setHeaderData(2, Qt::Horizontal,"club");
     table.setHeaderData(3, Qt::Horizontal,"age");
     table.setHeaderData(4, Qt::Horizontal,"notes");
     table.select();
});
    w.show();
    return a.exec();


}
