#ifndef CCPASPANCCONTACTDLG_H
#define CCPASPANCCONTACTDLG_H
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
#include <QSqlTableModel>
#include <QSqlRecord>

namespace Ui {
class CcpaSpancContactDlg;
}

class CcpaSpancContactDlg : public QDialog
{
    Q_OBJECT

public:
    ~CcpaSpancContactDlg();
    explicit CcpaSpancContactDlg(QWidget *parent = 0);
    void setDbIniFichiers(CcpaSpancDatabase* d,CcpaSpancFichiers* f,CcpaGeneriqueIniFile* i);
    void afficheListeChoix();
    void sauve();
    void maj();

    void setContact(int no);
    void setContact(QSqlTableModel* model);
    inline int getContact() { return contact; }
    inline int getAdresse() { return adresse; }
private slots:
    void on_buttonBox_accepted();
    void on_nom_editingFinished();

    void on_plusSociete_clicked();

    void on_plusAdresse_clicked();

    void on_no_editingFinished();

    void on_plusAdresse_pressed();

    void on_loupeAdresse_clicked();

public slots:
    void edit(QListWidgetItem* item);

private:
    Ui::CcpaSpancContactDlg *ui;

    CcpaSpancFichiers* fichiers;
    CcpaGeneriqueIniFile* fichierIni;
    CcpaSpancDatabase* db;
    QListWidget* tooltipE;

    bool estEdit=false;
    int contact=0;
    int adresse=0;
};

#endif // CCPASPANCCONTACTDLG_H
