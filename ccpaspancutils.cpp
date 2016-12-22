#include "ccpaspancutils.h"
#include "ui_ccpaspancutils.h"



#include <QString>
#include <QStringList>
#include <QStringListIterator>
#include <QMessageBox>
#include <QSqlQuery>
#include <QAction>
#include <QList>
#include <QInputDialog>

#include "ccpaspancfichiers.h"
#include "ccpaspancdlgretour.h"
#include "ccpaspanccreegroupe.h"
#include "ccpaspancmail.h"
#include "ccpaspanccopierapportlettre.h"
#include "ccpaspancintegrescan.h"
#include "ccpaspancdatabase.h"
#include "ccpaspancexportfactures.h"
#include "ccpaspanccontactdlg.h"
#include "ccpaspancadressedlg.h"
#include "ccpaspancproprietedlg.h"
#include "ccpaspancdossierdlg.h"
#include "ccpaspancdossierinitdlg.h"
#include "ccpaspancdossierstandarddlg.h"
#include "ccpaspancsocietedlg.h"
#include "ccpaspancrecherchedlg.h"

#include "ccpaspancestproprietairedlg.h"
#include "ccpaspancdenumerotedlg.h"

CcpaSpancUtils::CcpaSpancUtils(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CcpaSpancUtils)
{
    ui->setupUi(this);
}

void CcpaSpancUtils::setIniFile(QString file) {
    fichiers = new CcpaSpancFichiers("W:");
    fichierIni = new CcpaGeneriqueIniFile();
    fichierIni->setIniFile(file);
    this->db.setFichierIni(fichierIni);
    this->db.init();
   // connect(ui->actionContacts, SIGNAL(triggered()), this, SLOT(on_contacts_clicked()));
   // connect(ui->actionAdresses, SIGNAL(triggered()), this, SLOT(on_adresses_clicked()));
   // connect(ui->actionDossiers, SIGNAL(triggered()), this, SLOT(on_dossiers_clicked()));
}


void CcpaSpancUtils::fonctionTestListItem()
{
    db.setFichierIni(this->fichierIni);
    db.init();
    QMessageBox toto;
    QVariant compte=db.selectCount("nomcontact","contact","nomContact='FREYBURGER'");
    QString chaine2=db.selectValue("nomcontact","contact","prenomcontact='Paul'");
    QListWidget test;
    QStringList fields;
    fields.append("nomcontact");
    fields.append("prenomcontact");
    db.remplisTableau(&test,fields,"contact","nomContact='FREYBURGER'");
    test.show();
    toto.setText(compte.toString()+" "+chaine2);
    toto.exec();
    return;
}

CcpaSpancUtils::~CcpaSpancUtils()
{
    delete ui;
}

void CcpaSpancUtils::on_pushButton_clicked()
{
    CcpaSpancDossierDlg z;
    z.setDbIniFichiers(&(this->db),this->fichiers,fichierIni);
    z.exec();
    /*QStringList listeAtraiter;
    QString entree = ui->editNumCas->text();

    listeAtraiter=entree.split(";");
    listeAtraiter.removeDuplicates();
    QStringListIterator it(listeAtraiter);

    while (it.hasNext()) {
        QString cas = it.next();
        ui->listNumCas->addItem(cas);
    }
    ui->editNumCas->clear();*/
}

void CcpaSpancUtils::copieCommandesVersRepertoire()
{
    /*
    QStringList source;
    QString destination = ui->lineEdit->text();
    QString resultat;
    int nombreCas=ui->listNumCas->count();
    for (int i=0;i<nombreCas;i++)
    {
        QString cascourant= ui->listNumCas->item(i)->text();
        source.append(cascourant);
    }
    source.removeDuplicates();
    nombreCas=ui->listNumCas->count();

    ui->progressBar->setEnabled(true);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(nombreCas);

    for (int i=0;i<nombreCas;i++) {
        QString num = source.at(i);
        ui->progressBar->setValue(i+1);
        QString nomfic = fichiers->faitCheminComplet(num,"commande","pdf");
        QString nouveaufic = destination + FILESEP + fichiers->faitNomFichier(num,"commande","pdf");
        if (fichiers->existe(nomfic))
        {
            resultat.append("Commande " + num + " trouvée\n");
            if (fichiers->copie(nomfic,nouveaufic)) {
                resultat.append("Commande " + num + " copiée\n");
            }
            else {
                resultat.append("Commande " + num + " non copiée\n");
            }
        }
        else {
            resultat.append("Commande " + num + " non trouvée: " + nomfic + "\n");
        }
        ui->lineEdit->setText(resultat);

    }
    QMessageBox msgBox;
    msgBox.setText(resultat);
    msgBox.exec();
    */
}

void CcpaSpancUtils::on_buttonBox_accepted()
{
    this->close();
}

