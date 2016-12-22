#ifndef CCPASPANCESTPROPRIETAIREDLG_H
#define CCPASPANCESTPROPRIETAIREDLG_H
#include "ccpaspancfichiers.h"
#include "ccpaspancdlgretour.h"
#include "ccpaspanccreegroupe.h"
#include "ccpaspancmail.h"
#include "ccpaspanccopierapportlettre.h"
#include "ccpaspancintegrescan.h"
#include "ccpaspancdatabase.h"
#include "ccpaspancexportfactures.h"
#include "ccpaspanccontact.h"
#include "ccpaspanccombocommune.h"
#include "ccpaspanccombopays.h"
#include "ccpaspanccombotraitement.h"
#include "ccpaspanccombopretraitement.h"

#include <QDialog>

namespace Ui {
class CcpaSpancEstProprietaireDlg;
}

class CcpaSpancEstProprietaireDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CcpaSpancEstProprietaireDlg(QWidget *parent = 0);
    ~CcpaSpancEstProprietaireDlg();
    void setDbIniFichiers(CcpaSpancDatabase* d,CcpaSpancFichiers* f,CcpaGeneriqueIniFile* i);

private slots:
    void on_listView_clicked(const QModelIndex &index);

    void on_buttonBox_accepted();

private:

    Ui::CcpaSpancEstProprietaireDlg *ui;
    CcpaSpancDatabase* db;
    CcpaSpancFichiers* fichiers;
    CcpaGeneriqueIniFile* ini;
};

#endif // CCPASPANCESTPROPRIETAIREDLG_H
