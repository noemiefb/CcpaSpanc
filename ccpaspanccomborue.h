#ifndef CCPASPANCCOMBORUE_H
#define CCPASPANCCOMBORUE_H

#include <QObject>
#include <QWidget>
#include <QComboBox>

#include "ccpaspancdatabase.h"


class CcpaSpancComboRue : public QComboBox
{
public:
    Q_OBJECT
public:
    CcpaSpancComboRue();
    explicit CcpaSpancComboRue(QWidget* );
    void setDatabase(CcpaSpancDatabase* db);
    int indexCourant();
    void setValue(int i);
    void setOrder(QString champFiltre,Qt::SortOrder order);
    void setValue(QString nom);
    void setTable(QString nomTable);
    void setChampCle(QString champCle);
    void setChampValeur(QString champValeur);
    void creeMap();
    void peupleCombo();
    void select(QString);
    void setPays();
    void setCommune();
    void setAdresse();
    void setPropriete();
    void setPretraitement();
    void setTraitement();
    void setControle();
    void setExutoire();
    void setTarif();
    void setContact();
    void setWhere(QString);
    void rechargeTarifs(int controle);
    int maxChampValeur();
    void recharge();
signals:

public slots:

private:
    QStringList items;
      CcpaSpancDatabase *db;
      QMap<QString,int> carte;
      QString table;
      QString champCle;
      QString where;
      int filtre;
      Qt::SortOrder ordre;
      QString champValeur;
};





#endif // CCPASPANCCOMBORUE_H
