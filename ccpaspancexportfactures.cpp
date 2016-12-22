#include "ccpaspancexportfactures.h"
#include "ui_ccpaspancexportfactures.h"
#include "ccpagenerique.h"

#include <QMessageBox>
#include <QSqlTableModel>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QSqlError>
#include <QAbstractItemModel>
#include <QSqlRecord>
#include <QHeaderView>
#include <QModelIndexList>
#include <QSqlQueryModel>
#include <QStandardItem>

#include <QDebug>
#include <QMenu>


CcpaSpancExportFactures::CcpaSpancExportFactures(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CcpaSpancExportFactures)
{
    ui->setupUi(this);
}

CcpaSpancExportFactures::~CcpaSpancExportFactures()
{
    delete ui;
}

// -----------------------------------------------------------
//                      INITIALISATIONS
// -----------------------------------------------------------

void CcpaSpancExportFactures::setFichierIni(CcpaGeneriqueIniFile* fichier)
{
    this->fichierIni=fichier;
    return;
}
void CcpaSpancExportFactures::setDatabase(CcpaSpancDatabase* d)
{
    this->db=d;
    return;
}
void CcpaSpancExportFactures::setFichiers(CcpaSpancFichiers* fichiers)
{
    this->fichiers=fichiers;
    return;
}
void CcpaSpancExportFactures::initIniDbFichiers(CcpaGeneriqueIniFile* fichierIni,CcpaSpancDatabase* d,CcpaSpancFichiers* fichiers){
      setFichierIni(fichierIni);
      setDatabase(d);
      setFichiers(fichiers);

      //qDebug() << "Init combo pays";
      //initComboPays();
      qDebug() << "Init combo controles";
      initComboControles();
      qDebug() << "Init combo tarifs";
      initComboTarifs();
      qDebug() << "Init table";
      initTable();
      qDebug() << "MAJ total factures";
      initTotalFactures();
      qDebug() << "MAJ total montant";
      initTotalMontant();
      qDebug() << "Cherche prochain bordereau";
      ui->noBordereau->setText(QString::number(1+d->selectBordereauEnCours()));
      ui->noTitre->setText(QString::number(1+d->selectTitreEnCours()));
      ui->dateFactu->setDate(QDate::currentDate());
      return;
}
void CcpaSpancExportFactures::initComboControles()
{
    this->ui->controle->setControle();
}
/*void CcpaSpancExportFactures::initComboPays()
{
    ui->pays->setPays();
    return;
}
*/
void CcpaSpancExportFactures::initComboTarifs()
{    ui->tarif->setTarif();
    return;
}
void CcpaSpancExportFactures::initTotalFactures()
{
    qDebug() << "Calcul du nombre de factures";
    int Nombre=db->nombreFacturesEnCours();
    qDebug() << Nombre << " facture(s) trouvée(s)";
    this->ui->nbDossiers->setText(QString::number(Nombre));
    return;
}
void CcpaSpancExportFactures::initTotalMontant()
{
   qDebug() <<"Calcul du montant total des factures";
   QVariant reponse= db->sommeFacturesEnCours();
   qDebug() <<"Trouvé: " << reponse;
   ui->totalFacture->setText(reponse.toString());
   qDebug() << reponse.toString();
   QString Sum=db->sommeFacturesEnCours();
   qDebug() << Sum << " Euros à percevoir";
   this->ui->totalFacture->setText(Sum);
   return;
}
void CcpaSpancExportFactures::initTable()
{
   QSqlQueryModel* model = new QSqlQueryModel();
   QSqlQuery* query = new QSqlQuery();
   qDebug() << "INIT TABLE";
   QString recherche="select no as \"Dossier\", k.libelle as \"Contrôle\", titre_montant as \"Montant\" ,"
                     " a.commune as \"Commune\" , concat(nomcontact,' ',prenomcontact) as \"Propriétaire\" "
                     " from dossier d join controle k on k.code=d.controle "
                     " join propriete p on p.id=d.propriete"
                     " join adresse a on a.id=p.adresse "
                     " join est_proprietaire op on op.propriete=p.id"
                     " join contact c on c.id=op.proprietaire  "
                     "where no in (select no_dossier from dossiers_factures_en_cours)";
   qDebug() << recherche;
   query->prepare(recherche);
   if (query->exec())
   {
       model->setQuery(*query);
       model->setHeaderData(0,Qt::Vertical,"detail");
       qDebug() << "TABLE ROWCOUNT " << model->rowCount();
       ui->listView->setModel(model);
       qDebug() << model->lastError().databaseText();
       qDebug() << "FIN TABLE";
   }
   else {
       qDebug() << "Erreur: " << model->lastError().databaseText();
   }
   ui->listView->setSelectionBehavior(QAbstractItemView::SelectRows);

   //ui->listView->addAction(new QAction());
   return ;
}

