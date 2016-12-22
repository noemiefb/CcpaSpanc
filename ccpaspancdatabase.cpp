#include "ccpaspancdatabase.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlField>
#include <QSqlResult>
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDate>
#include <QListIterator>
#include "ccpagenerique.h"

#include <QDebug>
#include <QString>

CcpaSpancDatabase::CcpaSpancDatabase()
{
    qDebug() << "Création de la base"  ;
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("SPANC");
    this->dateDebut.setDate(1900,1,1);
    this->dateFin.setDate(2100,12,31);
}

CcpaSpancDatabase::~CcpaSpancDatabase()
{
    qDebug() << "Fermeture de la base" ;
    if (db.isOpen())
    db.close();
}

QString CcpaSpancDatabase::getAdresseData(int adresse)
{
    QString retour="";
    QSqlTableModel admod;
    admod.setTable("adresseselectview");
    QString filter="id="+QString::number(adresse);
    admod.setFilter(filter);
    admod.select();
    if (admod.rowCount()==1)
    {
        QString data=admod.record(0).value("data").toString();
        retour=data;
    }
    return retour;
}

void CcpaSpancDatabase::setFichierIni(CcpaGeneriqueIniFile* i)
{
    qDebug() << "ASSOCIATION FICHIER INI " << i->getFilename()  ;
    ini = i;
    return;
}

bool CcpaSpancDatabase::init()
{
    qDebug() << "INITIATION BASE"  ;
    if (!this->ini) {
        qDebug() << "ERREUR: Pas de fichier ini" ;
        return false;
    }
    bool connex=getConnexionInfo();
    if (connex) {
        qDebug() << "INITIATION BASE OK" ;
    }
    else {
        qDebug() << "INITIATION BASE KO : " << db.lastError().text();
    }
    return getConnexionInfo();
}

bool CcpaSpancDatabase::getConnexionInfo()
{
    qDebug() << "GET CONNEXION INFO ";
    if (!db.isOpen()) {
        QString user=ini->chercheParSectionCle("PGSQL","user");
        QString pass=ini->chercheParSectionCle("PGSQL","pass");
        QString base=ini->chercheParSectionCle("PGSQL","base");
        QString host=ini->chercheParSectionCle("PGSQL","host");
        QString port=ini->chercheParSectionCle("PGSQL","port");
        qDebug() << user << base << host << port ;
        db.setDatabaseName(base);
        db.setHostName(host);
        db.setUserName(user);
        db.setPassword(pass);
        db.setPort(port.toInt());
        bool test=db.open();
        if (test) qDebug() << "OK OUVERTURE BASE DE DONNEES" ;
        else qDebug() << "ERREUR OUVERTURE DE DONNEES" ;
        return test;
    }
    else {
        qDebug() << "OK BASE DE DONNEES OUVERTES AVANT L'APPEL" ;
    }
    return true;
}

int  CcpaSpancDatabase::selectCount(QString field, QString from, QString where) {
    int retour=0;
    QSqlTableModel* model= new QSqlTableModel();
    if (model) {
        model->setTable(from);
        model->setFilter(where);
        if (model->select()) {
            retour=model->rowCount();
        }
    }
    return retour;
}

float  CcpaSpancDatabase::selectSum(QString field, QString from, QString where) {
    qDebug() << "SELECT SUM" ;
    int retour=0;
    float somme=0;
    QSqlTableModel* model= new QSqlTableModel();
    if (model) {
        model->setTable(from);
        model->setFilter(where);
        if (model->select()) {
            int compte=model->rowCount();
            int idx=model->fieldIndex(field);
            for(int i=0;i<compte;i++) {
                QSqlRecord rec=model->record(i);
                somme+=rec.value(idx).toFloat();
            }
        }
    }
    return somme;
}

QString  CcpaSpancDatabase::selectSumS(QString field, QString from, QString where) {
    qDebug() << "SELECT SUM" ;

    if (!db.isOpen()) {
        qDebug() << "REOUVERTURE DB" ;
        db.open();
    }
    if (db.isOpen())
    {
        QString qstr="SELECT SUM(\"" + field + "\") from " + from + " where " + where;
        qDebug() << qstr ;

        QSqlQuery q(qstr);
        if (q.size()>0)
        {
            q.next();
            qDebug() << "Somme: " << q.value(0);
            return q.value(0).toString();
        }
        qDebug() << "Erreur de requête" ;
        return "";
    }
    qDebug() << "Base de données non accessible" ;
    return "";
}

QString  CcpaSpancDatabase::selectValue(QString field,QString from, QString where) {
    QVariant val="";
    bool trouve=false;

        if (field.at(0)!='"') {
            qDebug() << "Rajoute le guillemet avant " << field;
            field.prepend("\"");
            qDebug() << "--> " << field;
        }
        if (field.at(field.length()-1)!='"') {
            qDebug() << "Rajoute le guillemet après " << field;
            field.append("\"");
            qDebug() << "--> " << field;
        }
        QSqlTableModel model;
        model.setTable(from);
        model.setFilter(where);
        model.select();
        if (model.rowCount()==1) {
            QSqlRecord record=model.record(0);
            val=record.value(field).toString();
        }
        else {
            qDebug() << "Valeur non trouvée: " <<  where   ;
    }

        return val.toString();
}

QStringList  CcpaSpancDatabase::selectValues(QString field,QString from, QString where) {

    QStringList resultat;
    bool trouve=false;

    if (!db.isOpen()) {
        qDebug() << "REOUVERTURE DB" ;
        db.open();
    }
    if (db.isOpen())
    {
        QString qstr="SELECT "+ field + "  from \"" + from + "\" where " + where;
        QSqlRecord rec;
        QSqlQuery q2(qstr);

        while (q2.next()) {
                int size=q2.size();
                for (int i=0;i<size;i++) {
                    qDebug() << q2.value(i).toString() ;
                    resultat.append(q2.value(i).toString());
                }
                trouve=true;
        }
        if (!trouve) qDebug() << "Valeurs non trouvées: "  << q2.lastQuery()  << q2.lastError().text()  ;
    }
    else {
        qDebug() << "Base de données non accessible";
    }
    return resultat;
}


QStringList  CcpaSpancDatabase::selectFieldsOneRow(QStringList fields,QString from, QString where) {

    QStringList resListe;
    //bool trouve=false;
    QString field;
    QVariant val;
    QVariant value;
    QString champCourant;
    QString valeur;
    if (!db.isOpen()) {
        qDebug() << "REOUVERTURE DB" ;
        db.open();
    }
    if (db.isOpen())
    {
        int imax=fields.size();
        for (int i=0;i<imax;i++)
        {
            field.append("\"");
            field.append(fields.at(i));
            field.append("\"");
            if (i<imax-1) field.append(",");
        }
        QString qstr="SELECT "+ field + " from \"" + from + "\" where " + where;
        qDebug() << qstr ;
        QSqlQuery q2(qstr);
        if (q2.next()) {
            //trouve=true;
            for (int i=0;i<imax;i++)
            {
               champCourant= fields.at(i);
               value = q2.value(champCourant);
               valeur =value.toString();
               resListe.append(valeur);
            }
        }
        else {
            qDebug() << "Enregistrement non trouvé: "
                     << q2.executedQuery()
                     << q2.lastError().text()
                     << q2.lastError().databaseText()  ;
        }
    }
    else {
        qDebug() << "Base de données non accessible" ;
    }
    qDebug() << "FIN ONE ROW";
    return resListe;
}


QStringList CcpaSpancDatabase::selectFormule(QString field,QString from, QString where) {
    QStringList resultat;
    bool trouve=false;
    QSqlQuery query;
    if (!db.isOpen()) {
        qDebug() << "REOUVERTURE DB" ;
        db.open();
    }
    if (db.isOpen())
    {
        QString qstr="SELECT "+ field + " as \"formula\"  from \"" + from + "\" where " + where;
        query.exec(qstr);
        QVariant val=query.value("formula");
        QSqlRecord rec;
        QSqlQuery q2(qstr);
        while (q2.next()) {
                trouve=true;
                QString value = q2.value(0).toString();
                resultat.append(value);
        }
        if (!trouve) qDebug() << "Erreur de formule: "  << q2.lastQuery()  << q2.lastError().text()  ;
    }
    else {
        qDebug() << "Base de données non accessible" ;
    }
    return resultat;
}


QStringList CcpaSpancDatabase::selectAllFromWithId(QString from,QString where) {

    QStringList resultat;
    QSqlQuery query;
    bool trouve=false;

    if (!db.isOpen()) {
        qDebug() << "REOUVERTURE DB" ;
        db.open();
    }
    if (db.isOpen())
    {
        QString qstr="SELECT *  from \"" + from + "\" where " + where ;
        query.exec(qstr);
        QVariant val=query.value("formula");
        QSqlRecord rec;
        QSqlQuery q2(qstr);
        while (q2.next()) {
            trouve=true;
            int taille=q2.size();
            for(int i=0;i<taille;i++) {
               resultat.append(q2.value(i).toString());
        }
        if (!trouve) qDebug() << "Valeurs non trouvées: "  << q2.lastQuery()  << q2.lastError().text()  ;
        }
    }
    else {
        qDebug() << "Base de données non accessible" ;
    }
    return resultat;
}


int CcpaSpancDatabase::selectBordereauEnCours() {
    QString annee=QString::number(selectExercice());
    QString where="titre_exercice="+annee;
    int no_courant=selectMax("titre_bordereau","dossier",where);
    return no_courant;
}

int CcpaSpancDatabase::selectTitreEnCours() {
    QString annee=QString::number(selectExercice());
    QString where="titre_exercice="+annee;
    int no_courant=selectMax("titre_no","dossier",where);
    return no_courant;
}

float CcpaSpancDatabase::selectMax(QString field, QString from, QString where)
{
   float retour=0;
   QString champ="max(\""+field+"\")";
   QStringList retourlist=selectFormule(champ,from,where);
   if (retourlist.count()>0) {
       retour=retourlist.at(0).toFloat();
   }
   return retour;
}

int CcpaSpancDatabase::selectExercice()
{
    QDate maintenant;
    maintenant=QDate::currentDate();
    int annee=maintenant.year();
    return annee;
}

bool  CcpaSpancDatabase::remplisTableau(QListWidget* liste, QStringList champs,QString from,QString where)
{
    qDebug() << "Remplis tableau  " << from << " " << where ;
    if (!db.isOpen()) {
        db.open();
    }
    if (db.isOpen())
    {
        QString fields;
        QString champ;
        if (where.length()==0) {
            where="";
        }
        else where = "where " + where;
        for (int i=0;i<champs.length();i++) {
           champ = champs.at(i);
           if (fields.length()>0) {
               fields.append(",");
           }
           fields.append(champ);
        }
        QString qstr="SELECT " + fields + " from " + from + " " + where;

        QSqlQuery q2(qstr);
        int ligne=0;
        while (q2.next()) {
           for(int j=0;j<champs.size();j++) {
               liste->addItem(q2.value(j).toString());
           }
           ligne++;
        }
        return true;
    }
    return false;
}

