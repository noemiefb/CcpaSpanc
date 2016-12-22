/********************************************************************************
** Form generated from reading UI file 'ccpaspancproprietedlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCPASPANCPROPRIETEDLG_H
#define UI_CCPASPANCPROPRIETEDLG_H

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
#include <QtWidgets/QPushButton>
#include "ccpaspanccombo.h"

QT_BEGIN_NAMESPACE

class Ui_CcpaSpancProprieteDlg
{
public:
    QFormLayout *formLayout_2;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_adresse;
    QLabel *sectionLabel;
    QLineEdit *section;
    QLabel *prFixeLabel;
    QLineEdit *prefixe;
    QLabel *parcelleLabel;
    QLineEdit *parcelle;
    QLabel *nbpplab;
    QLineEdit *nbpp;
    QLabel *annEDeConstructionLabel;
    QLineEdit *annee;
    QLabel *notesLabel;
    QLineEdit *notes;
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton;
    QLabel *communeLabel;
    CcpaSpancCombo *commune;

    void setupUi(QDialog *CcpaSpancProprieteDlg)
    {
        if (CcpaSpancProprieteDlg->objectName().isEmpty())
            CcpaSpancProprieteDlg->setObjectName(QStringLiteral("CcpaSpancProprieteDlg"));
        CcpaSpancProprieteDlg->resize(468, 297);
        formLayout_2 = new QFormLayout(CcpaSpancProprieteDlg);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(CcpaSpancProprieteDlg);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label);

        label_adresse = new QLabel(CcpaSpancProprieteDlg);
        label_adresse->setObjectName(QStringLiteral("label_adresse"));
        label_adresse->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 0)"));
        label_adresse->setFrameShadow(QFrame::Sunken);
        label_adresse->setWordWrap(true);
        label_adresse->setTextInteractionFlags(Qt::NoTextInteraction);

        formLayout->setWidget(2, QFormLayout::FieldRole, label_adresse);

        sectionLabel = new QLabel(CcpaSpancProprieteDlg);
        sectionLabel->setObjectName(QStringLiteral("sectionLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, sectionLabel);

        section = new QLineEdit(CcpaSpancProprieteDlg);
        section->setObjectName(QStringLiteral("section"));

        formLayout->setWidget(3, QFormLayout::FieldRole, section);

        prFixeLabel = new QLabel(CcpaSpancProprieteDlg);
        prFixeLabel->setObjectName(QStringLiteral("prFixeLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, prFixeLabel);

        prefixe = new QLineEdit(CcpaSpancProprieteDlg);
        prefixe->setObjectName(QStringLiteral("prefixe"));

        formLayout->setWidget(4, QFormLayout::FieldRole, prefixe);

        parcelleLabel = new QLabel(CcpaSpancProprieteDlg);
        parcelleLabel->setObjectName(QStringLiteral("parcelleLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, parcelleLabel);

        parcelle = new QLineEdit(CcpaSpancProprieteDlg);
        parcelle->setObjectName(QStringLiteral("parcelle"));

        formLayout->setWidget(5, QFormLayout::FieldRole, parcelle);

        nbpplab = new QLabel(CcpaSpancProprieteDlg);
        nbpplab->setObjectName(QStringLiteral("nbpplab"));

        formLayout->setWidget(6, QFormLayout::LabelRole, nbpplab);

        nbpp = new QLineEdit(CcpaSpancProprieteDlg);
        nbpp->setObjectName(QStringLiteral("nbpp"));

        formLayout->setWidget(6, QFormLayout::FieldRole, nbpp);

        annEDeConstructionLabel = new QLabel(CcpaSpancProprieteDlg);
        annEDeConstructionLabel->setObjectName(QStringLiteral("annEDeConstructionLabel"));

        formLayout->setWidget(7, QFormLayout::LabelRole, annEDeConstructionLabel);

        annee = new QLineEdit(CcpaSpancProprieteDlg);
        annee->setObjectName(QStringLiteral("annee"));

        formLayout->setWidget(7, QFormLayout::FieldRole, annee);

        notesLabel = new QLabel(CcpaSpancProprieteDlg);
        notesLabel->setObjectName(QStringLiteral("notesLabel"));

        formLayout->setWidget(8, QFormLayout::LabelRole, notesLabel);

        notes = new QLineEdit(CcpaSpancProprieteDlg);
        notes->setObjectName(QStringLiteral("notes"));

        formLayout->setWidget(8, QFormLayout::FieldRole, notes);

        buttonBox = new QDialogButtonBox(CcpaSpancProprieteDlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(9, QFormLayout::FieldRole, buttonBox);

        pushButton = new QPushButton(CcpaSpancProprieteDlg);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        formLayout->setWidget(10, QFormLayout::FieldRole, pushButton);

        communeLabel = new QLabel(CcpaSpancProprieteDlg);
        communeLabel->setObjectName(QStringLiteral("communeLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, communeLabel);

        commune = new CcpaSpancCombo(CcpaSpancProprieteDlg);
        commune->setObjectName(QStringLiteral("commune"));

        formLayout->setWidget(1, QFormLayout::FieldRole, commune);


        formLayout_2->setLayout(0, QFormLayout::FieldRole, formLayout);


        retranslateUi(CcpaSpancProprieteDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), CcpaSpancProprieteDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CcpaSpancProprieteDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(CcpaSpancProprieteDlg);
    } // setupUi

    void retranslateUi(QDialog *CcpaSpancProprieteDlg)
    {
        CcpaSpancProprieteDlg->setWindowTitle(QApplication::translate("CcpaSpancProprieteDlg", "Propri\303\251t\303\251", 0));
        label->setText(QApplication::translate("CcpaSpancProprieteDlg", "Adresse", 0));
        label_adresse->setText(QString());
        sectionLabel->setText(QApplication::translate("CcpaSpancProprieteDlg", "Section", 0));
        prFixeLabel->setText(QApplication::translate("CcpaSpancProprieteDlg", "Pr\303\251fixe", 0));
        parcelleLabel->setText(QApplication::translate("CcpaSpancProprieteDlg", "Parcelle", 0));
        nbpplab->setText(QApplication::translate("CcpaSpancProprieteDlg", "Nombre de pi\303\250ces", 0));
        annEDeConstructionLabel->setText(QApplication::translate("CcpaSpancProprieteDlg", "Ann\303\251e de construction", 0));
        notesLabel->setText(QApplication::translate("CcpaSpancProprieteDlg", "Notes", 0));
        pushButton->setText(QApplication::translate("CcpaSpancProprieteDlg", "Changer l'adresse", 0));
        communeLabel->setText(QApplication::translate("CcpaSpancProprieteDlg", "Commune", 0));
    } // retranslateUi

};

namespace Ui {
    class CcpaSpancProprieteDlg: public Ui_CcpaSpancProprieteDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCPASPANCPROPRIETEDLG_H
