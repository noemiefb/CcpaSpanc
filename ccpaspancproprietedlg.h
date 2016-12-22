#ifndef CCPASPANCPROPRIETEDLG_H
#define CCPASPANCPROPRIETEDLG_H

#include "ccpaspancdatabase.h"
#include "ccpaspancfichiers.h"
#include "ccpageneriqueinifile.h"
#include "ccpaspancfichiers.h"
#include "ccpaspanccomboadresse.h"
#include "ccpaspanccombopays.h"

#include <QDialog>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlRelationalTableModel>

namespace Ui {
class CcpaSpancProprieteDlg;
}

class CcpaSpancProprieteDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CcpaSpancProprieteDlg(QWidget *parent = 0);
    ~CcpaSpancProprieteDlg();
    void setDbIniFichiers(CcpaSpancDatabase* d,CcpaSpancFichiers* f,CcpaGeneriqueIniFile* i);
    inline int getPropriete() { return propriete; }
    inline int getAdresse() { return adresse; }
    void setPropriete(int no);
    void setPropriete(QSqlRelationalTableModel* record);
    int sauve();
    int maj();
private slots:
    void on_buttonBox_accepted();
    void on_toolButton_clicked();
    void on_loupeAdresse_clicked();
    void on_commune_currentTextChanged(const QString &arg1);

    void on_plusAdresse_clicked();

  //  void on_commune_currentIndexChanged(const QString &arg1);

    void on_commune_currentIndexChanged(int index);

    void on_pushButton_clicked();

private:
   // int selectionneRues(QString nomCommune);
  //  int selectionneNumeros(QString nomCommune,QString nomRue);
   // bool verifieSiAdresseAPropriete(QString no,QString type,QString nom,QString commune);
    Ui::CcpaSpancProprieteDlg *ui;
    CcpaSpancFichiers* fichiers;
    CcpaGeneriqueIniFile* fichierIni;
    CcpaSpancDatabase* db;
    int propriete=0;
    int adresse=0;

};

#endif // CCPASPANCPROPRIETEDLG_H
