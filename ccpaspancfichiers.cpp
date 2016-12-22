#include "ccpaspancfichiers.h"
#include <QFile>
#include <QIODevice>
#include <QMessageBox>
#include <QRegExp>
#include <QStringList>
#include <QString>
#include <QQueue>
#include <QTextStream>
#include <QDirIterator>
#include <QDir>
#include <QDebug>

CcpaSpancFichiers::CcpaSpancFichiers(QString sracine)
{
    racine=sracine;
}

bool CcpaSpancFichiers::copie(QString noDossier,QString typeFichier,QString ext,QString destination)
{
    QString nomFichier=this->faitNomFichier(noDossier,typeFichier,ext);
    return copie(nomFichier, destination);
}

bool CcpaSpancFichiers::copie(QString source, QString dest)
{
    QFile file(source);
    if (file.exists()) {
        return file.copy(source,dest);
    }
    return false;
}
bool CcpaSpancFichiers::creeFichierVide(ulong num, QString nom,QString contenu) {
    QString nomRep = faitNomRep(num);
    QString nomFichier =  nomRep + "/" + nom + ".txt";
    QFile fichier;
    fichier.setFileName(nomFichier);
    if (fichier.open(QIODevice::WriteOnly)) {
        QTextStream out(&fichier);
        out << contenu;
        fichier.close();
        return true;
    }
    return false;
}

bool CcpaSpancFichiers::creeFichierVide(QString nom) {
    QString nomFichier =  nom;
    QFile fichier;
    fichier.setFileName(nomFichier);
    if (fichier.open(QIODevice::WriteOnly)) {
        fichier.close();
        return true;
    }
    return false;
}

bool CcpaSpancFichiers::ajouteLigne(QString fichiers,QString ligne)
{
    QString nomFichier = fichiers;
    QFile fichier;
    fichier.setFileName(nomFichier);
    if (fichier.open(QIODevice::Append)) {
        QTextStream out(&fichier);
        out << ligne;
        fichier.close();
        return true;
    }
    return false;
}

bool CcpaSpancFichiers::creeRep(QString nomDossier)
{
    bool retour=false;
    qDebug() << "Je vais créer: " << nomDossier;
    QString monRepertoire = faitNomRep(nomDossier);
    qDebug() << "Entrée: " << nomDossier << " Sortie: " << monRepertoire ;
    QDir repertoire(monRepertoire);
    if (existeRep(nomDossier)) {
        qDebug() << monRepertoire << " existe déjà.";
        retour=true;
    }
    else
    {
        qDebug() << monRepertoire << " n'existe pas.";
        QDir racinedir(racine);
        if (racinedir.isReadable())
        {
            qDebug() << this->racine << " est OK";
            if (racinedir.mkdir(nomDossier)) {
                retour=true;
            }
            else {

                qDebug() << "Impossible de créeer " << nomDossier << " dans " << this->racine;
            }
        }
        else {
        }


    }
    return retour ;
}

bool CcpaSpancFichiers::creeRep(ulong nomDossier)
{
    QString monDossier;
    monDossier.setNum(nomDossier);
    return creeRep(monDossier);
}

bool CcpaSpancFichiers::effaceFichier(QString source)
{
    QFile file(source);
    bool res=file.remove();
    return res;
}

bool CcpaSpancFichiers::est_extension(QString extension, QString modele)
{
    int i=extension.compare(modele);
    if (i==0) return true;
    else return false;
}


QString CcpaSpancFichiers::execTri(QString source, QString dest, QProgressBar* pB = NULL , bool creeRep = false) {
    QQueue<QStringList> liste_fichiers;
    QString resultat;
    liste_fichiers = listeFichiersRepertoire(source);
    if (liste_fichiers.count() > 0 ) {
        resultat=rangeFichiersEnRetour(liste_fichiers, dest, pB,creeRep);
    }
    else {
        resultat="Pas de fichier à trier";
    }
    return resultat;

}

bool CcpaSpancFichiers::existe(QString nom)
{
    QFile file(nom);
    if (file.exists())
           return true;

     return false;
}

bool CcpaSpancFichiers::existe(QString noDossier,QString typeFichier,QString ext)
{
    QString nomFichier = this->faitNomFichier(noDossier,typeFichier,ext);
    return existe(nomFichier);

}


bool CcpaSpancFichiers::existeRep(QString noDossier)
{
    QString nomRep = this->faitNomRep(noDossier);
    return existe(nomRep);

}