// ----------------------------------------------------------
//                      CONTROLES
// ----------------------------------------------------------

bool CcpaSpancExportFactures::dossierDejaAFacturer()
{
    bool deja=false;
    qDebug() << "Dans fonction: Dossier déjà à facturer";
    QString no_dossier=ui->noDossier->text();
    if (no_dossier.length()==0) return false;

    QSqlTableModel dossierModel;
    QString where="no_dossier="+no_dossier;
    dossierModel.setTable("dossiers_factures_en_cours");
    dossierModel.setFilter(where);
    dossierModel.select();
    if (dossierModel.rowCount()>0) {
        qDebug() << "Dossier déjà présent dans la table à facturer";
        QMessageBox info;
        info.setText("Ce dossier est déjà dans la liste des dossiers à facturer.");
        info.exec();
        deja=true;
    }
    qDebug() << "Retour: " << deja;
    return deja;
}
bool CcpaSpancExportFactures::dossierDejaFacture()
{
    bool deja=false;
    qDebug() << "Dans fonction: dossier déjà facturé";
    QString no_dossier=ui->noDossier->text();
    if (no_dossier.length()==0) return false;

    QSqlTableModel dossierModel;
    QString where="no="+no_dossier;
    dossierModel.setTable("dossier");
    dossierModel.setFilter(where);
    dossierModel.select();
    if (dossierModel.rowCount()>0) {
        QSqlRecord rec=dossierModel.record(0);
        int indexBordereau=rec.indexOf("titre_bordereau");
        int indexTitre=rec.indexOf("titre_no");
        int indexExercice=rec.indexOf("titre_exercice");
        int indexMontant=rec.indexOf("titre_montant");
        int bord=rec.value(indexBordereau).toInt();
        int titre=rec.value(indexTitre).toInt();
        int exercice=rec.value(indexExercice).toInt();
        QString montant=rec.value(indexMontant).toString();
        if ((bord>0) && (titre>0) && (exercice>0) ) {
            QString montant=rec.value(indexMontant).toString();
            QString message= "Dossier déjà facturé: " +montant +" " + exercice + "-" + bord + " " + titre;
            qDebug() << message;
            QMessageBox info;
            info.setText(message);
            info.exec();
            deja=true;
        }
    }
    qDebug() << "Retour: " << deja;
    return deja;
}
bool CcpaSpancExportFactures::verifieDate(QDate test) {
    QDate date;
    bool succes;
    date = QDate::currentDate();
    if (test>=date)  {
        succes=true;
    }
    else {
        QMessageBox err;
        err.setText("Date invalide: La date doit au moins être égale à la date du jour.");
        err.exec();
    }
    return succes;

}
bool CcpaSpancExportFactures::verifieBordereau(int b) {
    bool succes;
    int bmax = db->selectFormule("max(titre_bordereau)","dossier","true").at(0).toInt();
    if (b > bmax) {
        succes=true;
    }
    else {
        QMessageBox err;
        err.setText("Bordereau invalide: Le numéro doit au supérieur au dernier bordereau: " + QString::number(bmax));
        err.exec();
    }
    return succes;

}
bool CcpaSpancExportFactures::verifieTitre(int t) {
    bool succes=false;
    int tmax = db->selectFormule("max(titre_no)","dossier","true").at(0).toInt();
    if (t > tmax) {
        succes= true;
    }
    else {
        QMessageBox err;
        err.setText("Titre invalide: Le numéro doit au supérieur au dernier titre." + QString::number(tmax));
        err.exec();
    }
    return succes;

}
bool CcpaSpancExportFactures::valideNbFactures() {
    bool succes=false;
    QStringList montant = db->selectFormule("sum(titre_montant)","dossier","no in (select no_dossier from dossiers_factures_en_cours)");
    if (montant.count() > 0 ) {
        QString no=montant.at(0);
        float total=CcpaGenerique::moneyStringToFloat(no);
        if ( total > 0 ) {
            succes=true;
        }
        else {
            QMessageBox err;
            err.setText("Liste invalide: La somme à facturer est nulle.");
            err.exec();
        }
    }
    else {
        qDebug() << db->getDb()->lastError().databaseText();
    }
    return succes;
}
bool CcpaSpancExportFactures::valideFormulaireFacturation()
{
    bool succes=false;
    if (ui->totalL->text().compare("0")!=0) {
        if (verifieBordereau(ui->noBordereau->text().toInt())) {
            if (verifieTitre(ui->noTitre->text().toInt())) {
                if (verifieDate(ui->dateFactu->date())) {
                    if (valideNbFactures()) {
                        succes=true;
                    }
                }
            }
        }
    }
    return succes;
}

// -----------------------------------------------------------
//                      TRAITEMENTS
// -----------------------------------------------------------

QString renvoieChamp(QString nom,QSqlRecord* record)
{
    QString retour="";
    int i=record->indexOf(nom);
    if (i>=0) {
        retour=record->value(i).toString();
    }
    return retour;
}
void CcpaSpancExportFactures::ajouterCas()
{
    QString no_dossier=ui->noDossier->text();
    QString montant = ui->tarif->currentText();
    qDebug() << "Dossier ajout montant " << no_dossier << " " << montant;
    int no = no_dossier.toInt();
    if (no_dossier.length()==0) return;
    if (db->existeDossier(no)) {
        if (!dossierDejaFacture()) {
            if (!dossierDejaAFacturer()) {
                if (db->ajouteMontantTitreDossier(no,montant)) {
                    if (db->insereDossierAFacturer(no_dossier.toInt())) {
                        initTotalFactures();
                        initTotalMontant();
                        initTable();
                        effaceFormulaireCoordonnees();
                    }
                    else {
                        qDebug() << "Erreur d'insertion";
                    }
                }
            }
       }
   } else {
        QMessageBox alerteDossier;
        alerteDossier.setText("Ce dossier n'a pas encore été saisi");
        alerteDossier.exec();
   }
   return;
}
void CcpaSpancExportFactures::changeControle()
{
    int controleNum = ui->controle->indexCourant();
    ui->tarif->rechargeTarifs(controleNum);
    return;
}
void CcpaSpancExportFactures::menuListe(QPoint point) {
    QMenu menu(this);
    menu.addAction(new QAction("Voir",this));
    menu.addAction(new QAction("Quitter",this));
    menu.setVisible(true);
    menu.popup(point);
}
void CcpaSpancExportFactures::effaceFormulaireCoordonnees()
{
    ui->noDossier->clear();
    ui->nom->clear();
    ui->prenom->clear();
    ui->adresse1->clear();
    ui->adresse2->clear();
    ui->controle->setCurrentText("SYSTEMATIQUE");
    ui->civilite->clear();
    ui->cd->clear();
//    ui->pays->select("FRANCE");
    return;
}
void CcpaSpancExportFactures::enleveCas() {
    QItemSelectionModel *select = ui->listView->selectionModel();
    if (select->hasSelection()) {
        QModelIndexList selection = select->selectedRows();
        for(int i=0; i< selection.count(); i++) // on parcourt la liste des sélections
        {
            QModelIndex index = selection.at(i); // on prend le modèle de la sélection courante
            int row=index.row(); // on récupère le numéro de la ligne dans la vue
            int dossier =index.data().toInt();
            qDebug() << row;
            if (db->enleveDossierAFacturer(dossier)) {
                initTotalFactures();
                initTotalMontant();
                initTable();
                effaceFormulaireCoordonnees();            }
        }
    } // else: pas de sélection, rien à faire
}
void CcpaSpancExportFactures::faitFacturation() {
    if(valideFormulaireFacturation()) {
        QAbstractItemModel* model = ui->listView->model();
        int count=model->rowCount();
        int bordereau = ui->noBordereau->text().toInt();
        int titre = ui->noTitre->text().toInt();
        int exercice = db->selectExercice();
        QDate date=ui->dateFactu->date();
        QList<int> dossiers;
        for (int i=0;i<count;i++) {
            QModelIndex item = model->index(i,0);
            int no_dossier=item.data().toInt();
            qDebug() << "Je rajoute le dossier à la liste " << no_dossier;
            dossiers.append(no_dossier);
        }
        qDebug() << "Je traite les dossiers de la liste";
        if (db->valideExerciceBordereauFactureDateListe(exercice,bordereau,titre,date,dossiers)) {
            qDebug() << "Ca a marché";

            initTable();
            initTotalFactures();
            initTotalMontant();
            db->facturesVersFichier(exercice,bordereau);
        } else {
            qDebug() << "Ca a planté";
        }

    }
    return;
}

