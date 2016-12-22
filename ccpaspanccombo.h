#ifndef CCPASPANCCOMBO_H
#define CCPASPANCCOMBO_H

#include <QObject>
#include <QWidget>
#include <QComboBox>

#include "ccpaspancdatabase.h"


class CcpaSpancCombo: public QComboBox
{
    Q_OBJECT
public:
    explicit CcpaSpancCombo(QWidget* );
    void setDatabase(CcpaSpancDatabase* db);
    int indexCourant();
    void setValue(int i);
    void setOrder(QString champFiltre,Qt::SortOrder order);
    void setValue(QString nom);
    void setTable(QString nomTable);
    void setChampCle(QString champCle);
    void setChampValeur(QString champValeur);
    void creeMap();
    void creeMapDistinct();
    void peupleCombo();
    void select(QString);
    void setPays();
    void setCommune();
    void setCommuneA();
    void setAdresse();
    void setPropriete();
    void setPretraitement();
    void setTraitement();
    void setControle();
    void setExutoire();
    void setTarif();
    void setContact();
    void setRue();
    void setTypeRue();
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



#endif // CCPASPANCCOMBOSOCIETE_H
