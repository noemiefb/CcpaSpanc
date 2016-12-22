/********************************************************************************
** Form generated from reading UI file 'ccpaspancutils.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCPASPANCUTILS_H
#define UI_CCPASPANCUTILS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CcpaSpancUtils
{
public:
    QAction *actionRenommer_des_fichiers_de_retour_du_prestataire;
    QAction *actionRenommer_des_fichiers_de_retour_du_scanner;
    QAction *actionEnvoyer_des_fichiers_pour_la_facturation;
    QAction *actionQuitter;
    QAction *actionEnvoi_r_gularisation_de_commande;
    QAction *actionMair;
    QAction *actionBase_de_donn_es;
    QAction *actionContacts;
    QAction *actionAdresses;
    QAction *actionDossiers;
    QAction *actionQuitter_2;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_6;
    QPushButton *btnIntegreCommande;
    QPushButton *btnIntegreRapport;
    QToolButton *btnReserveGroupe;
    QPushButton *btnCopieRapportLettre;
    QGroupBox *groupBox1;
    QVBoxLayout *verticalLayout;
    QPushButton *btnEnvoiMail;
    QPushButton *btnIntegreScan;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton;
    QToolButton *rechercheBouton;
    QPushButton *pushButton_10;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_5;
    QToolButton *toolButton_2;
    QPushButton *pushButton_6;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_8;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QDialogButtonBox *buttonBox;
    QMenuBar *menuBar;
    QMenu *menuEnregistrer_fichier;
    QMenu *menuParam_tres;
    QMenu *menuDonn_es;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CcpaSpancUtils)
    {
        if (CcpaSpancUtils->objectName().isEmpty())
            CcpaSpancUtils->setObjectName(QStringLiteral("CcpaSpancUtils"));
        CcpaSpancUtils->resize(480, 604);
        CcpaSpancUtils->setStyleSheet(QStringLiteral(""));
        actionRenommer_des_fichiers_de_retour_du_prestataire = new QAction(CcpaSpancUtils);
        actionRenommer_des_fichiers_de_retour_du_prestataire->setObjectName(QStringLiteral("actionRenommer_des_fichiers_de_retour_du_prestataire"));
        actionRenommer_des_fichiers_de_retour_du_scanner = new QAction(CcpaSpancUtils);
        actionRenommer_des_fichiers_de_retour_du_scanner->setObjectName(QStringLiteral("actionRenommer_des_fichiers_de_retour_du_scanner"));
        actionEnvoyer_des_fichiers_pour_la_facturation = new QAction(CcpaSpancUtils);
        actionEnvoyer_des_fichiers_pour_la_facturation->setObjectName(QStringLiteral("actionEnvoyer_des_fichiers_pour_la_facturation"));
        actionQuitter = new QAction(CcpaSpancUtils);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionEnvoi_r_gularisation_de_commande = new QAction(CcpaSpancUtils);
        actionEnvoi_r_gularisation_de_commande->setObjectName(QStringLiteral("actionEnvoi_r_gularisation_de_commande"));
        actionMair = new QAction(CcpaSpancUtils);
        actionMair->setObjectName(QStringLiteral("actionMair"));
        actionBase_de_donn_es = new QAction(CcpaSpancUtils);
        actionBase_de_donn_es->setObjectName(QStringLiteral("actionBase_de_donn_es"));
        actionContacts = new QAction(CcpaSpancUtils);
        actionContacts->setObjectName(QStringLiteral("actionContacts"));
        actionAdresses = new QAction(CcpaSpancUtils);
        actionAdresses->setObjectName(QStringLiteral("actionAdresses"));
        actionDossiers = new QAction(CcpaSpancUtils);
        actionDossiers->setObjectName(QStringLiteral("actionDossiers"));
        actionQuitter_2 = new QAction(CcpaSpancUtils);
        actionQuitter_2->setObjectName(QStringLiteral("actionQuitter_2"));
        centralWidget = new QWidget(CcpaSpancUtils);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_6 = new QVBoxLayout(groupBox);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        btnIntegreCommande = new QPushButton(groupBox);
        btnIntegreCommande->setObjectName(QStringLiteral("btnIntegreCommande"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnIntegreCommande->sizePolicy().hasHeightForWidth());
        btnIntegreCommande->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(btnIntegreCommande);

        btnIntegreRapport = new QPushButton(groupBox);
        btnIntegreRapport->setObjectName(QStringLiteral("btnIntegreRapport"));
        sizePolicy.setHeightForWidth(btnIntegreRapport->sizePolicy().hasHeightForWidth());
        btnIntegreRapport->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(btnIntegreRapport);

        btnReserveGroupe = new QToolButton(groupBox);
        btnReserveGroupe->setObjectName(QStringLiteral("btnReserveGroupe"));
        sizePolicy.setHeightForWidth(btnReserveGroupe->sizePolicy().hasHeightForWidth());
        btnReserveGroupe->setSizePolicy(sizePolicy);
        btnReserveGroupe->setAutoFillBackground(false);
        btnReserveGroupe->setStyleSheet(QStringLiteral("background-color: aliceblue;"));

        verticalLayout_6->addWidget(btnReserveGroupe);

        btnCopieRapportLettre = new QPushButton(groupBox);
        btnCopieRapportLettre->setObjectName(QStringLiteral("btnCopieRapportLettre"));
        sizePolicy.setHeightForWidth(btnCopieRapportLettre->sizePolicy().hasHeightForWidth());
        btnCopieRapportLettre->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(btnCopieRapportLettre);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox1 = new QGroupBox(centralWidget);
        groupBox1->setObjectName(QStringLiteral("groupBox1"));
        verticalLayout = new QVBoxLayout(groupBox1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        btnEnvoiMail = new QPushButton(groupBox1);
        btnEnvoiMail->setObjectName(QStringLiteral("btnEnvoiMail"));
        sizePolicy.setHeightForWidth(btnEnvoiMail->sizePolicy().hasHeightForWidth());
        btnEnvoiMail->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(btnEnvoiMail);

        btnIntegreScan = new QPushButton(groupBox1);
        btnIntegreScan->setObjectName(QStringLiteral("btnIntegreScan"));
        sizePolicy.setHeightForWidth(btnIntegreScan->sizePolicy().hasHeightForWidth());
        btnIntegreScan->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(btnIntegreScan);


        gridLayout->addWidget(groupBox1, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setStyleSheet(QStringLiteral("background-color:green"));

        verticalLayout_4->addWidget(pushButton);

        rechercheBouton = new QToolButton(groupBox_2);
        rechercheBouton->setObjectName(QStringLiteral("rechercheBouton"));
        sizePolicy.setHeightForWidth(rechercheBouton->sizePolicy().hasHeightForWidth());
        rechercheBouton->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(rechercheBouton);

        pushButton_10 = new QPushButton(groupBox_2);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        sizePolicy.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy);
        pushButton_10->setStyleSheet(QLatin1String("\n"
"background-color:rgb(255, 0, 0);"));

        verticalLayout_4->addWidget(pushButton_10);


        gridLayout->addWidget(groupBox_2, 0, 1, 1, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_5 = new QVBoxLayout(groupBox_3);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        toolButton_2 = new QToolButton(groupBox_3);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        sizePolicy.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy);

        verticalLayout_5->addWidget(toolButton_2);

        pushButton_6 = new QPushButton(groupBox_3);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);

        verticalLayout_5->addWidget(pushButton_6);


        gridLayout->addWidget(groupBox_3, 0, 2, 1, 1);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        pushButton_2 = new QPushButton(groupBox_4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(groupBox_4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(pushButton_4);

        pushButton_8 = new QPushButton(groupBox_4);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(pushButton_8);

        pushButton_3 = new QPushButton(groupBox_4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(pushButton_3);

        pushButton_5 = new QPushButton(groupBox_4);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(pushButton_5);


        gridLayout->addWidget(groupBox_4, 1, 1, 1, 1);

        buttonBox = new QDialogButtonBox(centralWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 2, 1, 1);

        CcpaSpancUtils->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CcpaSpancUtils);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 480, 21));
        menuEnregistrer_fichier = new QMenu(menuBar);
        menuEnregistrer_fichier->setObjectName(QStringLiteral("menuEnregistrer_fichier"));
        menuParam_tres = new QMenu(menuBar);
        menuParam_tres->setObjectName(QStringLiteral("menuParam_tres"));
        menuDonn_es = new QMenu(menuBar);
        menuDonn_es->setObjectName(QStringLiteral("menuDonn_es"));
        CcpaSpancUtils->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CcpaSpancUtils);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CcpaSpancUtils->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CcpaSpancUtils);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CcpaSpancUtils->setStatusBar(statusBar);

        menuBar->addAction(menuEnregistrer_fichier->menuAction());
        menuBar->addAction(menuParam_tres->menuAction());
        menuBar->addAction(menuDonn_es->menuAction());
        menuEnregistrer_fichier->addAction(actionRenommer_des_fichiers_de_retour_du_prestataire);
        menuEnregistrer_fichier->addAction(actionRenommer_des_fichiers_de_retour_du_scanner);
        menuEnregistrer_fichier->addAction(actionEnvoyer_des_fichiers_pour_la_facturation);
        menuEnregistrer_fichier->addSeparator();
        menuEnregistrer_fichier->addAction(actionQuitter);
        menuEnregistrer_fichier->addAction(actionEnvoi_r_gularisation_de_commande);
        menuEnregistrer_fichier->addAction(actionQuitter_2);
        menuParam_tres->addAction(actionMair);
        menuParam_tres->addAction(actionBase_de_donn_es);
        menuDonn_es->addAction(actionContacts);
        menuDonn_es->addAction(actionAdresses);
        menuDonn_es->addAction(actionDossiers);

        retranslateUi(CcpaSpancUtils);

        QMetaObject::connectSlotsByName(CcpaSpancUtils);
    } // setupUi

    void retranslateUi(QMainWindow *CcpaSpancUtils)
    {
        CcpaSpancUtils->setWindowTitle(QApplication::translate("CcpaSpancUtils", "CcpaSpancUtils", 0));
        actionRenommer_des_fichiers_de_retour_du_prestataire->setText(QApplication::translate("CcpaSpancUtils", "&Renommer des fichiers de retour du prestataire", 0));
        actionRenommer_des_fichiers_de_retour_du_scanner->setText(QApplication::translate("CcpaSpancUtils", "Renommer &des fichiers de retour du scanner", 0));
        actionEnvoyer_des_fichiers_pour_la_facturation->setText(QApplication::translate("CcpaSpancUtils", "&Envoyer des fichiers pour la facturation", 0));
        actionQuitter->setText(QApplication::translate("CcpaSpancUtils", "&Quitter", 0));
        actionEnvoi_r_gularisation_de_commande->setText(QApplication::translate("CcpaSpancUtils", "Envoi r\303\251gularisation de &commande", 0));
        actionMair->setText(QApplication::translate("CcpaSpancUtils", "&Mail", 0));
        actionBase_de_donn_es->setText(QApplication::translate("CcpaSpancUtils", "&Base de donn\303\251es", 0));
        actionContacts->setText(QApplication::translate("CcpaSpancUtils", "&Contacts", 0));
        actionAdresses->setText(QApplication::translate("CcpaSpancUtils", "&Adresses", 0));
        actionDossiers->setText(QApplication::translate("CcpaSpancUtils", "&Dossiers", 0));
        actionQuitter_2->setText(QApplication::translate("CcpaSpancUtils", "Quitter", 0));
        groupBox->setTitle(QApplication::translate("CcpaSpancUtils", "JDBE", 0));
        btnIntegreCommande->setText(QApplication::translate("CcpaSpancUtils", "Int\303\251grer un bon de commande", 0));
        btnIntegreRapport->setText(QApplication::translate("CcpaSpancUtils", "Int\303\251grer les rapports de JDBE", 0));
        btnReserveGroupe->setText(QApplication::translate("CcpaSpancUtils", "R\303\251server un groupe", 0));
        btnCopieRapportLettre->setText(QApplication::translate("CcpaSpancUtils", "Copier les rapports pour la CCPA", 0));
        btnEnvoiMail->setText(QApplication::translate("CcpaSpancUtils", "Envoyer Mail", 0));
        btnIntegreScan->setText(QApplication::translate("CcpaSpancUtils", "Int\303\251grer un fichier scann\303\251", 0));
        groupBox_2->setTitle(QApplication::translate("CcpaSpancUtils", "Dossiers", 0));
        pushButton->setText(QApplication::translate("CcpaSpancUtils", "Dossiers", 0));
        rechercheBouton->setText(QApplication::translate("CcpaSpancUtils", "Recherche", 0));
        pushButton_10->setText(QApplication::translate("CcpaSpancUtils", "Effacer dossier", 0));
        groupBox_3->setTitle(QApplication::translate("CcpaSpancUtils", "Factures", 0));
        toolButton_2->setText(QApplication::translate("CcpaSpancUtils", "FACTURES", 0));
        pushButton_6->setText(QApplication::translate("CcpaSpancUtils", "D\303\251num\303\251rotation", 0));
        groupBox_4->setTitle(QApplication::translate("CcpaSpancUtils", "Fiches", 0));
        pushButton_2->setText(QApplication::translate("CcpaSpancUtils", "Contact", 0));
        pushButton_4->setText(QApplication::translate("CcpaSpancUtils", "Adresse", 0));
        pushButton_8->setText(QApplication::translate("CcpaSpancUtils", "Soci\303\251t\303\251", 0));
        pushButton_3->setText(QApplication::translate("CcpaSpancUtils", "Propriete", 0));
        pushButton_5->setText(QApplication::translate("CcpaSpancUtils", "Est Propri\303\251taire", 0));
        menuEnregistrer_fichier->setTitle(QApplication::translate("CcpaSpancUtils", "En&registrer fichier", 0));
        menuParam_tres->setTitle(QApplication::translate("CcpaSpancUtils", "Para&m\303\250tres", 0));
        menuDonn_es->setTitle(QApplication::translate("CcpaSpancUtils", "Donn\303\251es", 0));
    } // retranslateUi

};

namespace Ui {
    class CcpaSpancUtils: public Ui_CcpaSpancUtils {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCPASPANCUTILS_H
