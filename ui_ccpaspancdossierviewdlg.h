/********************************************************************************
** Form generated from reading UI file 'ccpaspancdossierviewdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCPASPANCDOSSIERVIEWDLG_H
#define UI_CCPASPANCDOSSIERVIEWDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CcpaSpancDossierViewDlg
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QLabel *label_exutoire;
    QLabel *label_7;
    QLabel *label_conformite;
    QLabel *label_delai;
    QLabel *label_ventil2;
    QLabel *label;
    QLabel *label_pretraitement;
    QLabel *label_traitement;
    QLabel *label_3;
    QLabel *label_ventil1;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_liste;
    QLabel *label_2;
    QLabel *label_8;
    QLabel *label_no;
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_propriete;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *label_adresse;
    QPushButton *modifPropriete;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_proprietaire;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_adresseP;
    QToolButton *modifProprietaire;
    QToolButton *copieAdresseProprieteProprietaire;

    void setupUi(QDialog *CcpaSpancDossierViewDlg)
    {
        if (CcpaSpancDossierViewDlg->objectName().isEmpty())
            CcpaSpancDossierViewDlg->setObjectName(QStringLiteral("CcpaSpancDossierViewDlg"));
        CcpaSpancDossierViewDlg->resize(522, 586);
        gridLayout = new QGridLayout(CcpaSpancDossierViewDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(CcpaSpancDossierViewDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 6, 0, 1, 1);

        label_exutoire = new QLabel(groupBox);
        label_exutoire->setObjectName(QStringLiteral("label_exutoire"));
        label_exutoire->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_exutoire->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(label_exutoire, 5, 1, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 7, 0, 1, 1);

        label_conformite = new QLabel(groupBox);
        label_conformite->setObjectName(QStringLiteral("label_conformite"));
        label_conformite->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_conformite->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(label_conformite, 6, 1, 1, 1);

        label_delai = new QLabel(groupBox);
        label_delai->setObjectName(QStringLiteral("label_delai"));
        label_delai->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_delai->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(label_delai, 7, 1, 1, 1);

        label_ventil2 = new QLabel(groupBox);
        label_ventil2->setObjectName(QStringLiteral("label_ventil2"));
        label_ventil2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_ventil2->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(label_ventil2, 4, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 2, 0, 1, 1);

        label_pretraitement = new QLabel(groupBox);
        label_pretraitement->setObjectName(QStringLiteral("label_pretraitement"));
        label_pretraitement->setAutoFillBackground(false);
        label_pretraitement->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_pretraitement->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(label_pretraitement, 1, 1, 1, 1);

        label_traitement = new QLabel(groupBox);
        label_traitement->setObjectName(QStringLiteral("label_traitement"));
        label_traitement->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_traitement->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(label_traitement, 2, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        label_ventil1 = new QLabel(groupBox);
        label_ventil1->setObjectName(QStringLiteral("label_ventil1"));
        label_ventil1->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_ventil1->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(label_ventil1, 3, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 4, 0, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 5, 0, 1, 1);

        label_liste = new QLabel(groupBox);
        label_liste->setObjectName(QStringLiteral("label_liste"));
        label_liste->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_liste->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(label_liste, 8, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 8, 0, 1, 1);

        label_no = new QLabel(groupBox);
        label_no->setObjectName(QStringLiteral("label_no"));
        label_no->setAutoFillBackground(false);
        label_no->setStyleSheet(QLatin1String("color:rgb(0, 255, 127);\n"
"background-color: rgb(0, 0, 0);\n"
"font: 75 12pt \"Fixedsys\";"));
        label_no->setFrameShadow(QFrame::Sunken);
        label_no->setAlignment(Qt::AlignCenter);
        label_no->setWordWrap(true);
        label_no->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_2->addWidget(label_no, 0, 1, 1, 1);


        gridLayout->addWidget(groupBox, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(CcpaSpancDossierViewDlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        gridLayout->addWidget(buttonBox, 9, 0, 1, 1);

        groupBox_4 = new QGroupBox(CcpaSpancDossierViewDlg);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_2 = new QVBoxLayout(groupBox_4);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_propriete = new QLabel(groupBox_4);
        label_propriete->setObjectName(QStringLiteral("label_propriete"));

        verticalLayout_2->addWidget(label_propriete);

        groupBox_2 = new QGroupBox(groupBox_4);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(480, 0));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_adresse = new QLabel(groupBox_2);
        label_adresse->setObjectName(QStringLiteral("label_adresse"));

        gridLayout_3->addWidget(label_adresse, 1, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_2);

        modifPropriete = new QPushButton(groupBox_4);
        modifPropriete->setObjectName(QStringLiteral("modifPropriete"));

        verticalLayout_2->addWidget(modifPropriete);


        gridLayout->addWidget(groupBox_4, 2, 0, 1, 1);

        groupBox_3 = new QGroupBox(CcpaSpancDossierViewDlg);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_proprietaire = new QLabel(groupBox_3);
        label_proprietaire->setObjectName(QStringLiteral("label_proprietaire"));

        verticalLayout->addWidget(label_proprietaire);

        groupBox_5 = new QGroupBox(groupBox_3);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        verticalLayout_3 = new QVBoxLayout(groupBox_5);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_adresseP = new QLabel(groupBox_5);
        label_adresseP->setObjectName(QStringLiteral("label_adresseP"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_adresseP->sizePolicy().hasHeightForWidth());
        label_adresseP->setSizePolicy(sizePolicy);
        label_adresseP->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(label_adresseP);


        verticalLayout->addWidget(groupBox_5);

        modifProprietaire = new QToolButton(groupBox_3);
        modifProprietaire->setObjectName(QStringLiteral("modifProprietaire"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(modifProprietaire->sizePolicy().hasHeightForWidth());
        modifProprietaire->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(modifProprietaire);

        copieAdresseProprieteProprietaire = new QToolButton(groupBox_3);
        copieAdresseProprieteProprietaire->setObjectName(QStringLiteral("copieAdresseProprieteProprietaire"));
        sizePolicy1.setHeightForWidth(copieAdresseProprieteProprietaire->sizePolicy().hasHeightForWidth());
        copieAdresseProprieteProprietaire->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(copieAdresseProprieteProprietaire);


        gridLayout->addWidget(groupBox_3, 4, 0, 1, 1);


        retranslateUi(CcpaSpancDossierViewDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), CcpaSpancDossierViewDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CcpaSpancDossierViewDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(CcpaSpancDossierViewDlg);
    } // setupUi

    void retranslateUi(QDialog *CcpaSpancDossierViewDlg)
    {
        CcpaSpancDossierViewDlg->setWindowTitle(QApplication::translate("CcpaSpancDossierViewDlg", "Vue de dossier", 0));
        groupBox->setTitle(QApplication::translate("CcpaSpancDossierViewDlg", "Donn\303\251es du contr\303\264le", 0));
        label_6->setText(QApplication::translate("CcpaSpancDossierViewDlg", "Conformit\303\251", 0));
        label_exutoire->setText(QString());
        label_7->setText(QApplication::translate("CcpaSpancDossierViewDlg", "D\303\251lai", 0));
        label_conformite->setText(QString());
        label_delai->setText(QString());
        label_ventil2->setText(QString());
        label->setText(QApplication::translate("CcpaSpancDossierViewDlg", "Traitement", 0));
        label_pretraitement->setText(QString());
        label_traitement->setText(QString());
        label_3->setText(QApplication::translate("CcpaSpancDossierViewDlg", "Ventilation primaire", 0));
        label_ventil1->setText(QString());
        label_4->setText(QApplication::translate("CcpaSpancDossierViewDlg", "Ventilation secondaire", 0));
        label_5->setText(QApplication::translate("CcpaSpancDossierViewDlg", "Exutoire", 0));
        label_liste->setText(QString());
        label_2->setText(QApplication::translate("CcpaSpancDossierViewDlg", "Pr\303\251traitement", 0));
        label_8->setText(QApplication::translate("CcpaSpancDossierViewDlg", "Liste", 0));
        label_no->setText(QString());
        groupBox_4->setTitle(QApplication::translate("CcpaSpancDossierViewDlg", "Propri\303\251t\303\251", 0));
        label_propriete->setText(QString());
        groupBox_2->setTitle(QApplication::translate("CcpaSpancDossierViewDlg", "Adresse", 0));
        label_adresse->setText(QString());
        modifPropriete->setText(QApplication::translate("CcpaSpancDossierViewDlg", "Modifier", 0));
        groupBox_3->setTitle(QApplication::translate("CcpaSpancDossierViewDlg", "Propri\303\251taire", 0));
        label_proprietaire->setText(QString());
        groupBox_5->setTitle(QApplication::translate("CcpaSpancDossierViewDlg", "Adresse", 0));
        label_adresseP->setText(QString());
        modifProprietaire->setText(QApplication::translate("CcpaSpancDossierViewDlg", "Modifier", 0));
        copieAdresseProprieteProprietaire->setText(QApplication::translate("CcpaSpancDossierViewDlg", "Copier l'adresse de la propri\303\251t\303\251 sur le propri\303\251taire", 0));
    } // retranslateUi

};

namespace Ui {
    class CcpaSpancDossierViewDlg: public Ui_CcpaSpancDossierViewDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCPASPANCDOSSIERVIEWDLG_H
