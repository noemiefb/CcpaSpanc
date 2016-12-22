/********************************************************************************
** Form generated from reading UI file 'ccpaspanccopierapportlettre.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCPASPANCCOPIERAPPORTLETTRE_H
#define UI_CCPASPANCCOPIERAPPORTLETTRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ccpaSpancCopieRapportLettre
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *btnOk;
    QLineEdit *editNo;
    QPushButton *btnSuppr;
    QListWidget *listWidget;

    void setupUi(QDialog *ccpaSpancCopieRapportLettre)
    {
        if (ccpaSpancCopieRapportLettre->objectName().isEmpty())
            ccpaSpancCopieRapportLettre->setObjectName(QStringLiteral("ccpaSpancCopieRapportLettre"));
        ccpaSpancCopieRapportLettre->resize(204, 143);
        buttonBox = new QDialogButtonBox(ccpaSpancCopieRapportLettre);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(20, 110, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        gridLayoutWidget = new QWidget(ccpaSpancCopieRapportLettre);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 201, 104));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        btnOk = new QPushButton(gridLayoutWidget);
        btnOk->setObjectName(QStringLiteral("btnOk"));

        gridLayout->addWidget(btnOk, 0, 2, 1, 1);

        editNo = new QLineEdit(gridLayoutWidget);
        editNo->setObjectName(QStringLiteral("editNo"));

        gridLayout->addWidget(editNo, 0, 1, 1, 1);

        btnSuppr = new QPushButton(gridLayoutWidget);
        btnSuppr->setObjectName(QStringLiteral("btnSuppr"));
        btnSuppr->setEnabled(false);

        gridLayout->addWidget(btnSuppr, 1, 2, 1, 1);

        listWidget = new QListWidget(gridLayoutWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout->addWidget(listWidget, 1, 1, 1, 1);


        retranslateUi(ccpaSpancCopieRapportLettre);
        QObject::connect(buttonBox, SIGNAL(accepted()), ccpaSpancCopieRapportLettre, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ccpaSpancCopieRapportLettre, SLOT(reject()));

        QMetaObject::connectSlotsByName(ccpaSpancCopieRapportLettre);
    } // setupUi

    void retranslateUi(QDialog *ccpaSpancCopieRapportLettre)
    {
        ccpaSpancCopieRapportLettre->setWindowTitle(QApplication::translate("ccpaSpancCopieRapportLettre", "Dialog", 0));
        label->setText(QApplication::translate("ccpaSpancCopieRapportLettre", "Num\303\251ro", 0));
        btnOk->setText(QApplication::translate("ccpaSpancCopieRapportLettre", "Ajouter", 0));
        btnSuppr->setText(QApplication::translate("ccpaSpancCopieRapportLettre", "Supprimer", 0));
    } // retranslateUi

};

namespace Ui {
    class ccpaSpancCopieRapportLettre: public Ui_ccpaSpancCopieRapportLettre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCPASPANCCOPIERAPPORTLETTRE_H