int CcpaSpancDatabase::insereContact(QString nom,QString prenom,QString titre,int societe,int adresse,QString mail,QString tel,QString fax,QString notes) {
    int value=0;
    qDebug() << "INSERE CONTACT " << titre << " " << nom << " " << prenom << " " << societe << " " << adresse << " " << notes ;
    QSqlQuery q2;
    if (!db.isOpen()) {
        qDebug() << "REOUVERTURE DB" ;
        db.open();
    }
    if (db.isOpen())
    {
        QSqlTableModel model;
        QSqlRecord record;

        model.setTable("contact");
        model.select();
        model.setEditStrategy(QSqlTableModel::OnFieldChange);
        record=model.record();

        record.setValue("id", this->chercheProchain("contact_id_seq"));
        record.setValue("nomContact",nom);
        record.setValue("titreContact",titre);
        record.setValue("prenomContact",prenom);
        record.setValue("mailContact",mail);
        record.setValue("telContact",tel);
        record.setValue("faxContact",fax);
        record.setValue("adresse",adresse);
        record.setValue("societe",societe);
        record.setValue("notes",notes);
        if (model.insertRecord(-1,record))
        {
            value = record.value("id").toInt();
            qDebug() << "OK"<< value ;
        }
        else
        {
            qDebug() << model.lastError().text();
        }
    }
    return value;
}

int CcpaSpancDatabase::majContact(int id,QString nom,QString prenom,QString titre,int societe,int adresse,QString mail,QString tel,QString fax,QString notes) {
    int value=0;
    qDebug() << "UPDATE CONTACT " << nom << " " << prenom << " " ;

    if (!db.isOpen()) {
        qDebug() << "REOUVERTURE DB" ;
        db.open();
    }
    if (db.isOpen())
    {
        QSqlTableModel model;
        QSqlRecord record;
        QString where;
        where="id="+QString::number(id);
        model.setTable("contact");
        model.setFilter(where);
        model.select();
        model.setEditStrategy(QSqlTableModel::OnFieldChange);
        record=model.record(0);

        record.setValue("nomContact",nom);
        record.setValue("titreContact",titre);
        record.setValue("prenomContact",prenom);
        record.setValue("mailContact",mail);
        record.setValue("telContact",tel);
        record.setValue("faxContact",fax);
        record.setValue("adresse",adresse);
        record.setValue("societe",societe);
        record.setValue("notes",notes);
        value=1;
    }
    return value;

}

int CcpaSpancDatabase::inserePropriete(int commune,QString section, QString prefixe,
                                       QString parcelle, int nbPP,int annee,int adresse,QString notes)
{
    int value=0;
    QString ids;
    QSqlQuery q2;

    section = CcpaGenerique::getSection(section,prefixe);

    qDebug() << "INSERE PROPRIETE " << commune << " " << section << " " << parcelle ;

    if (!db.isOpen()) {
        qDebug() << "REOUVERTURE DB" ;
        db.open();
    }
    if (db.isOpen())
    {

        QSqlTableModel model;
        QSqlRecord record;

        model.setTable("propriete");
        model.select();
        model.setEditStrategy(QSqlTableModel::OnFieldChange);
        record=model.record();

        record.setValue("id", this->chercheProchain("propriete_id_seq"));
        record.setValue("commune",commune);
        record.setValue("section",section);
        record.setValue("parcelle",parcelle);
        record.setValue("NbPP",nbPP);
        record.setValue("adresse",adresse);
        record.setValue("anneConstruction",annee);
        record.setValue("notes",notes);

        if (model.insertRecord(-1,record))
        {
            value = record.value("id").toInt();
            qDebug() << "OK"<< value ;
        }
        else
        {
            qDebug() << "Erreur :" << model.lastError().text();
        }
    }
    return value;
}


int CcpaSpancDatabase::majPropriete(int id, int commune, QString section, QString prefixe, QString parcelle, int nbPP, int annee, int adresse, QString notes)
{
    qDebug() << "UPDATE PROPRIETE " << id ;
    section = CcpaGenerique::getSection(section,prefixe);
    int value=0;
    if (!db.isOpen()) {
        qDebug() << "REOUVERTURE DB" ;
        db.open();
    }
    if (db.isOpen())
    {
        QString ids=QString::number(id);
        QSqlTableModel model;
        QSqlRecord record;
        QString where;
        where="id="+QString::number(id);
        model.setTable("propriete");
        model.setFilter(where);
        model.select();
        model.setEditStrategy(QSqlTableModel::OnFieldChange);
        record=model.record(0);
        record.setValue("commune",commune);
        record.setValue("section",section);
        record.setValue("parcelle",parcelle);
        record.setValue("NbPP",nbPP);
        record.setValue("adresse",adresse);
        record.setValue("anneConstruction",annee);
        record.setValue("notes",notes);
        value=1;
        model.setRecord(0,record);
    }
    return value;
}

