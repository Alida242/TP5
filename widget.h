#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QApplication>
#include <QSqlDatabase>
#include <QMessageBox>    //inclusion des librairies nécessaires
#include <QTableView>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget //déclaration de la classe widget, héritant de Qwidget
{
    Q_OBJECT

public:
   explicit Widget(QWidget *parent = 0); //constructeur de type explicite
    ~Widget(); //Destructeur

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H //fin de la déclaration du fichier d'en-tête
