#include "ccpaspancadresseselectdlg.h"
#include "ui_ccpaspancadresseselectdlg.h"


#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlField>
#include <QSqlResult>
#include <QAbstractItemModel>
#include <QSqlRelationalTableModel>
#include <QItemSelectionRange>
#include <QDebug>
#include <QString>
#include <QLineEdit>
#include <QMessageBox>
#include <QDate>
#include <QModelIndex>
#include <QModelIndexList>
#include <QMessageBox>

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




CcpaSpancAdresseSelectDlg::CcpaSpancAdresseSelectDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CcpaSpancAdresseSelectDlg)
{
    ui->setupUi(this);
}

CcpaSpancAdresseSelectDlg::~CcpaSpancAdresseSelectDlg()
{
    delete ui;
}

void CcpaSpancAdresseSelectDlg::setDbIniFichiers(CcpaSpancDatabase *d, CcpaSpancFichiers *f, CcpaGeneriqueIniFile *i)
{
    this->db = d;
    this->ini = i;
    this->fichiers = f;
/*
    CcpaSpancDatabase data = *d;
    QSqlDatabase* db = data.getDb();
    QSqlDatabase dbd = *db;
    */
    QSqlTableModel model;
    model.setTable("adresses");
    model.setEditStrategy(QSqlTableModel::OnManualSubmit);
    model.select();

    this->ui->commune->setCommuneA();
    this->ui->typeRue->setTypeRue();
    this->ui->rue->setRue();
    this->ui->commune->creeMapDistinct();
    this->ui->commune->peupleCombo();
   return ;
}


void CcpaSpancAdresseSelectDlg::on_commune_currentTextChanged(const QString &arg1)
{
    this->ui->rue->clear();
    this->ui->typeRue->clear();
    this->ui->tableView->clearMask();
    QString filtre="UPPER(\"commune\")='" + arg1.toUpper() + "'";

    this->ui->typeRue->setWhere(filtre);
    this->ui->typeRue->creeMapDistinct();
    this->ui->typeRue->peupleCombo();
}

void CcpaSpancAdresseSelectDlg::on_typeRue_currentIndexChanged(const QString &arg1)
{
    this->ui->rue->clear();
    this->ui->tableView->clearMask();

    QString commune=ui->commune->currentText().toUpper();

    QString filtre="UPPER(\"commune\")='" + commune + "' AND UPPER(\"typerue\")='" + arg1.toUpper() + "'";


    this->ui->rue->setWhere(filtre);
    this->ui->rue->creeMapDistinct();
    this->ui->rue->peupleCombo();
}

void CcpaSpancAdresseSelectDlg::on_rue_currentIndexChanged(const QString &arg1)
{
    QString commune=ui->commune->currentText().toUpper();
    QString typeRue=ui->typeRue->currentText().toUpper();
    QString rue=arg1.toUpper();
    this->ui->tableView->clearMask();

    QString filtre="id in (select id from adresse where UPPER(\"commune\")='" + commune + "' AND UPPER(\"typerue\")=UPPER('" + typeRue + "') AND upper(\"nomrue\")='"+rue+"')";
/*

    QSqlDatabase* db = this->db->getDb();
    //QSqlDatabase* db = data.getDb();
    QSqlDatabase dbd = *db;
*/
    QSqlTableModel* model = new QSqlTableModel(this);
    model->setTable("adresseselectview");
    model->setSort(0,Qt::AscendingOrder);
    model->setFilter(filtre);
    model->select();
    this->ui->tableView->setModel(model);

}

int CcpaSpancAdresseSelectDlg::getAdresse()
{
    return this->no_adresse;
}

QString CcpaSpancAdresseSelectDlg::getAdresseData()
{
    return this->texte;
}

void CcpaSpancAdresseSelectDlg::on_buttonBox_accepted()
{
    if (this->ui->tableView->selectionModel()->hasSelection())
    {
        QModelIndexList indexList = ui->tableView->selectionModel()->selectedIndexes();
        int row;int id;
        foreach (QModelIndex index, indexList) {
            row = index.row();
            id=index.data(1).toInt();
        }
    }
    else
    {
        QMessageBox rienPris;
        rienPris.setWindowTitle("Vous n'avez rien sélectionné");
        rienPris.setText("Quitter quand même?");
        rienPris.setStandardButtons(QMessageBox::Save  | QMessageBox::Cancel);
        rienPris.setDefaultButton( QMessageBox::Save);

        rienPris.setButtonText(0,"Oui");
        rienPris.setButtonText(1,"Annuler");
        int reponse=rienPris.exec();
        if (reponse==QMessageBox::Save) {
            return;
        }
        else if (reponse==QMessageBox::Cancel)
        {
            this->close();
            this->no_adresse=0;
            this->texte="";
            return;
        }
    }
    return;
}

void CcpaSpancAdresseSelectDlg::on_tableView_clicked(const QModelIndex &index)
{
    QMap <int,QVariant> ligne;
    ligne = ui->tableView->model()->itemData(index);
    int id=ligne[0].toInt();
    QString dataA=ligne[6].toString();
    qDebug() << "Index: " << id << " Détail: " << dataA;
    this->no_adresse = index.data(0).toInt();
    this->texte = index.data(6).toString();
    return;
}
