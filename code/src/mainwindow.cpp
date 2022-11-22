#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Initialisation des données
    stack = ui->stackedWidget;
    page_login = new PageLogin();
    page_accueil_client = new PageAccueilClient();

    //Insertion des différentes pages
    stack->insertWidget(LOGIN_PAGE, page_login);
    stack->insertWidget(ACCUEIL_CLIENT_PAGE, page_accueil_client);
    //Set l'index actuelle sur la page de login
    stack->setCurrentIndex(LOGIN_PAGE);

}

void MainWindow::setGestionnaireDialogue(GestionnaireDialogue *g)
{
    gestionnaire_dialogue = g;

    //Set les gestionnaires dialogues des Pages du StackedWidget.
    page_login->setGestionnaireDialogue(gestionnaire_dialogue);
    page_accueil_client->setGestionnaireDialogue(gestionnaire_dialogue);
}

MainWindow::~MainWindow()
{
    delete ui;
}

