#include "ccpaspancdossierdlg.h"
#include "ui_ccpaspancdossierdlg.h"

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlField>
#include <QSqlResult>
#include <QAbstractItemModel>
#include <QSqlRelationalTableModel>
#include <QDebug>
#include <QString>
#include <QLineEdit>

#include <QDate>

#include "ccpaspancfichiers.h"
#include "ccpaspancdlgretour.h"
#include "ccpaspanccreegroupe.h"
#include "ccpaspancmail.h"
#include "ccpaspanccopierapportlettre.h"
#include "ccpaspancintegrescan.h"
#include "ccpaspancdatabase.h"
#include "ccpaspancexportfactures.h"
#include "ccpaspanccontact.h"
#include "ccpaspanccombocommune.h"
#include "ccpaspanccombopays.h"
#include "ccpaspanccombotraitement.h"
#include "ccpaspanccombopretraitement.h"
#include "ccpaspancfichierlettre.h"



CcpaSpancDossierDlg::CcpaSpancDossierDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CcpaSpancDossierDlg)
{
    ui->setupUi(this);
}

CcpaSpancDossierDlg::~CcpaSpancDossierDlg()
{
    delete ui;
}

void CcpaSpancDossierDlg::setDbIniFichiers(CcpaSpancDatabase *d, CcpaSpancFichiers *f, CcpaGeneriqueIniFile *i)
{
    this->db = d;
    this->ini = i;
    this->fichiers = f;

    CcpaSpancDatabase data = *d;
    QSqlDatabase* db = data.getDb();
    QSqlDatabase dbd = *db;
    QSqlTableModel* model= new QSqlTableModel(this,dbd);
    model->setTable("adresses");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    this->ui->adresseDiff->setChecked(false);
    this->on_adresseDiff_clicked();

    //this->ui->pays->setDatabase(d);
    this->ui->ville->setDatabase(d);
    this->ui->controle->setDatabase(d);
    this->ui->prTraitementComboBox->setDatabase(d);
    this->ui->traitement->setDatabase(d);
    this->ui->exutoire->setDatabase(d);

    //this->ui->pays->setPays();
    this->ui->ville->setCommune();
    this->ui->controle->setControle();
    this->ui->prTraitementComboBox->setPretraitement();
    this->ui->traitement->setTraitement();
    this->ui->exutoire->setExutoire();



    return ;
}

// ENREGISTREMENTS

int CcpaSpancDossierDlg::sauveNouveauContact() {
    this->nocontact=0;
    QString nom = ui->nom->text();
    QString prenom = ui->prenom->text();
    QString titre = ui->civilite->currentText();
    int societe =3;
    QString mail,fax,tel,notes;
    mail=fax=tel=notes="";
    int resultat=db->insereContact(nom,prenom,titre,societe,this->adresseContact,mail,tel,fax,notes);
    if (resultat>0) {
        qDebug() << "SAUVEGARDE CONTACT " << resultat ;
        this->nocontact=resultat;
    }
    else {
        this->nocontact=0;
        qDebug() << "ERREUR SAUVEGARDE CONTACT";
    }
    afficheInfos();
    return this->nocontact;
}

int CcpaSpancDossierDlg::sauveNouvellePropriete() {
    this->propriete=0;
    QString nbPP =ui->nbPP->text();
    QString zeros;
    QString section =ui->section->text();
    QString prefixe = ui->prefixe->text();

    QString parcelle = ui->parcelle->text();
    QString annee = ui->annee->text();
    QString notes;
    int communeprop = db->retrouveNoCommune(ui->ville->currentText());
    int resultat=db->inserePropriete(communeprop, section,prefixe,parcelle,nbPP.toInt(),annee.toInt(),this->adresse,notes);
    if (resultat>0) this->propriete=resultat;
    else this->propriete=0;
    afficheInfos();
    return this->propriete;
}

int CcpaSpancDossierDlg::sauveNouveauEstProprietaire()
{
    QDate debut;
    QDate fin;
    int resultat;
    debut.setDate(1900,1,1);
    fin.setDate(2199,12,31);

    if (this->nocontact==0) sauveNouveauContact();
    if (this->propriete==0) sauveNouvellePropriete();

    resultat=db->insereEstProprietaire(this->propriete,this->nocontact,debut,fin);
    if (resultat>0) {
        this->estproprietaire=resultat;
    }
    else
    {
        this->estproprietaire=0;
    }
    afficheInfos();
    return resultat;
}

int CcpaSpancDossierDlg::sauveNouvelleAdresse()
{
    this->adresse=0;
    QString norue=ui->norue->text();
    QString typerue=ui->typerue->text();
    QString nomrue=ui->nomrue->text();
    QString commune=ui->ville->currentText();
    QString cedex=ui->cedex->text();
    QString cp=ui->cp->text();
    QString pays="FRANCE";
    QString adresse2=ui->adresse2->text();
    QString adresse3=ui->adresse3->text();
    int res=db->insereAdresse(norue,typerue,nomrue,adresse2,adresse3,commune,cp,cedex,pays);
    if (res>0) this->adresse=res;
    afficheInfos();
    return this->adresse;
 }

