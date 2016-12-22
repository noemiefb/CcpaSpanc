/********************************************************************************
** Form generated from reading UI file 'ccpaspancdossierinitdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCPASPANCDOSSIERINITDLG_H
#define UI_CCPASPANCDOSSIERINITDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "ccpaspanccombo.h"

QT_BEGIN_NAMESPACE

class Ui_CcpaSpancDossierInitDlg
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *numRoDeDossierLabel;
    QLineEdit *no;
    QHBoxLayout *horizontalLayout;
    CcpaSpancCombo *propriete;
    QToolButton *toolButton;
    QLabel *label;
    QDialogButtonBox *buttonBox;
    CcpaSpancCombo *controle;
    QLabel *contrLeLabel;

    void setupUi(QDialog *CcpaSpancDossierInitDlg)
    {
        if (CcpaSpancDossierInitDlg->objectName().isEmpty())
            CcpaSpancDossierInitDlg->setObjectName(QStringLiteral("CcpaSpancDossierInitDlg"));
        CcpaSpancDossierInitDlg->resize(262, 121);
        formLayoutWidget = new QWidget(CcpaSpancDossierInitDlg);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 0, 253, 111));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        numRoDeDossierLabel = new QLabel(formLayoutWidget);
        numRoDeDossierLabel->setObjectName(QStringLiteral("numRoDeDossierLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, numRoDeDossierLabel);

        no = new QLineEdit(formLayoutWidget);
        no->setObjectName(QStringLiteral("no"));

        formLayout->setWidget(0, QFormLayout::FieldRole, no);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        propriete = new CcpaSpancCombo(formLayoutWidget);
        propriete->setObjectName(QStringLiteral("propriete"));

        horizontalLayout->addWidget(propriete);

        toolButton = new QToolButton(formLayoutWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));

        horizontalLayout->addWidget(toolButton);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        buttonBox = new QDialogButtonBox(formLayoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(3, QFormLayout::FieldRole, buttonBox);

        controle = new CcpaSpancCombo(formLayoutWidget);
        controle->setObjectName(QStringLiteral("controle"));

        formLayout->setWidget(2, QFormLayout::FieldRole, controle);

        contrLeLabel = new QLabel(formLayoutWidget);
        contrLeLabel->setObjectName(QStringLiteral("contrLeLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, contrLeLabel);


        retranslateUi(CcpaSpancDossierInitDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), CcpaSpancDossierInitDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CcpaSpancDossierInitDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(CcpaSpancDossierInitDlg);
    } // setupUi

    void retranslateUi(QDialog *CcpaSpancDossierInitDlg)
    {
        CcpaSpancDossierInitDlg->setWindowTitle(QApplication::translate("CcpaSpancDossierInitDlg", "Dossier (interface simplifi\303\251e)", 0));
        numRoDeDossierLabel->setText(QApplication::translate("CcpaSpancDossierInitDlg", "Num\303\251ro de dossier", 0));
        toolButton->setText(QApplication::translate("CcpaSpancDossierInitDlg", "+", 0));
        label->setText(QApplication::translate("CcpaSpancDossierInitDlg", "Propri\303\251t\303\251", 0));
        contrLeLabel->setText(QApplication::translate("CcpaSpancDossierInitDlg", "Contr\303\264le", 0));
    } // retranslateUi

};

namespace Ui {
    class CcpaSpancDossierInitDlg: public Ui_CcpaSpancDossierInitDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCPASPANCDOSSIERINITDLG_H
