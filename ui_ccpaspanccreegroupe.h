/********************************************************************************
** Form generated from reading UI file 'ccpaspanccreegroupe.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCPASPANCCREEGROUPE_H
#define UI_CCPASPANCCREEGROUPE_H

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
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CcpaSpancCreeGroupe
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QTextEdit *textEdit;
    QLineEdit *dossierDe;
    QLabel *label;
    QLineEdit *dateFin;
    QLineEdit *nomCommune;
    QLabel *label_4;
    QLineEdit *dateDebut;
    QLabel *label_5;
    QLabel *label_2;
    QLineEdit *dossierA;
    QLabel *label_3;
    QProgressBar *progressBar;

    void setupUi(QDialog *CcpaSpancCreeGroupe)
    {
        if (CcpaSpancCreeGroupe->objectName().isEmpty())
            CcpaSpancCreeGroupe->setObjectName(QStringLiteral("CcpaSpancCreeGroupe"));
        CcpaSpancCreeGroupe->resize(413, 231);
        gridLayoutWidget = new QWidget(CcpaSpancCreeGroupe);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 10, 384, 207));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        buttonBox = new QDialogButtonBox(gridLayoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 5, 1, 1, 1);

        textEdit = new QTextEdit(gridLayoutWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 3, 1, 1, 1);

        dossierDe = new QLineEdit(gridLayoutWidget);
        dossierDe->setObjectName(QStringLiteral("dossierDe"));

        gridLayout->addWidget(dossierDe, 0, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        dateFin = new QLineEdit(gridLayoutWidget);
        dateFin->setObjectName(QStringLiteral("dateFin"));

        gridLayout->addWidget(dateFin, 2, 3, 1, 1);

        nomCommune = new QLineEdit(gridLayoutWidget);
        nomCommune->setObjectName(QStringLiteral("nomCommune"));

        gridLayout->addWidget(nomCommune, 1, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        dateDebut = new QLineEdit(gridLayoutWidget);
        dateDebut->setObjectName(QStringLiteral("dateDebut"));

        gridLayout->addWidget(dateDebut, 2, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 2, 2, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        dossierA = new QLineEdit(gridLayoutWidget);
        dossierA->setObjectName(QStringLiteral("dossierA"));

        gridLayout->addWidget(dossierA, 0, 3, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        progressBar = new QProgressBar(gridLayoutWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        gridLayout->addWidget(progressBar, 4, 1, 1, 1);

        QWidget::setTabOrder(dossierDe, dossierA);
        QWidget::setTabOrder(dossierA, nomCommune);
        QWidget::setTabOrder(nomCommune, dateDebut);
        QWidget::setTabOrder(dateDebut, dateFin);
        QWidget::setTabOrder(dateFin, textEdit);

        retranslateUi(CcpaSpancCreeGroupe);
        QObject::connect(buttonBox, SIGNAL(accepted()), CcpaSpancCreeGroupe, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CcpaSpancCreeGroupe, SLOT(reject()));

        QMetaObject::connectSlotsByName(CcpaSpancCreeGroupe);
    } // setupUi

    void retranslateUi(QDialog *CcpaSpancCreeGroupe)
    {
        CcpaSpancCreeGroupe->setWindowTitle(QApplication::translate("CcpaSpancCreeGroupe", "Dialog", 0));
        label->setText(QApplication::translate("CcpaSpancCreeGroupe", "Dossiers", 0));
        label_4->setText(QApplication::translate("CcpaSpancCreeGroupe", "Date de", 0));
        label_5->setText(QApplication::translate("CcpaSpancCreeGroupe", "\303\240", 0));
        label_2->setText(QApplication::translate("CcpaSpancCreeGroupe", "\303\240", 0));
        label_3->setText(QApplication::translate("CcpaSpancCreeGroupe", "Commune", 0));
    } // retranslateUi

};

namespace Ui {
    class CcpaSpancCreeGroupe: public Ui_CcpaSpancCreeGroupe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCPASPANCCREEGROUPE_H
