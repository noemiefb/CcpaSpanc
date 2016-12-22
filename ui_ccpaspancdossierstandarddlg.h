/********************************************************************************
** Form generated from reading UI file 'ccpaspancdossierstandarddlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCPASPANCDOSSIERSTANDARDDLG_H
#define UI_CCPASPANCDOSSIERSTANDARDDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
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

class Ui_CcpaSpancDossierStandardDlg
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *dossierLabel;
    QLineEdit *dossier;
    QLabel *dateDeContrLeLabel;
    QDateEdit *date;
    QLabel *contrLeLabel;
    CcpaSpancCombo *controle;
    QLabel *labelAdresse;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    CcpaSpancCombo *propriete;
    QToolButton *loupePropriete;
    QToolButton *plusPropriete;
    QToolButton *effacePropriete;
    QLabel *labelPropriete;
    QLabel *prTraitementLabel;
    CcpaSpancCombo *prTraitementComboBox;
    QLabel *traitementLabel;
    CcpaSpancCombo *traitement;
    QLabel *agrMentLabel;
    QLineEdit *agrement;
    QLabel *ventilationPrimaireLabel;
    QCheckBox *vp;
    QLabel *ventilationSecondaireLabel;
    QCheckBox *vs;
    QLabel *exutoireLabel;
    CcpaSpancCombo *exutoire;
    QLabel *conformeLabel;
    QCheckBox *conformeCheckBox;
    QLabel *dLaiLabel;
    QComboBox *delai;
    QLabel *urgenceLabel;
    QCheckBox *urgenceCheckBox;
    QDialogButtonBox *buttonBox;
    QLabel *facturation;
    QHBoxLayout *horizontalLayout_2;
    CcpaSpancCombo *proprietaire;
    QToolButton *loupeProprietaire;
    QToolButton *plusProprietaire;
    QToolButton *effaceProprietaire;
    QLabel *label_3;

    void setupUi(QDialog *CcpaSpancDossierStandardDlg)
    {
        if (CcpaSpancDossierStandardDlg->objectName().isEmpty())
            CcpaSpancDossierStandardDlg->setObjectName(QStringLiteral("CcpaSpancDossierStandardDlg"));
        CcpaSpancDossierStandardDlg->resize(810, 667);
        horizontalLayoutWidget = new QWidget(CcpaSpancDossierStandardDlg);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 0, 491, 541));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        dossierLabel = new QLabel(horizontalLayoutWidget);
        dossierLabel->setObjectName(QStringLiteral("dossierLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, dossierLabel);

        dossier = new QLineEdit(horizontalLayoutWidget);
        dossier->setObjectName(QStringLiteral("dossier"));

        formLayout->setWidget(0, QFormLayout::FieldRole, dossier);

        dateDeContrLeLabel = new QLabel(horizontalLayoutWidget);
        dateDeContrLeLabel->setObjectName(QStringLiteral("dateDeContrLeLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, dateDeContrLeLabel);

        date = new QDateEdit(horizontalLayoutWidget);
        date->setObjectName(QStringLiteral("date"));
        date->setCalendarPopup(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, date);

        contrLeLabel = new QLabel(horizontalLayoutWidget);
        contrLeLabel->setObjectName(QStringLiteral("contrLeLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, contrLeLabel);

        controle = new CcpaSpancCombo(horizontalLayoutWidget);
        controle->setObjectName(QStringLiteral("controle"));

        formLayout->setWidget(2, QFormLayout::FieldRole, controle);

        labelAdresse = new QLabel(horizontalLayoutWidget);
        labelAdresse->setObjectName(QStringLiteral("labelAdresse"));

        formLayout->setWidget(5, QFormLayout::FieldRole, labelAdresse);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setPointSize(8);
        font.setBold(false);
        font.setWeight(50);
        label_2->setFont(font);

        formLayout->setWidget(6, QFormLayout::LabelRole, label_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        propriete = new CcpaSpancCombo(horizontalLayoutWidget);
        propriete->setObjectName(QStringLiteral("propriete"));

        horizontalLayout_3->addWidget(propriete);

        loupePropriete = new QToolButton(horizontalLayoutWidget);
        loupePropriete->setObjectName(QStringLiteral("loupePropriete"));

        horizontalLayout_3->addWidget(loupePropriete);

        plusPropriete = new QToolButton(horizontalLayoutWidget);
        plusPropriete->setObjectName(QStringLiteral("plusPropriete"));

        horizontalLayout_3->addWidget(plusPropriete);

        effacePropriete = new QToolButton(horizontalLayoutWidget);
        effacePropriete->setObjectName(QStringLiteral("effacePropriete"));

        horizontalLayout_3->addWidget(effacePropriete);


        formLayout->setLayout(6, QFormLayout::FieldRole, horizontalLayout_3);

        labelPropriete = new QLabel(horizontalLayoutWidget);
        labelPropriete->setObjectName(QStringLiteral("labelPropriete"));

        formLayout->setWidget(8, QFormLayout::FieldRole, labelPropriete);

        prTraitementLabel = new QLabel(horizontalLayoutWidget);
        prTraitementLabel->setObjectName(QStringLiteral("prTraitementLabel"));

        formLayout->setWidget(10, QFormLayout::LabelRole, prTraitementLabel);

        prTraitementComboBox = new CcpaSpancCombo(horizontalLayoutWidget);
        prTraitementComboBox->setObjectName(QStringLiteral("prTraitementComboBox"));

        formLayout->setWidget(10, QFormLayout::FieldRole, prTraitementComboBox);

        traitementLabel = new QLabel(horizontalLayoutWidget);
        traitementLabel->setObjectName(QStringLiteral("traitementLabel"));

        formLayout->setWidget(11, QFormLayout::LabelRole, traitementLabel);

        traitement = new CcpaSpancCombo(horizontalLayoutWidget);
        traitement->setObjectName(QStringLiteral("traitement"));

        formLayout->setWidget(11, QFormLayout::FieldRole, traitement);

        agrMentLabel = new QLabel(horizontalLayoutWidget);
        agrMentLabel->setObjectName(QStringLiteral("agrMentLabel"));

        formLayout->setWidget(12, QFormLayout::LabelRole, agrMentLabel);

        agrement = new QLineEdit(horizontalLayoutWidget);
        agrement->setObjectName(QStringLiteral("agrement"));

        formLayout->setWidget(12, QFormLayout::FieldRole, agrement);

        ventilationPrimaireLabel = new QLabel(horizontalLayoutWidget);
        ventilationPrimaireLabel->setObjectName(QStringLiteral("ventilationPrimaireLabel"));

        formLayout->setWidget(13, QFormLayout::LabelRole, ventilationPrimaireLabel);

        vp = new QCheckBox(horizontalLayoutWidget);
        vp->setObjectName(QStringLiteral("vp"));

        formLayout->setWidget(13, QFormLayout::FieldRole, vp);

        ventilationSecondaireLabel = new QLabel(horizontalLayoutWidget);
        ventilationSecondaireLabel->setObjectName(QStringLiteral("ventilationSecondaireLabel"));

        formLayout->setWidget(14, QFormLayout::LabelRole, ventilationSecondaireLabel);

        vs = new QCheckBox(horizontalLayoutWidget);
        vs->setObjectName(QStringLiteral("vs"));

        formLayout->setWidget(14, QFormLayout::FieldRole, vs);

        exutoireLabel = new QLabel(horizontalLayoutWidget);
        exutoireLabel->setObjectName(QStringLiteral("exutoireLabel"));

        formLayout->setWidget(15, QFormLayout::LabelRole, exutoireLabel);

        exutoire = new CcpaSpancCombo(horizontalLayoutWidget);
        exutoire->setObjectName(QStringLiteral("exutoire"));

        formLayout->setWidget(15, QFormLayout::FieldRole, exutoire);

        conformeLabel = new QLabel(horizontalLayoutWidget);
        conformeLabel->setObjectName(QStringLiteral("conformeLabel"));

        formLayout->setWidget(16, QFormLayout::LabelRole, conformeLabel);

        conformeCheckBox = new QCheckBox(horizontalLayoutWidget);
        conformeCheckBox->setObjectName(QStringLiteral("conformeCheckBox"));

        formLayout->setWidget(16, QFormLayout::FieldRole, conformeCheckBox);

        dLaiLabel = new QLabel(horizontalLayoutWidget);
        dLaiLabel->setObjectName(QStringLiteral("dLaiLabel"));

        formLayout->setWidget(17, QFormLayout::LabelRole, dLaiLabel);

        delai = new QComboBox(horizontalLayoutWidget);
        delai->setObjectName(QStringLiteral("delai"));

        formLayout->setWidget(17, QFormLayout::FieldRole, delai);

        urgenceLabel = new QLabel(horizontalLayoutWidget);
        urgenceLabel->setObjectName(QStringLiteral("urgenceLabel"));

        formLayout->setWidget(18, QFormLayout::LabelRole, urgenceLabel);

        urgenceCheckBox = new QCheckBox(horizontalLayoutWidget);
        urgenceCheckBox->setObjectName(QStringLiteral("urgenceCheckBox"));

        formLayout->setWidget(18, QFormLayout::FieldRole, urgenceCheckBox);

        buttonBox = new QDialogButtonBox(horizontalLayoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(19, QFormLayout::FieldRole, buttonBox);

        facturation = new QLabel(horizontalLayoutWidget);
        facturation->setObjectName(QStringLiteral("facturation"));

        formLayout->setWidget(21, QFormLayout::FieldRole, facturation);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        proprietaire = new CcpaSpancCombo(horizontalLayoutWidget);
        proprietaire->setObjectName(QStringLiteral("proprietaire"));

        horizontalLayout_2->addWidget(proprietaire);

        loupeProprietaire = new QToolButton(horizontalLayoutWidget);
        loupeProprietaire->setObjectName(QStringLiteral("loupeProprietaire"));

        horizontalLayout_2->addWidget(loupeProprietaire);

        plusProprietaire = new QToolButton(horizontalLayoutWidget);
        plusProprietaire->setObjectName(QStringLiteral("plusProprietaire"));

        horizontalLayout_2->addWidget(plusProprietaire);

        effaceProprietaire = new QToolButton(horizontalLayoutWidget);
        effaceProprietaire->setObjectName(QStringLiteral("effaceProprietaire"));

        horizontalLayout_2->addWidget(effaceProprietaire);


        formLayout->setLayout(9, QFormLayout::FieldRole, horizontalLayout_2);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_3);


        horizontalLayout->addLayout(formLayout);

        QWidget::setTabOrder(dossier, date);
        QWidget::setTabOrder(date, controle);
        QWidget::setTabOrder(controle, propriete);
        QWidget::setTabOrder(propriete, loupePropriete);
        QWidget::setTabOrder(loupePropriete, plusPropriete);
        QWidget::setTabOrder(plusPropriete, effacePropriete);
        QWidget::setTabOrder(effacePropriete, proprietaire);
        QWidget::setTabOrder(proprietaire, loupeProprietaire);
        QWidget::setTabOrder(loupeProprietaire, plusProprietaire);
        QWidget::setTabOrder(plusProprietaire, effaceProprietaire);
        QWidget::setTabOrder(effaceProprietaire, prTraitementComboBox);
        QWidget::setTabOrder(prTraitementComboBox, traitement);
        QWidget::setTabOrder(traitement, agrement);
        QWidget::setTabOrder(agrement, vp);
        QWidget::setTabOrder(vp, vs);
        QWidget::setTabOrder(vs, exutoire);
        QWidget::setTabOrder(exutoire, conformeCheckBox);
        QWidget::setTabOrder(conformeCheckBox, delai);
        QWidget::setTabOrder(delai, urgenceCheckBox);

        retranslateUi(CcpaSpancDossierStandardDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), CcpaSpancDossierStandardDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CcpaSpancDossierStandardDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(CcpaSpancDossierStandardDlg);
    } // setupUi

    void retranslateUi(QDialog *CcpaSpancDossierStandardDlg)
    {
        CcpaSpancDossierStandardDlg->setWindowTitle(QApplication::translate("CcpaSpancDossierStandardDlg", "Dossier", 0));
        dossierLabel->setText(QApplication::translate("CcpaSpancDossierStandardDlg", "Dossier", 0));
        dateDeContrLeLabel->setText(QApplication::translate("CcpaSpancDossierStandardDlg", "Date de contr\303\264le", 0));
        contrLeLabel->setText(QApplication::translate("CcpaSpancDossierStandardDlg", "Contr\303\264le", 0));
        labelAdresse->setText(QString());
        label_2->setText(QApplication::translate("CcpaSpancDossierStandardDlg", "Propri\303\251t\303\251", 0));
        loupePropriete->setText(QApplication::translate("CcpaSpancDossierStandardDlg", "...", 0));
        plusPropriete->setText(QApplication::translate("CcpaSpancDossierStandardDlg", "+", 0));
        effacePropriete->setText(QApplication::translate("CcpaSpancDossierStandardDlg", "-", 0));
        labelPropriete->setText(QString());
        prTraitementLabel->setText(QApplication::translate("CcpaSpancDossierStandardDlg", "Pr\303\251traitement", 0));
        traitementLabel->setText(QApplication::translate("CcpaSpancDossierStandardDlg", "Traitement", 0));
        agrMentLabel->setText(QApplication::translate("CcpaSpancDossierStandardDlg", "Agr\303\251ment", 0));
        ventilationPrimaireLabel->setText(QApplication::translate("CcpaSpancDossierStandardDlg", "Ventilation primaire", 0));
        ventilationSecondaireLabel->setText(QApplication::translate("CcpaSpancDossierStandardDlg", "Ventilation secondaire", 0));
        exutoireLabel->setText(QApplication::translate("CcpaSpancDossierStandardDlg", "Exutoire", 0));
        conformeLabel->setText(QApplication::translate("CcpaSpancDossierStandardDlg", "Conforme", 0));
        dLaiLabel->setText(QApplication::translate("CcpaSpancDossierStandardDlg", "D\303\251lai ( en ann\303\251es)", 0));
        delai->clear();
        delai->insertItems(0, QStringList()
         << QApplication::translate("CcpaSpancDossierStandardDlg", "0", 0)
         << QApplication::translate("CcpaSpancDossierStandardDlg", "1", 0)
         << QApplication::translate("CcpaSpancDossierStandardDlg", "4", 0)
        );
        urgenceLabel->setText(QApplication::translate("CcpaSpancDossierStandardDlg", "Urgence", 0));
        facturation->setText(QString());
        loupeProprietaire->setText(QApplication::translate("CcpaSpancDossierStandardDlg", "...", 0));
        plusProprietaire->setText(QApplication::translate("CcpaSpancDossierStandardDlg", "+", 0));
        effaceProprietaire->setText(QApplication::translate("CcpaSpancDossierStandardDlg", "-", 0));
        label_3->setText(QApplication::translate("CcpaSpancDossierStandardDlg", "Propri\303\251taire", 0));
    } // retranslateUi

};

namespace Ui {
    class CcpaSpancDossierStandardDlg: public Ui_CcpaSpancDossierStandardDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCPASPANCDOSSIERSTANDARDDLG_H