void CcpaSpancUtils::on_buttonBox_rejected()
{
    this->close();
}
/*
void CcpaSpancUtils::on_editNumCas_returnPressed()
{
    on_buttonBox_accepted();
}

void CcpaSpancUtils::on_contacts_clicked()
{
    CcpaSpancContactDlg contacts;
    contacts.setDbIniFichiers(&db,fichiers,fichierIni);
    contacts.exec();
}


void CcpaSpancUtils::on_adresses_clicked()
{
    CcpaSpancAdresseDlg adresse;
    adresse.setDbIniFichiers(&db,fichiers,fichierIni);
    adresse.exec();
}



void CcpaSpancUtils::on_dossiers_clicked()
{
    CcpaSpancDossierDlg dossier;
    dossier.setDbIniFichiers(&db,fichiers,fichierIni);
    dossier.exec();
}

*/
void CcpaSpancUtils::on_btnCopieRapportLettre_clicked()
{
    ccpaSpancCopieRapportLettre rapport;
    rapport.setFichiers(fichiers);
    rapport.exec();
    return;
}

void CcpaSpancUtils::on_btnEnvoiMail_clicked()
{/*
    CcpaSpancMail mailer;
    mailer.setIniFile(fichierIni->getFilename());
    mailer.exec();*/
    return;
}

void CcpaSpancUtils::on_btnReserveGroupe_clicked()
{
    CcpaSpancCreeGroupe p;
    p.exec();
    return;
}

void CcpaSpancUtils::on_btnIntegreRapport_clicked()
{
    CcpaSpancDlgRetour D;
    D.setFichiers(this->fichiers);
    D.setFichierIni(this->fichierIni);
    D.exec();
}

void CcpaSpancUtils::on_btnIntegreScan_clicked()
{
    CcpaSpancIntegreScan p;
    p.setFichiers(this->fichiers);
    p.setFichiersIni(this->fichierIni);
    p.exec();
}
/*
void CcpaSpancUtils::on_toolButton_clicked()
{

}
*/

void CcpaSpancUtils::on_toolButton_2_clicked()
{

    CcpaSpancExportFactures toto;
    toto.initIniDbFichiers(fichierIni,&db,fichiers);
    toto.exec();
}

void CcpaSpancUtils::on_pushButton_2_clicked()
{
    CcpaSpancContactDlg contacts;
    contacts.setDbIniFichiers(&(this->db),this->fichiers,this->fichierIni);
    contacts.exec();
    return;
}

void CcpaSpancUtils::on_pushButton_3_clicked()
{
    CcpaSpancProprieteDlg propriete;
    propriete.setDbIniFichiers(&(this->db),this->fichiers,this->fichierIni);
    propriete.exec();
    return;
}

void CcpaSpancUtils::on_pushButton_4_clicked()
{
    CcpaSpancAdresseDlg adresse;
    adresse.setDbIniFichiers(&(this->db),this->fichiers,this->fichierIni);
    adresse.exec();
}

void CcpaSpancUtils::on_pushButton_5_clicked()
{
    CcpaSpancEstProprietaireDlg estprop;
    estprop.setDbIniFichiers(&(this->db),this->fichiers,this->fichierIni);
    estprop.exec();
}

void CcpaSpancUtils::on_pushButton_6_clicked()
{
    CcpaSpancDenumeroteDlg denumerote;
    denumerote.setDbIniFichiers(&(this->db),this->fichiers,this->fichierIni);
    denumerote.exec();
}


void CcpaSpancUtils::on_pushButton_8_clicked()
{
    CcpaSpancSocieteDlg societe;
    societe.setDbIniFichiers(&db,fichiers,fichierIni);
    societe.exec();
}


void CcpaSpancUtils::on_pushButton_10_clicked()
{
    QInputDialog efface;
    efface.setInputMode(QInputDialog::IntInput);
    int no = efface.getInt(this,"Quel dossier effacer?","Numéro");
    QString where="no="+QString::number(no);
    QString nom = db.selectValue("nomcontact","dossierselectview",where);
    QString prenom = db.selectValue("prenomcontact","dossierselectview",where);
    QMessageBox confirme;
    confirme.addButton(QMessageBox::Cancel);
    confirme.addButton(QMessageBox::Ok);
    confirme.setWindowTitle("Confirmez-vous la suppression de ce dossier?");
    confirme.setText(nom + " " + prenom);
    int fait=confirme.exec();
    if (fait==QMessageBox::Ok) {
        int i=db.effaceDossier(no);
        if (i>0) {
            qDebug() << "Suppression OK " << no;
        }
        else {
            qDebug() << "Echec à la suppression de " << no ;
        }
    }
    return;
}

void CcpaSpancUtils::on_rechercheBouton_clicked()
{
    CcpaSpancRechercheDlg toto;
    toto.exec();
    return;
}
