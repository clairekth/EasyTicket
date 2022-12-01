#include "ingenieur.h"
#include "mainwindow.h"
#include "gestionnairedialogue.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GestionnaireDialogue *g = new GestionnaireDialogue();
    MainWindow w;
    w.setGestionnaireDialogue(g);
    w.show();
    return a.exec();
}
