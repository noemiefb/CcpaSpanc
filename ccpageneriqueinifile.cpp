#include "ccpageneriqueinifile.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QRegExp>
#include <QDebug>

CcpaGeneriqueIniFile::CcpaGeneriqueIniFile() {
    chemin="";
}

CcpaGeneriqueIniFile::CcpaGeneriqueIniFile(QString nom) {
    setIniFile(nom);
    chemin=nom;
}

bool CcpaGeneriqueIniFile::changeValeurDeSectionCle(QString section, QString cle) {
    qDebug() << "Fonction non implémentée" << section << " " << cle;
    return true;
}

QString CcpaGeneriqueIniFile::chercheParSectionCle(QString section, QString cle) {
    bool ouvert=fichierIni.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!ouvert) {
        qDebug() << "Fichier pas ouvert";
    }
    QTextStream flux(&fichierIni);
    //QString tout =flux.readAll();
    QString ligne;
    QRegExp filtreSection;
    QRegExp filtreCle;
    QString valeur="";
    filtreSection.setPatternSyntax(QRegExp::FixedString);
    filtreSection.setPattern("["+section.toUpper()+"]");
    filtreCle.setPatternSyntax(QRegExp::RegExp);
    filtreCle.setPattern("^" + cle.toLower()+"=(.*)$");
    //On cherche d'abord le début de la section
    bool continueRecherche=true;

    while(continueRecherche && (!flux.atEnd()))
    {
        ligne = flux.readLine();
        //traitement de la ligne
        if (filtreSection.exactMatch(ligne)) {
            //On a trouuvé la section et on recherche maintenant la ligne de la clé tant que la section n'est pas finie
            QRegExp nouvelleSection;
            nouvelleSection.setPatternSyntax(QRegExp::RegExp);
            nouvelleSection.setPattern("\\^[.*]\\$");
            while(continueRecherche && (!flux.atEnd() ))
            {
                ligne = flux.readLine();
                if (nouvelleSection.exactMatch(ligne)) {
                    continueRecherche=false;
                }
                else {
                    if (filtreCle.exactMatch(ligne)) {
                        valeur=filtreCle.cap(1);
                        continueRecherche=false;
                    }
                }

            }
        }
    }
    fichierIni.close();
    return valeur;
}

QString CcpaGeneriqueIniFile::getFilename() {
    return chemin;
}

bool CcpaGeneriqueIniFile::estFichierValide() {
    if (fichierIni.exists()) {
        return true;
    }
    return false;
}

bool CcpaGeneriqueIniFile::ferme() {
    if (estFichierValide()) {
        fichierIni.close();
        return true;
    }
    return false;
}

bool CcpaGeneriqueIniFile::setIniFile(QString nom) {
    fichierIni.setFileName(nom);
    chemin=nom;
    return true;
}

CcpaGeneriqueIniFile::~CcpaGeneriqueIniFile() {
    if (fichierIni.isOpen())
        fichierIni.close();
}