int CcpaSpancDossierDlg::sauveNouveauDossier()
{
    QString no=ui->dossier->text();
    bool vp,vs,conforme,urgence;
    this->nodossier=ui->dossier->text().toInt();

    QDate dateDossier = ui->date->date();
    int exutoire = ui->exutoire->indexCourant();
    int pretraitement=ui->prTraitementComboBox->indexCourant();
    int traitement=ui->traitement->indexCourant();
    int controle=ui->controle->indexCourant();
    QString agrement=ui->agrement->text();
    QString delai=ui->delai->currentText();

    if (ui->urgenceCheckBox->isChecked()) urgence=true; else urgence=false;
    if (ui->conformeCheckBox->isChecked()) conforme=true; else conforme=false;
    if (ui->vp->isChecked()) vp=true; else vp=false;
    if (ui->vs->isChecked()) vs=true; else vs=false;

    int resultat=db->insereDossier(no.toInt(),dateDossier,controle,propriete,pretraitement,traitement,agrement,vp,vs,delai.toInt(),conforme,urgence,exutoire,liste);
    if (resultat > 0) this->nodossier=resultat;
    afficheInfos();
    return resultat;
}

int CcpaSpancDossierDlg::sauveNouvelleAdresseContact() {
     QString norue=ui->norue_p->text();
     QString typerue=ui->typerue_p->text();
     QString nomrue=ui->nomrue_p->text();
     QString commune=ui->ville_p->text();
     QString cedex=ui->cedex_p->text();
     QString cp=ui->cp_p->text();
     QString pays=ui->pays_p->currentText().trimmed();
     QString adresse2=ui->adresse2_p->text();
     QString adresse3=ui->adresse3_p->text();
     qDebug() << norue << " " << typerue << nomrue << commune << cedex;
     int resultat=db->insereAdresse(norue,typerue,nomrue,adresse2,adresse3,commune,cp,cedex,pays);
     if (resultat > 0) {
        this->adresseContact=resultat;
     }
     return this->adresseContact;
}

int CcpaSpancDossierDlg::editeAdresse(int i)
{
    QStringList demandes;
    qDebug() << "Adresse " << i ;
    return 1;
}

// MISES A JOUR

int CcpaSpancDossierDlg::majContact() {
    qDebug() << "Mise à jour du contact " << this->nocontact;
    int id = this->nocontact;
    QString nom = this->ui->nom->text();
    QString prenom = this->ui->prenom->text();
    QString titre = this->ui->civilite->currentText();
    int maj = db->majContact(id,nom,prenom,titre,3,this->adresseContact,NULL,NULL,NULL,NULL);
    return maj;
}

int CcpaSpancDossierDlg::majAdresse() {
    qDebug() << "Mise à jour de l'adresse " << this->adresse;
    int id=this->no_adresse;
    QString no=this->ui->norue->text();
    QString type=this->ui->typerue->text();
    QString nom=this->ui->nomrue->text();
    QString ad2=this->ui->adresse2->text();
    QString ad3=this->ui->adresse3->text();
    QString cp=this->ui->cp->text();
    QString ville=this->ui->ville->currentText();
    QString cedex=this->ui->cedex->text();
    int maj =db->majAdresse(id,no,type,nom,ad2,ad3,ville,cp,cedex,"FRANCE");
    qDebug() << "Sortie de MAJ " << maj;
    return maj;
}

int CcpaSpancDossierDlg::majAdresseP() {
    qDebug() << "Mise à jour de l'adresse du contact" << this->adresseContact;
    int id=this->adresseContact;
    QString no=this->ui->norue_p->text();
    QString type=this->ui->typerue_p->text();
    QString nom=this->ui->nomrue_p->text();
    QString ad2=this->ui->adresse2_p->text();
    QString ad3=this->ui->adresse3_p->text();
    QString cp=this->ui->cp_p->text();
    QString ville=this->ui->ville_p->text();
    QString cedex=this->ui->cedex_p->text();
    QString pays=this->ui->pays_p->currentText();
    int maj =db->majAdresse(id,no,type,nom,ad2,ad3,ville,cp,cedex,pays);
    return maj;
}

int CcpaSpancDossierDlg::majPropriete() {
    qDebug() << "Mise à jour de la propriété " << this->propriete;
    int id=this->propriete;
    QString section = ui->section->text();
    QString prefixe = ui->prefixe->text();
    QString parcelle = ui->parcelle->text();
    int annee= ui->annee->text().toInt();
    int nb = ui->nbPP->text().toInt();
    int commune=db->retrouveNoCommune(this->ui->ville->currentText());
    int maj =db->majPropriete(id,commune,section,prefixe,parcelle,nb,annee,this->adresse,"");
    return maj;
}

int CcpaSpancDossierDlg::majDossier() {
    qDebug() << "Mise à jour du dossier " << this->nodossier;
    int id=this->nodossier;
    QDate date=this->ui->date->date();
    int controle=ui->controle->indexCourant();
    int pretrait=ui->prTraitementComboBox->indexCourant();
    int trait=ui->traitement->indexCourant();
    QString agre=ui->agrement->text();
    bool v_p = ui->vp->isChecked();
    bool v_s = ui->vs->isChecked();
    bool conf =ui->conformeCheckBox->isChecked();
    int delai = ui->delai->currentText().toInt();
    bool urge = ui->urgenceCheckBox->isChecked();
    int exu=ui->exutoire->indexCourant();
    int maj =db->majDossier(id,date,this->propriete,controle,pretrait,trait,agre,v_p,v_s,delai,conf,urge,exu,liste);
    return maj;
}


// AFFICHAGES


void CcpaSpancDossierDlg::afficheInfos()
{
    qDebug() << " ---------------------------------------------------------------- Affiche infos";
    QString legendeAP,legendeA,legendeP,legendeC;
    legendeAP = "Adresse propriétaire: " + QString::number(this->adresseContact) ;
    legendeA = "Adresse propriété: " + QString::number(this->adresse);
    legendeC = "Contact: " +QString::number(this->nocontact);
    legendeP = "Propriété: " +QString::number(this->propriete);
    ui->infoNoAdresseProprietaire->setText(legendeAP);
    ui->infoNoAdressePropriete->setText(legendeA);
    ui->infoNoProprietaire->setText(legendeC);
    ui->infoNoPropriete->setText(legendeP);
    return;
}

void CcpaSpancDossierDlg::afficheAdresse() {
    qDebug() << "Affiche Adresse";
    QStringList fields;
    fields.append("norue");
    fields.append("typerue");
    fields.append("nomrue");
    fields.append("adresse2");
    fields.append("adresse3");
    fields.append("commune");
    fields.append("cp");
    fields.append("cedex");
    fields.append("pays");
    QString where="id=";
    where.append(QString::number(this->adresse));
    qDebug() << where;
    QStringList adresse = db->selectFieldsOneRow(fields,"adresse",where);
    if (adresse.count()>0) {
        ui->norue->setText(adresse.at(0));
        ui->typerue->setText(adresse.at(1));
        ui->nomrue->setText(adresse.at(2));
        ui->adresse2->setText(adresse.at(3));
        ui->adresse3->setText(adresse.at(4));

       /* qDebug() << "Commune:" << adresse.at(5);
        ui->ville->setCurrentText(adresse.at(5)); */
        ui->cp->setText(adresse.at(6));
        ui->cedex->setText(adresse.at(7));
        //ui->pays->setCurrentText(adresse.at(8));
    }
    return;
}

void CcpaSpancDossierDlg::afficheAdresseProprietaire() {
    qDebug() << "Affiche Adresse Proprietaire";

    QStringList fields;
    fields.append("norue");
    fields.append("typerue");
    fields.append("nomrue");
    fields.append("adresse2");
    fields.append("adresse3");
    fields.append("commune");
    fields.append("cp");
    fields.append("cedex");
    fields.append("pays");
    QStringList adresseProp = db->selectFieldsOneRow(fields,"adresse","id="+QString::number(this->adresseContact));
    ui->norue_p->setText(adresseProp.at(0));
    ui->typerue_p->setText(adresseProp.at(1));
    ui->nomrue_p->setText(adresseProp.at(2));
    ui->adresse2_p->setText(adresseProp.at(3));
    ui->adresse3_p->setText(adresseProp.at(4));
    ui->ville_p->setText(adresseProp.at(5));
    ui->cp_p->setText(adresseProp.at(6));
    ui->cedex_p->setText(adresseProp.at(7));
    ui->pays_p->setCurrentText(adresseProp.at(8));
    qDebug() << "Pays:" << adresseProp.at(8);
    return;
}

void CcpaSpancDossierDlg::affichePropriete()
{
    qDebug() << "Affiche propriete " ;
    QStringList champs;
    champs.append("NbPP");
    champs.append("anneConstruction");
    champs.append("section");
    champs.append("parcelle");
    champs.append("adresse");
    champs.append("commune");
    QString where="id=";
    where.append(QString::number(this->propriete));
    qDebug() << where;
    QStringList res=db->selectFieldsOneRow(champs,"propriete",where);
    if (res.count()>0) {
        ui->nbPP->setText(res.at(0));
        ui->annee->setText(res.at(1));
        ui->section->setText(res.at(2));
        ui->parcelle->setText(res.at(3));
        this->adresse=res.at(4).toInt();
        qDebug() << "Affiche ville" ;
        ui->ville->setValue(res.at(5).toInt());
    }
    return;
}

void CcpaSpancDossierDlg::afficheProprietaire()
    {
        QStringList champs;
        champs.append("nomcontact");
        champs.append("prenomcontact");
        champs.append("titrecontact");
        champs.append("adresse");
        champs.append("mailcontact");
        champs.append("faxcontact");
        champs.append("telcontact");
        champs.append("societe");
        champs.append("notes");
        QString where="id=";
        where.append(QString::number(this->nocontact));
        qDebug() << where;
        QStringList res=db->selectFieldsOneRow(champs,"contact",where);
        if (res.count()>0) {
            ui->nom->setText(res.at(0));
            ui->prenom->setText(res.at(1));
            ui->civilite->setCurrentText(res.at(2));
            this->adresseContact=res.at(3).toInt();
        }
        return;
}

void CcpaSpancDossierDlg::afficheDossier()
{
    QStringList champs;
    champs.append("no"); // 0
    champs.append("controle"); // 1
    champs.append("pttype"); // 2
    champs.append("ttype"); // 3
    champs.append("tagrement"); // 4
    champs.append("delai"); // 5
    champs.append("conformite"); // 6
    champs.append("urgence"); // 7
    champs.append("vp"); // 8
    champs.append("vs"); // 9
    champs.append("exutoire"); // 10
    champs.append("dateCreation"); // 11
    champs.append("titre_no"); // 12
    champs.append("titre_montant"); // 13
    champs.append("titre_exercice"); // 14
    champs.append("titre_bordereau"); // 15
    champs.append("titre_date"); // 16
    champs.append("titre_facture"); // 17
    champs.append("liste"); // 18
    QString where="no=";
    this->nodossier=ui->dossier->text().toInt();
    where.append(QString::number(this->nodossier));
    qDebug() << "ICI DEBUG DU WHERE" <<  where;
    QStringList res=db->selectFieldsOneRow(champs,"dossier",where);
    if (res.count()>0) {
        afficheRapport();
        int controle =res.at(1).toInt();
        ui->controle->setValue(controle);

        int ex=res.at(10).toInt();
        qDebug() << "Exutoire: " << ex;
        ui->exutoire->setValue(ex);

        QDate dateC=CcpaGenerique::stringToDate(res.at(11));
        qDebug() << "Date: " << dateC;
        ui->date->setDate(dateC);

        int pt=res.at(2).toInt();
        qDebug() << "Pretraitement: " << pt;
        ui->prTraitementComboBox->setValue(pt);

        int tt=res.at(3).toInt();
        ui->traitement->setValue(tt);

        QString agrement=res.at(4);
        if (agrement.length()>0) {
            ui->agrement->setText(agrement);
        }
        QString titre_no=res.at(12);
        QString montant=res.at(13);
        QString exercice=res.at(14);
        QString bordereau=res.at(15);
        QString titre_date=res.at(16);
        QString titre_facture=res.at(17);
        QString ligne_facturation;
        if (ligne_facturation.length()>0) { // Numéro de facture connu donc facture réalisée
            ligne_facturation="Facture no " + titre_facture + " : dossier facturé le " + titre_date + " sur l'exercice " + exercice + " bordereau " + bordereau + " titre " + titre_no + " montant: " + montant;
            ui->facturation->setStyleSheet("background-color:green;");
        } else if (CcpaGenerique::moneyStringToFloat(montant)>0) // Numéro non attribué mais montant oui: en cours de facturation
        {
            ligne_facturation="Dossier en cours de facturation. Montant: "+ montant;
            ui->facturation->setStyleSheet("background-color:orange;");
        }
        else {
            ligne_facturation="Dossier non facturé et non en cours de facturation.";
            ui->facturation->setStyleSheet("background-color:red;");
        }
        ui->facturation->setText(ligne_facturation);

        int listelue = res.at(18).toInt();
        ui->liste->setText(QString::number(listelue));

        QString delai=res.at(5);
        ui->delai->setCurrentText(delai);

        QString conformes=res.at(6);
        QString urgences=res.at(7);
        QString vps=res.at(8);
        QString vss=res.at(9);
        qDebug() << "Conforme: "<< conformes << " Urgence: " << urgences << " VP: " << vps << " VS: " << vss ;

        this->conforme=CcpaGenerique::stringToBool(conformes);
        this->urgence=CcpaGenerique::stringToBool(urgences);
        this->vp=CcpaGenerique::stringToBool(vps);
        this->vs=CcpaGenerique::stringToBool(vss);

        ui->conformeCheckBox->setChecked(this->conforme);
        if (this->conforme) {
            ui->delai->setEnabled(false);
        }
        ui->urgenceCheckBox->setChecked(this->urgence);
        ui->vp->setChecked(this->vp);
        ui->vs->setChecked(this->vs);
    }
    else this->chercheDeFichierLettre();
    afficheInfos();
    return;
}



void CcpaSpancDossierDlg::afficheRapport()
{
    ui->texteFichier->setText("");
    QString no=ui->dossier->text();
    QString fichierLettreTxt = fichiers->faitCheminComplet(no,"lettre","txt");
    if (fichiers->existe(fichierLettreTxt))
    {
        CcpaSpancFichierLettre fichier;
        fichier.setChemin(fichierLettreTxt);
        ui->texteFichier->setText(fichier.getText());
    }
    return;
}

bool CcpaSpancDossierDlg::clearMask() {
    this->nocontact=0;
    int nosuivant=this->nodossier+1;
    this->nodossier=0;
    this->no_adresse=0;
    this->adresse=0;
    this->adresseContact=0;
    this->conforme=0;
    this->delai=0;
    this->estproprietaire=0;
    this->est_adresse_propriete=0;
    this->pretraitement=0;
    this->propriete=0;
    this->traitement=0;
    this->urgence=false;
    this->vp=false;
    this->vs=false;
    QList<QLineEdit*> liste;
    liste.append(ui->nom);
    liste.append(ui->prenom);
    liste.append(ui->ville_p);
    liste.append(ui->norue);
    liste.append(ui->norue_p);
    liste.append(ui->nomrue);
    liste.append(ui->nomrue_p);
    liste.append(ui->typerue);
    liste.append(ui->typerue_p);
    liste.append(ui->cp);
    liste.append(ui->cp_p);
    liste.append(ui->adresse2);
    liste.append(ui->adresse2_p);
    liste.append(ui->adresse3);
    liste.append(ui->adresse3_p);
    liste.append(ui->section);
    liste.append(ui->prefixe);
    liste.append(ui->parcelle);
    liste.append(ui->annee);
    liste.append(ui->nbPP);
    liste.append(ui->noCommune);
    QList<QLabel*> listeLabel;
    listeLabel.append(ui->adresseLue);
    listeLabel.append(ui->adresseLue2);
    listeLabel.append(ui->exutoireLabel_2);
    listeLabel.append(ui->proprietaireLu);
    listeLabel.append(ui->installationLabel);
    listeLabel.append(ui->infoNoAdresseProprietaire);
    listeLabel.append(ui->infoNoAdressePropriete);
    listeLabel.append(ui->infoNoProprietaire);
    listeLabel.append(ui->infoNoPropriete);
    listeLabel.append(ui->delai_label);
    listeLabel.append(ui->exutoireLabel_2);
    for (int i=0;i<liste.size();i++) {
        QLineEdit* a= liste.at(i);
        a->setText("");
    }
    for (int i=0;i<listeLabel.size();i++) {
        QLabel* a= listeLabel.at(i);
        a->setText("");
    }
    ui->texteFichier->clear();

    ui->adresseDiff->setChecked(false);

    ui->dossier->setText(QString::number(nosuivant));
    ui->prTraitementComboBox->setValue(0);
    ui->traitement->setValue(0);
    ui->civilite->setCurrentText("Monsieur");
    ui->delai->setCurrentText("1");
    ui->urgenceCheckBox->setChecked(false);
    ui->conformeCheckBox->setChecked(false);
    ui->vp->setChecked(false);
    ui->vs->setChecked(false);
    this->aChangeAdresse=false;
    this->aChangeAdresseP=false;
    this->aChangeContact=false;
    this->aChangeElemDossier=false;
    this->aChangePropriete=false;
    this->estEdit=false;
    return true;
}

void CcpaSpancDossierDlg::afficheDossierDetail()
{
    int no = ui->dossier->text().toInt();
    if (ui->dossier->text().length()==0) {
        return;
    }
    if ( db->existeDossier(no))
    {
        this->nodossier=ui->dossier->text().toInt();
        //this->clearMask();
        ui->dossier->setText(QString::number(nodossier));
        this->nocontact=0;
        this->adresse=0;
        this->adresseContact=0;
        this->propriete=0;
        qDebug() << "Cherche Propriete" ;
        if (chercheProprieteDeDossier())    {
            this->estEdit=true;
            qDebug() << "Cherche Propriete de Dossier OK" ;
            this->affichePropriete();
            qDebug() << "Trouvé propriete " << this->propriete ;
            qDebug() << "Cherche adresse du dossier ";
            if (chercheAdresseDeDossier()) {
                qDebug() << "Trouvé adresse " << this->adresse ;
                this->afficheAdresse();
                qDebug() << "Cherche propriétaire";
                if (chercheProprietaireDeDossier()) {
                    qDebug() << "Trouvé proprietaire" << this->nocontact;
                    this->afficheProprietaire();
                    qDebug() << "Adresse bien:" << this->adresse << " Adresse proprietaire:" << this->adresseContact;
                    if (this->adresseContact==this->adresse) {
                        qDebug() << "Le propriétaire habite l'immeuble";
                        ui->adresseDiff->setChecked(false);
                        this->on_adresseDiff_clicked();
                    }
                    else {
                        if (adresseContact==0) {
                            qDebug() << "Le propriétaire n'a pas d'adresse renseignée donc il habite l'immeuble" ;
                            this->adresseContact=this->adresse;
                            this->afficheAdresseProprietaire();
                        } else {
                            qDebug() << "Le propriétaire n'habite pas l'immeuble";
                            ui->adresseDiff->setChecked(true);
                            this->on_adresseDiff_clicked();
                            this->afficheAdresseProprietaire();
                        }
                    }
                    qDebug() << "Cherche informations sur le dossier";
                    if (chercheDonneesDossier()) {
                        this->afficheDossier();
                    }
                }
            }
        }
    }
    else chercheDeFichierLettre();
}

// RECHERCHES


bool CcpaSpancDossierDlg::chercheProprieteDeDossier() {
    this->propriete = 0;
    this->propriete = db->selectValue("propriete","dossier","no="+QString::number(this->nodossier)).toInt();
    if (this->propriete>0)  return true;
    else return false;
}

bool CcpaSpancDossierDlg::chercheProprietaireDeDossier() {
    this->nocontact = 0;
    this->nocontact = db->selectValue("proprietaire","est_proprietaire","propriete="+QString::number(this->propriete)).toInt();
    if (this->nocontact>0) return true;
    else return false;
}

bool CcpaSpancDossierDlg::chercheAdresseDeDossier(){
    this->adresse = db->selectValue("adresse","propriete","id="+QString::number(this->propriete)).toInt();
    if (this->adresse>0) {

    }
    else return false;
    return true;
}

bool CcpaSpancDossierDlg::chercheAdresseProprietaire() {
return true;
}


