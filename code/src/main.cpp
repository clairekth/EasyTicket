#include "ingenieur.h"
#include "mainwindow.h"
#include "gestionnairedialogue.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    GestionnaireDialogue *g = new GestionnaireDialogue();
    w.setGestionnaireDialogue(g);
    w.show();
    return a.exec();
}