int CcpaSpancDatabase::effacePropriete(int id)
{

    qDebug() << "EFFACE PROPRIETE " << id ;
    int value=0;
    if (!db.isOpen()) {
        qDebug() << "REOUVERTURE DB" ;
        db.open();
    }
    if (db.isOpen())
    {
        QString ids=QString::number(id);
        QSqlTableModel model;
        QSqlRecord record;
        QString where;
        where="id="+QString::number(id);
        model.setTable("propriete");
        model.setFilter(where);
        model.select();
        model.setEditStrategy(QSqlTableModel::OnFieldChange);
        if (model.rowCount()>0)
        {
           if (model.removeRow(0))
           {
               qDebug() << "OK suppression propriete " << id;
               value=1;
           }
           else {
                 qDebug() << "Erreur suppression: " << model.lastError().text();
           }
        }
    }
    return value;
}

int CcpaSpancDatabase::retrouveNoCommune(QString commune) {
    int value=0;
    qDebug() << "RETROUVE NO COMMUNE " << commune ;
    QSqlTableModel* communeM = new QSqlTableModel();
    if (communeM) {
        communeM->setTable("commune");
        QString where="upper(\"nomCommune\")='"+commune.toUpper()+"'";
        communeM->setFilter(where);
        if (communeM->select())
        {
            if (communeM->rowCount()>0) {
                QSqlRecord record=communeM->record(0);
                int index=record.indexOf("noCommune");
                value=record.value(index).toInt();
            }
        }
    }
    return value;
}

QString CcpaSpancDatabase::codePostal(QString arg1)
{
    QString requete_where="upper(\"nomCommune\")='"+arg1.toUpper()+"'";
    QString cp=selectValue("cp","commune",requete_where);
    return cp;
}

int CcpaSpancDatabase::insereEstProprietaire(int propriete,int proprietaire,QDate debut,QDate fin ) {
    int estprop=0;
    qDebug() << "INSERE EST_PROPRIETAIRE " << propriete << " " << proprietaire ;

    if (!db.isOpen()) {
        qDebug() << "REOUVERTURE DB" ;
        db.open();
    }
    if (db.isOpen())
    {
        QString queryst="INSERT INTO est_proprietaire (id,propriete,proprietaire,date_debut,date_fin) VALUES (:id,:propriete,:proprietaire,:debut,:fin);";
        QSqlQuery q2;
        qDebug() << queryst ;
        if (q2.prepare(queryst))
        {
            int id=chercheProchain("est_proprietaire_id_seq");
           q2.bindValue(":id",id);
            q2.bindValue(":propriete",propriete);
            q2.bindValue(":proprietaire",proprietaire);
            q2.bindValue(":debut",debut);
            q2.bindValue(":fin",fin);
            if (q2.exec()) {
                estprop=retrouveSequence("est_proprietaire_id_seq");
                qDebug() << "INSERTION OK " << estprop ;
            }
            else {
                qDebug() << "Erreur de requête " << q2.executedQuery() << q2.lastError().text() ;
            }
        }
        else {
            qDebug() << "Erreur d'initialisation de la requête " << q2.lastQuery()   << q2.lastError().databaseText();
        }
    }
    else {
        qDebug() << "Erreur :" << db.lastError().text() ;
    }
    return estprop;
}

int CcpaSpancDatabase::majEstProprietaire(int id, int propriete, int proprietaire, QDate debut, QDate fin)
{
    QString where="id="+QString::number(id);
    QSqlTableModel* model = new QSqlTableModel();
    if (model) {
        model->setTable("est_proprietaire");
        model->setFilter(where);
        if (model->select()) {
            int compte=model->rowCount();
            if (compte > 0 ) {
                QSqlRecord rec = model->record(0);
                int idxPropriete=rec.indexOf("propriete");
                int idxProprietaire=rec.indexOf("proprietaire");
                int idxDateDebut=rec.indexOf("date_debut");
                int idxDateFin=rec.indexOf("date_fin");
                rec.setValue(idxPropriete,propriete);
                rec.setValue(idxProprietaire,proprietaire);
                rec.setValue(idxDateDebut,debut);
                rec.setValue(idxDateFin,fin);
            }
        }
    }
}

int CcpaSpancDatabase::effaceEstProprietaire(int propriete, int proprietaire)
{

    qDebug() << "EFFACE EST_PROPRIETAIRE " << proprietaire << " " << propriete ;
    int value=0;
    if (!db.isOpen()) {
        qDebug() << "REOUVERTURE DB" ;
        db.open();
    }
    if (db.isOpen())
    {
        QString proprietes=QString::number(propriete);
        QString proprietaires=QString::number(proprietaire);
        QSqlTableModel model;
        QSqlRecord record;
        QString where;
        where="propriete="+proprietes+" AND proprietaire=" + proprietaires;
        model.setTable("est_proprietaire");
        model.setFilter(where);
        model.select();
        model.setEditStrategy(QSqlTableModel::OnFieldChange);
        if (model.rowCount()>0)
        {
           qDebug() << "OK suppression de est_proprietaire sur propriete" << proprietes << " et proprietaire " << proprietaires ;
           if (model.removeRow(0)) value=1;
        }
        else {
            qDebug() << "Erreur suppression: " << model.lastError().text();
        }
    }
    return value;

}

