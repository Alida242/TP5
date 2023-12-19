#include "widget.h"
#include "ui_widget.h"
#include <QSqlQueryModel>
#include <QSqlQuery>                   //inclusion des librairies nécessaires
#include <QMessageBox>
#include <QModelIndex>
#include <QTableView>
#include <QtWidgets>
#include <QtSql>

Widget::Widget(QWidget *parent)
    : QWidget(parent)  //définition du construction de la classe Widget qui prend un pointeur ent tant que parent
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget() //définition du destructeur de la classe Widget
{
    delete ui; //Objet Widget détruit, mémoire libérée
}

