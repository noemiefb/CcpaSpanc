#include "ccpaspancrecherchedlg.h"
#include "ui_ccpaspancrecherchedlg.h"
#include "QAbstractButton"
#include "QDebug"
#include "QSqlRecord"
#include "ccpaspancdossierviewdlg.h"

CcpaSpancRechercheDlg::CcpaSpancRechercheDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CcpaSpancRechercheDlg)
{
    ui->setupUi(this);
    this->modelDossier.setTable("dossierselectview");
    this->modelDossier.select();
    ui->tableView->setModel(&(this->modelDossier));
}

CcpaSpancRechercheDlg::~CcpaSpancRechercheDlg()
{
    delete ui;
}

void CcpaSpancRechercheDlg::on_buttonBox_clicked(QAbstractButton *button)
{
    if (button->text()=="Aide")
    qDebug() << "AIDE";
}


void CcpaSpancRechercheDlg::on_lineEdit_editingFinished()
{
    QString filter;
    QString chaine=ui->lineEdit->text().toUpper();
    filter="upper(nomcontact)='"+chaine+"' or upper(icommune)='"+chaine+"'";
    this->modelDossier.setFilter(filter);
    this->modelDossier.select();
    return;

}

void CcpaSpancRechercheDlg::on_tableView_customContextMenuRequested(const QPoint &pos)
{

}

void CcpaSpancRechercheDlg::on_tableView_doubleClicked(const QModelIndex &index)
{
    CcpaSpancDossierViewDlg dossier;
    int no=index.row();
    QSqlRecord record = this->modelDossier.record(no);
    int courant=record.value("no").toInt();
    dossier.setNoDossier(courant);
    dossier.afficheDossier(courant);
    return;
}
