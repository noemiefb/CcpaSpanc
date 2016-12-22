#include "ccpaspancproprietedlg.h"
#include "ui_ccpaspancproprietedlg.h"

#include "ccpaspanccombo.h"
#include "ccpaspancadressedlg.h"

#include "ccpaspancdatabase.h"
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QtSql/QSqlRelationalTableModel>
#include <QSqlRecord>
#include <QDebug>

CcpaSpancProprieteDlg::CcpaSpancProprieteDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CcpaSpancProprieteDlg)
{
    ui->setupUi(this);
    ui->commune->setCommune();
    ui->commune->creeMap();
    ui->commune->peupleCombo();

}


void CcpaSpancProprieteDlg::setDbIniFichiers(CcpaSpancDatabase *d, CcpaSpancFichiers *f, CcpaGeneriqueIniFile *i)
{
    this->db = d;
    this->fichierIni = i;
    this->fichiers = f;
    CcpaSpancDatabase data = *d;
    QSqlDatabase* db = data.getDb();
    QSqlDatabase dbd = *db;
    this->ui->commune->setDatabase(d);
    return ;
}


CcpaSpancProprieteDlg::~CcpaSpancProprieteDlg()
{
    delete ui;
}

void CcpaSpancProprieteDlg::setPropriete(QSqlRelationalTableModel* propmodel) {
    QSqlRelation relation ("adresseselectview","id","data");
    if (relation.isValid()) qDebug() << "relation ok";
    propmodel->setRelation(6,relation);
        int compte=propmodel->rowCount();
        if (compte>0) {

            QSqlRecord record =  propmodel->record(0);
            this->propriete = record.value("id").toInt();
            this->adresse = record.value("adresse").toInt();
            QString commune=record.value("Commune").toString();
            qDebug() << "Commune lue : " << commune ;
            ui->commune->setValue(record.value("Commune").toInt());
            ui->section->setText(record.value("Section").toString());
            ui->parcelle->setText(record.value("Parcelle").toString());
            ui->nbpp->setText(record.value("NbPP").toString());
            ui->annee->setText(record.value("anneConstruction").toString());
            ui->notes->setText(record.value("Commentaire").toString());
            QString adresse = record.value("data").toString();
            ui->label_adresse->setText(adresse);
            QString idadresse=record.value("adresse").toString();
            QSqlTableModel ad;
            this->adresse=idadresse.toInt();
            ad.setTable("adresseselectview");
            ad.setFilter("id="+idadresse);
            ad.select();
            if (ad.rowCount()==1) {
                ui->label_adresse->setText(ad.record(0).value("data").toString());
            }
        }


}


void CcpaSpancProprieteDlg::setPropriete(int no) {
    QSqlTableModel* propmodel=new QSqlTableModel(this);
    propmodel->setTable("propriete");
    QString ids = QString::number(no);
    QString where="id="+ids;
    propmodel->setFilter(where);
    if (propmodel->select()) {
        int compte=propmodel->rowCount();
        if (compte>0) {
            QSqlRecord record =  propmodel->record(0);
            this->propriete=record.value("id").toInt();
            QString commune=record.value("Commune").toString();
            qDebug() << "Commune lue : " << commune ;
            ui->commune->setValue(record.value("Commune").toInt());
            ui->section->setText(record.value("Section").toString());
            ui->parcelle->setText(record.value("Parcelle").toString());
            ui->nbpp->setText(record.value("NbPP").toString());
            ui->annee->setText(record.value("anneConstruction").toString());
            ui->notes->setText(record.value("Commentaire").toString());
            QString idadresse=record.value("adresse").toString();
            QSqlTableModel ad;
            this->adresse=idadresse.toInt();
            ad.setTable("adresseselectview");
            ad.setFilter("id="+idadresse);
            ad.select();
            if (ad.rowCount()==1) {
                ui->label_adresse->setText(ad.record(0).value("data").toString());
            }
            this->propriete=no;
        }
    }
}



