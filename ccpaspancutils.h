#ifndef CCPASPANCUTILS_H
#define CCPASPANCUTILS_H

#include <QMainWindow>
#include <QSqlQuery>
#include "ccpaspancfichiers.h"
#include "ccpageneriqueinifile.h"
#include "ccpaspancdatabase.h"

namespace Ui {
class CcpaSpancUtils;
}

class CcpaSpancUtils : public QMainWindow
{
    Q_OBJECT

public:
    explicit CcpaSpancUtils(QWidget *parent = 0);
    ~CcpaSpancUtils();
    void setIniFile(QString file);
    void copieCommandesVersRepertoire();
    void fonctionTestListItem();
private slots:
    void on_pushButton_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

//    void on_editNumCas_returnPressed();


    void on_btnCopieRapportLettre_clicked();

    void on_btnEnvoiMail_clicked();

    void on_btnReserveGroupe_clicked();

    void on_btnIntegreRapport_clicked();

    void on_btnIntegreScan_clicked();

//    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

//    void on_contacts_clicked();

//    void on_adresses_clicked();

//    void on_dossiers_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();


    void on_pushButton_8_clicked();


    void on_pushButton_10_clicked();

    void on_rechercheBouton_clicked();

private:
    Ui::CcpaSpancUtils *ui;
    CcpaSpancFichiers* fichiers;
    CcpaGeneriqueIniFile* fichierIni;
    CcpaSpancDatabase db;
    QSqlQuery query;
};

#endif // CCPASPANCUTILS_H
