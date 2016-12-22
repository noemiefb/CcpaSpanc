#ifndef CCPASPANCOBJET_H
#define CCPASPANCOBJET_H
#include <QSqlTableModel>
#include <QSqlRecord>

class CcpaSpancObjet
{
public:
    CcpaSpancObjet();
    void setTable(QString table);
    bool maj();
    bool efface();
    bool ajoute();
    bool aRecordActif();
    void setRecordActif(QSqlRecord* record);
    QString getString(QString nom);
    int getInt(QString nom);
    QDate getDate(QString date);
    bool getBool(QString champ);
    void setString(QString champ,QString value);
    void setDate(QString champ,QDate date);
    void setInt(QString champ,int value);
    void setBool(QString champ,bool value);
    QSqlRecord* positionneSur(QString champ,QString value,bool guillemets=true);
protected:
    QSqlTableModel* model;
    QSqlRecord* record;
private:

};

#endif // CCPASPANCOBJET_H