int CcpaSpancProprieteDlg::sauve() {
    if (this->propriete==0)
    {
    qDebug() << "SAUVE " ;
    QSqlTableModel admo;
    admo.setTable("propriete");
    admo.setEditStrategy(QSqlTableModel::OnFieldChange);
    admo.setFilter("id="+QString::number(this->adresse));
    admo.select();
    if (admo.rowCount()==1)
    {
        QSqlRecord rec=admo.record(0);
        int commune=ui->commune->currentIndex()+1;
        QString section=ui->section->text();
        QString parcelle=ui->parcelle->text();
        int nb=ui->nbpp->text().toInt();
        int annee=ui->annee->text().toInt();
        QString notes=ui->notes->text();


        rec.setValue("commune",commune);
        rec.setValue("section",section);
        rec.setValue("parcelle",parcelle);
        rec.setValue("NbPP",nb);
        rec.setValue("anneConstruction",annee);
        rec.setValue("Commentaire",notes);
        rec.setValue("adresse",this->adresse);
        admo.setRecord(0,rec);
    }
    }
    else maj();
}


int CcpaSpancProprieteDlg::maj() {
    if (this->propriete==0) return 0;
    qDebug() << "MET À JOUR";
    QSqlTableModel admo;
    admo.setTable("propriete");
    admo.setEditStrategy(QSqlTableModel::OnFieldChange);
    QString test="id="+QString::number(this->propriete);
    qDebug() << test ;
    admo.setFilter(test);
    admo.select();
    if (admo.rowCount()==1)
    {
        QSqlRecord rec=admo.record(0);
        int commune=ui->commune->currentIndex()+1;
        QString section=ui->section->text();
        QString parcelle=ui->parcelle->text();
        QVariant nb=ui->nbpp->text().toInt();
        QVariant annee=ui->annee->text().toInt();
        QString notes=ui->notes->text();
        rec.setValue("commune",commune);
        rec.setValue("section",section);
        rec.setValue("parcelle",parcelle);
        rec.setValue("NbPP",nb);
        rec.setValue("anneConstuction",annee);
        rec.setValue("Commentaire",notes);
        rec.setValue("adresse",this->adresse);
        admo.setRecord(0,rec);
    }
}

void CcpaSpancProprieteDlg::on_buttonBox_accepted()
{
    if (this->propriete>0) {
        maj();
    }
    else {
        int retour=sauve();
        if (retour>0) this->propriete=retour;
    }
    return;
}


void CcpaSpancProprieteDlg::on_toolButton_clicked()
{
    CcpaSpancAdresseDlg* adresseD = new CcpaSpancAdresseDlg(this);
    if (adresseD) {
        adresseD->setDbIniFichiers(this->db,this->fichiers,this->fichierIni);
        adresseD->exec();
        this->adresse = adresseD->getAdresse();
    }
}

void CcpaSpancProprieteDlg::on_loupeAdresse_clicked()
{
    CcpaSpancAdresseDlg* adresseD = new CcpaSpancAdresseDlg(this);
    if (adresseD) {
        adresseD->setDbIniFichiers(this->db,this->fichiers,this->fichierIni);
        adresseD->setAdresse(this->adresse);
        adresseD->exec();
    }
}

void CcpaSpancProprieteDlg::on_commune_currentTextChanged(const QString &arg1)
{
    QString ids="'"+arg1.toUpper()+"'";

}

void CcpaSpancProprieteDlg::on_plusAdresse_clicked()
{
    CcpaSpancAdresseDlg* adresseD = new CcpaSpancAdresseDlg(this);
    if (adresseD) {
        adresseD->setDbIniFichiers(this->db,this->fichiers,this->fichierIni);
        adresseD->exec();
        this->adresse = adresseD->getAdresse();
    }
}



void CcpaSpancProprieteDlg::on_commune_currentIndexChanged(int index)
{

}

void CcpaSpancProprieteDlg::on_pushButton_clicked()
{
    CcpaSpancAdresseDlg adresse;
    adresse.setAdresse(this->adresse);
    adresse.exec();
    return;
}
