#include "ccpaspancdossierinitdlg.h"
#include "ui_ccpaspancdossierinitdlg.h"

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
#include "ccpaspancproprietedlg.h"


CcpaSpancDossierInitDlg::CcpaSpancDossierInitDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CcpaSpancDossierInitDlg)
{
    ui->setupUi(this);
}

CcpaSpancDossierInitDlg::~CcpaSpancDossierInitDlg()
{
    delete ui;
}


void CcpaSpancDossierInitDlg::setDbIniFichiers(CcpaSpancDatabase *d, CcpaSpancFichiers *f, CcpaGeneriqueIniFile *i)
{
    this->db = d;
    this->ini = i;
    this->fichiers = f;

    CcpaSpancDatabase data = *d;
    QSqlDatabase* db = data.getDb();
    QSqlDatabase dbd = *db;

    this->ui->propriete->setDatabase(d);
    this->ui->propriete->setPropriete();

    this->ui->controle->setDatabase(d);
    this->ui->controle->setControle();

    int maxprop=this->ui->propriete->maxChampValeur();
    ui->propriete->setValue(maxprop);
    return ;
}



void CcpaSpancDossierInitDlg::on_buttonBox_accepted()
{
    int succes;
    int liste = (ui->liste->getText()).toInt();
    succes=db->insereDossier(ui->no->text().toInt(),QDate::currentDate(),ui->propriete->indexCourant(),ui->controle->indexCourant(),0,0,"",false,false,0,false,false,99,liste);
    if (succes>0) {
        qDebug() << "OK nouveau dossier vierge";
    }
    else {
        qDebug() << "Erreur";
    }
}

void CcpaSpancDossierInitDlg::on_toolButton_clicked()
{
    CcpaSpancProprieteDlg propriete;
    propriete.setDbIniFichiers(this->db,this->fichiers,this->ini);
    propriete.exec();
    int k=propriete.getPropriete();
    ui->propriete->setValue(k);
    return;
}
