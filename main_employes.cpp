#include "main_employes.h"
#include "ui_main_employes.h"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QtCharts/QBarSeries>
#include <QtCharts>
#include <QIntValidator>
#include<QMessageBox>
#include "employes.h"
#include <iostream>
#include <string>
#include<QPropertyAnimation>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include<QTextDocument>
#include<QtPrintSupport/QPrinter>
#include<QByteArray>
#include <QSqlQuery>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QValidator *validator = new QIntValidator(1, 99999999, this);
    ui->lineEdit_nomE->setMaxLength(30);
    ui->lineEdit_PrenomE->setMaxLength(30);
    ui->lineEdit_mail->setMaxLength(30);
    ui->lineEdit_ID->setValidator(validator);
    ui->lineEdit_id_sup->setValidator(validator);
    ui->lineEdit_recherche->setValidator(validator);
    ui->lineEdit_salaire->setMaxLength(20);
    //ui->tab_fournisseur->setModel(SP.afficher());
    //ui->lineEdit_Nom->setValidator(new QRegExpValidator(QRegExp("[A-Z][a-z]*")));*/

   /* QRegularExpression rx3("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                         QRegularExpression::CaseInsensitiveOption);
               ui->lineEdit_Adr->setValidator(new QRegularExpressionValidator(rx3, this));


               //Initialize "countdown" label text
                   ui->countdown->setText("1:00");

                   //Connect timer to slot so it gets updated
                   timer = new QTimer();
                   QTime time(0, 1, 0);
                   connect(timer, SIGNAL(timeout()), this, SLOT(updateCountdown()));

                   //It is started with a value of 1000 milliseconds, indicating that it will time out every second.
                   timer->start(0000);*/



    //animation
    animation= new QPropertyAnimation(ui->pb_supp, "geometry");
    animation->setDuration(2500);
    animation->setStartValue(QRect(800, 500, 150, 50));
    animation->setEndValue(QRect(ui->pb_supp->geometry()));

    animation->start();

}

MainWindow::~MainWindow()
{
    delete ui;

}
/*void MainWindow::updateCountdown()
{
    QTime time = QTime::currentTime();
       QString text = time.toString("hh:mm");
       if ((time.second() % 2) == 0)
           text[2] = ' ';
       ui->countdown->setText(time.toString("m:ss"));
}*/



void MainWindow::on_pb_ajouter_clicked()
{
       QString nom_employes=ui->lineEdit_nomE->text();
       QString prenom_employes=ui->lineEdit_PrenomE->text();
       int ID=ui->lineEdit_ID->text().toInt();
       QString mail=ui->lineEdit_mail->text(); //mail
       int salaire=ui->lineEdit_salaire->text().toInt(); //salaire
       QString poste=ui->lineEdit_poste->text();//poste
       int hdt=ui->lineEdit_HDT->text().toInt(); //HDT

          //int x=0;

         // std::string str_phone = std::to_string(tlf);
         // std::string m = mail.toStdString();


         /* if (nom_fournisseur=="")
          {
              QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                          QObject::tr("Nom n'est pas vide"), QMessageBox::Ok);
                    x++;
          }*/



          /*else if (m.find("@gmail.com")== std:: string::npos)
          {
              QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                          QObject::tr("L'e-mail doit se terminer par @gmail.com"), QMessageBox::Ok);
                    x++;
          }

          else if (str_phone.length()!=8)
          {
              QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                          QObject::tr("Le numéro de téléphone doit être composé de 8 chiffres"), QMessageBox::Ok);
                    x++;
          }*/


           //if(x==0)
          {
          employes Sp(nom_employes,prenom_employes,ID,mail,salaire,poste,hdt);
          bool toTest =Sp.Ajouter();
          if(toTest)
          {
              QMessageBox::information(nullptr, QObject::tr("Ajout Fournisseur"),
                                QObject::tr(" ajout Fournisseur avec succès"), QMessageBox::Ok);
                                //ui->tab_fournisseur->setModel(Sp.afficher());
          }
          ui->lineEdit_ID->clear();
          ui->lineEdit_nomE->clear();
          ui->lineEdit_PrenomE->clear();
          ui->lineEdit_mail->clear();
          ui->lineEdit_salaire->clear();
          ui->lineEdit_recherche->clear();
          ui->lineEdit_poste->clear();




          }


}
void MainWindow::on_pb_recherche_clicked()
{
    employes Sp;
    Sp.set_ID(ui->lineEdit_recherche->text().toInt());
    bool test=Sp.RechercheemployesParID(Sp.get_ID());
    QMessageBox msgbox;

    if (test)
       {
        msgbox.setText("ID existe");
        ui->tab_fournisseur->setModel(Sp.afficher());
        }
    else
        msgbox.setText("ID n'existe pas");
        msgbox.exec();
        ui->lineEdit_recherche->clear();
}

void MainWindow::on_pb_supp_clicked()
{
    employes Sp;
    Sp.set_ID(ui->lineEdit_id_sup->text().toInt());
    bool test=Sp.supprimer(Sp.get_ID());
    QMessageBox msgbox;

    if (test)
       {
        msgbox.setText("Suppression avec succes");
        ui->tab_fournisseur->setModel(Sp.afficher());////////////////////////////
        }
    else
        msgbox.setText("failed");
        msgbox.exec();
        ui->lineEdit_id_sup->clear();
}
