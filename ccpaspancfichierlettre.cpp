#include "ccpaspancfichierlettre.h"
#include <QFile>
#include <QHash>
#include <QMap>
#include <QString>
#include <QStringData>
#include <QHashIterator>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>
#include <QDebug>
#include <QTextStream>
#include <QTextCodec>

CcpaSpancFichierLettre::CcpaSpancFichierLettre () : QFile()
{

}

CcpaSpancFichierLettre::CcpaSpancFichierLettre(QString lechemin)
{
    this->chemin = lechemin;
    return;
}

void CcpaSpancFichierLettre::setMotif(QString cle,QString valeur)
{
    QTextStream stream(stdout);
    QString motif;
    stream << "Création du motif " << cle << ": CHAINE prise en compte:" << valeur << endl;
    motifs.insert(cle,valeur);
    return;
}


void CcpaSpancFichierLettre::setMotif(QString cle,QRegularExpression* valeurs)
{
    QTextStream stream(stdout);
    QString motif;
    stream << "Création du motif " << cle << ": CHAINE prise en compte:" << valeurs->pattern() << endl;
    motifs.insert(cle,valeurs->pattern());
    return;
}



void CcpaSpancFichierLettre::setChemin(QString chem)
{
    this->chemin = chem;
    return;
}

QString CcpaSpancFichierLettre::getValue(QString cle)
{
    QString retour;
    retour="";
    if (valeurs.keys().contains(cle)) {
        retour= valeurs[cle];
    }
    return retour;
}

int CcpaSpancFichierLettre::nbOccurences(QRegularExpression cle)
{
    int retour=0;
    qDebug() << "--- Recherche nombre occurences de " << cle.pattern() << " dans "  << this->chemin;
    QTextStream stream(stdout);
    stream.setAutoDetectUnicode(true);
    QString texte = this->getText();
    if (texte.length()==0)
    {
        // Impossible d'ouvrir le fichier
        qDebug() << "Erreur d'ouverture du fichier: " << chemin;
    }
    else
    {
        QRegularExpressionMatchIterator matchCourant;
        QString trouve;
        QString motifCherche;
        QString nomChamp;
        matchCourant=cle.globalMatch(texte);
        int i=0;
        while (matchCourant.hasNext()) {
            matchCourant.next();        i++;

        }

        retour = i;
    }
    return retour;
}

QString CcpaSpancFichierLettre::getValue(QRegularExpression cle, int no)
{
    QString retour="";
    qDebug() << "--- Recherche occurence " << no << " de " << cle.pattern() << " dans "  << this->chemin;
    QTextStream stream(stdout);
    stream.setAutoDetectUnicode(true);
    QString texte = this->getText();
    if (texte.length()==0)
    {
        qDebug() << "Erreur d'ouverture du fichier: " << chemin;
    }
    else
    {
        QRegularExpressionMatch matchCourant;
        QString trouve;
        QString motifCherche;
        QString nomChamp;
        QRegularExpressionMatchIterator it = cle.globalMatch(texte);
        int i=0;
        while (it.hasNext()) {
            matchCourant = it.next();
            if (i+1==no) {
            qDebug() << matchCourant.captured(1);
            retour = matchCourant.captured(no);
            }
            i++;

        }
    }
    return retour;

}
int CcpaSpancFichierLettre::process()
{
    qDebug() << "--- Process du fichier " << this->chemin;
    QTextStream stream(stdout);
    stream.setAutoDetectUnicode(true);
    QString texte = this->getText();

 //QHashIterator<QString,QString> itMotif;
    int compte=0;

    if (texte.length()==0)
    {
        // Impossible d'ouvrir le fichier
        qDebug() << "Erreur d'ouverture du fichier: " << chemin;
    }
    else
    { QRegularExpression motifCourant;
        QRegularExpressionMatch matchCourant;
        QString trouve;
        QString motifCherche;
        QString nomChamp;
        QTextStream ficLu(this);
        ficLu.setAutoDetectUnicode(true);

        // QString t2 = QString::fromUtf8(texte.data);
        // stream << montexte;
        //texte=QString::fromStdString(montexte);
        motifCourant.setPatternOptions(QRegularExpression::MultilineOption   | QRegularExpression::DotMatchesEverythingOption);
        QHashIterator<QString,QString> itMotif(this->motifs);

        while(itMotif.hasNext()) {
            itMotif.next();
            nomChamp = itMotif.key();
            stream << "Je cherche: " << nomChamp << endl;

            motifCherche = itMotif.value();
            motifCourant.setPattern(motifCherche);
            matchCourant=motifCourant.match(texte);
            if (matchCourant.hasMatch())
            {
                compte++;
                trouve= matchCourant.captured(1);
                this->valeurs[nomChamp]=trouve;
                stream << "SORTIE: Trouvé: " << nomChamp << " " << this->valeurs[nomChamp] << endl ;
            }
            else
            {
                stream << "SORTIE: Motif non trouvé: " << motifCherche<< endl ;
            }
        }
    }
    return compte;
 }


QString CcpaSpancFichierLettre::getText()
{
    QString texte;
    QByteArray data;
    QFile fichier(this->chemin);
    if(fichier.open(QIODevice::ReadOnly | QIODevice::Text  ))
    {
        QChar apostrophe(0x92);

        fichier.setTextModeEnabled(true);
        data = fichier.readAll();
        fichier.close();
        QTextCodec *codec = QTextCodec::codecForName("Windows-1252");
        texte = codec->toUnicode(data);
        texte.replace(QChar::Nbsp,QChar::Space);
        texte.replace(QChar::CarriageReturn,QChar::Space);
        texte.replace(QChar::Tabulation,QChar::Space);
        texte.replace(QChar::ParagraphSeparator,QChar::Space);
        texte.replace(QChar::LineFeed,'\n');
        texte.replace(apostrophe,"'");

    }

    else texte = "";

    return texte;
}
