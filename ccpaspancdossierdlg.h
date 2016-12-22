#ifndef CCPASPANCDOSSIERDLG_H
#define CCPASPANCDOSSIERDLG_H
#include "ccpageneriqueinifile.h"
#include "ccpaspancdatabase.h"
#include "ccpagenerique.h"
#include "ccpaspancfichiers.h"

#include <QDialog>

namespace Ui {
class CcpaSpancDossierDlg;
}


class CcpaSpancDossierDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CcpaSpancDossierDlg(QWidget *parent = 0);
    ~CcpaSpancDossierDlg();
    void setDbIniFichiers(CcpaSpancDatabase* d,CcpaSpancFichiers* f,CcpaGeneriqueIniFile* i);
    int editeAdresse(int no);
    void editeAdressePropriete(int no);
    void afficheAdresseProprietaire();
    void afficheAdresse();
    bool clearMask();
    bool chercheDeFichierLettre();
private slots:
    void on_buttonBox_accepted();

    void on_ville_currentTextChanged(const QString &arg1);

    void on_adresseDiff_clicked();

    void on_dossier_returnPressed();

    void on_dossier_editingFinished();

    void on_conformeCheckBox_clicked(bool checked);

    void on_dossier_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_clicked();

    void on_section_textEdited(const QString &arg1);

    void on_prefixe_textChanged(const QString &arg1);

    void on_prefixe_textEdited(const QString &arg1);

    void on_parcelle_textEdited(const QString &arg1);

    void on_nbPP_textEdited(const QString &arg1);

    void on_annee_textEdited(const QString &arg1);

    void on_prTraitementComboBox_currentIndexChanged(int index);

    void on_traitement_currentIndexChanged(int index);

    void on_agrement_textEdited(const QString &arg1);

    void on_vp_toggled(bool checked);

    void on_vs_toggled(bool checked);

    void on_conformeCheckBox_toggled(bool checked);

    void on_delai_currentIndexChanged(int index);

    void on_urgenceCheckBox_toggled(bool checked);

    void on_exutoire_currentIndexChanged(int index);

    void on_date_userDateChanged(const QDate &date);

    void on_controle_currentIndexChanged(int index);

    void on_nom_textEdited(const QString &arg1);

    void on_prenom_textEdited(const QString &arg1);

    void on_civilite_currentIndexChanged(int index);

    void on_adresseDiff_toggled(bool checked);

    void on_norue_p_textEdited(const QString &arg1);

    void on_typerue_p_textEdited(const QString &arg1);

    void on_nomrue_p_textEdited(const QString &arg1);

    void on_adresse2_p_textEdited(const QString &arg1);

    void on_adresse3_p_textEdited(const QString &arg1);

    void on_ville_p_textEdited(const QString &arg1);

    void on_cp_p_textEdited(const QString &arg1);

    void on_cedex_p_textEdited(const QString &arg1);

    void on_pays_p_currentIndexChanged(int index);

    void on_norue_textEdited(const QString &arg1);

    void on_typerue_textEdited(const QString &arg1);

    void on_nomrue_textEdited(const QString &arg1);

    void on_adresse2_textEdited(const QString &arg1);

    void on_adresse3_textEdited(const QString &arg1);

    void on_ville_currentIndexChanged(int index);

    void on_cp_textEdited(const QString &arg1);


    void on_cedex_textEdited(const QString &arg1);

    void on_noCommune_editingFinished();

    void on_noCommune_textChanged(const QString &arg1);

    void on_norue_textChanged(const QString &arg1);

    void on_typerue_textChanged(const QString &arg1);

    void on_nomrue_textChanged(const QString &arg1);

    void on_adresse2_textChanged(const QString &arg1);

    void on_adresse3_textChanged(const QString &arg1);

    void on_cp_textChanged(const QString &arg1);

    void on_effaceBouton_clicked();

private:
    Ui::CcpaSpancDossierDlg *ui;
    CcpaSpancDatabase* db;
    CcpaSpancFichiers* fichiers;
    CcpaGeneriqueIniFile* ini;
    void afficheRapport();
    void afficheInfos();
    int no_adresse;
    bool est_adresse_propriete;
    int creeAdresse();
    int effaceAdresse();

    bool chercheProprieteDeDossier();
    bool chercheProprietaireDeDossier();
    bool chercheAdresseDeDossier();
    bool chercheAdresseProprietaire();
    bool chercheDonneesDossier();

    int majContact(int id,QString nom,QString prenom,QString titre,int societe,int adresse,QString mail,QString tel,QString fax,QString notes);
    int majContact();
    int majDossier();
    int majAdresseP();
    int majPropriete();
    int majAdresse();

    int sauveNouvelleAdresse();
    int sauveNouvellePropriete();
    int sauveNouveauContact();
    int sauveNouveauEstProprietaire();
    int sauveNouvelleAdresseContact();
    int sauveNouveauDossier();


    void affichePropriete();
    void afficheProprietaire();
    void afficheDossier();
    void afficheDossierDetail();

    void valideFormulaire();

    int nodossier;
    int nocontact;
    int adresseContact;
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
    int liste;

    bool aChangeAdresse=false;
    bool aChangeAdresseP=false;
    bool aChangePropriete=false;
    bool aChangeElemDossier=false;
    bool aChangeContact=false;
    bool aChangeListe=false;

    bool estEdit=false;
};


#endif // CCPASPANCDOSSIERDLG_H