bool CcpaSpancDossierDlg::chercheDeFichierLettre()
{


    QString no=ui->dossier->text();
    QString fichierLettreTxt = fichiers->faitCheminComplet(no,"lettre","txt");
    if (fichiers->existe(fichierLettreTxt))
    {

        QRegularExpression delai("(Dans un délai.*)Liste");
        QRegularExpression exutoire("^Vers quel exutoire.*:(.*)$");

        CcpaSpancFichierLettre fichier;
        fichier.setChemin(fichierLettreTxt);

        QString date = "Visite effectu.+e le.+: ([0-9]{2}/[0-9]{2}/[0-9]{4})";
        fichier.setMotif("Date",date);
        fichier.setMotif("Propriétaire","raison sociale : ([.\\s]*)\0x0D");
        fichier.setMotif("Section","Section\\s*: ([\\d\\w]+)");
        fichier.setMotif("Parcelle","parcelles\\s*:\\s*([\\d\\w\\s]+)\n");
        fichier.setMotif("Commentaires","(L.installation .*)Avis");
        fichier.setMotif("Commune1","COMMUNE : ([A-Za-z]+)\n");
        fichier.setMotif("NbPP","habitant : (\\d*) EH\n");

        fichier.setMotif("Exutoire",&exutoire);
        fichier.setMotif("Delai",&delai);



        QRegularExpression adresse("Adresse : (.*)");
        QRegularExpression nom("Nom, prénom, raison sociale : (.*)");
        if (fichier.nbOccurences(adresse)>1) {
            QString adresse2 = fichier.getValue(adresse,2);
            this->ui->adresseLue2->setText(adresse2);
            this->ui->adresseDiff->setChecked(true);
            this->on_adresseDiff_clicked();
        }
        QString adresse1 = fichier.getValue(adresse,1);
        this->ui->adresseLue->setText(adresse1);
        this->ui->proprietaireLu->setText(fichier.getValue(nom,1));

        fichier.process();

        QString datev=fichier.getValue("Date");
        QString section = fichier.getValue("Section");
        QString parcelle = fichier.getValue("Parcelle");
        QString exutoires = fichier.getValue("Exutoire");
        QString avis = fichier.getValue("Commentaires");
        QString commune1 = fichier.getValue("Commune1");
        QString proprietaire = fichier.getValue("Propriétaire");
        QString nbpp = fichier.getValue("NbPP");
        QString delais = fichier.getValue("Delai");

        QDate dateV = CcpaGenerique::stringToDate(datev);

        if (datev.length()>0) ui->date->setDate(dateV);
        if (section.length()>0) ui->section->setText(section);
        if (parcelle.length()>0) ui->parcelle->setText(parcelle);
        if (exutoires.length()>0) ui->exutoireLabel_2->setText(exutoires);
        if (commune1.length()>0) {
            ui->noCommune->setText(QString::number(db->retrouveNoCommune(commune1)));
            this->on_noCommune_editingFinished();
            ui->cp->setText(db->codePostal(commune1));
        }
        if (proprietaire.length()>0) ui->proprietaireLu->setText(proprietaire);
        if (nbpp.length()>0) ui->nbPP->setText(nbpp);
        if (avis.length()>0) {
            ui->installationLabel->setText(avis);
        }
        ui->delai_label->setText(delais);
        ui->texteFichier->setText(fichier.getText());

    }
    return true;
}


bool CcpaSpancDossierDlg::chercheDonneesDossier() {
return true;
}

// EXECUTION

void CcpaSpancDossierDlg::valideFormulaire()
{
    QSqlDatabase* d = db->getDb();

    int propriete;
    int estprop;
    bool continue_traitement=false;
    bool succes=false;
    this->afficheRapport();
    // 1er pas, vérifier si on est en mise à jour ou en création
    // Si this->nodossier = 0 : création
    // Si this->nodosser > 0: mise à jour

    if (this->estEdit ) {
        this->majAdresse();
        this->majContact();
        this->majAdresseP();
        this->majDossier();
        this->majPropriete();
        return;
    }
    db->init();
    d->transaction();
    QSqlQuery query(*d);
    if (ui->adresseDiff->isChecked()) { // Adresse différente du bien
        qDebug() << "L'adresse du bien et celle du propriétaire sont différentes.";
        qDebug() << "Etape 1: sauvegarde de l'adresse du contact";
        int sauveAdresseC=this->sauveNouvelleAdresseContact();
        if ( sauveAdresseC >0) {
            qDebug() << "Sauvegarde de l'adresse du Contact OK";
            this->adresseContact = sauveAdresseC;
            qDebug() << "Sauvegarde du contact";
            int contact = this->sauveNouveauContact();
            if (contact > 0 ) {
                qDebug() << "Sauvegarde du contact OK";
                this->nocontact= contact;
                qDebug() << "Etape 2: sauvegarde de l'adresse du dossier";
                int adr=this->sauveNouvelleAdresse();
                if (adr>0) {
                    qDebug() << "Adresse sauvegardée";
                    continue_traitement=true;
                }
                else {
                    qDebug() << "Erreur à l'insertion de l'adresse du dossier";
                }
            }
            else {
                qDebug() << "Erreur à l'insertion du contact";
            }
        }
        else {
            qDebug() << "Erreur à l'enregistrement de l'adresse du contact";
        }
    }
    else { // Même adresse que le bien
        qDebug() << "Le propriétaire habite à la même adresse";
        int sauveAdresse = this->sauveNouvelleAdresse();
        if (sauveAdresse>0) {
            this->adresse=sauveAdresse;
            this->adresseContact=sauveAdresse;
            qDebug() << "On sauvegarde le contact";
            int contact=this->sauveNouveauContact();
            if (contact > 0) {
                qDebug() << "Sauvegarde du contact OK";
                this->nocontact=contact;
                continue_traitement=true;
            }
            else {
                qDebug() << "Erreur à l'insertion du contact";
            }
        }
        else {
            qDebug() << "Erreur à l'enregistrement de l'adresse";
        }
    }
    if(continue_traitement) {
        propriete = this->sauveNouvellePropriete();
        if (propriete > 0 ) {
            estprop=this->sauveNouveauEstProprietaire();
            qDebug() << "EstProprietaire " << estprop;
            if (estprop>0) {
                this->nodossier=this->sauveNouveauDossier();
                if (this->nodossier>0) {
                    succes=true;
                }
                else {
                    qDebug() << "Echec insertion dossier";
                }
            }
            else {
                qDebug() << "Echec insertion est_proprietaire";
            }
       }
       else {
            qDebug() << "Echec insertion propriete";
       }
    }
    else {
        qDebug() << "Echec insertion adresse ou adresse prop";
    }
    if (succes) {
        qDebug() << "Succès insertion dossier " << this->nodossier;
        if (d->commit()) {
            qDebug() << "Commit OK";
        }
        else {
            qDebug() << "Commit échec" << d->lastError().text();
        }
    }
    else {
        qDebug() << "Echec insertion dossier " << this->nodossier;
        d->rollback();
    }
    return ;
}

