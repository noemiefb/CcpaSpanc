/********************************************************************************
** Form generated from reading UI file 'ccpaspancadressedlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCPASPANCADRESSEDLG_H
#define UI_CCPASPANCADRESSEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>
#include "ccpaspanccombo.h"

QT_BEGIN_NAMESPACE

class Ui_CcpaSpancAdresseDlg
{
public:
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *norueL;
    QLineEdit *norue;
    QLabel *typerueL;
    QLineEdit *typerue;
    QLabel *nomDeLaRueLabel;
    QLineEdit *nomrue;
    QLabel *adresse2Label;
    QLineEdit *adresse2;
    QLabel *adresse3Label;
    QLineEdit *adresse3;
    QLabel *villeLabel;
    CcpaSpancCombo *ville;
    QLabel *codePostalLabel;
    QLineEdit *cp;
    QLabel *cedexLabel;
    QLineEdit *cedex;
    QLabel *paysLabel;
    CcpaSpancCombo *pays;
    QDialogButtonBox *buttonBox;
    QLabel *communeLabel;
    QLineEdit *commune;

    void setupUi(QDialog *CcpaSpancAdresseDlg)
    {
        if (CcpaSpancAdresseDlg->objectName().isEmpty())
            CcpaSpancAdresseDlg->setObjectName(QStringLiteral("CcpaSpancAdresseDlg"));
        CcpaSpancAdresseDlg->resize(584, 341);
        layoutWidget = new QWidget(CcpaSpancAdresseDlg);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 559, 321));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        norueL = new QLabel(layoutWidget);
        norueL->setObjectName(QStringLiteral("norueL"));

        formLayout->setWidget(2, QFormLayout::LabelRole, norueL);

        norue = new QLineEdit(layoutWidget);
        norue->setObjectName(QStringLiteral("norue"));

        formLayout->setWidget(2, QFormLayout::FieldRole, norue);

        typerueL = new QLabel(layoutWidget);
        typerueL->setObjectName(QStringLiteral("typerueL"));

        formLayout->setWidget(3, QFormLayout::LabelRole, typerueL);

        typerue = new QLineEdit(layoutWidget);
        typerue->setObjectName(QStringLiteral("typerue"));

        formLayout->setWidget(3, QFormLayout::FieldRole, typerue);

        nomDeLaRueLabel = new QLabel(layoutWidget);
        nomDeLaRueLabel->setObjectName(QStringLiteral("nomDeLaRueLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, nomDeLaRueLabel);

        nomrue = new QLineEdit(layoutWidget);
        nomrue->setObjectName(QStringLiteral("nomrue"));

        formLayout->setWidget(5, QFormLayout::FieldRole, nomrue);

        adresse2Label = new QLabel(layoutWidget);
        adresse2Label->setObjectName(QStringLiteral("adresse2Label"));

        formLayout->setWidget(6, QFormLayout::LabelRole, adresse2Label);

        adresse2 = new QLineEdit(layoutWidget);
        adresse2->setObjectName(QStringLiteral("adresse2"));

        formLayout->setWidget(6, QFormLayout::FieldRole, adresse2);

        adresse3Label = new QLabel(layoutWidget);
        adresse3Label->setObjectName(QStringLiteral("adresse3Label"));

        formLayout->setWidget(7, QFormLayout::LabelRole, adresse3Label);

        adresse3 = new QLineEdit(layoutWidget);
        adresse3->setObjectName(QStringLiteral("adresse3"));

        formLayout->setWidget(7, QFormLayout::FieldRole, adresse3);

        villeLabel = new QLabel(layoutWidget);
        villeLabel->setObjectName(QStringLiteral("villeLabel"));

        formLayout->setWidget(9, QFormLayout::LabelRole, villeLabel);

        ville = new CcpaSpancCombo(layoutWidget);
        ville->setObjectName(QStringLiteral("ville"));

        formLayout->setWidget(9, QFormLayout::FieldRole, ville);

        codePostalLabel = new QLabel(layoutWidget);
        codePostalLabel->setObjectName(QStringLiteral("codePostalLabel"));

        formLayout->setWidget(11, QFormLayout::LabelRole, codePostalLabel);

        cp = new QLineEdit(layoutWidget);
        cp->setObjectName(QStringLiteral("cp"));

        formLayout->setWidget(11, QFormLayout::FieldRole, cp);

        cedexLabel = new QLabel(layoutWidget);
        cedexLabel->setObjectName(QStringLiteral("cedexLabel"));

        formLayout->setWidget(12, QFormLayout::LabelRole, cedexLabel);

        cedex = new QLineEdit(layoutWidget);
        cedex->setObjectName(QStringLiteral("cedex"));

        formLayout->setWidget(12, QFormLayout::FieldRole, cedex);

        paysLabel = new QLabel(layoutWidget);
        paysLabel->setObjectName(QStringLiteral("paysLabel"));

        formLayout->setWidget(13, QFormLayout::LabelRole, paysLabel);

        pays = new CcpaSpancCombo(layoutWidget);
        pays->setObjectName(QStringLiteral("pays"));

        formLayout->setWidget(13, QFormLayout::FieldRole, pays);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(17, QFormLayout::FieldRole, buttonBox);

        communeLabel = new QLabel(layoutWidget);
        communeLabel->setObjectName(QStringLiteral("communeLabel"));

        formLayout->setWidget(8, QFormLayout::LabelRole, communeLabel);

        commune = new QLineEdit(layoutWidget);
        commune->setObjectName(QStringLiteral("commune"));

        formLayout->setWidget(8, QFormLayout::FieldRole, commune);

        QWidget::setTabOrder(norue, typerue);
        QWidget::setTabOrder(typerue, nomrue);
        QWidget::setTabOrder(nomrue, adresse2);
        QWidget::setTabOrder(adresse2, adresse3);
        QWidget::setTabOrder(adresse3, commune);
        QWidget::setTabOrder(commune, ville);
        QWidget::setTabOrder(ville, cp);
        QWidget::setTabOrder(cp, cedex);
        QWidget::setTabOrder(cedex, pays);

        retranslateUi(CcpaSpancAdresseDlg);

        QMetaObject::connectSlotsByName(CcpaSpancAdresseDlg);
    } // setupUi

    void retranslateUi(QDialog *CcpaSpancAdresseDlg)
    {
        CcpaSpancAdresseDlg->setWindowTitle(QApplication::translate("CcpaSpancAdresseDlg", "Adresse", 0));
        norueL->setText(QApplication::translate("CcpaSpancAdresseDlg", "No dans la rue", 0));
        typerueL->setText(QApplication::translate("CcpaSpancAdresseDlg", "Type de voie", 0));
        nomDeLaRueLabel->setText(QApplication::translate("CcpaSpancAdresseDlg", "Nom de la rue", 0));
        adresse2Label->setText(QApplication::translate("CcpaSpancAdresseDlg", "Adresse 2", 0));
        adresse3Label->setText(QApplication::translate("CcpaSpancAdresseDlg", "Adresse\302\2403", 0));
        villeLabel->setText(QApplication::translate("CcpaSpancAdresseDlg", "Ville", 0));
        codePostalLabel->setText(QApplication::translate("CcpaSpancAdresseDlg", "Code Postal", 0));
        cedexLabel->setText(QApplication::translate("CcpaSpancAdresseDlg", "Cedex", 0));
        paysLabel->setText(QApplication::translate("CcpaSpancAdresseDlg", "Pays", 0));
        communeLabel->setText(QApplication::translate("CcpaSpancAdresseDlg", "Commune", 0));
    } // retranslateUi

};

namespace Ui {
    class CcpaSpancAdresseDlg: public Ui_CcpaSpancAdresseDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCPASPANCADRESSEDLG_H
