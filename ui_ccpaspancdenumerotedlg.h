/********************************************************************************
** Form generated from reading UI file 'ccpaspancdenumerotedlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCPASPANCDENUMEROTEDLG_H
#define UI_CCPASPANCDENUMEROTEDLG_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CcpaSpancDenumeroteDlg
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *numRoDeBordereauLabel;
    QLineEdit *noBordereau;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CcpaSpancDenumeroteDlg)
    {
        if (CcpaSpancDenumeroteDlg->objectName().isEmpty())
            CcpaSpancDenumeroteDlg->setObjectName(QStringLiteral("CcpaSpancDenumeroteDlg"));
        CcpaSpancDenumeroteDlg->resize(276, 64);
        verticalLayoutWidget = new QWidget(CcpaSpancDenumeroteDlg);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 271, 61));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        numRoDeBordereauLabel = new QLabel(verticalLayoutWidget);
        numRoDeBordereauLabel->setObjectName(QStringLiteral("numRoDeBordereauLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, numRoDeBordereauLabel);

        noBordereau = new QLineEdit(verticalLayoutWidget);
        noBordereau->setObjectName(QStringLiteral("noBordereau"));

        formLayout->setWidget(0, QFormLayout::FieldRole, noBordereau);

        buttonBox = new QDialogButtonBox(verticalLayoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(1, QFormLayout::FieldRole, buttonBox);


        verticalLayout->addLayout(formLayout);


        retranslateUi(CcpaSpancDenumeroteDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), CcpaSpancDenumeroteDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CcpaSpancDenumeroteDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(CcpaSpancDenumeroteDlg);
    } // setupUi

    void retranslateUi(QDialog *CcpaSpancDenumeroteDlg)
    {
        CcpaSpancDenumeroteDlg->setWindowTitle(QApplication::translate("CcpaSpancDenumeroteDlg", "D\303\251num\303\251rotation", 0));
        numRoDeBordereauLabel->setText(QApplication::translate("CcpaSpancDenumeroteDlg", "Num\303\251ro de bordereau", 0));
    } // retranslateUi

};

namespace Ui {
    class CcpaSpancDenumeroteDlg: public Ui_CcpaSpancDenumeroteDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCPASPANCDENUMEROTEDLG_H
