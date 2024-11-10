#include "employes.h"
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>
#include <QByteArray>
#include<map>
#include<QSqlRecord>
#include <QFile>

employes::employes()
{
     nom_employes="";
     prenom_employes="";
     ID=0;
     mail="";
     salaire=0;
     poste="";
     hdt=0;

}
employes::employes(QString nom_employes,QString prenom_employes,int ID,QString mail,int salaire,QString poste,int hdt)
{
    this->nom_employes=nom_employes;
    this->prenom_employes=prenom_employes;
    this->ID=ID;
    this->mail=mail;
    this->salaire=salaire;
    this->poste=poste;
    this->hdt=hdt;

}

QString employes::get_Nom()
{
    return nom_employes;
}
QString employes::get_prenom()
{
    return prenom_employes;
}
int employes::get_ID()
{
    return ID;
}
QString employes::get_mail()
{
    return mail;
}
int employes::get_salaire()
{
    return salaire;
}
QString employes::get_poste()
{
    return poste;
}
int employes::get_hdt()
{
    return hdt;
}

// setters
void employes::set_Nom(QString nom_employes)
{
    this->nom_employes=nom_employes;
}
void employes::set_prenom(QString prenom_employes)
{
    this->prenom_employes=prenom_employes;
}
void employes::set_ID(int ID)
{
    this->ID=ID;
}
void employes::set_mail(QString mail)
{
    this->mail=mail;
}
void employes::set_salaire(int salaire)
{
    this->salaire=salaire;
}
void employes::set_poste(QString poste)
{
    this->poste=poste;
}
void employes::set_hdt(int hdt)
{
    this->hdt=hdt;
}


bool employes::Ajouter()
{

    QSqlQuery query;
    QString id_string= QString::number(ID);

          query.prepare("INSERT INTO Employes(nom_employes,prenom_employes,ID,mail,salaire,poste,hdt)"
                        "VALUES (:NOM, :PRENOM, :ID, :MAIL, :SALAIRE, :POSTE, :HDT)");
          query.bindValue(":NOM", nom_employes);
          query.bindValue(":PRENOM", prenom_employes);
          query.bindValue(":ID", ID);
          query.bindValue(":MAIL", mail);
          query.bindValue(":SALAIRE", salaire);
          query.bindValue(":POSTE  ", poste);
          query.bindValue(":HDT", hdt);



         return query.exec();
}


bool employes::modifier(){
    QSqlQuery query;
    query.prepare("INSERT INTO Employes(nom_employes,prenom_employes,ID,mail,salaire,poste,hdt)"
                  "VALUES (:NOM, :PRENOM, :ID, :MAIL, :SALAIRE, :POSTE, :HDT)");
    query.bindValue(":NOM", nom_employes);
    query.bindValue(":PRENOM", prenom_employes);
    query.bindValue(":ID", ID);
    query.bindValue(":MAIL", mail);
    query.bindValue(":SALAIRE", salaire);
    query.bindValue(":POSTE  ", poste);
    query.bindValue(":HDT", hdt);

    return query.exec();
}

QSqlQueryModel* employes::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT * FROM Fournisseur");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom_employes"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom_employes"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("mail"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("salaire"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("poste"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("hdt"));


    return model;
}

bool employes::supprimer(int id)
{
    QSqlQuery query;

          query.prepare(" Delete from Fournisseur where id=:id");
          query.bindValue(0,id);

         return query.exec();
}

bool employes::RechercheemployesParID(int IDrecherche)
{
    QSqlQuery query;

    query.prepare("SELECT * FROM Fournisseur WHERE id=:IDrecherche");
    query.bindValue(":IDrecherche",IDrecherche);
    query.exec();
    if (!query.first()){
        return false;
    }
    else
    {
        int nID = query.record().indexOf("ID");
        int nNom=query.record().indexOf("nom_employes");
        int nPrenom=query.record().indexOf("prenom_employes");
        int nMail=query.record().indexOf("mail");
        int nSalaire=query.record().indexOf("Salaire");
        int nPoste=query.record().indexOf("Poste");
        int nHDT=query.record().indexOf("HDT");

        nom_employes=query.value(nNom).toString();
        prenom_employes=query.value(nPrenom).toString();

        ID=query.value(nID).toInt();
        mail=query.value(nMail).toString();
        salaire=query.value(nSalaire).toInt();
        poste=query.value(nPoste).toString();
        hdt=query.value(nHDT).toInt();


        return true;
    }

}
/*
QSqlQueryModel * Fournisseur::tri_ID()
{
    QSqlQueryModel *model= new QSqlQueryModel;
    QSqlQuery *q=new QSqlQuery();
    q->prepare("select * from Fournisseur order by id  asc");
    q->exec();
    model->setQuery(*q);
    return  model;
}

QSqlQueryModel * Fournisseur::tri_nom()
{
    QSqlQueryModel *model= new QSqlQueryModel;
    QSqlQuery *q=new QSqlQuery();
    q->prepare("select * from Fournisseur order by nom_fournisseur  asc");
    q->exec();
    model->setQuery(*q);
    return  model;
}
*/
