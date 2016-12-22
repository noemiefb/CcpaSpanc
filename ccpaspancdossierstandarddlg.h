#ifndef CCPASPANCDOSSIERSTANDARDDLG_H
#define CCPASPANCDOSSIERSTANDARDDLG_H
#include "ccpageneriqueinifile.h"
#include "ccpaspancdatabase.h"
#include "ccpagenerique.h"
#include "ccpaspancfichiers.h"

#include <QDialog>

namespace Ui {
class CcpaSpancDossierStandardDlg;
}


class CcpaSpancDossierStandardDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CcpaSpancDossierStandardDlg(QWidget *parent = 0);
    ~CcpaSpancDossierStandardDlg();
    void setDbIniFichiers(CcpaSpancDatabase* d,CcpaSpancFichiers* f,CcpaGeneriqueIniFile* i);

    void editeAdressePropriete(int no);
    void afficheAdresseProprietaire();
    void afficheDetailPropriete();
    bool clearMask();
private slots:
    void on_buttonBox_accepted();
    void on_dossier_editingFinished();
    void on_conformeCheckBox_clicked(bool checked);
    void on_plusProprietaire_clicked();

    void on_plusPropriete_clicked();

    void on_loupeProprietaire_clicked();

    void on_loupePropriete_clicked();

    void on_proprietaire_currentIndexChanged(int index);


    void on_effacePropriete_clicked();

    void on_effaceProprietaire_clicked();

    void on_proprietaire_currentTextChanged(const QString &arg1);

private:
    Ui::CcpaSpancDossierStandardDlg *ui;
    CcpaSpancDatabase* db;
    CcpaSpancFichiers* fichiers;
    CcpaGeneriqueIniFile* ini;
    int no_adresse;
    bool est_adresse_propriete;


    bool chercheProprieteDeDossier();
    bool chercheProprietaireDeDossier();
    bool chercheAdresseDeDossier();
    bool chercheAdresseProprietaire();
    bool chercheDonneesDossier();
    bool chercheProprieteAdresse();
    bool chercheControleDeDossier();

    int sauveNouveauDossier();
    void afficheDossier();
    void afficheControle();
    void afficheAdresse();
    void affichePropriete();
    void afficheProprietaire();
    void afficheDossierDetail();
    void initPropriete();
    bool majDossier();

    int nodossier;
    int controle;
    int nocontact;
    int adresse;
    int propriete;
    int pretraitement;
    int traitement;
    int delai;
    int estproprietaire;
    bool conforme;
    bool vp;
    bool vs;
    bool urgence;
};


#endif // CCPASPANCDOSSIERSTANDARDDLG_H
