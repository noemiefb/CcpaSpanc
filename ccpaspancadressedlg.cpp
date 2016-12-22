#include "ccpaspancadressedlg.h"
#include "ui_ccpaspancadressedlg.h"

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlField>
#include <QSqlResult>
#include <QAbstractItemModel>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QDebug>
#include <QString>
#include <QLineEdit>
#include <QMessageBox>
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



CcpaSpancAdresseDlg::CcpaSpancAdresseDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CcpaSpancAdresseDlg)
{
    ui->setupUi(this);
    ui->pays->select("FRANCE");

    return;
}

CcpaSpancAdresseDlg::~CcpaSpancAdresseDlg()
{
    delete ui;
}

void CcpaSpancAdresseDlg::setDbIniFichiers(CcpaSpancDatabase *d, CcpaSpancFichiers *f, CcpaGeneriqueIniFile *i)
{
    this->db = d;
    this->ini = i;
    this->fichiers = f;
/*
    CcpaSpancDatabase data = *d;
    QSqlDatabase* db = data.getDb();
    QSqlDatabase dbd = *db; */
    QSqlTableModel* model= new QSqlTableModel(this);
    model->setTable("adresses");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    this->ui->pays->setDatabase(d);
    this->ui->ville->setDatabase(d);
    ui->ville->setCommune();
    ui->pays->setPays();
    ui->pays->setTable("pays");
    ui->pays->setChampCle("LIBCOG");
    ui->pays->setChampValeur("CODENUM3");
    ui->pays->setOrder("LIBCOG",Qt::AscendingOrder);
    ui->pays->creeMap();
    ui->pays->peupleCombo();
    ui->pays->setAutoCompletion(true);

    ui->pays->setValue(250);

   return ;
}

int CcpaSpancAdresseDlg::sauveNouvelleAdresse()
{
    if (this->adresse==0) {
    QSqlTableModel modelad;
    modelad.setTable("adresse");
    QSqlRecord record=modelad.record();
    modelad.setEditStrategy(QSqlTableModel::OnFieldChange);
    QString norue=ui->norue->text();
    QString typerue=ui->typerue->text();
    QString nomrue=ui->nomrue->text();
    QString commune=ui->ville->currentText();
    QString cedex=ui->cedex->text();
    QString cp=ui->cp->text();
    QString pays=ui->pays->currentText().trimmed();
    QString adresse2=ui->adresse2->text();
    QString adresse3=ui->adresse3->text();
    record.setValue("norue",norue);
    record.setValue("nomrue",nomrue);
    record.setValue("typerue",typerue);
    record.setValue("nomrue",nomrue);
    record.setValue("cedex",cedex);
    record.setValue("commune",commune);
    record.setValue("cp",cp);
    record.setValue("pays",pays);
    record.setValue("adresse2",adresse2);
    record.setValue("adresse3",adresse3);
    modelad.insertRecord(-1,record);
    return this->adresse;
    }
    else majAdresse();
 }

int CcpaSpancAdresseDlg::majAdresse()
{
        qDebug() << "Mise à jour de l'adresse no " << this->adresse ;
        if (this->adresse==0) return 0;
        QSqlTableModel modelad;
        modelad.setTable("adresse");
        modelad.setFilter("id="+ QString::number(this->adresse));
        modelad.select();
        if (modelad.rowCount()==1) {

            modelad.setEditStrategy(QSqlTableModel::OnFieldChange);
            QSqlRecord record=modelad.record(0);

            QString norue=ui->norue->text();
            QString typerue=ui->typerue->text();
            QString nomrue=ui->nomrue->text();
            int commune=ui->ville->currentIndex();
            QString cedex=ui->cedex->text();
            QString cp=ui->cp->text();
            QString pays=ui->pays->currentText().trimmed();
            QString adresse2=ui->adresse2->text();
            QString adresse3=ui->adresse3->text();
            record.setValue("norue",norue);
            record.setValue("typerue",typerue);
            record.setValue("nomrue",nomrue);
            record.setValue("commune",commune);
            record.setValue("cedex",cedex);
            record.setValue("cp",cp);
            record.setValue("pays",pays);
            record.setValue("adresse2",adresse2);
            record.setValue("adresse3",adresse3);
           modelad.setRecord(0,record);

        }
        return this->adresse;


}

int CcpaSpancAdresseDlg::editeAdresse(int i)
{
    QStringList demandes;
    qDebug()  << "Adresse " << i << endl;
    return 1;
}

void CcpaSpancAdresseDlg::on_buttonBox_accepted()
{
    if (this->sauveNouvelleAdresse() >0) {
            qDebug() << "OK insertion adresse." ;
            this->close();
    }
    else {
        qDebug() << "Echec insertion adresse " << this->adresse;

    }
    return ;
}


