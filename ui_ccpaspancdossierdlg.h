/********************************************************************************
** Form generated from reading UI file 'ccpaspancdossierdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCPASPANCDOSSIERDLG_H
#define UI_CCPASPANCDOSSIERDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
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
#include <QtWidgets/QTextEdit>
#include "ccpaspanccombo.h"

QT_BEGIN_NAMESPACE

class Ui_CcpaSpancDossierDlg
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *dossierLabel;
    QLineEdit *dossier;
    QLabel *dateDeContrLeLabel;
    QDateEdit *date;
    QLabel *contrLeLabel;
    CcpaSpancCombo *controle;
    QLabel *civilitLabel;
    QComboBox *civilite;
    QLabel *nomLabel;
    QLineEdit *nom;
    QLabel *prNomLabel;
    QLineEdit *prenom;
    QLabel *proprietaireLu;
    QLabel *label_2;
    QLabel *adresseLue;
    QLabel *adresseDuPropriTaireDiffRenteLabel;
    QCheckBox *adresseDiff;
    QLabel *norueL;
    QLineEdit *norue;
    QLabel *typerueL;
    QLineEdit *typerue;
    QLabel *nomDeLaRueLabel;
    QLineEdit *nomrue;
    QLabel *adresse2Label;
    QLineEdit *adresse2;
    QLabel *adresse3Label;
    QLineEdit *adresse3;
    QLabel *villeLabel;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *noCommune;
    CcpaSpancCombo *ville;
    QLabel *codePostalLabel;
    QLineEdit *cp;
    QLabel *cedexLabel;
    QLineEdit *cedex;
    QLabel *adresseLue2;
    QLabel *label;
    QLabel *norueL_5;
    QLineEdit *norue_p;
    QLabel *typerueL_4;
    QLineEdit *typerue_p;
    QLabel *nomDeLaRueLabel_4;
    QLineEdit *nomrue_p;
    QLabel *adresse2Label_4;
    QLineEdit *adresse2_p;
    QLabel *adresse3Label_4;
    QLineEdit *adresse3_p;
    QLabel *villeLabel_4;
    QLineEdit *ville_p;
    QLabel *codePostalLabel_4;
    QLineEdit *cp_p;
    QLabel *cedexLabel_4;
    QLineEdit *cedex_p;
    QLabel *paysLabel_4;
    CcpaSpancCombo *pays_p;
    QFormLayout *formLayout_3;
    QLabel *sectionLabel;
    QLineEdit *section;
    QLabel *prefixeL;
    QLineEdit *prefixe;
    QLabel *parcelleLabel;
    QLineEdit *parcelle;
    QLabel *nombreDePiCesPrincipalesLabel;
    QLineEdit *nbPP;
    QLabel *annEDeConstructionLabel;
    QLineEdit *annee;
    QLabel *prTraitementLabel;
    CcpaSpancCombo *prTraitementComboBox;
    QLabel *traitementLabel;
    CcpaSpancCombo *traitement;
    QLabel *agrMentLabel;
    QLineEdit *agrement;
    QLabel *ventilationPrimaireLabel;
    QCheckBox *vp;
    QLabel *ventilationSecondaireLabel;
    QCheckBox *vs;
    QLabel *conformeLabel;
    QCheckBox *conformeCheckBox;
    QLabel *dLaiLabel;
    QComboBox *delai;
    QLabel *urgenceLabel;
    QCheckBox *urgenceCheckBox;
    QLabel *exutoireLabel;
    CcpaSpancCombo *exutoire;
    QLabel *exutoireLabel_2;
    QLabel *installationLabel;
    QLabel *facturation;
    QPushButton *effaceBouton;
    QPushButton *pushButton;
    QDialogButtonBox *buttonBox;
    QTextEdit *texteFichier;
    QGridLayout *gridLayout;
    QLineEdit *liste;
    QLabel *label_3;
    QLabel *delai_label;
    QHBoxLayout *horizontalLayout_3;
    QLabel *infoNoAdressePropriete;
    QLabel *infoNoProprietaire;
    QLabel *infoNoPropriete;
    QLabel *infoNoAdresseProprietaire;

    void setupUi(QDialog *CcpaSpancDossierDlg)
    {
        if (CcpaSpancDossierDlg->objectName().isEmpty())
            CcpaSpancDossierDlg->setObjectName(QStringLiteral("CcpaSpancDossierDlg"));
        CcpaSpancDossierDlg->resize(1020, 800);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CcpaSpancDossierDlg->sizePolicy().hasHeightForWidth());
        CcpaSpancDossierDlg->setSizePolicy(sizePolicy);
        CcpaSpancDossierDlg->setMaximumSize(QSize(1900, 800));
        QIcon icon;
        icon.addFile(QStringLiteral("../Pictures/SVG/trousse-secours.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        CcpaSpancDossierDlg->setWindowIcon(icon);
        CcpaSpancDossierDlg->setSizeGripEnabled(true);
        gridLayout_2 = new QGridLayout(CcpaSpancDossierDlg);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetNoConstraint);
        formLayout->setHorizontalSpacing(0);
        formLayout->setVerticalSpacing(0);
        dossierLabel = new QLabel(CcpaSpancDossierDlg);
        dossierLabel->setObjectName(QStringLiteral("dossierLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, dossierLabel);

        dossier = new QLineEdit(CcpaSpancDossierDlg);
        dossier->setObjectName(QStringLiteral("dossier"));

        formLayout->setWidget(0, QFormLayout::FieldRole, dossier);

        dateDeContrLeLabel = new QLabel(CcpaSpancDossierDlg);
        dateDeContrLeLabel->setObjectName(QStringLiteral("dateDeContrLeLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, dateDeContrLeLabel);

        date = new QDateEdit(CcpaSpancDossierDlg);
        date->setObjectName(QStringLiteral("date"));
        date->setCalendarPopup(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, date);

        contrLeLabel = new QLabel(CcpaSpancDossierDlg);
        contrLeLabel->setObjectName(QStringLiteral("contrLeLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, contrLeLabel);

        controle = new CcpaSpancCombo(CcpaSpancDossierDlg);
        controle->setObjectName(QStringLiteral("controle"));

        formLayout->setWidget(2, QFormLayout::FieldRole, controle);

        civilitLabel = new QLabel(CcpaSpancDossierDlg);
        civilitLabel->setObjectName(QStringLiteral("civilitLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, civilitLabel);

        civilite = new QComboBox(CcpaSpancDossierDlg);
        civilite->setObjectName(QStringLiteral("civilite"));

        formLayout->setWidget(3, QFormLayout::FieldRole, civilite);

        nomLabel = new QLabel(CcpaSpancDossierDlg);
        nomLabel->setObjectName(QStringLiteral("nomLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, nomLabel);

        nom = new QLineEdit(CcpaSpancDossierDlg);
        nom->setObjectName(QStringLiteral("nom"));

        formLayout->setWidget(4, QFormLayout::FieldRole, nom);

        prNomLabel = new QLabel(CcpaSpancDossierDlg);
        prNomLabel->setObjectName(QStringLiteral("prNomLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, prNomLabel);

        prenom = new QLineEdit(CcpaSpancDossierDlg);
        prenom->setObjectName(QStringLiteral("prenom"));

        formLayout->setWidget(5, QFormLayout::FieldRole, prenom);

        proprietaireLu = new QLabel(CcpaSpancDossierDlg);
        proprietaireLu->setObjectName(QStringLiteral("proprietaireLu"));

        formLayout->setWidget(6, QFormLayout::FieldRole, proprietaireLu);

        label_2 = new QLabel(CcpaSpancDossierDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);

        formLayout->setWidget(9, QFormLayout::LabelRole, label_2);

        adresseLue = new QLabel(CcpaSpancDossierDlg);
        adresseLue->setObjectName(QStringLiteral("adresseLue"));
        adresseLue->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(9, QFormLayout::FieldRole, adresseLue);

        adresseDuPropriTaireDiffRenteLabel = new QLabel(CcpaSpancDossierDlg);
        adresseDuPropriTaireDiffRenteLabel->setObjectName(QStringLiteral("adresseDuPropriTaireDiffRenteLabel"));

        formLayout->setWidget(10, QFormLayout::LabelRole, adresseDuPropriTaireDiffRenteLabel);

        adresseDiff = new QCheckBox(CcpaSpancDossierDlg);
        adresseDiff->setObjectName(QStringLiteral("adresseDiff"));

        formLayout->setWidget(10, QFormLayout::FieldRole, adresseDiff);

        norueL = new QLabel(CcpaSpancDossierDlg);
        norueL->setObjectName(QStringLiteral("norueL"));

        formLayout->setWidget(11, QFormLayout::LabelRole, norueL);

        norue = new QLineEdit(CcpaSpancDossierDlg);
        norue->setObjectName(QStringLiteral("norue"));

        formLayout->setWidget(11, QFormLayout::FieldRole, norue);

        typerueL = new QLabel(CcpaSpancDossierDlg);
        typerueL->setObjectName(QStringLiteral("typerueL"));

        formLayout->setWidget(12, QFormLayout::LabelRole, typerueL);

        typerue = new QLineEdit(CcpaSpancDossierDlg);
        typerue->setObjectName(QStringLiteral("typerue"));

        formLayout->setWidget(12, QFormLayout::FieldRole, typerue);

        nomDeLaRueLabel = new QLabel(CcpaSpancDossierDlg);
        nomDeLaRueLabel->setObjectName(QStringLiteral("nomDeLaRueLabel"));

        formLayout->setWidget(13, QFormLayout::LabelRole, nomDeLaRueLabel);

        nomrue = new QLineEdit(CcpaSpancDossierDlg);
        nomrue->setObjectName(QStringLiteral("nomrue"));

        formLayout->setWidget(13, QFormLayout::FieldRole, nomrue);

        adresse2Label = new QLabel(CcpaSpancDossierDlg);
        adresse2Label->setObjectName(QStringLiteral("adresse2Label"));

        formLayout->setWidget(14, QFormLayout::LabelRole, adresse2Label);

        adresse2 = new QLineEdit(CcpaSpancDossierDlg);
        adresse2->setObjectName(QStringLiteral("adresse2"));

        formLayout->setWidget(14, QFormLayout::FieldRole, adresse2);

        adresse3Label = new QLabel(CcpaSpancDossierDlg);
        adresse3Label->setObjectName(QStringLiteral("adresse3Label"));

        formLayout->setWidget(15, QFormLayout::LabelRole, adresse3Label);

        adresse3 = new QLineEdit(CcpaSpancDossierDlg);
        adresse3->setObjectName(QStringLiteral("adresse3"));

        formLayout->setWidget(15, QFormLayout::FieldRole, adresse3);

        villeLabel = new QLabel(CcpaSpancDossierDlg);
        villeLabel->setObjectName(QStringLiteral("villeLabel"));

        formLayout->setWidget(16, QFormLayout::LabelRole, villeLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        noCommune = new QLineEdit(CcpaSpancDossierDlg);
        noCommune->setObjectName(QStringLiteral("noCommune"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(noCommune->sizePolicy().hasHeightForWidth());
        noCommune->setSizePolicy(sizePolicy1);
        noCommune->setBaseSize(QSize(20, 20));
        noCommune->setMaxLength(3);

        horizontalLayout_2->addWidget(noCommune);

        ville = new CcpaSpancCombo(CcpaSpancDossierDlg);
        ville->setObjectName(QStringLiteral("ville"));

        horizontalLayout_2->addWidget(ville);


        formLayout->setLayout(16, QFormLayout::FieldRole, horizontalLayout_2);

        codePostalLabel = new QLabel(CcpaSpancDossierDlg);
        codePostalLabel->setObjectName(QStringLiteral("codePostalLabel"));

        formLayout->setWidget(17, QFormLayout::LabelRole, codePostalLabel);

        cp = new QLineEdit(CcpaSpancDossierDlg);
        cp->setObjectName(QStringLiteral("cp"));

        formLayout->setWidget(17, QFormLayout::FieldRole, cp);

        cedexLabel = new QLabel(CcpaSpancDossierDlg);
        cedexLabel->setObjectName(QStringLiteral("cedexLabel"));

        formLayout->setWidget(18, QFormLayout::LabelRole, cedexLabel);

        cedex = new QLineEdit(CcpaSpancDossierDlg);
        cedex->setObjectName(QStringLiteral("cedex"));

        formLayout->setWidget(18, QFormLayout::FieldRole, cedex);

        adresseLue2 = new QLabel(CcpaSpancDossierDlg);
        adresseLue2->setObjectName(QStringLiteral("adresseLue2"));
        adresseLue2->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(19, QFormLayout::FieldRole, adresseLue2);

        label = new QLabel(CcpaSpancDossierDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        formLayout->setWidget(20, QFormLayout::LabelRole, label);

        norueL_5 = new QLabel(CcpaSpancDossierDlg);
        norueL_5->setObjectName(QStringLiteral("norueL_5"));

        formLayout->setWidget(21, QFormLayout::LabelRole, norueL_5);

        norue_p = new QLineEdit(CcpaSpancDossierDlg);
        norue_p->setObjectName(QStringLiteral("norue_p"));

        formLayout->setWidget(21, QFormLayout::FieldRole, norue_p);

        typerueL_4 = new QLabel(CcpaSpancDossierDlg);
        typerueL_4->setObjectName(QStringLiteral("typerueL_4"));

        formLayout->setWidget(22, QFormLayout::LabelRole, typerueL_4);

        typerue_p = new QLineEdit(CcpaSpancDossierDlg);
        typerue_p->setObjectName(QStringLiteral("typerue_p"));

        formLayout->setWidget(22, QFormLayout::FieldRole, typerue_p);

        nomDeLaRueLabel_4 = new QLabel(CcpaSpancDossierDlg);
        nomDeLaRueLabel_4->setObjectName(QStringLiteral("nomDeLaRueLabel_4"));

        formLayout->setWidget(23, QFormLayout::LabelRole, nomDeLaRueLabel_4);

        nomrue_p = new QLineEdit(CcpaSpancDossierDlg);
        nomrue_p->setObjectName(QStringLiteral("nomrue_p"));

        formLayout->setWidget(23, QFormLayout::FieldRole, nomrue_p);

        adresse2Label_4 = new QLabel(CcpaSpancDossierDlg);
        adresse2Label_4->setObjectName(QStringLiteral("adresse2Label_4"));

        formLayout->setWidget(24, QFormLayout::LabelRole, adresse2Label_4);

        adresse2_p = new QLineEdit(CcpaSpancDossierDlg);
        adresse2_p->setObjectName(QStringLiteral("adresse2_p"));

        formLayout->setWidget(24, QFormLayout::FieldRole, adresse2_p);

        adresse3Label_4 = new QLabel(CcpaSpancDossierDlg);
        adresse3Label_4->setObjectName(QStringLiteral("adresse3Label_4"));

        formLayout->setWidget(25, QFormLayout::LabelRole, adresse3Label_4);

        adresse3_p = new QLineEdit(CcpaSpancDossierDlg);
        adresse3_p->setObjectName(QStringLiteral("adresse3_p"));

        formLayout->setWidget(25, QFormLayout::FieldRole, adresse3_p);

        villeLabel_4 = new QLabel(CcpaSpancDossierDlg);
        villeLabel_4->setObjectName(QStringLiteral("villeLabel_4"));

        formLayout->setWidget(26, QFormLayout::LabelRole, villeLabel_4);

        ville_p = new QLineEdit(CcpaSpancDossierDlg);
        ville_p->setObjectName(QStringLiteral("ville_p"));

        formLayout->setWidget(26, QFormLayout::FieldRole, ville_p);

        codePostalLabel_4 = new QLabel(CcpaSpancDossierDlg);
        codePostalLabel_4->setObjectName(QStringLiteral("codePostalLabel_4"));

        formLayout->setWidget(27, QFormLayout::LabelRole, codePostalLabel_4);

        cp_p = new QLineEdit(CcpaSpancDossierDlg);
        cp_p->setObjectName(QStringLiteral("cp_p"));

        formLayout->setWidget(27, QFormLayout::FieldRole, cp_p);

        cedexLabel_4 = new QLabel(CcpaSpancDossierDlg);
        cedexLabel_4->setObjectName(QStringLiteral("cedexLabel_4"));

        formLayout->setWidget(28, QFormLayout::LabelRole, cedexLabel_4);

        cedex_p = new QLineEdit(CcpaSpancDossierDlg);
        cedex_p->setObjectName(QStringLiteral("cedex_p"));

        formLayout->setWidget(28, QFormLayout::FieldRole, cedex_p);

        paysLabel_4 = new QLabel(CcpaSpancDossierDlg);
        paysLabel_4->setObjectName(QStringLiteral("paysLabel_4"));

        formLayout->setWidget(29, QFormLayout::LabelRole, paysLabel_4);

        pays_p = new CcpaSpancCombo(CcpaSpancDossierDlg);
        pays_p->setObjectName(QStringLiteral("pays_p"));

        formLayout->setWidget(29, QFormLayout::FieldRole, pays_p);


        horizontalLayout->addLayout(formLayout);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setSizeConstraint(QLayout::SetNoConstraint);
        formLayout_3->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        formLayout_3->setVerticalSpacing(0);
        sectionLabel = new QLabel(CcpaSpancDossierDlg);
        sectionLabel->setObjectName(QStringLiteral("sectionLabel"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, sectionLabel);

        section = new QLineEdit(CcpaSpancDossierDlg);
        section->setObjectName(QStringLiteral("section"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, section);

        prefixeL = new QLabel(CcpaSpancDossierDlg);
        prefixeL->setObjectName(QStringLiteral("prefixeL"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, prefixeL);

        prefixe = new QLineEdit(CcpaSpancDossierDlg);
        prefixe->setObjectName(QStringLiteral("prefixe"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, prefixe);

        parcelleLabel = new QLabel(CcpaSpancDossierDlg);
        parcelleLabel->setObjectName(QStringLiteral("parcelleLabel"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, parcelleLabel);

        parcelle = new QLineEdit(CcpaSpancDossierDlg);
        parcelle->setObjectName(QStringLiteral("parcelle"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, parcelle);

        nombreDePiCesPrincipalesLabel = new QLabel(CcpaSpancDossierDlg);
        nombreDePiCesPrincipalesLabel->setObjectName(QStringLiteral("nombreDePiCesPrincipalesLabel"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, nombreDePiCesPrincipalesLabel);

        nbPP = new QLineEdit(CcpaSpancDossierDlg);
        nbPP->setObjectName(QStringLiteral("nbPP"));

        formLayout_3->setWidget(3, QFormLayout::FieldRole, nbPP);

        annEDeConstructionLabel = new QLabel(CcpaSpancDossierDlg);
        annEDeConstructionLabel->setObjectName(QStringLiteral("annEDeConstructionLabel"));

        formLayout_3->setWidget(4, QFormLayout::LabelRole, annEDeConstructionLabel);

        annee = new QLineEdit(CcpaSpancDossierDlg);
        annee->setObjectName(QStringLiteral("annee"));
        annee->setMaxLength(4);

        formLayout_3->setWidget(4, QFormLayout::FieldRole, annee);

        prTraitementLabel = new QLabel(CcpaSpancDossierDlg);
        prTraitementLabel->setObjectName(QStringLiteral("prTraitementLabel"));

        formLayout_3->setWidget(5, QFormLayout::LabelRole, prTraitementLabel);

        prTraitementComboBox = new CcpaSpancCombo(CcpaSpancDossierDlg);
        prTraitementComboBox->setObjectName(QStringLiteral("prTraitementComboBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(prTraitementComboBox->sizePolicy().hasHeightForWidth());
        prTraitementComboBox->setSizePolicy(sizePolicy2);

        formLayout_3->setWidget(5, QFormLayout::FieldRole, prTraitementComboBox);

        traitementLabel = new QLabel(CcpaSpancDossierDlg);
        traitementLabel->setObjectName(QStringLiteral("traitementLabel"));

        formLayout_3->setWidget(6, QFormLayout::LabelRole, traitementLabel);

        traitement = new CcpaSpancCombo(CcpaSpancDossierDlg);
        traitement->setObjectName(QStringLiteral("traitement"));
        sizePolicy2.setHeightForWidth(traitement->sizePolicy().hasHeightForWidth());
        traitement->setSizePolicy(sizePolicy2);

        formLayout_3->setWidget(6, QFormLayout::FieldRole, traitement);

        agrMentLabel = new QLabel(CcpaSpancDossierDlg);
        agrMentLabel->setObjectName(QStringLiteral("agrMentLabel"));

        formLayout_3->setWidget(7, QFormLayout::LabelRole, agrMentLabel);

        agrement = new QLineEdit(CcpaSpancDossierDlg);
        agrement->setObjectName(QStringLiteral("agrement"));

        formLayout_3->setWidget(7, QFormLayout::FieldRole, agrement);

        ventilationPrimaireLabel = new QLabel(CcpaSpancDossierDlg);
        ventilationPrimaireLabel->setObjectName(QStringLiteral("ventilationPrimaireLabel"));

        formLayout_3->setWidget(8, QFormLayout::LabelRole, ventilationPrimaireLabel);

        vp = new QCheckBox(CcpaSpancDossierDlg);
        vp->setObjectName(QStringLiteral("vp"));

        formLayout_3->setWidget(8, QFormLayout::FieldRole, vp);

        ventilationSecondaireLabel = new QLabel(CcpaSpancDossierDlg);
        ventilationSecondaireLabel->setObjectName(QStringLiteral("ventilationSecondaireLabel"));

        formLayout_3->setWidget(9, QFormLayout::LabelRole, ventilationSecondaireLabel);

        vs = new QCheckBox(CcpaSpancDossierDlg);
        vs->setObjectName(QStringLiteral("vs"));

        formLayout_3->setWidget(9, QFormLayout::FieldRole, vs);

        conformeLabel = new QLabel(CcpaSpancDossierDlg);
        conformeLabel->setObjectName(QStringLiteral("conformeLabel"));

        formLayout_3->setWidget(10, QFormLayout::LabelRole, conformeLabel);

        conformeCheckBox = new QCheckBox(CcpaSpancDossierDlg);
        conformeCheckBox->setObjectName(QStringLiteral("conformeCheckBox"));

        formLayout_3->setWidget(10, QFormLayout::FieldRole, conformeCheckBox);

        dLaiLabel = new QLabel(CcpaSpancDossierDlg);
        dLaiLabel->setObjectName(QStringLiteral("dLaiLabel"));

        formLayout_3->setWidget(11, QFormLayout::LabelRole, dLaiLabel);

        delai = new QComboBox(CcpaSpancDossierDlg);
        delai->setObjectName(QStringLiteral("delai"));
        sizePolicy2.setHeightForWidth(delai->sizePolicy().hasHeightForWidth());
        delai->setSizePolicy(sizePolicy2);

        formLayout_3->setWidget(11, QFormLayout::FieldRole, delai);

        urgenceLabel = new QLabel(CcpaSpancDossierDlg);
        urgenceLabel->setObjectName(QStringLiteral("urgenceLabel"));

        formLayout_3->setWidget(12, QFormLayout::LabelRole, urgenceLabel);

        urgenceCheckBox = new QCheckBox(CcpaSpancDossierDlg);
        urgenceCheckBox->setObjectName(QStringLiteral("urgenceCheckBox"));

        formLayout_3->setWidget(12, QFormLayout::FieldRole, urgenceCheckBox);

        exutoireLabel = new QLabel(CcpaSpancDossierDlg);
        exutoireLabel->setObjectName(QStringLiteral("exutoireLabel"));

        formLayout_3->setWidget(13, QFormLayout::LabelRole, exutoireLabel);

        exutoire = new CcpaSpancCombo(CcpaSpancDossierDlg);
        exutoire->setObjectName(QStringLiteral("exutoire"));
        sizePolicy2.setHeightForWidth(exutoire->sizePolicy().hasHeightForWidth());
        exutoire->setSizePolicy(sizePolicy2);

        formLayout_3->setWidget(13, QFormLayout::FieldRole, exutoire);

        exutoireLabel_2 = new QLabel(CcpaSpancDossierDlg);
        exutoireLabel_2->setObjectName(QStringLiteral("exutoireLabel_2"));

        formLayout_3->setWidget(15, QFormLayout::FieldRole, exutoireLabel_2);

        installationLabel = new QLabel(CcpaSpancDossierDlg);
        installationLabel->setObjectName(QStringLiteral("installationLabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(installationLabel->sizePolicy().hasHeightForWidth());
        installationLabel->setSizePolicy(sizePolicy3);
        installationLabel->setMinimumSize(QSize(0, 156));
        installationLabel->setStyleSheet(QStringLiteral("background-color: rgb(197, 197, 197);"));
        installationLabel->setWordWrap(true);

        formLayout_3->setWidget(17, QFormLayout::SpanningRole, installationLabel);

        facturation = new QLabel(CcpaSpancDossierDlg);
        facturation->setObjectName(QStringLiteral("facturation"));

        formLayout_3->setWidget(25, QFormLayout::SpanningRole, facturation);

        effaceBouton = new QPushButton(CcpaSpancDossierDlg);
        effaceBouton->setObjectName(QStringLiteral("effaceBouton"));

        formLayout_3->setWidget(19, QFormLayout::FieldRole, effaceBouton);

        pushButton = new QPushButton(CcpaSpancDossierDlg);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        formLayout_3->setWidget(20, QFormLayout::FieldRole, pushButton);

        buttonBox = new QDialogButtonBox(CcpaSpancDossierDlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout_3->setWidget(21, QFormLayout::FieldRole, buttonBox);

        texteFichier = new QTextEdit(CcpaSpancDossierDlg);
        texteFichier->setObjectName(QStringLiteral("texteFichier"));
        texteFichier->setReadOnly(true);
        texteFichier->setAcceptRichText(false);

        formLayout_3->setWidget(22, QFormLayout::FieldRole, texteFichier);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        formLayout_3->setLayout(22, QFormLayout::LabelRole, gridLayout);

        liste = new QLineEdit(CcpaSpancDossierDlg);
        liste->setObjectName(QStringLiteral("liste"));
        liste->setMaxLength(4);

        formLayout_3->setWidget(14, QFormLayout::FieldRole, liste);

        label_3 = new QLabel(CcpaSpancDossierDlg);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_3->setWidget(14, QFormLayout::LabelRole, label_3);

        delai_label = new QLabel(CcpaSpancDossierDlg);
        delai_label->setObjectName(QStringLiteral("delai_label"));
        delai_label->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 127)"));
        delai_label->setFrameShadow(QFrame::Sunken);
        delai_label->setAlignment(Qt::AlignJustify|Qt::AlignTop);
        delai_label->setWordWrap(true);

        formLayout_3->setWidget(18, QFormLayout::SpanningRole, delai_label);


        horizontalLayout->addLayout(formLayout_3);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        infoNoAdressePropriete = new QLabel(CcpaSpancDossierDlg);
        infoNoAdressePropriete->setObjectName(QStringLiteral("infoNoAdressePropriete"));
        sizePolicy2.setHeightForWidth(infoNoAdressePropriete->sizePolicy().hasHeightForWidth());
        infoNoAdressePropriete->setSizePolicy(sizePolicy2);
        infoNoAdressePropriete->setMinimumSize(QSize(70, 10));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(255, 255, 63, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(127, 127, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(170, 170, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        infoNoAdressePropriete->setPalette(palette);
        infoNoAdressePropriete->setAutoFillBackground(true);
        infoNoAdressePropriete->setFrameShape(QFrame::Box);
        infoNoAdressePropriete->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(infoNoAdressePropriete);

        infoNoProprietaire = new QLabel(CcpaSpancDossierDlg);
        infoNoProprietaire->setObjectName(QStringLiteral("infoNoProprietaire"));
        sizePolicy2.setHeightForWidth(infoNoProprietaire->sizePolicy().hasHeightForWidth());
        infoNoProprietaire->setSizePolicy(sizePolicy2);
        infoNoProprietaire->setMinimumSize(QSize(70, 10));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush8(QColor(170, 255, 255, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush8);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush6);
        QBrush brush9(QColor(212, 255, 255, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush9);
        QBrush brush10(QColor(85, 127, 127, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush10);
        QBrush brush11(QColor(113, 170, 170, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush11);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush8);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush9);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        infoNoProprietaire->setPalette(palette1);
        infoNoProprietaire->setAutoFillBackground(true);
        infoNoProprietaire->setFrameShape(QFrame::Box);
        infoNoProprietaire->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(infoNoProprietaire);

        infoNoPropriete = new QLabel(CcpaSpancDossierDlg);
        infoNoPropriete->setObjectName(QStringLiteral("infoNoPropriete"));
        sizePolicy2.setHeightForWidth(infoNoPropriete->sizePolicy().hasHeightForWidth());
        infoNoPropriete->setSizePolicy(sizePolicy2);
        infoNoPropriete->setMinimumSize(QSize(70, 10));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush12(QColor(85, 255, 255, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush12);
        QBrush brush13(QColor(213, 255, 255, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush13);
        QBrush brush14(QColor(149, 255, 255, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush14);
        QBrush brush15(QColor(42, 127, 127, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush15);
        QBrush brush16(QColor(56, 170, 170, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush16);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush12);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush8);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush12);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush13);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush14);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush15);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush16);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush12);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush13);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush16);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        infoNoPropriete->setPalette(palette2);
        infoNoPropriete->setAutoFillBackground(true);
        infoNoPropriete->setFrameShape(QFrame::Box);
        infoNoPropriete->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(infoNoPropriete);

        infoNoAdresseProprietaire = new QLabel(CcpaSpancDossierDlg);
        infoNoAdresseProprietaire->setObjectName(QStringLiteral("infoNoAdresseProprietaire"));
        sizePolicy2.setHeightForWidth(infoNoAdresseProprietaire->sizePolicy().hasHeightForWidth());
        infoNoAdresseProprietaire->setSizePolicy(sizePolicy2);
        infoNoAdresseProprietaire->setMinimumSize(QSize(70, 10));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush17(QColor(0, 255, 0, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush17);
        QBrush brush18(QColor(127, 255, 127, 255));
        brush18.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush18);
        QBrush brush19(QColor(63, 255, 63, 255));
        brush19.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush19);
        QBrush brush20(QColor(0, 127, 0, 255));
        brush20.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush20);
        QBrush brush21(QColor(0, 170, 0, 255));
        brush21.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush21);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush17);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush18);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush18);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush19);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush20);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush21);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush17);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush18);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush20);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush18);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush19);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush20);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush21);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush20);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush20);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush17);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        infoNoAdresseProprietaire->setPalette(palette3);
        infoNoAdresseProprietaire->setAutoFillBackground(true);
        infoNoAdresseProprietaire->setFrameShape(QFrame::Box);
        infoNoAdresseProprietaire->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(infoNoAdresseProprietaire);


        gridLayout_2->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        QWidget::setTabOrder(dossier, date);
        QWidget::setTabOrder(date, controle);
        QWidget::setTabOrder(controle, civilite);
        QWidget::setTabOrder(civilite, nom);
        QWidget::setTabOrder(nom, prenom);
        QWidget::setTabOrder(prenom, adresseDiff);
        QWidget::setTabOrder(adresseDiff, norue);
        QWidget::setTabOrder(norue, typerue);
        QWidget::setTabOrder(typerue, nomrue);
        QWidget::setTabOrder(nomrue, adresse2);
        QWidget::setTabOrder(adresse2, adresse3);
        QWidget::setTabOrder(adresse3, noCommune);
        QWidget::setTabOrder(noCommune, cp);
        QWidget::setTabOrder(cp, ville);
        QWidget::setTabOrder(ville, cedex);
        QWidget::setTabOrder(cedex, norue_p);
        QWidget::setTabOrder(norue_p, typerue_p);
        QWidget::setTabOrder(typerue_p, nomrue_p);
        QWidget::setTabOrder(nomrue_p, adresse2_p);
        QWidget::setTabOrder(adresse2_p, adresse3_p);
        QWidget::setTabOrder(adresse3_p, ville_p);
        QWidget::setTabOrder(ville_p, cp_p);
        QWidget::setTabOrder(cp_p, cedex_p);
        QWidget::setTabOrder(cedex_p, pays_p);
        QWidget::setTabOrder(pays_p, section);
        QWidget::setTabOrder(section, prefixe);
        QWidget::setTabOrder(prefixe, parcelle);
        QWidget::setTabOrder(parcelle, nbPP);
        QWidget::setTabOrder(nbPP, annee);
        QWidget::setTabOrder(annee, prTraitementComboBox);
        QWidget::setTabOrder(prTraitementComboBox, traitement);
        QWidget::setTabOrder(traitement, agrement);
        QWidget::setTabOrder(agrement, vp);
        QWidget::setTabOrder(vp, vs);
        QWidget::setTabOrder(vs, conformeCheckBox);
        QWidget::setTabOrder(conformeCheckBox, delai);
        QWidget::setTabOrder(delai, urgenceCheckBox);

        retranslateUi(CcpaSpancDossierDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), CcpaSpancDossierDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CcpaSpancDossierDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(CcpaSpancDossierDlg);
    } // setupUi

    void retranslateUi(QDialog *CcpaSpancDossierDlg)
    {
        CcpaSpancDossierDlg->setWindowTitle(QApplication::translate("CcpaSpancDossierDlg", "Dossier", 0));
        dossierLabel->setText(QApplication::translate("CcpaSpancDossierDlg", "Dossier", 0));
        dateDeContrLeLabel->setText(QApplication::translate("CcpaSpancDossierDlg", "Date de contr\303\264le", 0));
        contrLeLabel->setText(QApplication::translate("CcpaSpancDossierDlg", "Contr\303\264le", 0));
        civilitLabel->setText(QApplication::translate("CcpaSpancDossierDlg", "Civilit\303\251", 0));
        civilite->clear();
        civilite->insertItems(0, QStringList()
         << QApplication::translate("CcpaSpancDossierDlg", "Monsieur", 0)
         << QApplication::translate("CcpaSpancDossierDlg", "Madame", 0)
        );
        nomLabel->setText(QApplication::translate("CcpaSpancDossierDlg", "Nom", 0));
        prNomLabel->setText(QApplication::translate("CcpaSpancDossierDlg", "Pr\303\251nom", 0));
        proprietaireLu->setText(QString());
        label_2->setText(QApplication::translate("CcpaSpancDossierDlg", "Adresse de l'immeuble", 0));
        adresseLue->setText(QString());
        adresseDuPropriTaireDiffRenteLabel->setText(QApplication::translate("CcpaSpancDossierDlg", "Adresse du propri\303\251taire diff\303\251rente", 0));
        norueL->setText(QApplication::translate("CcpaSpancDossierDlg", "No dans la rue", 0));
        typerueL->setText(QApplication::translate("CcpaSpancDossierDlg", "Type de voie", 0));
        nomDeLaRueLabel->setText(QApplication::translate("CcpaSpancDossierDlg", "Nom de la rue", 0));
        adresse2Label->setText(QApplication::translate("CcpaSpancDossierDlg", "Adresse 2", 0));
        adresse3Label->setText(QApplication::translate("CcpaSpancDossierDlg", "Adresse\302\2403", 0));
        villeLabel->setText(QApplication::translate("CcpaSpancDossierDlg", "Ville", 0));
        codePostalLabel->setText(QApplication::translate("CcpaSpancDossierDlg", "Code Postal", 0));
        cedexLabel->setText(QApplication::translate("CcpaSpancDossierDlg", "Cedex", 0));
        adresseLue2->setText(QString());
        label->setText(QApplication::translate("CcpaSpancDossierDlg", "Adresse du propri\303\251taire", 0));
        norueL_5->setText(QApplication::translate("CcpaSpancDossierDlg", "No dans la rue", 0));
        typerueL_4->setText(QApplication::translate("CcpaSpancDossierDlg", "Type de voie", 0));
        nomDeLaRueLabel_4->setText(QApplication::translate("CcpaSpancDossierDlg", "Nom de la rue", 0));
        adresse2Label_4->setText(QApplication::translate("CcpaSpancDossierDlg", "Adresse 2", 0));
        adresse3Label_4->setText(QApplication::translate("CcpaSpancDossierDlg", "Adresse\302\2403", 0));
        villeLabel_4->setText(QApplication::translate("CcpaSpancDossierDlg", "Ville", 0));
        codePostalLabel_4->setText(QApplication::translate("CcpaSpancDossierDlg", "Code Postal", 0));
        cedexLabel_4->setText(QApplication::translate("CcpaSpancDossierDlg", "Cedex", 0));
        paysLabel_4->setText(QApplication::translate("CcpaSpancDossierDlg", "Pays", 0));
        sectionLabel->setText(QApplication::translate("CcpaSpancDossierDlg", "Section", 0));
        prefixeL->setText(QApplication::translate("CcpaSpancDossierDlg", "Pr\303\251fixe", 0));
        parcelleLabel->setText(QApplication::translate("CcpaSpancDossierDlg", "Parcelle", 0));
        nombreDePiCesPrincipalesLabel->setText(QApplication::translate("CcpaSpancDossierDlg", "Nombre de pi\303\250ces principales", 0));
        annEDeConstructionLabel->setText(QApplication::translate("CcpaSpancDossierDlg", "Ann\303\251e de construction", 0));
        prTraitementLabel->setText(QApplication::translate("CcpaSpancDossierDlg", "Pr\303\251traitement", 0));
        traitementLabel->setText(QApplication::translate("CcpaSpancDossierDlg", "Traitement", 0));
        agrMentLabel->setText(QApplication::translate("CcpaSpancDossierDlg", "Agr\303\251ment", 0));
        ventilationPrimaireLabel->setText(QApplication::translate("CcpaSpancDossierDlg", "Ventilation primaire", 0));
        ventilationSecondaireLabel->setText(QApplication::translate("CcpaSpancDossierDlg", "Ventilation secondaire", 0));
        conformeLabel->setText(QApplication::translate("CcpaSpancDossierDlg", "Conforme", 0));
        dLaiLabel->setText(QApplication::translate("CcpaSpancDossierDlg", "D\303\251lai ( en ann\303\251es)", 0));
        delai->clear();
        delai->insertItems(0, QStringList()
         << QApplication::translate("CcpaSpancDossierDlg", "0", 0)
         << QApplication::translate("CcpaSpancDossierDlg", "1", 0)
         << QApplication::translate("CcpaSpancDossierDlg", "4", 0)
        );
        urgenceLabel->setText(QApplication::translate("CcpaSpancDossierDlg", "Urgence", 0));
        exutoireLabel->setText(QApplication::translate("CcpaSpancDossierDlg", "Exutoire", 0));
        exutoireLabel_2->setText(QString());
        installationLabel->setText(QString());
        facturation->setText(QString());
        effaceBouton->setText(QApplication::translate("CcpaSpancDossierDlg", "Effacer le formulaire", 0));
        pushButton->setText(QApplication::translate("CcpaSpancDossierDlg", "Enregistrer et nouveau", 0));
        texteFichier->setHtml(QApplication::translate("CcpaSpancDossierDlg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        label_3->setText(QApplication::translate("CcpaSpancDossierDlg", "Liste", 0));
        delai_label->setText(QString());
        infoNoAdressePropriete->setText(QString());
        infoNoProprietaire->setText(QString());
        infoNoPropriete->setText(QString());
        infoNoAdresseProprietaire->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CcpaSpancDossierDlg: public Ui_CcpaSpancDossierDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCPASPANCDOSSIERDLG_H
