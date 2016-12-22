#ifndef CCPAGENERIQUE_H
#define CCPAGENERIQUE_H

#include <QString>
#include <QDate>

class CcpaGenerique
{
public:
    CcpaGenerique();
    static bool inferieur(QString valeur,QString borne);
    static bool inferieur(ulong valeur,ulong borne);
    static bool stringToBool(QString);
    static QDate stringToDate(QString);
    static float moneyStringToFloat(QString);
    static QString dateVersAMJ(QDate date);
    static QString intVersStringAvecZerosDevant(int nombre, int zeros);
    static QString getSection(QString section,QString prefixe);
};

#endif // CCPAGENERIQUE_H
