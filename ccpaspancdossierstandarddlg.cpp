#include "ccpaspancdossierstandarddlg.h"
#include "ui_ccpaspancdossierstandarddlg.h"

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
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>
#include <QPushButton>
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
#include "ccpaspanccontactdlg.h"
#include "ccpaspancproprietedlg.h"


CcpaSpancDossierStandardDlg::CcpaSpancDossierStandardDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CcpaSpancDossierStandardDlg)
{
    ui->setupUi(this);
}

CcpaSpancDossierStandardDlg::~CcpaSpancDossierStandardDlg()
{
    delete ui;
}

void CcpaSpancDossierStandardDlg::setDbIniFichiers(CcpaSpancDatabase *d, CcpaSpancFichiers *f, CcpaGeneriqueIniFile *i)
{
    this->db = d;
    this->ini = i;
    this->fichiers = f;

    CcpaSpancDatabase data = *d;
    QSqlDatabase* db = data.getDb();
    QSqlDatabase dbd = *db;

        this->ui->propriete->setDatabase(d);
        this->ui->controle->setDatabase(d);
        this->ui->prTraitementComboBox->setDatabase(d);
        this->ui->traitement->setDatabase(d);
        this->ui->exutoire->setDatabase(d);
        this->ui->proprietaire->setDatabase(d);

        this->ui->propriete->setPropriete();
        this->ui->controle->setControle();
        this->ui->prTraitementComboBox->setPretraitement();
        this->ui->traitement->setTraitement();
        this->ui->exutoire->setExutoire();
        this->ui->proprietaire->setContact();

        this->ui->propriete->creeMap();

    return ;
}


bool CcpaSpancDossierStandardDlg::chercheProprieteDeDossier() {
    this->propriete = 0;
    this->propriete = db->selectValue("propriete","dossier","no="+QString::number(this->nodossier)).toInt();
    if (this->propriete>0)  return true;
    else return false;
}

bool CcpaSpancDossierStandardDlg::chercheProprietaireDeDossier() {
    this->nocontact = 0;
    QString where="propriete="+QString::number(this->propriete);
    qDebug() << "Propriétaire: where " + where;
    this->nocontact = db->selectValue("proprietaire","est_proprietaire",where).toInt();
    if (this->nocontact>0) return true;
    else return false;
}

bool CcpaSpancDossierStandardDlg::chercheAdresseDeDossier(){
    this->adresse = db->selectValue("adresse","propriete","id="+QString::number(this->propriete)).toInt();
    if (this->adresse>0) {
        return true;
    }
    else return false;
    return true;
}

bool CcpaSpancDossierStandardDlg::chercheProprieteAdresse()
{
    this->propriete=db->selectValue("propriete","propriete","adresse="+QString::number(this->adresse)).toInt();
    if (this->propriete >0) {
        return true;
    }
    return false;
}

bool CcpaSpancDossierStandardDlg::chercheControleDeDossier()
{
    this->controle=db->selectValue("controle","dossier","no="+QString::number(this->nodossier)).toInt();
    if (this->controle >0) {
        return true;
    }
    return false;
}

bool CcpaSpancDossierStandardDlg::chercheAdresseProprietaire() {
return true;
}

bool CcpaSpancDossierStandardDlg::chercheDonneesDossier() {
return true;
}

void CcpaSpancDossierStandardDlg::afficheControle()
{
    this->ui->controle->setValue(this->controle);
}

void CcpaSpancDossierStandardDlg::afficheProprietaire()
    {
        qDebug() << "On affiche le propriétaire no " << this->nocontact;
        this->ui->proprietaire->setValue(this->nocontact);
        this->ui->proprietaire->setEnabled(false);
        this->ui->plusProprietaire->setEnabled(false);
        return;
}

void CcpaSpancDossierStandardDlg::afficheDossier()
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
    QString where="no=";
    this->nodossier=ui->dossier->text().toInt();
    where.append(QString::number(this->nodossier));
    qDebug() << "ICI DEBUG DU WHERE" <<  where;
    QStringList res=db->selectFieldsOneRow(champs,"dossier",where);
    if (res.count()>0) {
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
    return;
}

void CcpaSpancDossierStandardDlg::afficheAdresse()
{
    this->ui->propriete->setValue(this->propriete);
    return;
}

void CcpaSpancDossierStandardDlg::afficheDossierDetail()
{
    if (ui->dossier->text().length()==0) {
        return;
    }
    else {
        QUrl url;
        url.setUrl("file:///"+fichiers->faitCheminComplet(QString::number(this->nodossier),"rapport","pdf"));
        QDesktopServices::openUrl(url);
        this->nodossier=ui->dossier->text().toInt();
        //this->clearMask();
        ui->dossier->setText(QString::number(nodossier));
        this->nocontact=0;
        this->adresse=0;
        this->propriete=0;
        if (db->existeDossier(this->nodossier))
        {
            qDebug() << "Cherche Propriete" ;
            if (chercheControleDeDossier()) {
                qDebug() << "Cherche Controle de dossier OK";
                this->afficheControle();
                if (chercheProprieteDeDossier())    {
                    qDebug() << "Cherche Propriete de Dossier OK" ;
                    this->affichePropriete();
                    qDebug() << "Trouvé propriete " << this->propriete ;
                    qDebug() << "Cherche adresse du dossier ";
                    this->afficheDetailPropriete();
                    if (chercheAdresseDeDossier()) {
                        qDebug() << "Trouvé adresse " << this->adresse ;
                        qDebug() << "Cherche propriétaire";
                        this->afficheAdresse();
                        if (chercheProprietaireDeDossier()) {
                            qDebug() << "Trouvé proprietaire" << this->nocontact;
                            this->afficheProprietaire();
                            qDebug() << "Cherche informations sur le dossier";
                            if (chercheDonneesDossier()) {
                                this->afficheDossier();
                            }
                        }
                    }
                }
            }
        }
        else {
            this->ui->propriete->setValue(ui->propriete->maxChampValeur());
            this->ui->proprietaire->setValue(ui->proprietaire->maxChampValeur());
        }
    }
}

void CcpaSpancDossierStandardDlg::affichePropriete() {
    this->ui->propriete->setValue(this->propriete);
    afficheDetailPropriete();
    return;
}

void CcpaSpancDossierStandardDlg::afficheDetailPropriete()
{
    QString label;
    QString where="id=" + QString::number(this->propriete);
    QStringList listFields;
    listFields.append("section");
    listFields.append("parcelle");
    listFields.append("NbPP");
    listFields.append("anneConstruction");
    listFields.append("adresse");
    QStringList rows = db->selectFieldsOneRow(listFields,"propriete",where);
    if (rows.count()>0) {

        QString sectionS = rows.value(0);
        QString parcelleS = rows.value(1);
        QString nbpS = rows.value(2);
        QString anneeS = rows.value(3);
        label="Section " + sectionS +  " parcelle " + parcelleS + " Nombre de pièces:" + nbpS;
        ui->labelPropriete->setText(label);
        ui->labelPropriete->setStyleSheet("color:black;background-color:white;border:true;");
        ui->propriete->setEnabled(false);
        ui->plusPropriete->setEnabled(false);
    }
}

bool CcpaSpancDossierStandardDlg::clearMask() {
    QList<QLineEdit*> liste;

    ui->prTraitementComboBox->setValue(0);
    ui->traitement->setValue(0);
    ui->delai->setCurrentText("1");
    ui->urgenceCheckBox->setChecked(false);
    ui->conformeCheckBox->setChecked(false);
    ui->vp->setChecked(false);
    ui->vs->setChecked(false);
    ui->plusProprietaire->setEnabled(true);
    ui->proprietaire->setEnabled(true);
    ui->effaceProprietaire->setEnabled(false);
    ui->propriete->setEnabled(true);
    ui->plusPropriete->setEnabled(true);
    ui->effaceProprietaire->setEnabled(false);
    return true;
}

void CcpaSpancDossierStandardDlg::initPropriete()
{
    ui->propriete->setPropriete();
}

int CcpaSpancDossierStandardDlg::sauveNouveauDossier()
{
    int resultat=0;
    if (this->nodossier==0) {
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

    resultat=db->insereDossier(no.toInt(),dateDossier,controle,propriete,pretraitement,traitement,agrement,vp,vs,delai.toInt(),conforme,urgence,exutoire);
    if (resultat > 0) this->nodossier=resultat;
    }
    else resultat = majDossier();
    return resultat;
}

bool CcpaSpancDossierStandardDlg::majDossier()
{
    bool retour=false;
    QString no=ui->dossier->text();
    int nod = no.toInt();
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

    int resultat=db->majDossier(nod,dateDossier,controle,propriete,pretraitement,traitement,agrement,vp,vs,delai.toInt(),conforme,urgence,exutoire);
    if (resultat > 0) retour=true;
    qDebug() << "MAJ RETOUR " << resultat ;
    return retour;

}

void CcpaSpancDossierStandardDlg::on_plusProprietaire_clicked()
{
    CcpaSpancContactDlg* contactDlg = new CcpaSpancContactDlg();
    contactDlg->setDbIniFichiers(this->db,this->fichiers,this->ini);
    contactDlg->exec();
    int contact = contactDlg->getContact();
    if (contact>0) {
        this->nocontact=contact;
        ui->proprietaire->recharge();
        ui->proprietaire->setValue(contact);
    }
}