// SLOTS

void CcpaSpancDossierDlg::on_dossier_editingFinished()
{
    qDebug() << "Affiche Dossier Detail" ;
    this->afficheDossierDetail();
}

void CcpaSpancDossierDlg::on_conformeCheckBox_clicked(bool checked)
{
    if (checked) {
        ui->delai->setCurrentText("0");
        ui->delai->setEnabled(false);
        ui->urgenceCheckBox->setChecked(false);
        ui->urgenceCheckBox->setEnabled(false);
    }
    else {
        ui->delai->setCurrentText("1");
        ui->delai->setEnabled(true);
        ui->urgenceCheckBox->setEnabled(true);
    }
}

void CcpaSpancDossierDlg::on_dossier_cursorPositionChanged(int arg1, int arg2)
{
    int t = arg1 + arg2;
    qDebug() << t;
    return;
}

void CcpaSpancDossierDlg::on_buttonBox_accepted()
{
    valideFormulaire();
}

void CcpaSpancDossierDlg::on_ville_currentTextChanged(const QString &arg1)
{
    QString requete_where="\"nomCommune\"='"+arg1+"'";
    QString cp=db->selectValue("cp","commune",requete_where);
    ui->cp->setText(cp);
    return ;
}

void CcpaSpancDossierDlg::on_adresseDiff_clicked()
{
    bool value;
    if (ui->adresseDiff->isChecked()) {
        value=true;
    }
    else {
        value=false;
    }
    ui->adresse2_p->setEnabled(value);
    ui->adresse3_p->setEnabled(value);
    ui->norue_p->setEnabled(value);
    ui->typerue_p->setEnabled(value);
    ui->nomrue_p->setEnabled(value);
    ui->ville_p->setEnabled(value);
    ui->cp_p->setEnabled(value);
    ui->cedex_p->setEnabled(value);
    ui->pays_p->setEnabled(value);
    return;

}

void CcpaSpancDossierDlg::on_pushButton_clicked()
{
    valideFormulaire();
        clearMask();
        ui->dossier->setFocus();
}

void CcpaSpancDossierDlg::on_dossier_returnPressed()
{
    this->on_buttonBox_accepted();
    this->clearMask();
}

void CcpaSpancDossierDlg::on_section_textEdited(const QString &arg1)
{
    this->aChangePropriete=true;
    return;
}

void CcpaSpancDossierDlg::on_prefixe_textChanged(const QString &arg1)
{

    this->aChangePropriete=true;
    return;
}

void CcpaSpancDossierDlg::on_prefixe_textEdited(const QString &arg1)
{


    this->aChangePropriete=true;
    return;
}

void CcpaSpancDossierDlg::on_parcelle_textEdited(const QString &arg1)
{

    this->aChangePropriete=true;
    return;
}

void CcpaSpancDossierDlg::on_nbPP_textEdited(const QString &arg1)
{

    this->aChangePropriete=true;
    return;
}

void CcpaSpancDossierDlg::on_annee_textEdited(const QString &arg1)
{
    this->aChangePropriete=true;
    return;
}

void CcpaSpancDossierDlg::on_prTraitementComboBox_currentIndexChanged(int index)
{
    this->aChangeElemDossier=true;
    return;
}

void CcpaSpancDossierDlg::on_traitement_currentIndexChanged(int index)
{
    this->aChangeElemDossier=true;
    return;
}

void CcpaSpancDossierDlg::on_agrement_textEdited(const QString &arg1)
{
    this->aChangeElemDossier=true;
    return;
}

void CcpaSpancDossierDlg::on_vp_toggled(bool checked)
{
    this->aChangeElemDossier=true;
    return;
}

void CcpaSpancDossierDlg::on_vs_toggled(bool checked)
{
    this->aChangeElemDossier=true;
    return;
}

void CcpaSpancDossierDlg::on_conformeCheckBox_toggled(bool checked)
{
    this->aChangeElemDossier=true;
    return;
}

void CcpaSpancDossierDlg::on_delai_currentIndexChanged(int index)
{
    this->aChangeElemDossier=true;
    return;
}