int CcpaSpancDatabase::insereAdresse( QString nr,QString tr, QString mr,QString a2,QString a3,QString v,QString cpp,QString cx,QString p) {
    int adresse=0;
    if (!db.isOpen()) {
        db.open();
    }
    if (db.isOpen())
    {
        qDebug() << "INSERTION ADRESSE " << nr << tr << mr << a2 << a3 << v << cpp << cx << p  ;
        QString queryst;
        QSqlQuery query(this->db);
        queryst = "INSERT INTO adresse(  id,     norue,  typerue,  nomrue,  adresse2,  adresse3,  commune,  cp,   cedex,   pays)";
        queryst+=" VALUES (:id,:norue,:typerue,:nomrue,:adresse2,:adresse3,:commune,:cp,:cedex,:pays)";
        query.prepare(queryst);
        int id=this->chercheProchain("adresse_id_seq");
        query.bindValue(":id",id);
        query.bindValue(":norue",nr);
        query.bindValue(":typerue",tr);
        query.bindValue(":nomrue",mr);
        query.bindValue(":adresse2",a2);
        query.bindValue(":adresse3",a3);
        query.bindValue(":commune",v);
        query.bindValue(":cp",cpp);
        query.bindValue(":cedex",cx);
        query.bindValue(":pays",p);
        QMap<QString,QVariant> bounds;
        bounds=query.boundValues();
        if (query.exec()) {
            qDebug() << "INSERTION ADRESSE OK " ;
            adresse = retrouveSequence("adresse_id_seq");
        }
        else {
                qDebug() << "INSERTION ADRESSE KO " ;
        }
        QString executed=query.executedQuery();
        qDebug() << "Commande: " << executed ;
    }
    else {
        qDebug() << "Problème d'ouverture de la DB";
    }
    return adresse;
}

int CcpaSpancDatabase::majAdresse(int id, QString nr, QString tr, QString mr, QString a2, QString a3, QString v, QString cpp, QString cx, QString p)
{
    int value=0;
    qDebug() << "UPDATE ADRESSE " << nr << " " << tr << " " << mr  << " " << v ;

    if (!db.isOpen()) {
        qDebug() << "REOUVERTURE DB" ;
        db.open();
    }
    if (db.isOpen())
    {
        QSqlTableModel model;
        QSqlRecord record;
        QString where;
        where="id="+QString::number(id);
        model.setTable("adresse");
        model.setFilter(where);
        model.select();
        model.setEditStrategy(QSqlTableModel::OnFieldChange);
        record=model.record(0);
        record.setValue("id",id);
        record.setValue("noRue",nr);
        record.setValue("typeRue",tr);
        record.setValue("nomRue",mr);
        record.setValue("adresse2",a2);
        record.setValue("adresse3",a3);
        record.setValue("commune",v);
        record.setValue("cp",cpp);
        record.setValue("pays",p);
        record.setValue("cedex",cx);
        bool retour = model.setRecord(0,record);
        if (retour) value=1;
        else {
            qDebug() << "Erreur: " << db.lastError().text();
        }
    }
    return value;
}

QString CcpaSpancDatabase::retrouveTexteAdresse(int no) {
    QString value="";
    qDebug() << "CHERCHE TEXTE ADRESSE  " << no ;

    if (!db.isOpen()) {
        qDebug() << "REOUVERTURE DB" ;
        db.open();
    }
    if (db.isOpen())
    {
        QSqlTableModel model;
        QSqlRecord record;
        QString where;
        where="id="+QString::number(no);
        model.setTable("adresse");
        model.setFilter(where);
        model.select();
        if (model.rowCount()>=1)
        {
            value=model.record(0).value("data").toString();
        }
    }
    return value;
}

quint16 CcpaSpancDatabase::retrouveSequence(QString nomSequence)
{
    quint16 retour=0;
    QSqlQuery query(this->db);
    if (!db.isOpen()) {
        db.open();
    }
    if (db.isOpen())
    {
        if (query.exec("select currval('" + nomSequence + "')")) {
            query.next();
            retour=query.value(0).toInt();
        }
        else {
            qDebug() << "Impossible de récupérer la valeur adresse";
            qDebug() << query.lastError().databaseText();
        }
    }
    return retour;
}

quint16 CcpaSpancDatabase::chercheProchain(QString nomSequence)
{
    quint16 retour=0;
    QSqlQuery query(this->db);
    if (!db.isOpen()) {
        db.open();
    }
    if (db.isOpen())
    {
        if (query.exec("select nextval('" + nomSequence + "'::regclass)")) {
            query.next();
            retour=query.value(0).toInt();
        }
        else {
            qDebug() << "Impossible de récupérer la valeur adresse";
            qDebug() << query.lastError().databaseText();
        }
    }
    return retour;
}

int CcpaSpancDatabase::insereDossier(int no,QDate date, int controle,int propriete, int pttype,int ttype,QString tagrement,bool vp,bool vs,int delai,bool conformite,bool urgence,int exutoire, int liste)
{
    int resultat=0;
    if (!db.isOpen()) {
        qDebug() << "REOUVERTURE DB" ;
        db.open();
    }
    if (db.isOpen())
    {
        QSqlTableModel tableDossier;
        QSqlRecord recordDossier;
        tableDossier.setTable("dossier");
        tableDossier.select();
        tableDossier.setEditStrategy(QSqlTableModel::OnFieldChange);
        recordDossier=tableDossier.record();

        recordDossier.setValue("no",no);
        recordDossier.setValue("controle",controle);
        recordDossier.setValue("propriete",propriete);
        recordDossier.setValue("pttype",pttype);
        recordDossier.setValue("ttype",ttype);

        recordDossier.setValue("tagrement",tagrement);
        recordDossier.setValue("vp",vp);
        recordDossier.setValue("vs",vs);
        recordDossier.setValue("delai",delai);
        recordDossier.setValue("conformite",conformite);
        recordDossier.setValue("urgence",urgence);
        recordDossier.setValue("dateCreation",date);
        recordDossier.setValue("exutoire",exutoire);
        recordDossier.setValue("liste",liste);
        if (tableDossier.insertRecord(-1,recordDossier))
        {
            resultat = recordDossier.value("no").toInt();
            qDebug() << "OK"<< resultat ;
        }
        else
        {
            qDebug() << tableDossier.lastError().text();
        }
    }
    else {
        qDebug() << "Base non ouverte" ;
    }
    return resultat;
}

