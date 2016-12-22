/********************************************************************************
** Form generated from reading UI file 'ccpaspancexportfactures.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCPASPANCEXPORTFACTURES_H
#define UI_CCPASPANCEXPORTFACTURES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ccpaspanccombo.h"

QT_BEGIN_NAMESPACE

class Ui_CcpaSpancExportFactures
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *civilite;
    QLineEdit *nom;
    QLabel *label_2;
    QLineEdit *adresse1;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *prenom;
    QLabel *label_3;
    QLineEdit *adresse2;
    QLineEdit *cd;
    QLineEdit *ville;
    QLabel *label;
    QLineEdit *noDossier;
    QLabel *label_6;
    CcpaSpancCombo *controle;
    QLabel *label_7;
    CcpaSpancCombo *tarif;
    QPushButton *pushButton;
    QTableView *listView;
    QPushButton *pushButton_2;
    QFormLayout *formLayout;
    QLabel *nbDossiersL;
    QLineEdit *nbDossiers;
    QLabel *totalL;
    QLineEdit *totalFacture;
    QLabel *numRoDeBordereauLabel;
    QLineEdit *noBordereau;
    QLabel *libellDeLaFacturationLabel;
    QLineEdit *labelFactu;
    QLineEdit *noTitre;
    QLabel *numRoDuTitreLabel;
    QHBoxLayout *horizontalLayout;
    QDateEdit *dateFactu;
    QToolButton *toolButton;
    QLabel *dateDeFacturationLabel;
    QPushButton *pushButton_3;
    QDialogButtonBox *buttonBox;
    QGridLayout *gridLayout_2;

    void setupUi(QDialog *CcpaSpancExportFactures)
    {
        if (CcpaSpancExportFactures->objectName().isEmpty())
            CcpaSpancExportFactures->setObjectName(QStringLiteral("CcpaSpancExportFactures"));
        CcpaSpancExportFactures->resize(695, 597);
        verticalLayoutWidget = new QWidget(CcpaSpancExportFactures);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 681, 577));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        civilite = new QLineEdit(verticalLayoutWidget);
        civilite->setObjectName(QStringLiteral("civilite"));
        civilite->setEnabled(false);

        gridLayout->addWidget(civilite, 1, 1, 1, 1);

        nom = new QLineEdit(verticalLayoutWidget);
        nom->setObjectName(QStringLiteral("nom"));
        nom->setEnabled(false);

        gridLayout->addWidget(nom, 1, 2, 1, 1);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        adresse1 = new QLineEdit(verticalLayoutWidget);
        adresse1->setObjectName(QStringLiteral("adresse1"));
        adresse1->setEnabled(false);

        gridLayout->addWidget(adresse1, 2, 1, 1, 1);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        prenom = new QLineEdit(verticalLayoutWidget);
        prenom->setObjectName(QStringLiteral("prenom"));
        prenom->setEnabled(false);

        gridLayout->addWidget(prenom, 1, 3, 1, 1);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        adresse2 = new QLineEdit(verticalLayoutWidget);
        adresse2->setObjectName(QStringLiteral("adresse2"));
        adresse2->setEnabled(false);

        gridLayout->addWidget(adresse2, 3, 1, 1, 1);

        cd = new QLineEdit(verticalLayoutWidget);
        cd->setObjectName(QStringLiteral("cd"));
        cd->setEnabled(false);

        gridLayout->addWidget(cd, 4, 1, 1, 1);

        ville = new QLineEdit(verticalLayoutWidget);
        ville->setObjectName(QStringLiteral("ville"));
        ville->setEnabled(false);

        gridLayout->addWidget(ville, 4, 2, 1, 1);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        noDossier = new QLineEdit(verticalLayoutWidget);
        noDossier->setObjectName(QStringLiteral("noDossier"));

        gridLayout->addWidget(noDossier, 0, 1, 1, 1);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        controle = new CcpaSpancCombo(verticalLayoutWidget);
        controle->setObjectName(QStringLiteral("controle"));

        gridLayout->addWidget(controle, 5, 1, 1, 1);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 5, 2, 1, 1);

        tarif = new CcpaSpancCombo(verticalLayoutWidget);
        tarif->setObjectName(QStringLiteral("tarif"));

        gridLayout->addWidget(tarif, 5, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        listView = new QTableView(verticalLayoutWidget);
        listView->setObjectName(QStringLiteral("listView"));

        verticalLayout->addWidget(listView);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        nbDossiersL = new QLabel(verticalLayoutWidget);
        nbDossiersL->setObjectName(QStringLiteral("nbDossiersL"));

        formLayout->setWidget(0, QFormLayout::LabelRole, nbDossiersL);

        nbDossiers = new QLineEdit(verticalLayoutWidget);
        nbDossiers->setObjectName(QStringLiteral("nbDossiers"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nbDossiers);

        totalL = new QLabel(verticalLayoutWidget);
        totalL->setObjectName(QStringLiteral("totalL"));

        formLayout->setWidget(1, QFormLayout::LabelRole, totalL);

        totalFacture = new QLineEdit(verticalLayoutWidget);
        totalFacture->setObjectName(QStringLiteral("totalFacture"));

        formLayout->setWidget(1, QFormLayout::FieldRole, totalFacture);

        numRoDeBordereauLabel = new QLabel(verticalLayoutWidget);
        numRoDeBordereauLabel->setObjectName(QStringLiteral("numRoDeBordereauLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, numRoDeBordereauLabel);

        noBordereau = new QLineEdit(verticalLayoutWidget);
        noBordereau->setObjectName(QStringLiteral("noBordereau"));

        formLayout->setWidget(2, QFormLayout::FieldRole, noBordereau);

        libellDeLaFacturationLabel = new QLabel(verticalLayoutWidget);
        libellDeLaFacturationLabel->setObjectName(QStringLiteral("libellDeLaFacturationLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, libellDeLaFacturationLabel);

        labelFactu = new QLineEdit(verticalLayoutWidget);
        labelFactu->setObjectName(QStringLiteral("labelFactu"));

        formLayout->setWidget(4, QFormLayout::FieldRole, labelFactu);

        noTitre = new QLineEdit(verticalLayoutWidget);
        noTitre->setObjectName(QStringLiteral("noTitre"));

        formLayout->setWidget(3, QFormLayout::FieldRole, noTitre);

        numRoDuTitreLabel = new QLabel(verticalLayoutWidget);
        numRoDuTitreLabel->setObjectName(QStringLiteral("numRoDuTitreLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, numRoDuTitreLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        dateFactu = new QDateEdit(verticalLayoutWidget);
        dateFactu->setObjectName(QStringLiteral("dateFactu"));

        horizontalLayout->addWidget(dateFactu);

        toolButton = new QToolButton(verticalLayoutWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));

        horizontalLayout->addWidget(toolButton);


        formLayout->setLayout(8, QFormLayout::FieldRole, horizontalLayout);

        dateDeFacturationLabel = new QLabel(verticalLayoutWidget);
        dateDeFacturationLabel->setObjectName(QStringLiteral("dateDeFacturationLabel"));

        formLayout->setWidget(8, QFormLayout::LabelRole, dateDeFacturationLabel);


        verticalLayout->addLayout(formLayout);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        buttonBox = new QDialogButtonBox(verticalLayoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));

        verticalLayout->addLayout(gridLayout_2);

        QWidget::setTabOrder(noDossier, civilite);
        QWidget::setTabOrder(civilite, nom);
        QWidget::setTabOrder(nom, prenom);
        QWidget::setTabOrder(prenom, adresse1);
        QWidget::setTabOrder(adresse1, adresse2);
        QWidget::setTabOrder(adresse2, cd);
        QWidget::setTabOrder(cd, ville);
        QWidget::setTabOrder(ville, controle);
        QWidget::setTabOrder(controle, tarif);
        QWidget::setTabOrder(tarif, pushButton);
        QWidget::setTabOrder(pushButton, listView);
        QWidget::setTabOrder(listView, pushButton_2);
        QWidget::setTabOrder(pushButton_2, nbDossiers);
        QWidget::setTabOrder(nbDossiers, totalFacture);
        QWidget::setTabOrder(totalFacture, noBordereau);
        QWidget::setTabOrder(noBordereau, noTitre);
        QWidget::setTabOrder(noTitre, labelFactu);
        QWidget::setTabOrder(labelFactu, pushButton_3);

        retranslateUi(CcpaSpancExportFactures);
        QObject::connect(buttonBox, SIGNAL(accepted()), CcpaSpancExportFactures, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CcpaSpancExportFactures, SLOT(reject()));

        QMetaObject::connectSlotsByName(CcpaSpancExportFactures);
    } // setupUi

    void retranslateUi(QDialog *CcpaSpancExportFactures)
    {
        CcpaSpancExportFactures->setWindowTitle(QApplication::translate("CcpaSpancExportFactures", "Facturation", 0));
        label_2->setText(QApplication::translate("CcpaSpancExportFactures", "Civilit\303\251 / Nom / Pr\303\251nom", 0));
        label_4->setText(QApplication::translate("CcpaSpancExportFactures", "Adresse2", 0));
        label_5->setText(QApplication::translate("CcpaSpancExportFactures", "CP / Ville / Pays", 0));
        label_3->setText(QApplication::translate("CcpaSpancExportFactures", "Adresse 1", 0));
        label->setText(QApplication::translate("CcpaSpancExportFactures", "Num\303\251ro de dossier", 0));
        label_6->setText(QApplication::translate("CcpaSpancExportFactures", "Contr\303\264le", 0));
        label_7->setText(QApplication::translate("CcpaSpancExportFactures", "Tarif", 0));
        pushButton->setText(QApplication::translate("CcpaSpancExportFactures", "Ajouter", 0));
        pushButton_2->setText(QApplication::translate("CcpaSpancExportFactures", "Supprimer les lignes s\303\251lectionn\303\251es", 0));
        nbDossiersL->setText(QApplication::translate("CcpaSpancExportFactures", "Nombre de dossiers", 0));
        totalL->setText(QApplication::translate("CcpaSpancExportFactures", "Total factur\303\251:", 0));
        numRoDeBordereauLabel->setText(QApplication::translate("CcpaSpancExportFactures", "Num\303\251ro de bordereau", 0));
        libellDeLaFacturationLabel->setText(QApplication::translate("CcpaSpancExportFactures", "Libell\303\251 de la facturation", 0));
        numRoDuTitreLabel->setText(QApplication::translate("CcpaSpancExportFactures", "Num\303\251ro du titre", 0));
        toolButton->setText(QApplication::translate("CcpaSpancExportFactures", "...", 0));
        dateDeFacturationLabel->setText(QApplication::translate("CcpaSpancExportFactures", "Date de facturation", 0));
        pushButton_3->setText(QApplication::translate("CcpaSpancExportFactures", "Proc\303\251der \303\240 la facturation", 0));
    } // retranslateUi

};

namespace Ui {
    class CcpaSpancExportFactures: public Ui_CcpaSpancExportFactures {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCPASPANCEXPORTFACTURES_H
