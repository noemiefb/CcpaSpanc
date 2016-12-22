/********************************************************************************
** Form generated from reading UI file 'ccpaspanccontactdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCPASPANCCONTACTDLG_H
#define UI_CCPASPANCCONTACTDLG_H

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
#include "ccpaspanccombo.h"

QT_BEGIN_NAMESPACE

class Ui_CcpaSpancContactDlg
{
public:
    QFormLayout *formLayout_2;
    QFormLayout *formLayout;
    QLabel *titreLabel;
    QLineEdit *titre;
    QLabel *nomLabel;
    QLineEdit *nom;
    QLabel *prNomLabel;
    QLineEdit *prenom;
    QLabel *mailLabel;
    QLineEdit *mail;
    QLabel *tLPhoneLabel;
    QLineEdit *tel;
    QLabel *faxLabel;
    QLineEdit *fax;
    QLabel *sociTLabel_2;
    QLabel *notesLabel;
    QLineEdit *notesLineEdit;
    QCheckBox *checkBox;
    QLabel *label;
    QDialogButtonBox *buttonBox;
    QLabel *adresseLabel;
    QHBoxLayout *horizontalLayout;
    QLabel *adresseDonnees;
    QToolButton *loupeAdresse;
    QToolButton *plusAdresse;
    QHBoxLayout *horizontalLayout_2;
    CcpaSpancCombo *societe;
    QToolButton *toolButton;
    QToolButton *plusSociete;
    QLabel *label_2;
    QLineEdit *no;

    void setupUi(QDialog *CcpaSpancContactDlg)
    {
        if (CcpaSpancContactDlg->objectName().isEmpty())
            CcpaSpancContactDlg->setObjectName(QStringLiteral("CcpaSpancContactDlg"));
        CcpaSpancContactDlg->resize(292, 369);
        CcpaSpancContactDlg->setSizeGripEnabled(true);
        formLayout_2 = new QFormLayout(CcpaSpancContactDlg);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        titreLabel = new QLabel(CcpaSpancContactDlg);
        titreLabel->setObjectName(QStringLiteral("titreLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, titreLabel);

        titre = new QLineEdit(CcpaSpancContactDlg);
        titre->setObjectName(QStringLiteral("titre"));

        formLayout->setWidget(1, QFormLayout::FieldRole, titre);

        nomLabel = new QLabel(CcpaSpancContactDlg);
        nomLabel->setObjectName(QStringLiteral("nomLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, nomLabel);

        nom = new QLineEdit(CcpaSpancContactDlg);
        nom->setObjectName(QStringLiteral("nom"));

        formLayout->setWidget(2, QFormLayout::FieldRole, nom);

        prNomLabel = new QLabel(CcpaSpancContactDlg);
        prNomLabel->setObjectName(QStringLiteral("prNomLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, prNomLabel);

        prenom = new QLineEdit(CcpaSpancContactDlg);
        prenom->setObjectName(QStringLiteral("prenom"));

        formLayout->setWidget(3, QFormLayout::FieldRole, prenom);

        mailLabel = new QLabel(CcpaSpancContactDlg);
        mailLabel->setObjectName(QStringLiteral("mailLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, mailLabel);

        mail = new QLineEdit(CcpaSpancContactDlg);
        mail->setObjectName(QStringLiteral("mail"));

        formLayout->setWidget(5, QFormLayout::FieldRole, mail);

        tLPhoneLabel = new QLabel(CcpaSpancContactDlg);
        tLPhoneLabel->setObjectName(QStringLiteral("tLPhoneLabel"));

        formLayout->setWidget(6, QFormLayout::LabelRole, tLPhoneLabel);

        tel = new QLineEdit(CcpaSpancContactDlg);
        tel->setObjectName(QStringLiteral("tel"));

        formLayout->setWidget(6, QFormLayout::FieldRole, tel);

        faxLabel = new QLabel(CcpaSpancContactDlg);
        faxLabel->setObjectName(QStringLiteral("faxLabel"));

        formLayout->setWidget(7, QFormLayout::LabelRole, faxLabel);

        fax = new QLineEdit(CcpaSpancContactDlg);
        fax->setObjectName(QStringLiteral("fax"));

        formLayout->setWidget(7, QFormLayout::FieldRole, fax);

        sociTLabel_2 = new QLabel(CcpaSpancContactDlg);
        sociTLabel_2->setObjectName(QStringLiteral("sociTLabel_2"));

        formLayout->setWidget(8, QFormLayout::LabelRole, sociTLabel_2);

        notesLabel = new QLabel(CcpaSpancContactDlg);
        notesLabel->setObjectName(QStringLiteral("notesLabel"));

        formLayout->setWidget(11, QFormLayout::LabelRole, notesLabel);

        notesLineEdit = new QLineEdit(CcpaSpancContactDlg);
        notesLineEdit->setObjectName(QStringLiteral("notesLineEdit"));

        formLayout->setWidget(11, QFormLayout::FieldRole, notesLineEdit);

        checkBox = new QCheckBox(CcpaSpancContactDlg);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        formLayout->setWidget(12, QFormLayout::FieldRole, checkBox);

        label = new QLabel(CcpaSpancContactDlg);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(12, QFormLayout::LabelRole, label);

        buttonBox = new QDialogButtonBox(CcpaSpancContactDlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(13, QFormLayout::FieldRole, buttonBox);

        adresseLabel = new QLabel(CcpaSpancContactDlg);
        adresseLabel->setObjectName(QStringLiteral("adresseLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, adresseLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        adresseDonnees = new QLabel(CcpaSpancContactDlg);
        adresseDonnees->setObjectName(QStringLiteral("adresseDonnees"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(adresseDonnees->sizePolicy().hasHeightForWidth());
        adresseDonnees->setSizePolicy(sizePolicy);
        adresseDonnees->setMaximumSize(QSize(40, 16777215));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 255, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(127, 255, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(63, 255, 63, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(0, 127, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(0, 170, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        adresseDonnees->setPalette(palette);
        adresseDonnees->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 0)"));
        adresseDonnees->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(adresseDonnees);

        loupeAdresse = new QToolButton(CcpaSpancContactDlg);
        loupeAdresse->setObjectName(QStringLiteral("loupeAdresse"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(loupeAdresse->sizePolicy().hasHeightForWidth());
        loupeAdresse->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(loupeAdresse);

        plusAdresse = new QToolButton(CcpaSpancContactDlg);
        plusAdresse->setObjectName(QStringLiteral("plusAdresse"));
        sizePolicy1.setHeightForWidth(plusAdresse->sizePolicy().hasHeightForWidth());
        plusAdresse->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(plusAdresse);


        formLayout->setLayout(4, QFormLayout::FieldRole, horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        societe = new CcpaSpancCombo(CcpaSpancContactDlg);
        societe->setObjectName(QStringLiteral("societe"));

        horizontalLayout_2->addWidget(societe);

        toolButton = new QToolButton(CcpaSpancContactDlg);
        toolButton->setObjectName(QStringLiteral("toolButton"));

        horizontalLayout_2->addWidget(toolButton);

        plusSociete = new QToolButton(CcpaSpancContactDlg);
        plusSociete->setObjectName(QStringLiteral("plusSociete"));

        horizontalLayout_2->addWidget(plusSociete);


        formLayout->setLayout(8, QFormLayout::FieldRole, horizontalLayout_2);

        label_2 = new QLabel(CcpaSpancContactDlg);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        no = new QLineEdit(CcpaSpancContactDlg);
        no->setObjectName(QStringLiteral("no"));

        formLayout->setWidget(0, QFormLayout::FieldRole, no);


        formLayout_2->setLayout(0, QFormLayout::LabelRole, formLayout);

        QWidget::setTabOrder(no, titre);
        QWidget::setTabOrder(titre, nom);
        QWidget::setTabOrder(nom, prenom);
        QWidget::setTabOrder(prenom, plusAdresse);
        QWidget::setTabOrder(plusAdresse, mail);
        QWidget::setTabOrder(mail, tel);
        QWidget::setTabOrder(tel, fax);
        QWidget::setTabOrder(fax, societe);
        QWidget::setTabOrder(societe, plusSociete);
        QWidget::setTabOrder(plusSociete, notesLineEdit);
        QWidget::setTabOrder(notesLineEdit, checkBox);

        retranslateUi(CcpaSpancContactDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), CcpaSpancContactDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CcpaSpancContactDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(CcpaSpancContactDlg);
    } // setupUi

    void retranslateUi(QDialog *CcpaSpancContactDlg)
    {
        CcpaSpancContactDlg->setWindowTitle(QApplication::translate("CcpaSpancContactDlg", "Contact", 0));
        titreLabel->setText(QApplication::translate("CcpaSpancContactDlg", "Titre", 0));
        nomLabel->setText(QApplication::translate("CcpaSpancContactDlg", "Nom", 0));
        prNomLabel->setText(QApplication::translate("CcpaSpancContactDlg", "Pr\303\251nom", 0));
        mailLabel->setText(QApplication::translate("CcpaSpancContactDlg", "Mail", 0));
        tLPhoneLabel->setText(QApplication::translate("CcpaSpancContactDlg", "T\303\251l\303\251phone", 0));
        faxLabel->setText(QApplication::translate("CcpaSpancContactDlg", "Fax", 0));
        sociTLabel_2->setText(QApplication::translate("CcpaSpancContactDlg", "Soci\303\251t\303\251", 0));
        notesLabel->setText(QApplication::translate("CcpaSpancContactDlg", "Notes", 0));
        checkBox->setText(QString());
        label->setText(QApplication::translate("CcpaSpancContactDlg", "Est propri\303\251taire", 0));
        adresseLabel->setText(QApplication::translate("CcpaSpancContactDlg", "Adresse", 0));
        adresseDonnees->setText(QString());
        loupeAdresse->setText(QApplication::translate("CcpaSpancContactDlg", "...", 0));
        plusAdresse->setText(QApplication::translate("CcpaSpancContactDlg", "+", 0));
        toolButton->setText(QApplication::translate("CcpaSpancContactDlg", "...", 0));
        plusSociete->setText(QApplication::translate("CcpaSpancContactDlg", "+", 0));
        label_2->setText(QApplication::translate("CcpaSpancContactDlg", "No", 0));
    } // retranslateUi

};

namespace Ui {
    class CcpaSpancContactDlg: public Ui_CcpaSpancContactDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCPASPANCCONTACTDLG_H
