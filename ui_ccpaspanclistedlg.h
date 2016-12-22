/********************************************************************************
** Form generated from reading UI file 'ccpaspanclistedlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCPASPANCLISTEDLG_H
#define UI_CCPASPANCLISTEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CcpaSpancListeDlg
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QTableView *tableView;

    void setupUi(QDialog *CcpaSpancListeDlg)
    {
        if (CcpaSpancListeDlg->objectName().isEmpty())
            CcpaSpancListeDlg->setObjectName(QStringLiteral("CcpaSpancListeDlg"));
        CcpaSpancListeDlg->resize(577, 542);
        gridLayoutWidget = new QWidget(CcpaSpancListeDlg);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 561, 521));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        buttonBox = new QDialogButtonBox(gridLayoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);

        tableView = new QTableView(gridLayoutWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);


        retranslateUi(CcpaSpancListeDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), CcpaSpancListeDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CcpaSpancListeDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(CcpaSpancListeDlg);
    } // setupUi

    void retranslateUi(QDialog *CcpaSpancListeDlg)
    {
        CcpaSpancListeDlg->setWindowTitle(QApplication::translate("CcpaSpancListeDlg", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class CcpaSpancListeDlg: public Ui_CcpaSpancListeDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCPASPANCLISTEDLG_H
