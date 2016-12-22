/********************************************************************************
** Form generated from reading UI file 'ccpaspancdlgretour.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCPASPANCDLGRETOUR_H
#define UI_CCPASPANCDLGRETOUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CcpaSpancDlgRetour
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QPlainTextEdit *resultatEdit;
    QProgressBar *progressBar;
    QCheckBox *checkBox;
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton_3;

    void setupUi(QDialog *CcpaSpancDlgRetour)
    {
        if (CcpaSpancDlgRetour->objectName().isEmpty())
            CcpaSpancDlgRetour->setObjectName(QStringLiteral("CcpaSpancDlgRetour"));
        CcpaSpancDlgRetour->resize(812, 369);
        formLayoutWidget = new QWidget(CcpaSpancDlgRetour);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 0, 801, 361));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(formLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        pushButton = new QPushButton(formLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        formLayout->setWidget(1, QFormLayout::FieldRole, pushButton);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        lineEdit_2 = new QLineEdit(formLayoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_2);

        pushButton_2 = new QPushButton(formLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        formLayout->setWidget(3, QFormLayout::FieldRole, pushButton_2);

        resultatEdit = new QPlainTextEdit(formLayoutWidget);
        resultatEdit->setObjectName(QStringLiteral("resultatEdit"));

        formLayout->setWidget(7, QFormLayout::FieldRole, resultatEdit);

        progressBar = new QProgressBar(formLayoutWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setMaximum(0);
        progressBar->setValue(0);

        formLayout->setWidget(8, QFormLayout::FieldRole, progressBar);

        checkBox = new QCheckBox(formLayoutWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        formLayout->setWidget(5, QFormLayout::FieldRole, checkBox);

        buttonBox = new QDialogButtonBox(formLayoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(9, QFormLayout::FieldRole, buttonBox);

        pushButton_3 = new QPushButton(formLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        formLayout->setWidget(6, QFormLayout::FieldRole, pushButton_3);


        retranslateUi(CcpaSpancDlgRetour);
        QObject::connect(buttonBox, SIGNAL(accepted()), CcpaSpancDlgRetour, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CcpaSpancDlgRetour, SLOT(reject()));

        QMetaObject::connectSlotsByName(CcpaSpancDlgRetour);
    } // setupUi

    void retranslateUi(QDialog *CcpaSpancDlgRetour)
    {
        CcpaSpancDlgRetour->setWindowTitle(QApplication::translate("CcpaSpancDlgRetour", "Dialog", 0));
        label->setText(QApplication::translate("CcpaSpancDlgRetour", "Source", 0));
        lineEdit->setText(QApplication::translate("CcpaSpancDlgRetour", "P:/SPANC_A_TRIER", 0));
        pushButton->setText(QApplication::translate("CcpaSpancDlgRetour", "Choisir", 0));
        label_2->setText(QApplication::translate("CcpaSpancDlgRetour", "Destination", 0));
        lineEdit_2->setText(QApplication::translate("CcpaSpancDlgRetour", "W:", 0));
        pushButton_2->setText(QApplication::translate("CcpaSpancDlgRetour", "Choisir", 0));
        checkBox->setText(QApplication::translate("CcpaSpancDlgRetour", "Cr\303\251er le r\303\251pertoire s'il n'existe pas", 0));
        pushButton_3->setText(QApplication::translate("CcpaSpancDlgRetour", "Proc\303\251der", 0));
    } // retranslateUi

};

namespace Ui {
    class CcpaSpancDlgRetour: public Ui_CcpaSpancDlgRetour {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCPASPANCDLGRETOUR_H
