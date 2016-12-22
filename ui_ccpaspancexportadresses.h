/********************************************************************************
** Form generated from reading UI file 'ccpaspancexportadresses.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCPASPANCEXPORTADRESSES_H
#define UI_CCPASPANCEXPORTADRESSES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_CcpaSpancExportAdresses
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CcpaSpancExportAdresses)
    {
        if (CcpaSpancExportAdresses->objectName().isEmpty())
            CcpaSpancExportAdresses->setObjectName(QStringLiteral("CcpaSpancExportAdresses"));
        CcpaSpancExportAdresses->resize(400, 300);
        buttonBox = new QDialogButtonBox(CcpaSpancExportAdresses);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(CcpaSpancExportAdresses);
        QObject::connect(buttonBox, SIGNAL(accepted()), CcpaSpancExportAdresses, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CcpaSpancExportAdresses, SLOT(reject()));

        QMetaObject::connectSlotsByName(CcpaSpancExportAdresses);
    } // setupUi

    void retranslateUi(QDialog *CcpaSpancExportAdresses)
    {
        CcpaSpancExportAdresses->setWindowTitle(QApplication::translate("CcpaSpancExportAdresses", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class CcpaSpancExportAdresses: public Ui_CcpaSpancExportAdresses {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCPASPANCEXPORTADRESSES_H
