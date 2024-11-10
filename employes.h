#ifndef EMPLOYES_H
#define EMPLOYES_H
#include <QString>
#include <QSqlQueryModel>
#include <QImage>



class employes
{
public:
    employes();
    employes(QString,QString,int,QString,int,QString,int);
    QString get_Nom();
    QString get_prenom();
    int get_ID();
    QString get_mail();
    int get_salaire();
    QString get_poste();
    int get_hdt();



    void set_Nom(QString);
    void set_prenom(QString);
    void set_ID(int);
    void set_mail(QString);
    void set_salaire(int);
    void set_poste(QString);
    void set_hdt(int);

    bool Ajouter();
    bool modifier();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool RechercheemployesParID(int IDrecherche);
   // QSqlQueryModel *tri_ID();
   // QSqlQueryModel *tri_nom();


private:
    int ID,salaire,hdt;
    QString nom_employes,prenom_employes,mail,poste;

};

#endif // EMPLOYES_H