void CcpaSpancAdresseDlg::on_ville_currentTextChanged(const QString &arg1)
{
    QString requete_where="\"nomCommune\"='"+arg1+"'";
    QString cp=db->selectValue("cp","commune",requete_where);
    ui->cp->setText(cp);
    return ;
}

void CcpaSpancAdresseDlg::afficheAdresse() {
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
        ui->pays->setCurrentText(adresse.at(8));
    }
    return;
}

void CcpaSpancAdresseDlg::on_dossier_returnPressed()
{
    if (this->adresse > 0) majAdresse();
    else sauveNouvelleAdresse();

}

bool CcpaSpancAdresseDlg::clearMask() {
    QList<QLineEdit*> liste;

    liste.append(ui->norue);
    liste.append(ui->nomrue);
    liste.append(ui->typerue);
    liste.append(ui->cp);
    liste.append(ui->adresse2);
    liste.append(ui->adresse3);

    for (int i=0;i<liste.size();i++) {
        QLineEdit* a= liste.at(i);
        a->setText("");
    }
    ui->ville->setValue("Altenach");
    ui->pays->select("FRANCE");
    return true;
}

void CcpaSpancAdresseDlg::on_buttonBox_rejected()
{
    this->close();
}

void CcpaSpancAdresseDlg::on_pays_currentIndexChanged(int index)
{
    qDebug() << index << endl;
}

void CcpaSpancAdresseDlg::on_commune_editingFinished()
{
    QMessageBox attention;
    attention.setWindowTitle("Attention SVP");
    attention.setText("Attention de vérifier le code postal si vous saisissez une commune hors périmètre");
    attention.setButtonText(1,"Merci j'ai compris");
    attention.exec();
}

QString CcpaSpancAdresseDlg::getAdresseText()
{
    QSqlTableModel* adrmodel=new QSqlTableModel(this);
    adrmodel->setTable("adresseselectview");
    QString ids = QString::number(this->no_adresse);
    QString where="id="+ids;
    QString retour="";
    adrmodel->setFilter(where);
    if (adrmodel->select()) {
        int compte=adrmodel->rowCount();
        if (compte>0) {
            int retourIdx = adrmodel->fieldIndex("data");
            QSqlRecord record = adrmodel->record(0);
            retour = record.value(retourIdx).toString();
        }
    }
    return retour;
}


QString CcpaSpancAdresseDlg::getAdresseText(int no)
{
    QSqlTableModel* adrmodel=new QSqlTableModel();
    adrmodel->setTable("adresseselectview");
    QString ids = QString::number(no);
    QString where="id="+ids;
    QString retour="";
    adrmodel->setFilter(where);
    if (adrmodel->select()) {
        int compte=adrmodel->rowCount();
        if (compte>0) {
            int retourIdx = adrmodel->fieldIndex("data");
            QSqlRecord record = adrmodel->record(0);
            retour = record.value(retourIdx).toString();
        }
    }
    return retour;
}


void CcpaSpancAdresseDlg::setAdresse(int no) {
    QSqlTableModel* adrmodel=new QSqlTableModel(this);
    adrmodel->setTable("adresse");
    QString ids = QString::number(no);
    QString where="id="+ids;
    adrmodel->setFilter(where);
    if (adrmodel->select()) {
        int compte=adrmodel->rowCount();
        if (compte>0) {
            this->adresse=no;
            int idxNoRue = adrmodel->fieldIndex("noRue");
            int idxTypRue = adrmodel->fieldIndex("typeRue");
            int idxNomRue = adrmodel->fieldIndex("nomRue");
            int idxAdresse2 = adrmodel->fieldIndex("adresse2");
            int idxAdresse3 = adrmodel->fieldIndex("adresse3");
            int idxCp = adrmodel->fieldIndex("cp");
            int idxCommune = adrmodel->fieldIndex("commune");
            int idxCedex = adrmodel->fieldIndex("cedex");
            //int idxPays = adrmodel->fieldIndex("pays");

            QSqlRecord record =  adrmodel->record(0);
            ui->commune->setText(record.value(idxCommune).toString());
            ui->norue->setText(record.value(idxNoRue).toString());
            ui->typerue->setText(record.value(idxTypRue).toString());
            ui->nomrue->setText(record.value(idxNomRue).toString());
            ui->adresse2->setText(record.value(idxAdresse2).toString());
            ui->adresse3->setText(record.value(idxAdresse3).toString());
            ui->cp->setText(record.value(idxCp).toString());
            ui->cedex->setText(record.value(idxCedex).toString());
            ui->pays->setCurrentText(record.value(idxAdresse2).toString());

        }
    }
}
