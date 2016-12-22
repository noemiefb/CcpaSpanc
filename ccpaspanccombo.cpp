#include "ccpaspanccombo.h"
#include <QComboBox>
#include <QSqlTableModel>
#include <QMapIterator>
#include <QSqlRecord>
#include <QDebug>

CcpaSpancCombo::CcpaSpancCombo(QWidget *parent) :
    QComboBox(parent)
{
    where="";
}

void CcpaSpancCombo::setDatabase(CcpaSpancDatabase *d)
{
    /*
    this->db = d;
    CcpaSpancDatabase data = *d;
    QSqlDatabase* db = data.getDb();
    QSqlDatabase dbd = *db;
    d->init();*/
    return ;
}

void CcpaSpancCombo::creeMap() {
    items.clear();
    carte.clear();
    bool debugDetail=false;
    QString nom =this->objectName();
    QSqlTableModel* model= new QSqlTableModel(this);

    model->setTable(table);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->sort(this->filtre,this->ordre);

    if (this->where.length()>0) {
         qDebug() << "AVEC FILTRE " << where ;
         model->setFilter(where);
    }
    else {
        qDebug() << "SANS FILTRE "+nom ;
    }
    model->select();
    for (int i = 0; i < model->rowCount(); ++i) {
        QSqlRecord rec = model->record(i);
        QString valeur = rec.value(this->champCle).toString();
        int id = rec.value(this->champValeur).toInt();
        this->carte[valeur]=id;
       // this->addItem(valeur);
        items.append(valeur);
        if (debugDetail) qDebug() << "Champ Clé: " << valeur << "Id: " << id;
    }
    model->submitAll();
}


void CcpaSpancCombo::creeMapDistinct() {
    items.clear();
    carte.clear();
    bool debugDetail=false;
    QString nom =this->objectName();
    QSqlTableModel* model= new QSqlTableModel(this);

    model->setTable(table);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->sort(this->filtre,this->ordre);

    if (this->where.length()>0) {
         qDebug() << "AVEC FILTRE " << where ;
         model->setFilter(where);
    }
    else {
        qDebug() << "SANS FILTRE "+nom ;
    }
    model->select();
    for (int i = 0; i < model->rowCount(); ++i) {
        QSqlRecord rec = model->record(i);
        QString valeur = rec.value(this->champCle).toString().toUpper();
        int id = rec.value(this->champValeur).toInt();
        if (!items.contains(valeur)) {
            int len=items.length();
            this->carte[valeur]=len;
            items.append(valeur);
        }
        if (debugDetail) qDebug() << "Champ Clé: " << valeur << "Id: " << id;
    }
    model->submitAll();
}




void CcpaSpancCombo::select(QString value)
{
   int d=this->findText(value,Qt::MatchExactly);
   if (d>-1) {
        this->setCurrentIndex(d);
    }
}

void CcpaSpancCombo::peupleCombo()
{
    this->clear();
    this->addItems(this->items);
}



int CcpaSpancCombo::maxChampValeur() {
    int maxVal=0;
    QMapIterator<QString,int> i(this->carte);
    while (i.hasNext()) {
        i.next();
        int j= i.value();
        if (j>maxVal) {
            maxVal=j;
        }
    }
    return maxVal;
}

void CcpaSpancCombo::recharge()
{
    creeMap();
    peupleCombo();
    this->repaint();
}

void CcpaSpancCombo::setPays()
{
    setTable("pays");
    setChampCle("LIBCOG");
    setChampValeur("CODENUM3");
    setOrder("LIBCOG",Qt::AscendingOrder);
    creeMap();
    peupleCombo();
    setCurrentText("FRANCE");
}

void CcpaSpancCombo::setCommune()
{
    setTable("commune");
    setChampCle("nomCommune");
    setChampValeur("noCommune");
    setOrder("noCommune",Qt::AscendingOrder);
    creeMap();
    peupleCombo();
}


void CcpaSpancCombo::setCommuneA()
{
    setTable("adresse");
    setChampCle("commune");
    setChampValeur(NULL);
    setOrder("commune",Qt::AscendingOrder);
    creeMap();
    peupleCombo();
}



void CcpaSpancCombo::setRue()
{
    setTable("adresse");
    setChampCle("nomRue");
    setChampValeur(NULL);
    setOrder("nomRue",Qt::AscendingOrder);
    creeMap();
    peupleCombo();
}

void CcpaSpancCombo::setTypeRue()
{
    setTable("adresse");
    setChampCle("typeRue");
    setChampValeur(NULL);
    setOrder("typeRue",Qt::AscendingOrder);
    creeMap();
    peupleCombo();
}

void CcpaSpancCombo::setPropriete()
{
    setTable("proprieteselectview");
    setChampValeur("propriété");
    setChampCle("data");
    setOrder("adresse1",Qt::AscendingOrder);
    creeMap();
    peupleCombo();
}

void CcpaSpancCombo::setAdresse()
{

    setTable("adresseselectview");
    setChampCle("id");
    setChampValeur("data");
    setOrder("data",Qt::AscendingOrder);
    creeMap();
    peupleCombo();
    setCurrentIndex(1);
}

void CcpaSpancCombo::setPretraitement()
{
    setTable("pretraitement");
    setChampCle("type");
    setChampValeur("id");
    setOrder("type",Qt::AscendingOrder);
    creeMap();
    peupleCombo();
    setValue(8);
}

void CcpaSpancCombo::setTraitement()
{
    setTable("traitement");
    setChampValeur("id");
    setChampCle("traitement");
    setOrder("traitement",Qt::AscendingOrder);
    creeMap();
    peupleCombo();
    setValue(0);
}

void CcpaSpancCombo::setControle()
{
    setTable("controle");
    setChampValeur("code");
    setChampCle("libelle");
    setOrder("code",Qt::AscendingOrder);
    creeMap();
    peupleCombo();
    setCurrentText("SYSTEMATIQUE");
}

void CcpaSpancCombo::setExutoire()
{
    setTable("exutoire");
    setChampValeur("id");
    setChampCle("label");
    setOrder("id",Qt::AscendingOrder);
    creeMap();
    peupleCombo();
    setValue(99);
}

void CcpaSpancCombo::setTarif()
{
    setTable("tarif");
    setChampValeur("id");
    setChampCle("montantTTC");
    QString where="controle=0";
    setOrder("montantTTC",Qt::AscendingOrder);
    creeMap();
    peupleCombo();
}


void CcpaSpancCombo::setContact()
{
    setTable("contactselectview");
    setChampValeur("contact");
    setChampCle("data");
    setOrder("nomContact",Qt::AscendingOrder);
    creeMap();
    peupleCombo();
}


void CcpaSpancCombo::rechargeTarifs(int controle)
{
    qDebug() << "Recharge tarif";
    this->where="controle="+QString::number(controle);
    qDebug() << "Where: " << where;
    creeMap();
    peupleCombo();
    qDebug() << "fin recharge tarif";
    return;
}

void CcpaSpancCombo::setOrder(QString champFiltre,Qt::SortOrder order) {

    QSqlTableModel model;
    model.setTable(this->table);
    this->filtre=model.fieldIndex(champFiltre);
    if (order==Qt::AscendingOrder) {
        this->ordre=order;
    }
    else this->ordre=Qt::DescendingOrder;
    return;
}

void CcpaSpancCombo::setWhere(QString wh)
{
    this->where=wh;
}

void CcpaSpancCombo::setTable(QString nomTable) {
    this->table=nomTable;
}

void CcpaSpancCombo::setChampCle(QString nomChampCle) {
    this->champCle=nomChampCle;
}

void CcpaSpancCombo::setChampValeur(QString nomChampValeur) {
    this->champValeur=nomChampValeur;
}


int CcpaSpancCombo::indexCourant()
{
    QString courant=currentText();
    int cle=carte[courant];
    return cle;
}

void CcpaSpancCombo::setValue(int item) {
    qDebug() << "Je dois trouver : " << item;
    int max=carte.count();
    bool trouve=false;
    QMapIterator<QString,int> iterator(carte);
    while (iterator.hasNext() && (!trouve)) {
        iterator.next();
        int valeurCourante=iterator.value();
        QString cleCourante=iterator.key();
        if ( valeurCourante== item) {
            qDebug() << "Trouvé: " << cleCourante << " " << valeurCourante;
            setCurrentText(cleCourante);
            trouve=true;
        }
    }
    return;
}

void CcpaSpancCombo::setValue(QString nom) {
    qDebug() << "SetValue par String" << nom;
    this->setCurrentText(nom);
    return;
}