void CcpaSpancDossierStandardDlg::on_plusPropriete_clicked()
{
    CcpaSpancProprieteDlg* propriete = new CcpaSpancProprieteDlg();
    propriete->setDbIniFichiers(db,fichiers,ini);
    propriete->exec();
    this->propriete = propriete->getPropriete();
    if (this->propriete > 0) {
        ui->propriete->recharge();
        ui->propriete->setValue(this->propriete);
        afficheDetailPropriete();
    }
}

void CcpaSpancDossierStandardDlg::on_loupeProprietaire_clicked()
{
    CcpaSpancContactDlg* contactD= new CcpaSpancContactDlg(this);
    contactD->setDbIniFichiers(this->db,this->fichiers,this->ini);
    contactD->setContact(this->nocontact);
    contactD->exec();
    this->nocontact=contactD->getContact();
    ui->proprietaire->recharge();
    ui->proprietaire->setValue(this->nocontact);
    return;
}

void CcpaSpancDossierStandardDlg::on_loupePropriete_clicked()
{
    CcpaSpancProprieteDlg* propD= new CcpaSpancProprieteDlg(this);
    propD->setDbIniFichiers(this->db,this->fichiers,this->ini);
    propD->setPropriete(this->propriete);
    propD->exec();
    this->propriete = propD->getPropriete();
    ui->propriete->recharge();
    ui->propriete->setValue(this->propriete);
    afficheDetailPropriete();
    return;
}

void CcpaSpancDossierStandardDlg::on_proprietaire_currentIndexChanged(int index)
{
    this->nocontact=ui->proprietaire->indexCourant();
    QString where="propriété in (select propriete from est_proprietaire where est_proprietaire.proprietaire="+QString::number(this->nocontact)+")";
//    ui->propriete->setWhere(where);
//    ui->propriete->creeMap();
//    ui->propriete->peupleCombo();
}

void CcpaSpancDossierStandardDlg::on_conformeCheckBox_clicked(bool checked)
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

void CcpaSpancDossierStandardDlg::on_dossier_editingFinished()
{
    qDebug() << "Affiche Dossier Detail" ;
    this->afficheDossierDetail();

}

void CcpaSpancDossierStandardDlg::on_buttonBox_accepted()
{
    if (this->nodossier == 0 ) {
        this->nodossier=this->sauveNouveauDossier();
        if (this->nodossier<=0) {
            qDebug() << "Echec insertion dossier";
        }
    }
    else {
        this->majDossier();
    }
    return ;
}

void CcpaSpancDossierStandardDlg::on_effacePropriete_clicked()
{
    QMessageBox effaceLien;
    QPushButton seulementLien;
    QPushButton lesDeux;
    seulementLien.setText("Seulement le lien");
    lesDeux.setText("Les deux");
    QString message = "Voulez-vous supprimer le lien entre ce dossier et cette propriété ou également supprimer la propriété numéro " + QString::number(this->propriete) + "?";
    effaceLien.setText(message);
    effaceLien.setWindowTitle("Changement de propriété");
    effaceLien.addButton(&seulementLien,QMessageBox::ActionRole);
    effaceLien.addButton(&lesDeux,QMessageBox::ActionRole);
    effaceLien.addButton(QMessageBox::Abort);
    effaceLien.setIcon(QMessageBox::Question);
    effaceLien.exec();

    if (effaceLien.clickedButton() == &seulementLien) {
        this->propriete=0;

    } else if (effaceLien.clickedButton() == &lesDeux) {
        this->propriete=0;
        if(db->effacePropriete(this->propriete)>0) this->propriete=0;
    }
    if (this->propriete==0)
    {
        ui->plusPropriete->setEnabled(true);
        ui->effacePropriete->setEnabled(false);
        ui->propriete->setEnabled(true);
        ui->labelPropriete->clear();
    }
}

void CcpaSpancDossierStandardDlg::on_effaceProprietaire_clicked()
{
    QMessageBox effaceLien;
    QPushButton seulementLien;
    QPushButton lesDeux;
    seulementLien.setText("Seulement le lien");
    lesDeux.setText("Les deux");
    QString message = "Voulez-vous supprimer le lien entre cette propriété et ce propriétaire ou également supprimer le propriétaire numéro " + QString::number(this->nocontact) + "?";
    effaceLien.setText(message);
    effaceLien.setWindowTitle("Changement de propriétaire");
    effaceLien.addButton(&seulementLien,QMessageBox::ActionRole);
    effaceLien.addButton(&lesDeux,QMessageBox::ActionRole);
    effaceLien.addButton(QMessageBox::Abort);
    effaceLien.setIcon(QMessageBox::Question);
    effaceLien.exec();

    if (effaceLien.clickedButton() == &seulementLien) {
        this->propriete=0;
    } else if (effaceLien.clickedButton() == &lesDeux) {
        this->propriete=0;
        if(db->effaceEstProprietaire(this->propriete,this->nocontact)>0) this->nocontact=0;
    }

}

void CcpaSpancDossierStandardDlg::on_proprietaire_currentTextChanged(const QString &arg1)
{

}
