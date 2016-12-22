#ifndef CCPASPANCFICHIERS_H
#define CCPASPANCFICHIERS_H

#include <QObject>

#include <QString>
#include <QProgressBar>

class CcpaSpancFichiers
{
private:
    QString racine;

public:
    CcpaSpancFichiers(QString racine);
    bool existe(QString noDossier,QString typeFichier,QString ext);
    bool copie(QString noDossier,QString typeFichier,QString ext,QString destination);
    bool creeFichierVide(ulong num, QString nom, QString contenu);
    bool creeRep(QString noDossier);
    bool creeRep(ulong noDossier);
    bool effaceFichier(QString source);
    bool est_extension(QString extension, QString modele);
    QString execTri(QString source, QString dest, QProgressBar *pB, bool creeRep);
    bool existeRep(QString nomDossier);
    QString faitNomFichier(QString noDossier,QString typeFichier,QString ext);
    QString faitNomFichier(ulong noDossier,QString typeFichier,QString ext);

    QString faitNomRep(QString noDossier);
    QString faitNomRep(ulong noDossier);

    QString faitCheminComplet(QString noDossier,QString typeFichier,QString ext);
    QString formatDossier(QString num);
    QQueue<QStringList> listeFichiersRepertoire(QString source);
    QString rangeFichiersEnRetour(QQueue<QStringList> liste, QString dest, QProgressBar *pB, bool creeRep);


    static bool creeFichierVide(QString nom);
    static bool existe(QString nom);
    static bool copie(QString source, QString dest);
    static bool ajouteLigne(QString fichier,QString ligne);


};

#endif // CCPASPANCFICHIERS_H
