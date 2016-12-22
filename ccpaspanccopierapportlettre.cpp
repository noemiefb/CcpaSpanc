#include "ccpaspanccopierapportlettre.h"
#include "ccpaspancfichiers.h"

#include <QDebug>

#include "ui_ccpaspanccopierapportlettre.h"

ccpaSpancCopieRapportLettre::ccpaSpancCopieRapportLettre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ccpaSpancCopieRapportLettre)
{
    ui->setupUi(this);
}

ccpaSpancCopieRapportLettre::~ccpaSpancCopieRapportLettre()
{
    delete ui;
}

void ccpaSpancCopieRapportLettre::on_btnOk_clicked()
{
    int len;
    QString texte;
    texte = ui->editNo->text();
    len = texte.length();
    if (len>0) {
        ui->listWidget->addItem(texte);
        ui->listWidget->sortItems();
        ui->editNo->clear();
        ui->btnSuppr->setEnabled(true);
    }
}
void ccpaSpancCopieRapportLettre::on_pushButton_clicked()
{
    QListWidgetItem* itemCourant = ui->listWidget->currentItem();
    ui->listWidget->removeItemWidget(itemCourant);
    if(ui->listWidget->count()==0) {
        ui->btnSuppr->setEnabled(false);
    }
}

void ccpaSpancCopieRapportLettre::on_buttonBox_accepted()
{
    QString rapport;
    QList<QString> items;
    int count = ui->listWidget->count();
    for (int i=0;i<count;i++) {
        qDebug() << "Je traite le cas: " << i;
        QString dossier=ui->listWidget->item(i)->text();
        if (dossier.length()>0)
        {
            qDebug() << "Le numéro de dossier est: " << dossier;
            if (!fichiers->existe(dossier,"lettre","doc"))
            {
                qDebug() <<"Il n'existe pas de fichier lettre.doc pour ce dossier";
                QString source=fichiers->faitCheminComplet(dossier,"rapport","doc");
                QString destination=fichiers->faitCheminComplet(dossier,"lettre","doc");
                qDebug() << "Je copie " << source << " sur " << destination;
                if (fichiers->copie(source,destination))
                {
                    qDebug() << "Cela a fonctionné.";
                }
                else {
                    qDebug() << "Erreur de copie";
                }
            }
            else {
                qDebug() <<"Il existe le fichier lettre.doc pour ce dossier. Je ne fais rien.";

            }
        }
    }
}