int CcpaSpancDatabase::majDossier(int no, QDate date, int propriete, int controle, int pttype, int ttype, QString tagrement, bool vp, bool vs, int delai, bool conformite, bool urgence, int exutoire, int liste)
{
    int resultat=0;
    QSqlTableModel* tableDossier=new QSqlTableModel();
    if (tableDossier) {
        QString where="no="+QString::number(no);
        tableDossier->setTable("dossier");
        tableDossier->setFilter(where);
        if (tableDossier->select())
        {
            int compte=tableDossier->rowCount();
            if (compte>0) {
                tableDossier->setEditStrategy(QSqlTableModel::OnFieldChange);
                QSqlRecord recordDossier=tableDossier->record(0);

                recordDossier.setValue("controle",controle);
                recordDossier.setValue("propriete",propriete);
                recordDossier.setValue("pttype",pttype);
                recordDossier.setValue("ttype",ttype);

                recordDossier.setValue("tagrement",tagrement);
                recordDossier.setValue("vp",vp);
                recordDossier.setValue("vs",vs);
                recordDossier.setValue("delai",delai);
                recordDossier.setValue("conformite",conformite);
                recordDossier.setValue("urgence",urgence);
                recordDossier.setValue("dateCreation",date);
                recordDossier.setValue("exutoire",exutoire);
                recordDossier.setValue("liste",liste);
                resultat=tableDossier->setRecord(0,recordDossier);
                if (!resultat) {
                    qDebug() << "Erreur: " << tableDossier->lastError().text();
                }
            }
        }
    }
    return resultat;
}



int CcpaSpancDatabase::effaceDossier(int id)
{

    qDebug() << "EFFACE DOSSIER " << id ;
    int value=0;
    if (!db.isOpen()) {
        qDebug() << "REOUVERTURE DB" ;
        db.open();
    }
    if (db.isOpen())
    {
        QString ids=QString::number(id);
        QSqlTableModel model;
        QSqlRecord record;
        QString where;
        where="no="+ids;
        model.setTable("dossier");
        model.setFilter(where);
        model.select();
        model.setEditStrategy(QSqlTableModel::OnFieldChange);
        if (model.rowCount()>0)
        {
           if (model.removeRow(0))
           {
               qDebug() << "OK suppression dossier " << ids;
               value=1;
           }
           else {
                 qDebug() << "Erreur suppression: " << model.lastError().text();
           }
        }
    }
    return value;
}

int CcpaSpancDatabase::insereSociete(int id, QString nomS, QString siret, int adresse, QString tel, QString fax, QString mail, QString web, bool notaire)
{
    int resultat=0;
    if (!db.isOpen()) {
        qDebug() << "REOUVERTURE DB" ;
        db.open();
    }
    if (db.isOpen())
    {
        QSqlTableModel tableSociete;
        QSqlRecord recordSociete;
        tableSociete.setTable("societe");
        tableSociete.select();
        tableSociete.setEditStrategy(QSqlTableModel::OnFieldChange);
        recordSociete=tableSociete.record();

        recordSociete.setValue("id",-1);
        recordSociete.setValue("nomSociete",nomS);
        recordSociete.setValue("siret",siret);
        recordSociete.setValue("adresse",adresse);
        recordSociete.setValue("telSociete",tel);

        recordSociete.setValue("faxSociete",fax);
        recordSociete.setValue("mailSociete",mail);
        recordSociete.setValue("webSociete",web);
        recordSociete.setValue("est_notaire",notaire);

        if (tableSociete.insertRecord(-1,recordSociete))
        {
            resultat = recordSociete.value("id").toInt();
            qDebug() << "OK"<< resultat ;
        }
        else
        {
            qDebug() << tableSociete.lastError().text();
        }
    }
    else {
        qDebug() << "Base non ouverte" ;
    }
    return resultat;
}

int CcpaSpancDatabase::majSociete(int id, QString nomS, QString siret, int adresse, QString tel, QString fax, QString mail, QString web, bool notaire)
{
    int resultat=0;
    QSqlTableModel* model = new QSqlTableModel();
    if (model) {
        QString where="no="+QString::number(id);
        model->setTable("dossier");
        model->setFilter(where);
        if (model->select())
        {
            int compte=model->rowCount();
            if (compte>0) {
                model->setEditStrategy(QSqlTableModel::OnFieldChange);
                QSqlRecord recordSociete=model->record(0);
                recordSociete.setValue("id",-1);
                recordSociete.setValue("nomSociete",nomS);
                recordSociete.setValue("siret",siret);
                recordSociete.setValue("adresse",adresse);
                recordSociete.setValue("telSociete",tel);

                recordSociete.setValue("faxSociete",fax);
                recordSociete.setValue("mailSociete",mail);
                recordSociete.setValue("webSociete",web);
                recordSociete.setValue("est_notaire",notaire);

                resultat=true;
            }
        }
    }
    return resultat;
}