QString CcpaSpancFichiers::faitNomFichier(QString noDossier,QString typeFichier,QString ext)
{
    QString nomFichier =  "bc" + noDossier + "_" + typeFichier + "." + ext;
    return nomFichier;
}

QString CcpaSpancFichiers::faitNomFichier(ulong noDossier,QString typeFichier,QString ext)
{
    QString num;
    num.setNum(noDossier+1000);
    num = num.right(3);
    QString nomFichier =  "bc" + num + "_" + typeFichier + "." + ext;
    return nomFichier;
}


QString CcpaSpancFichiers::faitNomRep(QString noDossier)
{
    QString nomFichier =  racine + "/" + noDossier;
    return nomFichier;
}


QString CcpaSpancFichiers::faitNomRep(ulong noDossier)
{
    QString num;
    num.setNum(noDossier);
    QString nomFichier =  racine + "/" + num;
    return nomFichier;
}



QString CcpaSpancFichiers::faitCheminComplet(QString noDossier,QString typeFichier,QString ext)
{
    QString nomFichier = racine + "/" + noDossier + "/" + "bc" + noDossier + "_" + typeFichier + "." + ext;
    return nomFichier;
}

QString CcpaSpancFichiers::formatDossier(QString num) {
    if (num.length()==3) return num;
    if (num.length()>3) return num.left(3);
    if (num.length()<3) {
            num.prepend("000");
            num.right(3);
    }
    return num;
}

QQueue<QStringList> CcpaSpancFichiers::listeFichiersRepertoire(QString source)
{
    QQueue<QStringList> queue;
    QStringList fichier;
    QString numfic;
    QString extension;

    QRegExp pattern;
    pattern.setPattern("(\\d+)\\D*(pdf|doc|dwg)");
    QTextStream qout(stdout);
    QDirIterator it(source);
    if (it.path().length()==0) qDebug() << source << " non accessible" ;
    QString courant;
    QStringList matches;
    qDebug() << it.path();
    while (it.hasNext()) {
       courant = it.next();
       if (QFile::exists(courant))
       {
           QString fichierCourt = it.fileName();
           if( !  pattern.exactMatch(fichierCourt) ) {
                continue;
            }
            matches = pattern.capturedTexts();
            numfic = matches[1];
            extension = matches[2];
            fichier.clear();
            fichier.append(courant);
            fichier.append(numfic);
            fichier.append(extension);
            queue.push_front( fichier );
        }
    }
    return queue;
}


QString CcpaSpancFichiers::rangeFichiersEnRetour(QQueue<QStringList> liste, QString dest, QProgressBar* pB = NULL ,bool creeRepOK = false ) {
    QString dossier;
    QString resultat;
    QStringList lignefichier;
    QString nomRep;
    QString fichiernom;
    QString num;
    QString ext;
    QString cible;
    int i=0;
    bool ignoreCopie=false;
    bool gerePb=false;
    if ((!liste.empty()) && ( pB != NULL )) {
        gerePb=true;
        pB->setEnabled(true);
        pB->setMinimum(0);
        pB->setMaximum(liste.count());
    }
    while (!liste.empty()) {
        i++;
        lignefichier = liste.front();
        fichiernom=lignefichier[0];
//        fichiernom = source + "/" + fichiernom;
        num=lignefichier[1];
        ext=lignefichier[2];
        nomRep = dest + "/" + num + "/";
        if (est_extension(ext,"pdf")) {
            cible=nomRep + "bc" + num + "_rapport.pdf";
        }
        else {
            cible=nomRep + "bc" + num + "_rapport." + ext;
        }
        if (existe(cible))
        {
            QFile::remove(cible);
        }
        else {
            if (!existeRep(num)) {
                if (creeRepOK) {
                    if (creeRep(num)) {
                        resultat.append("Répertoire créé: " + num +"\n");
                    }
                    else {
                        resultat.append("Erreur à la création du répertoire " + num +"\n");
                        ignoreCopie=true;
                    }
                }
            }
        }
        if (!ignoreCopie) {
            resultat.append("Fichier en cours: " + fichiernom + " vers " +cible);
            bool k=QFile::copy(fichiernom,cible);
            if (k) {
                resultat.append(": OK\n");
            }
            else {
                resultat.append(": échec.\n");
            }
        }
        else {
            resultat.append("Copie de " + fichiernom + " vers " + cible + " ignorée.\n");
        }
        if (gerePb) {
            pB->setValue(i);
        }
        liste.pop_front();
    }
    return resultat;
}
