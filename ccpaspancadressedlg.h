#ifndef CCPASPANCADRESSEDLG_H
#define CCPASPANCADRESSEDLG_H
#include "ccpageneriqueinifile.h"
#include "ccpaspancdatabase.h"
#include "ccpagenerique.h"
#include "ccpaspancfichiers.h"

#include <QDialog>

namespace Ui {
class CcpaSpancAdresseDlg;
}

class CcpaSpancAdresseDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CcpaSpancAdresseDlg(QWidget *parent = 0);
    ~CcpaSpancAdresseDlg();
    void setDbIniFichiers(CcpaSpancDatabase* d,CcpaSpancFichiers* f,CcpaGeneriqueIniFile* i);
    int editeAdresse(int no);
    void afficheAdresse();
    inline int getAdresse() { return adresse ; }
    bool clearMask();
    void setAdresse(int no);
    QString getAdresseText();
    static QString getAdresseText(int no);

private slots:
    void on_buttonBox_accepted();

    void on_ville_currentTextChanged(const QString &arg1);

    void on_dossier_returnPressed();
    void on_buttonBox_rejected();

    void on_pays_currentIndexChanged(int index);

    void on_commune_editingFinished();

private:
    Ui::CcpaSpancAdresseDlg *ui;
    CcpaSpancDatabase* db;
    CcpaSpancFichiers* fichiers;
    CcpaGeneriqueIniFile* ini;
    int no_adresse;
    bool est_adresse_propriete;
    int creeAdresse();
    int effaceAdresse();
    int majAdresse();
    bool chercheAdresseDeDossier();
    int sauveNouvelleAdresse();

    void affichePropriete();
    int adresseContact;
    int adresse=0;
};

#endif // CCPASPANCADRESSEDLG_H
