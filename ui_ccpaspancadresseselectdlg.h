/********************************************************************************
** Form generated from reading UI file 'ccpaspancadresseselectdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCPASPANCADRESSESELECTDLG_H
#define UI_CCPASPANCADRESSESELECTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ccpaspanccombo.h"

QT_BEGIN_NAMESPACE

class Ui_CcpaSpancAdresseSelectDlg
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *communeLabel;
    CcpaSpancCombo *commune;
    QLabel *typeRue_label;
    CcpaSpancCombo *typeRue;
    QLabel *sLectionnerLaRueLabel;
    CcpaSpancCombo *rue;
    QTableView *tableView;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CcpaSpancAdresseSelectDlg)
    {
        if (CcpaSpancAdresseSelectDlg->objectName().isEmpty())
            CcpaSpancAdresseSelectDlg->setObjectName(QStringLiteral("CcpaSpancAdresseSelectDlg"));
        CcpaSpancAdresseSelectDlg->resize(400, 300);
        verticalLayoutWidget = new QWidget(CcpaSpancAdresseSelectDlg);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 381, 281));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        communeLabel = new QLabel(verticalLayoutWidget);
        communeLabel->setObjectName(QStringLiteral("communeLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, communeLabel);

        commune = new CcpaSpancCombo(verticalLayoutWidget);
        commune->setObjectName(QStringLiteral("commune"));

        formLayout->setWidget(0, QFormLayout::FieldRole, commune);

        typeRue_label = new QLabel(verticalLayoutWidget);
        typeRue_label->setObjectName(QStringLiteral("typeRue_label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, typeRue_label);

        typeRue = new CcpaSpancCombo(verticalLayoutWidget);
        typeRue->setObjectName(QStringLiteral("typeRue"));

        formLayout->setWidget(1, QFormLayout::FieldRole, typeRue);

        sLectionnerLaRueLabel = new QLabel(verticalLayoutWidget);
        sLectionnerLaRueLabel->setObjectName(QStringLiteral("sLectionnerLaRueLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, sLectionnerLaRueLabel);

        rue = new CcpaSpancCombo(verticalLayoutWidget);
        rue->setObjectName(QStringLiteral("rue"));

        formLayout->setWidget(2, QFormLayout::FieldRole, rue);


        verticalLayout->addLayout(formLayout);

        tableView = new QTableView(verticalLayoutWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSortingEnabled(true);

        verticalLayout->addWidget(tableView);

        buttonBox = new QDialogButtonBox(verticalLayoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(CcpaSpancAdresseSelectDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), CcpaSpancAdresseSelectDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CcpaSpancAdresseSelectDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(CcpaSpancAdresseSelectDlg);
    } // setupUi

    void retranslateUi(QDialog *CcpaSpancAdresseSelectDlg)
    {
        CcpaSpancAdresseSelectDlg->setWindowTitle(QApplication::translate("CcpaSpancAdresseSelectDlg", "Dialog", 0));
        communeLabel->setText(QApplication::translate("CcpaSpancAdresseSelectDlg", "S\303\251lectionner la commune", 0));
        typeRue_label->setText(QApplication::translate("CcpaSpancAdresseSelectDlg", "S\303\251lectionner le type de voie", 0));
        sLectionnerLaRueLabel->setText(QApplication::translate("CcpaSpancAdresseSelectDlg", "S\303\251lectionner la rue", 0));
    } // retranslateUi

};

namespace Ui {
    class CcpaSpancAdresseSelectDlg: public Ui_CcpaSpancAdresseSelectDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCPASPANCADRESSESELECTDLG_H
