/********************************************************************************
** Form generated from reading UI file 'ccpaspancestproprietairedlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCPASPANCESTPROPRIETAIREDLG_H
#define UI_CCPASPANCESTPROPRIETAIREDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "ccpaspanccombo.h"

QT_BEGIN_NAMESPACE

class Ui_CcpaSpancEstProprietaireDlg
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    CcpaSpancCombo *proprietaire;
    QLabel *label_2;
    QDateEdit *dateEdit;
    QDateEdit *dateEdit_2;
    QLabel *label_5;
    QLabel *label;
    QDialogButtonBox *buttonBox;
    QLabel *label_6;
    CcpaSpancCombo *propriete;

    void setupUi(QDialog *CcpaSpancEstProprietaireDlg)
    {
        if (CcpaSpancEstProprietaireDlg->objectName().isEmpty())
            CcpaSpancEstProprietaireDlg->setObjectName(QStringLiteral("CcpaSpancEstProprietaireDlg"));
        CcpaSpancEstProprietaireDlg->resize(539, 300);
        gridLayoutWidget = new QWidget(CcpaSpancEstProprietaireDlg);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(50, 0, 471, 241));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        proprietaire = new CcpaSpancCombo(gridLayoutWidget);
        proprietaire->setObjectName(QStringLiteral("proprietaire"));

        gridLayout->addWidget(proprietaire, 0, 2, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        dateEdit = new QDateEdit(gridLayoutWidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setDateTime(QDateTime(QDate(1900, 1, 1), QTime(0, 0, 0)));

        gridLayout->addWidget(dateEdit, 3, 2, 1, 1);

        dateEdit_2 = new QDateEdit(gridLayoutWidget);
        dateEdit_2->setObjectName(QStringLiteral("dateEdit_2"));
        dateEdit_2->setDateTime(QDateTime(QDate(2100, 1, 1), QTime(0, 0, 0)));

        gridLayout->addWidget(dateEdit_2, 4, 2, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(gridLayoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 5, 2, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        propriete = new CcpaSpancCombo(gridLayoutWidget);
        propriete->setObjectName(QStringLiteral("propriete"));

        gridLayout->addWidget(propriete, 1, 2, 1, 1);


        retranslateUi(CcpaSpancEstProprietaireDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), CcpaSpancEstProprietaireDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CcpaSpancEstProprietaireDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(CcpaSpancEstProprietaireDlg);
    } // setupUi

    void retranslateUi(QDialog *CcpaSpancEstProprietaireDlg)
    {
        CcpaSpancEstProprietaireDlg->setWindowTitle(QApplication::translate("CcpaSpancEstProprietaireDlg", "Dialog", 0));
        label_2->setText(QApplication::translate("CcpaSpancEstProprietaireDlg", "Adresse du bien", 0));
        label_5->setText(QApplication::translate("CcpaSpancEstProprietaireDlg", "Date de fin", 0));
        label->setText(QApplication::translate("CcpaSpancEstProprietaireDlg", "Propri\303\251taire", 0));
        label_6->setText(QApplication::translate("CcpaSpancEstProprietaireDlg", "Date de d\303\251but", 0));
    } // retranslateUi

};

namespace Ui {
    class CcpaSpancEstProprietaireDlg: public Ui_CcpaSpancEstProprietaireDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCPASPANCESTPROPRIETAIREDLG_H
