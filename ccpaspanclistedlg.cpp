#include "ccpaspanclistedlg.h"
#include "ui_ccpaspanclistedlg.h"

CcpaSpancListeDlg::CcpaSpancListeDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CcpaSpancListeDlg)
{
    ui->setupUi(this);
}

CcpaSpancListeDlg::~CcpaSpancListeDlg()
{
    delete ui;
}
