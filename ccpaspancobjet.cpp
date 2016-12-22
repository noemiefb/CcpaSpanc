#include "ccpaspancobjet.h"
#include "ccpaspancdatabase.h"
#include "ccpagenerique.h"
#include "ccpaspancfichiers.h"

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlRecord>


CcpaSpancObjet::CcpaSpancObjet()
{
    this->model=new QSqlTableModel();
    this->record=new QSqlRecord();
    return;
}

void CcpaSpancObjet::setTable(QString table) {
    this->model->setTable(table);
}

bool CcpaSpancObjet::maj() {
    return true;
}

bool CcpaSpancObjet::efface() {
    return true;
}

bool CcpaSpancObjet::ajoute() {
    bool retour= this->model->insertRecord(-1,*(this->record));
    return retour;
}

QString CcpaSpancObjet::getString(QString nom) {
    int index=record->indexOf(nom);
    QString retour;
    if (index>0) {
        retour=record->value(index).toString();
    }
    else retour="";
    return retour;
}

int CcpaSpancObjet::getInt(QString nom) {
    QString retour= getString(nom);
    return retour.toInt();
}

QDate CcpaSpancObjet::getDate(QString date) {
    QString retour=getString(date);
    return CcpaGenerique::stringToDate(retour);
}

void CcpaSpancObjet::setString(QString champ,QString value) {
    int index=record->indexOf(champ);
    record->setValue(index,value);
    return;
}

void CcpaSpancObjet::setDate(QString champ,QDate date) {
    int index=record->indexOf(champ);
    record->setValue(index,date);
    return;
}

void CcpaSpancObjet::setBool(QString champ, bool value) {
    int index=record->indexOf("champ");
    record->setValue(index,value);
    return;
}

bool CcpaSpancObjet::getBool(QString nom) {
    int index=record->indexOf(nom);
    bool retour;
    if (index>0) {
        retour=record->value(index).toBool();
    }
    else retour="";
    return retour;
}

void CcpaSpancObjet::setInt(QString champ,int value) {
    int index=record->indexOf(champ);
    record->setValue(index,value);
    return;
}

bool CcpaSpancObjet::aRecordActif() {
   if (!this->record) return false;
   return true;
}

void CcpaSpancObjet::setRecordActif(QSqlRecord* rec)
{
    this->record=rec;
    return;
}

QSqlRecord* CcpaSpancObjet::positionneSur(QString champ,QString value,bool guillemets) {
    QSqlRecord* editeRecord = new QSqlRecord();
    QString gui=guillemets?"'":"";
    QString where="\""+champ+"\"="+gui+value+gui;
    model->setFilter(where);
    if (model->select()) {
        if (model->rowCount() > 0 )
            *editeRecord = model->record(0);
    }
    else {
        delete editeRecord;
        editeRecord=NULL;
    }
    this->record=editeRecord;
    return this->record;
}
