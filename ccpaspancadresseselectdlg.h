#ifndef CCPASPANCADRESSESELECTDLG_H
#define CCPASPANCADRESSESELECTDLG_H
#include "ccpageneriqueinifile.h"
#include "ccpaspancdatabase.h"
#include "ccpagenerique.h"
#include "ccpaspancfichiers.h"
#include <QDialog>
#include <QString>

namespace Ui {
class CcpaSpancAdresseSelectDlg;
}

class CcpaSpancAdresseSelectDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CcpaSpancAdresseSelectDlg(QWidget *parent = 0);
    ~CcpaSpancAdresseSelectDlg();
    void setDbIniFichiers(CcpaSpancDatabase* d,CcpaSpancFichiers* f,CcpaGeneriqueIniFile* i);
    int getAdresse();
    QString getAdresseData();

private slots:
    void on_commune_currentTextChanged(const QString &arg1);

    void on_typeRue_currentIndexChanged(const QString &arg1);

    void on_rue_currentIndexChanged(const QString &arg1);

    void on_buttonBox_accepted();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::CcpaSpancAdresseSelectDlg *ui;
    CcpaSpancDatabase* db;
    CcpaSpancFichiers* fichiers;
    CcpaGeneriqueIniFile* ini;
    int no_adresse=0;
    QString texte="";
};

#endif // CCPASPANCADRESSESELECTDLG_H