bool CcpaSpancDatabase::insereDossierAFacturer(int no) {
    bool succes=false;
    QSqlTableModel dossierModel;
    dossierModel.setTable("dossiers_factures_en_cours");
    QSqlRecord dossierRec=dossierModel.record();
    dossierRec.setValue(0,no);
    if (dossierModel.insertRecord(-1,dossierRec)) {
            qDebug() << "Insertion OK";
            succes=true;
        }
        else {
            qDebug() << "Impossible de sauvegarder " << dossierModel.lastError().text();
        }
    return succes;
}

bool CcpaSpancDatabase::enleveDossierAFacturer(int no)
{
    bool succes=false;
    QSqlTableModel dossierModel;
    QString where="no_dossier="+ QString::number(no);
    dossierModel.setTable("dossiers_factures_en_cours");
    dossierModel.setFilter(where);
    if (dossierModel.select()) {
        if (dossierModel.rowCount()>0) {
            if (dossierModel.removeRow(0)) {
                    qDebug() << "Suppression de la ligne no_dossier=" << no << " OK";
                    succes=true;
            }
            else {
                    qDebug() << "Impossible de supprimer " << dossierModel.lastError().text();
            }
        } else {
                qDebug() << "Pas de ligne trouvée";
        }
    }
    else {
        qDebug() << dossierModel.lastError().databaseText();
        succes = false ;
    } // pas trouvé la ligne à supprimer
    return succes;
}

int CcpaSpancDatabase::nombreFacturesEnCours()
{
    int Nombre=selectCount("no_dossier","dossiers_factures_en_cours");
    return Nombre;
}

QString CcpaSpancDatabase::sommeFacturesEnCours()
{
    QString where="no in (select no_dossier from dossiers_factures_en_cours)";
    QString sum=selectSumS("titre_montant","dossier",where);
    qDebug() << "Retourne " << sum;
    return sum;
}

bool CcpaSpancDatabase::ajouteMontantTitreDossier(int dossier, QString montant, bool remplace)
{
    bool retour=false;
    QString where="no="+QString::number(dossier);
    QString montantActuel=selectValue("titre_montant","dossier",where);
    if ((montantActuel.length()>0) && (!remplace)) {
        qDebug () << "Il y avait déjà un montant (" <<  montantActuel << ") et j'avais consigne de ne pas le changer";
    }
    else if ((montantActuel.length()==0) || remplace) {
        qDebug() << "Pas encore de montant connu pour le dossier";
        QSqlTableModel model;
        model.setEditStrategy(QSqlTableModel::OnFieldChange);
        model.setTable("dossier");
        model.setFilter(where);
        model.select();
        if (model.rowCount()>0)
        {
            qDebug() << "Je me positionne sur le dossier";
            QSqlRecord dossRec = model.record(0);
            qDebug() << "Pour prouver que j'y suis: Propriété " << dossRec.value("propriete");
            dossRec.setValue("titre_montant",montant);
            if (model.setRecord(0,dossRec)) {
                qDebug() << "Insertion montant dossier OK";
                QString value = selectValue("titre_montant","dossier",where);
                qDebug() << "Montant: " << value;

                retour=true;
            }
            else {
                qDebug() << "Insertion montant dossier failed: " << model.lastError().databaseText();
            }

        }
        else {
            qDebug() << "Erreur de mise à jour du montant" << model.lastError().databaseText();
        }
    }
    else // montantActuel a longueur nulle
    {
        qDebug() << "Ah c'est gratuit pour lui? " << montantActuel;
    }
    return retour;
}

bool CcpaSpancDatabase::existeDossier(int no)
{
    QString where="no="+QString::number(no);
    int nombre=selectCount("no","dossier",where);
    bool succes;
    succes=(nombre>0)?true:false;
    return succes;
}

int CcpaSpancDatabase::getNombreTitresSurBordereau(int no) {
    QString exercice=QString::number(selectExercice());
    QString nos=QString::number(no);
    QString where="exercice="+exercice+" and titre_bordereau="+nos;
    int compte=selectCount("no","dossier",where);
    return compte;
}

QList<int> CcpaSpancDatabase::getNumTitresSurBordereau(int no) {
    qDebug() << "getNumTitresSurBordereau";
    QString exercice=QString::number(selectExercice());
    QString nos=QString::number(no);
    QString where="titre_exercice="+exercice+" and titre_bordereau="+nos;
    QStringList liste=selectFormule("no","dossier",where);
    int compte=liste.count();
    QList<int> retourliste;
    for (int i=0;i<compte;i++) {
      retourliste.append(liste.at(i).toInt());
    }
    return retourliste;
}

QString CcpaSpancDatabase::calculeNoFacture(int bordereau, int titre, int sequence) {
    QString retour;
    QString gauche,milieu,droite;
    int b1000 = bordereau + 1000;
    gauche= QString::number(selectExercice());
    milieu = QString::number(b1000);
    milieu = gauche.right(3);
    milieu.prepend("-");
    milieu.append("-");
    int titre1000 = titre + 1000;
    quint32 total=sequence;
    droite=CcpaGenerique::intVersStringAvecZerosDevant(sequence,6);
    retour=gauche + milieu + droite;
    return retour;
}