void CcpaSpancDossierDlg::on_urgenceCheckBox_toggled(bool checked)
{
    this->aChangeElemDossier=true;
    return;
}

void CcpaSpancDossierDlg::on_exutoire_currentIndexChanged(int index)
{
    this->aChangeElemDossier=true;
    return;
}

void CcpaSpancDossierDlg::on_date_userDateChanged(const QDate &date)
{
    this->aChangeElemDossier=true;
    return;
}

void CcpaSpancDossierDlg::on_controle_currentIndexChanged(int index)
{
    this->aChangeElemDossier=true;
    return;
}

void CcpaSpancDossierDlg::on_nom_textEdited(const QString &arg1)
{
    this->aChangeContact=true;
    return;
}

void CcpaSpancDossierDlg::on_prenom_textEdited(const QString &arg1)
{
    this->aChangeContact=true;
    return;
}

void CcpaSpancDossierDlg::on_civilite_currentIndexChanged(int index)
{
    this->aChangeContact=true;
    return;
}

void CcpaSpancDossierDlg::on_adresseDiff_toggled(bool checked)
{
    this->aChangeAdresseP=true;
    return;
}

void CcpaSpancDossierDlg::on_norue_p_textEdited(const QString &arg1)
{
    this->aChangeAdresseP=true;
    return;
}

void CcpaSpancDossierDlg::on_typerue_p_textEdited(const QString &arg1)
{
    this->aChangeAdresseP=true;
    return;
}

void CcpaSpancDossierDlg::on_nomrue_p_textEdited(const QString &arg1)
{
    this->aChangeAdresseP=true;
    return;
}

void CcpaSpancDossierDlg::on_adresse2_p_textEdited(const QString &arg1)
{
    this->aChangeAdresseP=true;
    return;
}

void CcpaSpancDossierDlg::on_adresse3_p_textEdited(const QString &arg1)
{
    this->aChangeAdresseP=true;
    return;
}

void CcpaSpancDossierDlg::on_ville_p_textEdited(const QString &arg1)
{
    this->aChangeAdresseP=true;
    return;
}

void CcpaSpancDossierDlg::on_cp_p_textEdited(const QString &arg1)
{
    this->aChangeAdresseP=true;
    return;
}

void CcpaSpancDossierDlg::on_cedex_p_textEdited(const QString &arg1)
{
    this->aChangeAdresseP=true;
    return;
}

void CcpaSpancDossierDlg::on_pays_p_currentIndexChanged(int index)
{
    this->aChangeAdresseP=true;
    return;
}

void CcpaSpancDossierDlg::on_norue_textEdited(const QString &arg1)
{
    this->aChangeAdresse=true;
}

void CcpaSpancDossierDlg::on_typerue_textEdited(const QString &arg1)
{
    this->aChangeAdresseP=true;
    return;
}

void CcpaSpancDossierDlg::on_nomrue_textEdited(const QString &arg1)
{
    this->aChangeAdresseP=true;
    return;
}

void CcpaSpancDossierDlg::on_adresse2_textEdited(const QString &arg1)
{   this->aChangeAdresseP=true;
    return;

}

void CcpaSpancDossierDlg::on_adresse3_textEdited(const QString &arg1)
{   this->aChangeAdresseP=true;
    return;

}

void CcpaSpancDossierDlg::on_ville_currentIndexChanged(int index)
{
    this->aChangeAdresse=true;
    ui->noCommune->setText(QString::number(ui->ville->indexCourant()));
    ui->cp->setText(db->codePostal(ui->noCommune->text()));
    return;

}

void CcpaSpancDossierDlg::on_cp_textEdited(const QString &arg1)
{   this->aChangeAdresseP=true;
    return;

}

void CcpaSpancDossierDlg::on_cedex_textEdited(const QString &arg1)
{
    this->aChangeAdresseP=true;
    return;
}

void CcpaSpancDossierDlg::on_noCommune_editingFinished()
{
    qDebug() << "Changement de ville par numéro";
    QString no=ui->noCommune->text();
    qDebug() << "Numéro: " << no;
    ui->ville->setValue(no.toInt());
    ui->cp->setText(db->codePostal(ui->ville->currentText()));
    ui->section->setFocus();
    return;
}

void CcpaSpancDossierDlg::on_noCommune_textChanged(const QString &arg1)
{
    this->aChangeAdresse=true;
}

void CcpaSpancDossierDlg::on_norue_textChanged(const QString &arg1)
{
    this->aChangeAdresse=true;
}

void CcpaSpancDossierDlg::on_typerue_textChanged(const QString &arg1)
{
    this->aChangeAdresse=true;
}

void CcpaSpancDossierDlg::on_nomrue_textChanged(const QString &arg1)
{
    this->aChangeAdresse=true;
}

void CcpaSpancDossierDlg::on_adresse2_textChanged(const QString &arg1)
{
    this->aChangeAdresse=true;
}

void CcpaSpancDossierDlg::on_adresse3_textChanged(const QString &arg1)
{
    this->aChangeAdresse=true;
}

void CcpaSpancDossierDlg::on_cp_textChanged(const QString &arg1)
{
    this->aChangeAdresse=true;
}



void CcpaSpancDossierDlg::on_effaceBouton_clicked()
{
    this->clearMask();
    this->ui->dossier->setFocus();
    return;
}
