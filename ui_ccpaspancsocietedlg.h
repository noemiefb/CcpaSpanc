/********************************************************************************
** Form generated from reading UI file 'ccpaspancsocietedlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCPASPANCSOCIETEDLG_H
#define UI_CCPASPANCSOCIETEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
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

class Ui_CcpaSpancSocieteDlg
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *titreLabel;
    QLineEdit *nom;
    QLabel *nomLabel;
    QLineEdit *siret;
    QLabel *adresseLabel;
    QHBoxLayout *horizontalLayout;
    CcpaSpancCombo *adresse;
    QToolButton *plusAdresse;
    QLabel *mailLabel;
    QLineEdit *mail;
    QLabel *tLPhoneLabel;
    QLineEdit *tel;
    QLabel *faxLabel;
    QLineEdit *fax;
    QLabel *label_2;
    QLineEdit *web;
    QLabel *label;
    QCheckBox *checkBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CcpaSpancSocieteDlg)
    {
        if (CcpaSpancSocieteDlg->objectName().isEmpty())
            CcpaSpancSocieteDlg->setObjectName(QStringLiteral("CcpaSpancSocieteDlg"));
        CcpaSpancSocieteDlg->resize(384, 268);
        formLayoutWidget = new QWidget(CcpaSpancSocieteDlg);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(19, 9, 351, 251));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        titreLabel = new QLabel(formLayoutWidget);
        titreLabel->setObjectName(QStringLiteral("titreLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, titreLabel);

        nom = new QLineEdit(formLayoutWidget);
        nom->setObjectName(QStringLiteral("nom"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nom);

        nomLabel = new QLabel(formLayoutWidget);
        nomLabel->setObjectName(QStringLiteral("nomLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, nomLabel);

        siret = new QLineEdit(formLayoutWidget);
        siret->setObjectName(QStringLiteral("siret"));

        formLayout->setWidget(1, QFormLayout::FieldRole, siret);

        adresseLabel = new QLabel(formLayoutWidget);
        adresseLabel->setObjectName(QStringLiteral("adresseLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, adresseLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        adresse = new CcpaSpancCombo(formLayoutWidget);
        adresse->setObjectName(QStringLiteral("adresse"));

        horizontalLayout->addWidget(adresse);

        plusAdresse = new QToolButton(formLayoutWidget);
        plusAdresse->setObjectName(QStringLiteral("plusAdresse"));

        horizontalLayout->addWidget(plusAdresse);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout);

        mailLabel = new QLabel(formLayoutWidget);
        mailLabel->setObjectName(QStringLiteral("mailLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, mailLabel);

        mail = new QLineEdit(formLayoutWidget);
        mail->setObjectName(QStringLiteral("mail"));

        formLayout->setWidget(3, QFormLayout::FieldRole, mail);

        tLPhoneLabel = new QLabel(formLayoutWidget);
        tLPhoneLabel->setObjectName(QStringLiteral("tLPhoneLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, tLPhoneLabel);

        tel = new QLineEdit(formLayoutWidget);
        tel->setObjectName(QStringLiteral("tel"));

        formLayout->setWidget(4, QFormLayout::FieldRole, tel);

        faxLabel = new QLabel(formLayoutWidget);
        faxLabel->setObjectName(QStringLiteral("faxLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, faxLabel);

        fax = new QLineEdit(formLayoutWidget);
        fax->setObjectName(QStringLiteral("fax"));

        formLayout->setWidget(5, QFormLayout::FieldRole, fax);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_2);

        web = new QLineEdit(formLayoutWidget);
        web->setObjectName(QStringLiteral("web"));

        formLayout->setWidget(6, QFormLayout::FieldRole, web);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label);

        checkBox = new QCheckBox(formLayoutWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        formLayout->setWidget(8, QFormLayout::FieldRole, checkBox);

        buttonBox = new QDialogButtonBox(formLayoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(9, QFormLayout::FieldRole, buttonBox);


        retranslateUi(CcpaSpancSocieteDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), CcpaSpancSocieteDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CcpaSpancSocieteDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(CcpaSpancSocieteDlg);
    } // setupUi

    void retranslateUi(QDialog *CcpaSpancSocieteDlg)
    {
        CcpaSpancSocieteDlg->setWindowTitle(QApplication::translate("CcpaSpancSocieteDlg", "Soci\303\251t\303\251", 0));
        titreLabel->setText(QApplication::translate("CcpaSpancSocieteDlg", "Raison sociale", 0));
        nomLabel->setText(QApplication::translate("CcpaSpancSocieteDlg", "SIRET", 0));
        adresseLabel->setText(QApplication::translate("CcpaSpancSocieteDlg", "Adresse", 0));
        plusAdresse->setText(QApplication::translate("CcpaSpancSocieteDlg", "+", 0));
        mailLabel->setText(QApplication::translate("CcpaSpancSocieteDlg", "Mail", 0));
        tLPhoneLabel->setText(QApplication::translate("CcpaSpancSocieteDlg", "T\303\251l\303\251phone", 0));
        faxLabel->setText(QApplication::translate("CcpaSpancSocieteDlg", "Fax", 0));
        label_2->setText(QApplication::translate("CcpaSpancSocieteDlg", "Site web", 0));
        label->setText(QApplication::translate("CcpaSpancSocieteDlg", "Est notaire", 0));
        checkBox->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CcpaSpancSocieteDlg: public Ui_CcpaSpancSocieteDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCPASPANCSOCIETEDLG_H
