#include "ccpaspanccontactdlg.h"
#include "ccpaspanccombo.h"

#include "ccpaspancdatabase.h"
#include "ccpaspancsocietedlg.h"
#include "ccpaspancadressedlg.h"
#include "ccpaspancadresseselectdlg.h"

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


#include "ui_ccpaspanccontactdlg.h"

CcpaSpancContactDlg::CcpaSpancContactDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CcpaSpancContactDlg)
{
    ui->setupUi(this);

}

CcpaSpancContactDlg::~CcpaSpancContactDlg()
{
    delete ui;
}

void CcpaSpancContactDlg::setDbIniFichiers(CcpaSpancDatabase *d, CcpaSpancFichiers *f, CcpaGeneriqueIniFile *i)
{
    this->db = d;
    this->fichierIni = i;
    this->fichiers = f;
    CcpaSpancDatabase data = *d;
    QSqlDatabase* db = data.getDb();
    QSqlDatabase dbd = *db;

    ui->societe->setChampCle("nomSociete");
    ui->societe->setChampValeur("id");
    ui->societe->setTable("societe");
    ui->societe->setOrder("nomSociete",Qt::AscendingOrder);
    ui->societe->creeMap();
    ui->societe->peupleCombo();
    //ui->adresse->setChampCle("data");
    //ui->adresse->setChampValeur("id");
   // ui->adresse->setTable("adresseselectview");
    //ui->adresse->setOrder("commune",Qt::AscendingOrder);
   // ui->adresse->creeMap();
    //ui->adresse->peupleCombo();


    this->ui->societe->setDatabase(d);
//    this->ui->adresse->setDatabase(d);
    return ;
}

void CcpaSpancContactDlg::sauve()
{
    int ad;
    int contact=db->insereContact(ui->nom->text(),
                      ui->prenom->text(),
                      ui->titre->text(),
                      ui->societe->indexCourant(),
                      ui->adresseDonnees->text().toInt(),
                      ui->mail->text(),
                      ui->tel->text(),
                      ui->fax->text(),
                      ui->notesLineEdit->text());
    if (contact > 0) {
        qDebug() << "Le contact est propriétaire de l'adresse déclarée" << endl;
        qDebug() << "On vérifie que l'adresse est bien dans la collectivité" << endl;
        qDebug() << "1ere étape: récupérer le nom de la commune" << endl;
        QString adresseWhere = "id="+QString::number(this->adresse);
        QString communeDeAdresse = db->selectValue("commune","adresse",adresseWhere);
        if (communeDeAdresse.length()>0) {
            qDebug() << "L'adresse est à " << communeDeAdresse;
            qDebug() << "2eme étapee: On vérifie si la commune appartient à la collectivité";
            QString communeWhere = "upper(\"nomCommune\")='"+communeDeAdresse.toUpper()+"'";
            QString cp=db->selectValue("\"noCommune\"","commune",communeWhere);
            if (cp.length()>0) {
                qDebug() << "Il s'agit bien d'une commune de la collectivité.";
                qDebug() << "Cherchons maintenant si une propriété a déjà cette adresse";
                QString where="adresse="+QString::number(this->adresse);
                int propriete=db->selectValue("id","propriete",where).toInt();
                if (propriete>0) {
                    qDebug() << "Il y a bien une propriété enregistrée à cette adresse";
                    qDebug() << "On vérifie s'il y a déjà un propriétaire pour cette propriété";
                    QString estPropWhere="propriete="+QString::number(propriete);
                    QString estprop=db->selectValue("proprietaire","est_proprietaire",estPropWhere);
                    if (estprop.length()>0) {
                        qDebug() << "Il y a déjà au moins un propriétaire";
                    }
                    else {
                        int estprop=db->insereEstProprietaire(propriete,contact,db->dateDebut,db->dateFin);
                        if (estprop>0) {
                            qDebug() << "Succès insertion propriétaire <--> propriete avec dates par défaut";
                        }
                        else {
                            qDebug() << "Echec insertion propriétaire <--> propriete" << db->getDb()->lastError().databaseText();
                        }
                    }
                }
                else {
                    qDebug() << "Il n'y a pas de propriété à cette adresse";
                }
            }
            else {
                qDebug() << "Il ne s'agit pas d'une commune de la collectivité: " << communeDeAdresse;
            }
        }
    }
    this->contact=contact;
    return;
}