QString CcpaSpancDatabase::chercheMontantDeDossier(int no)
{
    QString sel;
    QString where="no="+QString::number(no);
    sel=selectValue("titre_montant","dossier",where);
    return sel;
}

bool CcpaSpancDatabase::valideExerciceBordereauFactureDateListe(int exercice, int bordereau, int titre, QDate date, QList<int> nodoss)
{
    bool retour=true;
    QSqlQuery query;
    QString bs = QString::number(bordereau);
    QString es = QString::number(exercice);
    QString ts;
    QString no_facture;
    QListIterator<int> iterator(nodoss);
    while (iterator.hasNext())  {
        int courant=iterator.next();
            QString courantDossier=QString::number(courant);
            ts= QString::number(titre);
            int no_sequence_factu=chercheProchain("facture_id_seq");
            QString factus=calculeNoFacture(bordereau,titre,no_sequence_factu);

            titre++;
            QString prepareS="update dossier set titre_bordereau="+bs+", titre_no="
                    +  ts+ ",titre_exercice=" + es + ", titre_facture='"
                    + factus + "', titre_date='" + CcpaGenerique::dateVersAMJ(date) + "' where no="+courantDossier;
            qDebug() << prepareS;
            query.prepare(prepareS);
            if (query.exec()) {
                qDebug() << "Ok pour dossier " << courantDossier;
                retour= retour && true;
                qDebug() << "Maintenant, on enlève le fichier de la liste des fichiers à facturer;";
                if (enleveDossierAFacturer(courant)) {
                    qDebug() << "Dossier enlevé de la liste à facturer: " << courant;
                }
            }
            else {
                qDebug() << "Erreur de numérotation: " << query.lastError().databaseText();
                retour=false;
            }
        }

    return retour;

}

QString CcpaSpancDatabase::noDossierIn(QList<int> liste) {
    QString where="no in (";
    int compte = liste.count();
    for (int i=0;i<compte;i++) {
        int courant = liste.at(i);
        QString courants = QString::number(courant);
        where.append(courants);
        if (i<compte-1) {
            where.append(",");
        }
    }
    where.append(")");
    qDebug() << "WHERE NO IN: " << where;
    return where;
}

bool CcpaSpancDatabase::effaceExerciceBordereauMontantDateNoFacListe(QList<int> liste) {
   qDebug() << "effaceExerciceBordereauMontantDateNoFacListe";
    bool retour=false;
   QSqlQuery query;
   QString prepareS="update dossier set titre_bordereau=0, titre_montant=0,titre_no=0,titre_exercice=0, titre_facture='', titre_date=NULL where " + noDossierIn(liste);
   qDebug() << prepareS;
   query.prepare(prepareS);
   if (query.exec()) {
       retour=true;
   }
   else {
       qDebug() << "Erreur de dénumérotation: " << query.lastError().databaseText();
   }
   return retour;

}

bool CcpaSpancDatabase::facturesVersFichier(int exercice,int bordereau) {
    bool retour=true;
    int sequence=1;
    QString section="PESV2";
    QString chemin=ini->chercheParSectionCle(section,"CHEMIN");
    QString  budget=ini->chercheParSectionCle(section,"BUDGET");
    QString  codcol=ini->chercheParSectionCle(section,"CODCOL");
    QString  compte=ini->chercheParSectionCle(section,"COMPTE");
    QString  codeProduit=ini->chercheParSectionCle(section,"CODEPRODUIT");
    QString objet=ini->chercheParSectionCle(section,"OBJET");
    QString tribunal=ini->chercheParSectionCle(section,"TRIBUNAL");
    QString ex=QString::number(exercice);
    QSqlTableModel model;
    model.setTable("ligne_export_facture");
    QString where="exercice="+QString::number(exercice)+" and bordereau="+QString::number(bordereau);
    model.setFilter(where);
    model.select();
    int cp=model.rowCount();
    if ( cp > 0 ) {

        if (CcpaSpancFichiers::existe(chemin)) {
            QString madate = CcpaGenerique::dateVersAMJ(QDate::currentDate());
            QString copieS=chemin;
            copieS.append("_").append(madate);
            if (CcpaSpancFichiers::copie(chemin,copieS))
            {
                qDebug() << "Fichier existant renommé";
            }
            else {
                qDebug() << "Erreur en renommant le fichier de " << chemin << " vers "  << copieS ;
            }
        }
        if (CcpaSpancFichiers::creeFichierVide(chemin)) {
            for (int i=0;i<cp;i++) {
                QSqlRecord record=model.record(i);
                static int ind=record.indexOf("concat");
                QString data=record.value(ind).toString();
                QDate date=record.value("date").toDate();
                data.replace("#CODCOL#",codcol);
                data.replace("#BUDGET#",budget);
                data.replace("#COMPTE#",compte);
                data.replace("#CODEPRODUIT#",codeProduit);
                data.replace("#OBJET#",objet);
                data.replace("#TRIBUNAL#",tribunal);
                data.replace("#EXERCICE#",ex);
                data.replace("#DATEFACTU#",CcpaGenerique::dateVersAMJ(date));
                data.replace("#SEQUENCE#",QString::number(sequence));
                qDebug() << data;

                sequence++;
                qDebug() << data ;
                if (!CcpaSpancFichiers::ajouteLigne(chemin,data)) {
                    qDebug() << "Pas d'écriture...";
                    retour=false;
                }
            }
        }
    }
    return retour;
}
