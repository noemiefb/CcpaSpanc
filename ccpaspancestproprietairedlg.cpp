#include "ccpaspancestproprietairedlg.h"
#include "ui_ccpaspancestproprietairedlg.h"

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

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlField>
#include <QSqlResult>
#include <QAbstractItemModel>
#include <QSqlRelationalTableModel>
#include <QDebug>

#include <QListView>


CcpaSpancEstProprietaireDlg::CcpaSpancEstProprietaireDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CcpaSpancEstProprietaireDlg)
{
    ui->setupUi(this);

}

void CcpaSpancEstProprietaireDlg::setDbIniFichiers(CcpaSpancDatabase *d, CcpaSpancFichiers *f, CcpaGeneriqueIniFile *i)
{
    this->db = d;
    this->ini = i;
    this->fichiers = f;


    CcpaSpancDatabase data = *d;
    QSqlDatabase* db = data.getDb();
    QSqlDatabase dbd = *db;

    ui->proprietaire->setDatabase(d);
    ui->propriete->setDatabase(d);

    ui->proprietaire->setContact();
    ui->propriete->setPropriete();

    return ;
}



CcpaSpancEstProprietaireDlg::~CcpaSpancEstProprietaireDlg()
{
    delete ui;
}

void CcpaSpancEstProprietaireDlg::on_listView_clicked(const QModelIndex &index)
{
    qDebug() << index.data();
}

void CcpaSpancEstProprietaireDlg::on_buttonBox_accepted()
{
    int contact= ui->proprietaire->indexCourant();
    int propriete = ui->propriete->indexCourant();
    QDate debut = ui->dateEdit->date();
    QDate fin = ui->dateEdit_2->date();
    int sauve = db->insereEstProprietaire(contact,propriete,debut,fin);
    if (sauve>0) {
        qDebug() << "OK est_proprietaire : " << ui->proprietaire->currentText() << " " << ui->propriete->currentText() ;
    }
    else {
        qDebug() << "Echec: " << ui->proprietaire->currentText() << " " << ui->propriete->currentText() ;
    }
}