void CcpaSpancContactDlg::maj() {
    int retour = db->majContact(this->contact,
                      ui->nom->text(),
                      ui->prenom->text(),
                      ui->titre->text(),
                      ui->societe->indexCourant(),
                      this->adresse,
                      ui->mail->text(),
                      ui->tel->text(),
                      ui->fax->text(),
                      ui->notesLineEdit->text());
    if (retour > 0) {
    }
}

void CcpaSpancContactDlg::on_buttonBox_accepted()
{
    qDebug() << "Contact en cours: " << this->contact;
    if (this->contact > 0 )
    {
        qDebug() << "MISE A JOUR DU CONTACT";
        maj();
    }
    else {
        qDebug() << "Sauvegarde du contact";
        sauve();
    }
    return;

}

void CcpaSpancContactDlg::edit(QListWidgetItem* item) {
    QString value= item->text();
    int debut_id=value.indexOf("(")+1;
    int fin_id=value.indexOf(")")-1;
    int longueur=fin_id+1-debut_id;
    QString ids=value.mid(debut_id,longueur);
    int id=ids.toInt();
    setContact(id);
    /*
    CcpaSpancContact* contact = new CcpaSpancContact();
    contact->positionneSur("id",ids,false);
    if (contact->aRecordActif()) {
        estEdit=true;
        this->ui->no->setText(ids);
        this->contact=contact->getInt("id");
        this->ui->nom->setText(contact->getString("nomcontact"));
        this->ui->prenom->setText(contact->getString("prenomcontact"));
        this->ui->titre->setText(contact->getString("titrecontact"));
        this->ui->societe->setValue(contact->getInt("societecontact"));
        int adresse=contact->getInt("adresse");
        this->ui->adresse->setValue(adresse);
        this->ui->tel->setText(contact->getString("telcontact"));
        this->ui->mail->setText(contact->getString("mailcontact"));
        this->ui->fax->setText(contact->getString("faxcontact"));
    }
    */
    if (this->tooltipE) {
        this->tooltipE->close();
        //delete this->tooltipE;
    }
}



void CcpaSpancContactDlg::afficheListeChoix()
{
    CcpaSpancContact contact;
    QString nom=ui->nom->text();
    QString where="UPPER(nomcontact)='"+nom.toUpper()+"'";
    int compte=db->selectCount("nomcontact","contact",where);

    if (compte>0) {
        QStringList values_id=db->selectValues("id","contact",where);
        QStringListIterator* iterator=  new QStringListIterator(values_id);
        QList<QStringList> data;
        QStringList fields;
        fields.append("id");
        fields.append("nomcontact");
        fields.append("prenomcontact");
        fields.append("titrecontact");
        fields.append("societe");
        fields.append("telcontact");
        fields.append("faxcontact");
        fields.append("mailcontact");
        fields.append("notes");
        fields.append("adresse");

        this->tooltipE = new QListWidget(this);

        while (iterator->hasNext()) {
            QString courant=iterator->next();
            QString whereCourant="id="+courant;
            QStringList dataCourant=db->selectFieldsOneRow(fields,"contact",whereCourant);

            if (dataCourant.count()>0) {
                data.append(dataCourant);
                QListWidgetItem* listitem = new QListWidgetItem();
                QString presentation;
                presentation.append(dataCourant.at(3));
                presentation.append(" ");
                presentation.append(dataCourant.at(1));
                presentation.append(" ");
                presentation.append(dataCourant.at(2));
                presentation.append(" ");
                presentation.append(dataCourant.at(4));
                presentation.append(" ");
                presentation.append(dataCourant.at(7));
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

void CcpaSpancContactDlg::on_nom_editingFinished()
{
   afficheListeChoix();
}

void CcpaSpancContactDlg::on_plusSociete_clicked()
{
    CcpaSpancSocieteDlg societe;
    societe.setDbIniFichiers(this->db,this->fichiers,this->fichierIni);
    societe.exec();
    int i=societe.getSociete();
    ui->societe->setValue(i);
    return;
}

void CcpaSpancContactDlg::on_plusAdresse_clicked()
{
    CcpaSpancAdresseSelectDlg adresse;
    adresse.setDbIniFichiers(this->db,this->fichiers,this->fichierIni);
    adresse.exec();
    int i=adresse.getAdresse();
    QString data=adresse.getAdresseData();
    this->adresse=i;
    ui->adresseDonnees->setText(data);
    return;
}


void CcpaSpancContactDlg::setContact(QSqlTableModel* model) {
    if (model->rowCount()==1) {
        CcpaSpancContact* contact = new CcpaSpancContact();
        QSqlRecord contactr=model->record(0);
        int no=contactr.value("id").toInt();
        contact->setRecordActif(&contactr);
        if (contact->aRecordActif()) {
            estEdit=true;
            this->ui->no->setEnabled(false);
            this->ui->no->setText(QString::number(no));
            this->ui->nom->setText(contact->getString("nomcontact"));
            this->ui->prenom->setText(contact->getString("prenomcontact"));
            this->ui->titre->setText(contact->getString("titrecontact"));
            this->ui->societe->setValue(contact->getInt("societecontact"));
            this->adresse=contact->getInt("adresse");
            this->ui->adresseDonnees->setText(db->getAdresseData(adresse));
            this->ui->tel->setText(contact->getString("telcontact"));
            this->ui->mail->setText(contact->getString("mailcontact"));
            this->ui->fax->setText(contact->getString("faxcontact"));
        }
    }

}


void CcpaSpancContactDlg::setContact(int no) {
    CcpaSpancContact* contact = new CcpaSpancContact();
    contact->positionneSur("id",QString::number(no),false);
    if (contact->aRecordActif()) {
        estEdit=true;
        this->ui->no->setEnabled(false);
        this->ui->no->setText(QString::number(no));
        this->ui->nom->setText(contact->getString("nomcontact"));
        this->ui->prenom->setText(contact->getString("prenomcontact"));
        this->ui->titre->setText(contact->getString("titrecontact"));
        this->ui->societe->setValue(contact->getInt("societecontact"));
        this->adresse=contact->getInt("adresse");
        this->ui->adresseDonnees->setText(db->selectValue("data","adresselectview",QString("id=").append(adresse)));
        this->ui->tel->setText(contact->getString("telcontact"));
        this->ui->mail->setText(contact->getString("mailcontact"));
        this->ui->fax->setText(contact->getString("faxcontact"));

    }
}

void CcpaSpancContactDlg::on_no_editingFinished()
{
    int no = ui->no->text().toInt();
    setContact(no);
    ui->no->setEnabled(false);
    ui->titre->setFocus();
    this->contact=no;
    return;
}

void CcpaSpancContactDlg::on_plusAdresse_pressed()
{

    CcpaSpancAdresseDlg adDlg;
    adDlg.setDbIniFichiers(this->db,this->fichiers,this->fichierIni);
    adDlg.exec();
    int adresse = adDlg.getAdresse();
    ui->adresseDonnees->setText(QString::number(adresse));
    return;

}

void CcpaSpancContactDlg::on_loupeAdresse_clicked()
{
    CcpaSpancAdresseDlg adS;
    adS.setAdresse(this->adresse);
    adS.exec();
    QString texte = db->getAdresseData(this->adresse);
    ui->adresseDonnees->setText(texte);
    return;
}
