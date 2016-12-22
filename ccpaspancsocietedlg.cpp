#include "ccpaspancsocietedlg.h"
#include "ccpaspanccombo.h"

#include "ccpaspancdatabase.h"
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDebug>

#include <QListWidget>
#include <QListWidgetItem>
#include <QStringListIterator>
#include <QStringList>
#include <QRect>
#include <QObject>

#include "ccpaspancadressedlg.h"
#include "ccpaspancsocietedlg.h"
#include "ccpaspancsociete.h"

#include "ui_ccpaspancsocietedlg.h"

CcpaSpancSocieteDlg::CcpaSpancSocieteDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CcpaSpancSocieteDlg)
{
    ui->setupUi(this);

}

CcpaSpancSocieteDlg::~CcpaSpancSocieteDlg()
{
    delete ui;
}

void CcpaSpancSocieteDlg::setDbIniFichiers(CcpaSpancDatabase *d, CcpaSpancFichiers *f, CcpaGeneriqueIniFile *i)
{
    this->db = d;
    this->fichierIni = i;
    this->fichiers = f;
    CcpaSpancDatabase data = *d;
    QSqlDatabase* db = data.getDb();
    QSqlDatabase dbd = *db;


    ui->adresse->setChampCle("data");
    ui->adresse->setChampValeur("id");
    ui->adresse->setTable("adresseselectview");
    ui->adresse->setOrder("commune",Qt::AscendingOrder);
    ui->adresse->creeMap();
    ui->adresse->peupleCombo();


    this->ui->adresse->setDatabase(d);
    return ;
}

void CcpaSpancSocieteDlg::on_buttonBox_accepted()
{
    bool estNotaire=ui->checkBox->isChecked();
    int societe=db->insereSociete(-1,
                      ui->nom->text(),
                      ui->siret->text(),
                      ui->adresse->indexCourant(),
                      ui->tel->text(),
                      ui->fax->text(),
                      ui->mail->text(),
                      ui->web->text(),
                      ui->checkBox->isChecked());

    return;
}

void CcpaSpancSocieteDlg::edit(QListWidgetItem* item) {
    QString value= item->text();
    int debut_id=value.indexOf("(")+1;
    int fin_id=value.indexOf(")")-1;
    int longueur=fin_id+1-debut_id;
    QString ids=value.mid(debut_id,longueur);
    CcpaSpancSociete* societe = new CcpaSpancSociete();
    societe->positionneSur("id",ids,true);
    if (societe->aRecordActif()) {
        estEdit=true;
        this->ui->nom->setText(societe->getString("nomSociete"));
        this->ui->siret->setText(societe->getString("siret"));
        this->ui->adresse->setValue(societe->getInt("adresse"));
        this->ui->tel->setText(societe->getString("telSociete"));
        this->ui->mail->setText(societe->getString("mailSociete"));
        this->ui->fax->setText(societe->getString("faxSociete"));
        this->ui->web->setText(societe->getString("webSociete"));
        this->ui->checkBox->setChecked(societe->getBool("est_notaire"));
    }
    if (this->tooltipE) {
        this->tooltipE->close();
    }
}

void CcpaSpancSocieteDlg::afficheListeChoix()
{
    CcpaSpancContact contact;
    QString nom=ui->nom->text();
    QString where="UPPER(\"nomSociete\")='"+nom.toUpper()+"'";
    int compte=db->selectCount("nomSociete","societe",where);

    if (compte>0) {
        QStringList values_id=db->selectValues("id","societe",where);
        QStringListIterator* iterator=  new QStringListIterator(values_id);
        QList<QStringList> data;
        QStringList fields;
        fields.append("id");
        fields.append("nomSociete");
        fields.append("siret");


        this->tooltipE = new QListWidget(this);

        while (iterator->hasNext()) {
            QString courant=iterator->next();
            QString whereCourant="id="+courant;
            QStringList dataCourant=db->selectFieldsOneRow(fields,"societe",whereCourant);

            if (dataCourant.count()>0) {
                data.append(dataCourant);
                QListWidgetItem* listitem = new QListWidgetItem();
                QString presentation;
                presentation.append(dataCourant.at(1));
                presentation.append(" ");
                presentation.append(dataCourant.at(2));
                presentation.append(" ");
                presentation.append(" (");
                presentation.append(dataCourant.at(0));
                presentation.append(")");
                listitem->setText(presentation);
                this->tooltipE->addItem(listitem);
            }
        }
        QObject::connect(this->tooltipE,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(edit(QListWidgetItem*)));
        QRect geometryNom=ui->nom->geometry();
        QRect geometry=geometryNom;
        geometry.setTopLeft(geometryNom.bottomLeft());
        geometry.setHeight(geometryNom.height()*data.count());
        this->tooltipE->setGeometry(geometry);
        this->tooltipE->show();

    }
}

void CcpaSpancSocieteDlg::on_nom_editingFinished()
{
   afficheListeChoix();
}

void CcpaSpancSocieteDlg::on_plusAdresse_clicked()
{
    CcpaSpancAdresseDlg adresse;
    adresse.setDbIniFichiers(this->db,this->fichiers,this->fichierIni);
    adresse.exec();
    int j = adresse.getAdresse();
    ui->adresse->setValue(j);
}


