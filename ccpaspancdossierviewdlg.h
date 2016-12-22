#ifndef CCPASPANCDOSSIERVIEWDLG_H
#define CCPASPANCDOSSIERVIEWDLG_H

#include <QDialog>
#include <QtSql/QSqlTableModel>

namespace Ui {
class CcpaSpancDossierViewDlg;
}

class CcpaSpancDossierViewDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CcpaSpancDossierViewDlg(QWidget *parent = 0);
    ~CcpaSpancDossierViewDlg();
    bool setNoDossier(int no);
    void afficheDossier(int no);

private slots:
    void on_groupBox_4_clicked();

    void on_groupBox_2_clicked();

    void on_groupBox_3_clicked();

    void on_groupBox_5_clicked();

    void on_modifPropriete_clicked();

    void on_modifProprietaire_clicked();

    void on_copieAdresseProprieteProprietaire_clicked();

private:
    Ui::CcpaSpancDossierViewDlg *ui;
    QSqlTableModel dossier_model;
    int no=0;
    int propriete;
    int proprietaire;
    int trouveProprietaire();
    int prevenirDouble();
    void initAdresse();
    void initAdresseP();
    void initPropriete();
    void initProprietaire();
    void initDossier();
    bool adresseIdem();
    int cadresse;
    int padresse;

};

#endif // CCPASPANCDOSSIERVIEWDLG_H
