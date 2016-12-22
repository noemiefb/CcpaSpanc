#include "ccpaspancdossierviewdlg.h"
#include "ui_ccpaspancdossierviewdlg.h"
#include "QtSql/QSqlTableModel"
#include "QtSql/QSqlRelationalTableModel"
#include "QtSql/QSqlRecord"
#include "QtSql/QSqlQuery"
#include "QtSql/QSqlQueryModel"
#include <QDebug>
#include <QMessageBox>
#include "ccpaspancproprietedlg.h"
#include "ccpaspanccontactdlg.h"


CcpaSpancDossierViewDlg::CcpaSpancDossierViewDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CcpaSpancDossierViewDlg)
{
    ui->setupUi(this);
}

CcpaSpancDossierViewDlg::~CcpaSpancDossierViewDlg()
{
    delete ui;
}

bool CcpaSpancDossierViewDlg::setNoDossier(int nod)
{
    bool retour=false;
    dossier_model.setTable("dossierselectview");
    dossier_model.setFilter("no="+QString::number(nod));
    dossier_model.select();
    if (dossier_model.rowCount()==1) {
        retour=true;
        no=nod;
    }
    return retour;
}

void CcpaSpancDossierViewDlg::afficheDossier(int no)
{
    this->ui->label_no->setText(QString::number(no));
    if (no==0) this->setNoDossier(no);
    this->initAdresse();
    this->initAdresseP();
    this->initDossier();
    this->initProprietaire();
    this->initPropriete();
    this->exec();
    return;
}

void CcpaSpancDossierViewDlg::initAdresse()
{
    QSqlRecord courant = dossier_model.record(0);
    QString adresse= courant.value("inorue").toString() + " " + courant.value("ityperue").toString() + " " + courant.value("inomrue").toString() + " " + courant.value("icommune").toString();
    ui->label_adresse->setText(adresse);
    return;
}

void CcpaSpancDossierViewDlg::initAdresseP()
{
    QSqlRecord courant = dossier_model.record(0);
    QString adresse= courant.value("norue").toString() + " " + courant.value("typerue").toString() + " " + courant.value("nomrue").toString() + " " + courant.value("cp").toString() + " " + courant.value("ville").toString();
    ui->label_adresseP->setText(adresse);
    return;
}

void CcpaSpancDossierViewDlg::initProprietaire()
{
   QSqlRecord courant = dossier_model.record(0);
   QString proprietaire= courant.value("titrecontact").toString() + " " + courant.value("nomcontact").toString() + " " + courant.value("prenomcontact").toString();
   ui->label_proprietaire->setText(proprietaire);
   return;
}

void CcpaSpancDossierViewDlg::initPropriete()
{
    QSqlRecord courant = dossier_model.record(0);
    QString propriete = "Section: " +  courant.value("section").toString() + " Parcelle " + courant.value("parcelle").toString() + " Nb PP: " + courant.value("nbPP").toString();
    ui->label_propriete->setText(propriete);
    this->propriete=courant.value("id").toInt();
    return;
}

void CcpaSpancDossierViewDlg::initDossier()
{
    QSqlRecord courant = dossier_model.record(0);
    QString pretraitement=courant.value("type").toString();
    ui->label_pretraitement->setText(pretraitement);
    ui->label_traitement->setText(courant.value("traitement").toString());
    ui->label_ventil1->setText(courant.value("vp").toString());
    ui->label_ventil2->setText(courant.value("vs").toString());
    ui->label_conformite->setText(courant.value("conformite").toString());
    ui->label_delai->setText(courant.value("delai").toString());
    int delai = courant.value("delai").toInt();
    bool urgence = courant.value("urgence").toBool();
    QString delais;
    if (delai==4) {
        delais = "4 ans";
    }
    else if (delai==1) {
        if (urgence) delais="Dans les meilleurs délais";
        else delais = "1 an après la vente ou dans le cas d'un PC";
    }
    ui->label_delai->setText(delais);
    ui->label_exutoire->setText(courant.value("label").toString());
    return;
}

void CcpaSpancDossierViewDlg::on_groupBox_4_clicked()
{

}

void CcpaSpancDossierViewDlg::on_groupBox_2_clicked()
{

}

void CcpaSpancDossierViewDlg::on_groupBox_3_clicked()
{

}

void CcpaSpancDossierViewDlg::on_groupBox_5_clicked()
{

}

void CcpaSpancDossierViewDlg::on_modifPropriete_clicked()
{
    if (adresseIdem())
    {
        if (prevenirDouble()==QMessageBox::Cancel) return;
    }
    QSqlRecord courant = dossier_model.record();
    QSqlRelationalTableModel modelPropriete;
    modelPropriete.setTable("propriete");
    QString filter="id=(select propriete from dossier where no="+QString::number(this->no)+")";
    QString sqlreq = "select id from propriete where " + filter;
    qDebug() << sqlreq;
    modelPropriete.setFilter(filter);
    modelPropriete.select();
    if (modelPropriete.rowCount()>0) {
        CcpaSpancProprieteDlg dialog;
        dialog.setPropriete(&modelPropriete);
        dialog.exec();
    }

}

void CcpaSpancDossierViewDlg::on_modifProprietaire_clicked()
{
    if (adresseIdem())
    {
        if (prevenirDouble()==QMessageBox::Cancel) return;
    }
    QSqlRecord courant = dossier_model.record();

    QSqlRelationalTableModel modelContact;
    modelContact.setTable("contact");
    QString filter="id=(select max(proprietaire) from est_proprietaire where propriete=(select propriete from dossier where no="+QString::number(this->no)+"))";
    QString sqlreq = "select nomcontact from contact where " + filter;
    qDebug() << sqlreq;
    modelContact.setFilter(filter);
    modelContact.select();
    if (modelContact.rowCount()>0) {
        CcpaSpancContactDlg dialog;
        dialog.setContact(&modelContact);
        dialog.exec();
    }
}

int CcpaSpancDossierViewDlg::prevenirDouble()
{
    QMessageBox attention;
    attention.setIcon(QMessageBox::Warning);
    attention.setWindowTitle("Attention");
    attention.setButtonText(QMessageBox::Cancel,tr("Annuler"));
    attention.setButtonText(QMessageBox::Ok,tr("J'ai compris, je fais attention."));

    attention.setText("Le propriétaire et l'immeuble partagent la même adresse. Si vous ne voulez pas modifier simultanément les deux adresses, cliquez sur Annuler puis choisissez Copier ou Créer une adresse vierge.");
    int retour=attention.exec();
    return retour;
}

int CcpaSpancDossierViewDlg::trouveProprietaire()
{
    int retour=-1;
    QSqlRelationalTableModel modelContact;
    modelContact.setTable("contact");
    QString filter="id=(select max(proprietaire) from est_proprietaire where propriete=(select propriete from dossier where no="+QString::number(this->no)+"))";
    QString sqlreq = "select nomcontact from contact where " + filter;
    qDebug() << sqlreq;
    modelContact.setFilter(filter);
    modelContact.select();
    if (modelContact.rowCount()>0) {
        retour=modelContact.record(0).value("id").toInt();
    }
    return retour;
}


bool CcpaSpancDossierViewDlg::adresseIdem()
{
    bool retour=false;
    int contact=trouveProprietaire();
    QString requete="select c.adresse as cadresse,p.adresse as padresse from propriete p left join est_proprietaire a on a.propriete=p.id left join contact c on a.proprietaire=c.id where p.id="+QString::number(this->propriete) + " and c.id=" + QString::number(contact);
    QSqlQueryModel modele;
    QSqlQuery query;
    query.prepare(requete);
    modele.setQuery(query);
    query.exec();
    if (modele.rowCount()==1)
    {
        int cadresse=modele.record(0).value("cadresse").toInt();
        int padresse=modele.record(0).value("padresse").toInt();
        if (cadresse==padresse) {
            retour=true;
        }
    }
    return retour;
}

void CcpaSpancDossierViewDlg::on_copieAdresseProprieteProprietaire_clicked()
{
    if (adresseIdem())
    {
        return;
    }
    else {
        QSqlTableModel contact;
        contact.setTable("contact");
        contact.setFilter(QString(this->proprietaire));
        contact.select();
        contact.setEditStrategy(QSqlTableModel::OnFieldChange);
        if (contact.rowCount()==1) contact.record(0).setValue("adresse",padresse);
        int retour=contact.record(0).value("adresse").toInt();
        qDebug() << "Valeur de cadresse: " << endl;
    }
    return;
}
