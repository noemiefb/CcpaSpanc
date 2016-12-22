#include "ccpaspancdenumerotedlg.h"
#include "ui_ccpaspancdenumerotedlg.h"

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


CcpaSpancDenumeroteDlg::CcpaSpancDenumeroteDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CcpaSpancDenumeroteDlg)
{
    ui->setupUi(this);
}

CcpaSpancDenumeroteDlg::~CcpaSpancDenumeroteDlg()
{
    delete ui;
}

void CcpaSpancDenumeroteDlg::setDbIniFichiers(CcpaSpancDatabase *d, CcpaSpancFichiers *f, CcpaGeneriqueIniFile *i)
{
    this->db = d;
    this->fichierIni = i;
    this->fichiers = f;
    CcpaSpancDatabase data = *d;
    QSqlDatabase* db = data.getDb();
    QSqlDatabase dbd = *db;
    ui->noBordereau->setText(QString::number(d->selectBordereauEnCours()));

    return ;
}

void CcpaSpancDenumeroteDlg::on_buttonBox_accepted()
{
    QString no_bordereau;
    QMessageBox confirme;
    no_bordereau=ui->noBordereau->text();
    int no=no_bordereau.toInt();
    if (no==0)
    {
        confirme.setText("Le numéro de bordereau doit être numérique...");
        confirme.setStandardButtons(QMessageBox::Ok);
        confirme.exec();
    }
    else {
        confirme.setText("Confirmez-vous la dénumérotation du bordereau ");
        confirme.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
        int retour=confirme.exec();
        if (retour == QMessageBox::Cancel) {
            qDebug() << "Dénumérotation de la facturation annulée.";
        } else {
           denumerotation(no);
        }
    }
}
 void CcpaSpancDenumeroteDlg::denumerotation(int no) {
      QList<int> liste=db->getNumTitresSurBordereau(no);
      db->effaceExerciceBordereauMontantDateNoFacListe(liste);
 }
