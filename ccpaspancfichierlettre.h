#ifndef CCPASPANCFICHIERLETTRE_H
#define CCPASPANCFICHIERLETTRE_H

#include <QList>
#include <QFile>
#include <QListIterator>
#include <QHash>
#include <QMap>
#include <QString>

class CcpaSpancFichierLettre : public QFile
{
private:
    QHash<QString, QString> motifs;
    QHash<QString, QString> valeurs;
    QString chemin;
public:
    void setChemin(QString);
    CcpaSpancFichierLettre();
    CcpaSpancFichierLettre(QString chemin);
    int process();
    int nbOccurences(QRegularExpression cle);
    QString getValue(QRegularExpression cle, int no);
    void setMotif(QString valeur,QString motif);
    void setMotif(QString valeur,QRegularExpression* motif);
    QString getValue(QString cle);
    QString getText();
};

#endif // CCPASPANCFICHIERLETTRE_H