// ---------------------------------------------------------------------------------
//                          SLOTS
// ---------------------------------------------------------------------------------

void CcpaSpancExportFactures::on_pushButton_3_clicked()
{
   faitFacturation();
    return;
}
void CcpaSpancExportFactures::on_toolButton_clicked()
{
    ui->dateFactu->setDate(QDate::currentDate());
    return;
}
void CcpaSpancExportFactures::on_noDossier_textChanged(const QString &arg1)
{
    qDebug() << "on_noDossier_textChanged()" << arg1;

   initTotalFactures();
   initTotalMontant();
}
void CcpaSpancExportFactures::on_pushButton_2_clicked()
{
    enleveCas();
    return;
}
void CcpaSpancExportFactures::on_controle_currentIndexChanged(int index)
{
    qDebug() << "on_controle_currentIndexChanged()" << index;
    changeControle();
    /*
    int i=ui->controle->indexCourant();
    QString where="no="+QString::number(i);
    ui->tarif->setWhere(where);
    ui->tarif->rechargeTarifs(index); */
    return;
}
void CcpaSpancExportFactures::on_listView_customContextMenuRequested(const QPoint &pos)
{
    menuListe(pos);
}
void CcpaSpancExportFactures::on_listView_doubleClicked(const QModelIndex &index)
{
    qDebug() <<  "Row: " << index.row() << " Col: " << index.column();
    return;
}
void CcpaSpancExportFactures::on_controle_currentTextChanged(const QString &arg1)
{
    qDebug() << arg1;
    changeControle();
    return;
}
void CcpaSpancExportFactures::on_pushButton_clicked()
{
    ajouterCas();
    return;
}
void CcpaSpancExportFactures::on_noDossier_editingFinished()
{
    qDebug() << "on_noDossier_editingFinished()";
    QString noD = this->ui->noDossier->text();

        int compte;
        QString where="no="+noD;
        compte = db->selectCount("no","dossier",where);
        if (compte > 0 ) {
            QStringList demande;
            QSqlTableModel dossiersel;
            dossiersel.setTable("dossierselectview");
            dossiersel.setFilter(where);
            dossiersel.select();
            int reponses = dossiersel.rowCount();
            if (reponses>0) {
                QSqlRecord reponse=dossiersel.record(0);
                QString pays=renvoieChamp("pays",&reponse);
                QString nom=renvoieChamp("nomcontact",&reponse);
                QString prenom=renvoieChamp("prenomcontact",&reponse);
                QString civilite=renvoieChamp("titrecontact",&reponse);
                QString norue=renvoieChamp("norue",&reponse);
                QString typerue=renvoieChamp("typerue",&reponse);
                QString nomrue=renvoieChamp("nomrue",&reponse);
                QString adresse= norue + " "+typerue+ " "+nomrue;
                QString cp=renvoieChamp("cp",&reponse);
                QString commune=renvoieChamp("commune",&reponse);
                QString adresse2=renvoieChamp("adresse2",&reponse);
                QString controle=renvoieChamp("controle",&reponse);
                //this->ui->pays->setCurrentText(pays);
                this->ui->nom->setText(nom);
                this->ui->prenom->setText(prenom);
                this->ui->civilite->setText(civilite);
                this->ui->adresse1->setText(adresse);
                this->ui->adresse2->setText(adresse2);
                this->ui->cd->setText(cp);
                this->ui->ville->setText(commune);
                this->ui->controle->setCurrentText(controle);
           }
        }
}
void CcpaSpancExportFactures::on_noDossier_returnPressed()
{
    qDebug() << "on_noDossier_returnPressed()";
    return;
}

