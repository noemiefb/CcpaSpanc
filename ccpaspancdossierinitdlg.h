#ifndef CCPASPANCDOSSIERINITDLG_H
#define CCPASPANCDOSSIERINITDLG_H

#include "ccpageneriqueinifile.h"
#include "ccpaspancdatabase.h"
#include "ccpagenerique.h"
#include "ccpaspancfichiers.h"

#include <QDialog>

namespace Ui {
class CcpaSpancDossierInitDlg;
}

class CcpaSpancDossierInitDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CcpaSpancDossierInitDlg(QWidget *parent = 0);
    ~CcpaSpancDossierInitDlg();
    void setDbIniFichiers(CcpaSpancDatabase* d,CcpaSpancFichiers* f,CcpaGeneriqueIniFile* i);


private slots:
    void on_buttonBox_accepted();

    void on_toolButton_clicked();

private:
    Ui::CcpaSpancDossierInitDlg *ui;
    CcpaSpancDatabase* db;
    CcpaSpancFichiers* fichiers;
    CcpaGeneriqueIniFile* ini;
};

#endif // CCPASPANCDOSSIERINITDLG_H
