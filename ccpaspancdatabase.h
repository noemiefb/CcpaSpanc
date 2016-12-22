#ifndef CCPASPANCDATABASE_H
#define CCPASPANCDATABASE_H

#include "ccpageneriqueinifile.h"
#include <QSqlDatabase>
#include <QObject>
#include <QList>
#include <QSqlQuery>
#include <QListWidget>
#include <QList>
#include <QStringList>
#include <QSqlError>
#include <QDate>


class CcpaSpancDatabase
{
public:
    CcpaSpancDatabase();
    ~CcpaSpancDatabase();

    bool init();
    void setFichierIni(CcpaGeneriqueIniFile*);

    //SELECT
    int selectCount(QString field,QString from,QString where="true");
    float selectSum(QString field,QString from,QString where="true");
    QString selectSumS(QString field,QString from,QString where="true");
    float selectMax(QString field,QString from,QString where="true");
    int selectExercice();
    int selectBordereauEnCours();
    int selectTitreEnCours();
    QString selectValue(QString field,QString from, QString where);
    QStringList selectValues(QString field,QString from, QString where);
    QStringList selectFieldsOneRow(QStringList fields,QString from,QString where);
    QStringList selectFormule(QString formule,QString from,QString where);
    QStringList selectAllFromWithId(QString from,QString where);
    QString codePostal(QString nomCommune);
    int retrouveNoCommune(QString commune);
    bool existeDossier(int no);

    // BORDEREAUX
    int getNombreTitresSurBordereau(int no);
    QList<int> getNumTitresSurBordereau(int no);
    bool valideExerciceBordereauFactureDateListe(int exercice, int bordereau, int titre, QDate date, QList<int> nodoss_montant);
    bool effaceExerciceBordereauMontantDateNoFacListe(QList<int> liste);
    QString noDossierIn(QList<int> liste);
    QString chercheMontantDeDossier(int no);
    bool ajouteMontantTitreDossier(int dossier,QString montant,bool remplace=true);
    int nombreFacturesEnCours();
    QString sommeFacturesEnCours();
    QString calculeNoFacture(int bordereau,int titre, int sequence);
    bool facturesVersFichier(int exercice,int bordereau);
    QString getAdresseData(int adresse);
    // INSERER ET METTRE A JOUR
    int insereContact(QString nom,QString prenom,QString titre,int societe,int adresse,QString mail,QString tel,QString fax,QString notes);
    int majContact(int id,QString nom,QString prenom,QString titre,int societe,int adresse,QString mail,QString tel,QString fax,QString notes);
    bool updateContact();

    int inserePropriete(int commune,QString section, QString prefixe, QString parcelle, int nbPP,int annee,int adresse,QString notes);
    int majPropriete(int id,int commune,QString section, QString prefixe, QString parcelle, int nbPP,int annee,int adresse,QString notes);
    int effacePropriete(int id);

    int insereAdresse(QString nr,QString tr, QString mr,QString a2,QString a3,QString v,QString cpp,QString cx,QString p);
    int majAdresse(int id,  QString nr,QString tr, QString mr,QString a2,QString a3,QString v,QString cpp,QString cx,QString p);
    QString retrouveTexteAdresse(int no);

    int insereDossier(int no,QDate date,int propriete,int controle,int pttype,int ttype,QString tagrement,bool vp,bool vs,int delai,bool conformite,bool urgence,int exutoire,int liste);
    int majDossier(int no,QDate date,int propriete,int controle,int pttype,int ttype,QString tagrement,bool vp,bool vs,int delai,bool conformite,bool urgence,int exutoire,int liste );
    int effaceDossier(int no);


    int insereEstProprietaire(int propriete,int proprietaire,QDate debut,QDate fin );
    int majEstProprietaire(int id,int propriete,int proprietaire,QDate debut,QDate fin);
    int effaceEstProprietaire(int propriete,int proprietaire);

    int insereSociete(int id,QString nomS,QString siret,int adresse,QString tel, QString fax,QString mail,QString web,bool notaire);
    int majSociete(int id,QString nomS,QString siret,int adresse,QString tel, QString fax,QString mail,QString web,bool notaire);


    bool insereDossierAFacturer(int no);
    bool enleveDossierAFacturer(int no);



    quint16 retrouveSequence(QString nomSequence);
    quint16 chercheProchain(QString nomsequence);

    bool remplisTableau(QListWidget* liste, QStringList champs,QString from,QString where);


    QSqlDatabase* getDb() { return &db; }
    QDate dateDebut;
    QDate dateFin;
private:
    QSqlDatabase db;
    QSqlQuery query;

    CcpaGeneriqueIniFile* ini;
    bool getConnexionInfo();


};

#endif // CCPASPANCDATABASE_H
