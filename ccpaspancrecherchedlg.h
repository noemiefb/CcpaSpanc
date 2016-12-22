#ifndef CCPASPANCRECHERCHEDLG_H
#define CCPASPANCRECHERCHEDLG_H

#include <QDialog>
#include "QtSql/QSqlDatabase"
#include "QTableView"
#include "QtSql/QSqlTableModel"
#include "QAbstractButton"

namespace Ui {
class CcpaSpancRechercheDlg;
}

class CcpaSpancRechercheDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CcpaSpancRechercheDlg(QWidget *parent = 0);
    ~CcpaSpancRechercheDlg();
    QSqlTableModel modelDossier;

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

    void on_lineEdit_editingFinished();

    void on_tableView_customContextMenuRequested(const QPoint &pos);

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::CcpaSpancRechercheDlg *ui;
};

#endif // CCPASPANCRECHERCHEDLG_H
