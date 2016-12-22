#include "ccpagenerique.h"
#include <QDate>
#include <QString>
#include <QVariant>
#include <QStringList>
#include <QRegularExpression>
#include <QtMath>

CcpaGenerique::CcpaGenerique()
{

}

QString CcpaGenerique::getSection(QString section, QString prefixe) {
    QString zeros;
    int lsection = section.length();
    int lprefixe = prefixe.length();
    int lzeros = 8 - lsection - lprefixe;
    zeros.fill('0',lzeros);
    section = prefixe.append(zeros).append(section);
    return section;
}

bool CcpaGenerique::inferieur(QString valeur, QString borne) {
    ulong v = valeur.toULong();
    ulong b = borne.toULong();
    return inferieur(v,b);
}

bool CcpaGenerique::inferieur(ulong valeur, ulong borne) {
    return valeur < borne;
}

bool CcpaGenerique::stringToBool(QString t)
{
    return (t.toUpper().compare("TRUE")==0)?true:false;
}


QDate CcpaGenerique::stringToDate(QString t)
{
    int indexjour,indexmois,indexan;
    QString jour,mois,annee;
    QStringList dateSplit=t.split("-");
    if (dateSplit.count()<3){
        dateSplit = t.split("/");
        indexan=2;
        indexmois=1;
        indexjour=0;
    }
    else {
        indexan=0;
        indexmois=1;
        indexjour=2;
    }
    QDate retour;
    retour.setDate(0,0,0);
    if (dateSplit.count()==3) {
        jour = dateSplit.at(indexjour);
        mois = dateSplit.at(indexmois);
        annee= dateSplit.at(indexan);
        int j,m,a;
        j = jour.toInt();
        m = mois.toInt();
        a = annee.toInt();
        retour.setDate(a,m,j);
    }
    return retour;
}

QString CcpaGenerique::intVersStringAvecZerosDevant(int i,int zeros) {
    QString retour="";
    quint16 puissance,puissanceMoinsUn;
    puissance=qPow(10,zeros);
    puissanceMoinsUn=qPow(10,zeros-1);
    if (i>puissanceMoinsUn - 1) {
        retour = QString::number(i);
    }
    else {
        int total= puissance+i;
        retour =QString::number(total);
        retour=retour.right(zeros);
    }
    return retour;
}

QString CcpaGenerique::dateVersAMJ(QDate t) {
    int jour,mois,annee;
    QString j,m,a, retour;

    jour=t.day();
    mois=t.month();
    annee=t.year();

    j=intVersStringAvecZerosDevant(jour,2);
    m=intVersStringAvecZerosDevant(mois,2);
    a=intVersStringAvecZerosDevant(annee,4);

    retour=a+m+j;
    return retour;
}

float CcpaGenerique::moneyStringToFloat(QString montant)
{
    if (montant.length()==0) return 0;
    QStringList liste=montant.split(" ");
    QString debut=liste.at(0);
    QStringList parts=debut.split(",");
    QString gauche=parts.at(0);
    QString droite=parts.at(1);
    gauche=gauche.remove(QChar(160));
    int entier=gauche.toInt();
    int decimal=droite.toInt();
    float deci=decimal/100;
    float retour=entier+deci;
    return retour;
}
