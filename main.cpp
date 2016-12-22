#include <QApplication>
#include <QApplication>
#include <QMessageBox>
#include <QString>
#include <QRegExp>
#include <QDebug>

#include "ccpageneriqueinifile.h"
#include "ccpaspancutils.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CcpaSpancUtils w;
    int retour=0;
    QString ini;

    if (argc==2) {
        ini = argv[1];
        w.setIniFile(ini);
        w.show();
        retour = a.exec();
    }
    else {
        qDebug() << "Erreur d'appel: pas de nom de fichier fourni";
    }
    return retour;
}
