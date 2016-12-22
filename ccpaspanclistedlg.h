#ifndef CCPASPANCLISTEDLG_H
#define CCPASPANCLISTEDLG_H

#include <QDialog>

namespace Ui {
class CcpaSpancListeDlg;
}

class CcpaSpancListeDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CcpaSpancListeDlg(QWidget *parent = 0);
    ~CcpaSpancListeDlg();

private:
    Ui::CcpaSpancListeDlg *ui;
};

#endif // CCPASPANCLISTEDLG_H
