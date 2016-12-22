/********************************************************************************
** Form generated from reading UI file 'ccpaspancrecherchedlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCPASPANCRECHERCHEDLG_H
#define UI_CCPASPANCRECHERCHEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_CcpaSpancRechercheDlg
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QDialog *CcpaSpancRechercheDlg)
    {
        if (CcpaSpancRechercheDlg->objectName().isEmpty())
            CcpaSpancRechercheDlg->setObjectName(QStringLiteral("CcpaSpancRechercheDlg"));
        CcpaSpancRechercheDlg->resize(1094, 640);
        gridLayout = new QGridLayout(CcpaSpancRechercheDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableView = new QTableView(CcpaSpancRechercheDlg);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionMode(QAbstractItemView::NoSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSortingEnabled(true);

        gridLayout->addWidget(tableView, 1, 1, 1, 1);

        buttonBox = new QDialogButtonBox(CcpaSpancRechercheDlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Help|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 1, 1, 1);

        lineEdit = new QLineEdit(CcpaSpancRechercheDlg);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label = new QLabel(CcpaSpancRechercheDlg);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(CcpaSpancRechercheDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), CcpaSpancRechercheDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CcpaSpancRechercheDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(CcpaSpancRechercheDlg);
    } // setupUi

    void retranslateUi(QDialog *CcpaSpancRechercheDlg)
    {
        CcpaSpancRechercheDlg->setWindowTitle(QApplication::translate("CcpaSpancRechercheDlg", "Dialog", 0));
        label->setText(QApplication::translate("CcpaSpancRechercheDlg", "Nom ou ville", 0));
    } // retranslateUi

};

namespace Ui {
    class CcpaSpancRechercheDlg: public Ui_CcpaSpancRechercheDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCPASPANCRECHERCHEDLG_H
