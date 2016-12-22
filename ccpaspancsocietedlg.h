#ifndef CCPASPANCSOCIETEDLG_H
#define CCPASPANCSOCIETEDLG_H
#include "ccpaspancdatabase.h"
#include "ccpaspancfichiers.h"
#include "ccpageneriqueinifile.h"
#include "ccpaspancfichiers.h"
#include "ccpaspanccomboadresse.h"
#include "ccpaspanccombopays.h"
#include "ccpaspanccontact.h"
#include <QDialog>
#include <QListWidget>
#include <QListWidgetItem>
#include <QList>
#include <QStringList>
#include <QStringListIterator>

namespace Ui {
class CcpaSpancSocieteDlg;
}

class CcpaSpancSocieteDlg : public QDialog
{
    Q_OBJECT

public:
    ~CcpaSpancSocieteDlg();
    explicit CcpaSpancSocieteDlg(QWidget *parent = 0);
    void setDbIniFichiers(CcpaSpancDatabase* d,CcpaSpancFichiers* f,CcpaGeneriqueIniFile* i);
    void afficheListeChoix();
    inline int getSociete() { return societe; }
private slots:
    void on_buttonBox_accepted();
    void on_nom_editingFinished();
    void on_plusAdresse_clicked();


public slots:
    void edit(QListWidgetItem* item);

private:
    Ui::CcpaSpancSocieteDlg *ui;

    CcpaSpancFichiers* fichiers;
    CcpaGeneriqueIniFile* fichierIni;
    CcpaSpancDatabase* db;
    QListWidget* tooltipE;

    bool estEdit=false;
    int societe=0;
};

#endif // CCPASPANCSOCIETEDLG_H

