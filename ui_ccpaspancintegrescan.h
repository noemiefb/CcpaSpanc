/********************************************************************************
** Form generated from reading UI file 'ccpaspancintegrescan.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCPASPANCINTEGRESCAN_H
#define UI_CCPASPANCINTEGRESCAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CcpaSpancIntegreScan
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *edtCheminFichier;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QCheckBox *checkBox;
    QPushButton *btnParcourir;
    QRadioButton *radioCommande;
    QRadioButton *radioRapport;
    QRadioButton *radioLettre;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CcpaSpancIntegreScan)
    {
        if (CcpaSpancIntegreScan->objectName().isEmpty())
            CcpaSpancIntegreScan->setObjectName(QStringLiteral("CcpaSpancIntegreScan"));
        CcpaSpancIntegreScan->resize(368, 178);
        gridLayoutWidget = new QWidget(CcpaSpancIntegreScan);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 361, 172));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        edtCheminFichier = new QLineEdit(gridLayoutWidget);
        edtCheminFichier->setObjectName(QStringLiteral("edtCheminFichier"));

        gridLayout->addWidget(edtCheminFichier, 1, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit = new QLineEdit(gridLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        checkBox = new QCheckBox(gridLayoutWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 5, 1, 1, 1);

        btnParcourir = new QPushButton(gridLayoutWidget);
        btnParcourir->setObjectName(QStringLiteral("btnParcourir"));

        gridLayout->addWidget(btnParcourir, 1, 2, 1, 1);

        radioCommande = new QRadioButton(gridLayoutWidget);
        radioCommande->setObjectName(QStringLiteral("radioCommande"));
        radioCommande->setChecked(false);

        gridLayout->addWidget(radioCommande, 2, 1, 1, 1);

        radioRapport = new QRadioButton(gridLayoutWidget);
        radioRapport->setObjectName(QStringLiteral("radioRapport"));

        gridLayout->addWidget(radioRapport, 3, 1, 1, 1);

        radioLettre = new QRadioButton(gridLayoutWidget);
        radioLettre->setObjectName(QStringLiteral("radioLettre"));
        radioLettre->setChecked(true);

        gridLayout->addWidget(radioLettre, 4, 1, 1, 1);

        buttonBox = new QDialogButtonBox(gridLayoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 6, 1, 1, 1);


        retranslateUi(CcpaSpancIntegreScan);
        QObject::connect(buttonBox, SIGNAL(accepted()), CcpaSpancIntegreScan, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CcpaSpancIntegreScan, SLOT(reject()));

        QMetaObject::connectSlotsByName(CcpaSpancIntegreScan);
    } // setupUi

    void retranslateUi(QDialog *CcpaSpancIntegreScan)
    {
        CcpaSpancIntegreScan->setWindowTitle(QApplication::translate("CcpaSpancIntegreScan", "Int\303\251grer un fichier scann\303\251", 0));
        label->setText(QApplication::translate("CcpaSpancIntegreScan", "No", 0));
        label_3->setText(QApplication::translate("CcpaSpancIntegreScan", "Type", 0));
        label_2->setText(QApplication::translate("CcpaSpancIntegreScan", "Fichier", 0));
        checkBox->setText(QApplication::translate("CcpaSpancIntegreScan", "Effacer apr\303\250s copie", 0));
        btnParcourir->setText(QApplication::translate("CcpaSpancIntegreScan", "Parcourir", 0));
        radioCommande->setText(QApplication::translate("CcpaSpancIntegreScan", "Commande", 0));
        radioRapport->setText(QApplication::translate("CcpaSpancIntegreScan", "Rapport", 0));
        radioLettre->setText(QApplication::translate("CcpaSpancIntegreScan", "Lettre", 0));
    } // retranslateUi

};

namespace Ui {
    class CcpaSpancIntegreScan: public Ui_CcpaSpancIntegreScan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCPASPANCINTEGRESCAN_H
