#ifndef CCPASPANCEXPORTFACTURES_H
#define CCPASPANCEXPORTFACTURES_H
#include "ccpaspancdatabase.h"
#include "ccpageneriqueinifile.h"
#include "ccpaspancfichiers.h"

#include <QDialog>

namespace Ui {
class CcpaSpancExportFactures;
}

class CcpaSpancExportFactures : public QDialog
{
    Q_OBJECT

public:
    explicit CcpaSpancExportFactures(QWidget *parent = 0);
    ~CcpaSpancExportFactures();
    void setFichierIni(CcpaGeneriqueIniFile* fichier);
    void setDatabase(CcpaSpancDatabase* d);
    void setFichiers(CcpaSpancFichiers* fichiers);
    void initIniDbFichiers(CcpaGeneriqueIniFile* fichier,CcpaSpancDatabase* d,CcpaSpancFichiers* fichiers);
    void initComboControles();
    void initComboTarifs();
    //void initComboPays();
    void initTable();
    void initTotalFactures();
    void initTotalMontant();
    void effaceFormulaireCoordonnees();
    void ajouterCas();
    void changeControle();
    void enleveCas();
    void faitFacturation();

private slots:
    void on_noDossier_editingFinished();

    void on_noDossier_returnPressed();

    void on_pushButton_clicked();

    void on_controle_currentTextChanged(const QString &arg1);

    void on_noDossier_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_controle_currentIndexChanged(int index);

    void menuListe(QPoint point);

    void on_listView_customContextMenuRequested(const QPoint &pos);

    void on_listView_doubleClicked(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_toolButton_clicked();

private:
    Ui::CcpaSpancExportFactures *ui;
    CcpaGeneriqueIniFile* fichierIni;
    CcpaSpancFichiers *fichiers;
    CcpaSpancDatabase* db;
    bool dossierDejaAFacturer();
    bool dossierDejaFacture();
    bool verifieDate(QDate d);
    bool verifieBordereau(int b);
    bool verifieTitre(int t);
    bool valideNbFactures();
    bool valideFormulaireFacturation();
};

#endif // CCPASPANCEXPORTFACTURES_H
