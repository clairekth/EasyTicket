#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Initialisation des données
    stack = ui->stackedWidget;
    page_login = new PageLogin(parent, &gestionnaire_dialogue);
    page_accueil_client = new PageAccueilClient(parent, &gestionnaire_dialogue);
    page_ajout_ticket = new PageAjoutTicket(parent, &gestionnaire_dialogue);
    page_accueil_personnel = new PageAccueilPersonnel(parent,&gestionnaire_dialogue);

    //Insertion des différentes pages
    stack->insertWidget(LOGIN_PAGE, page_login);
    stack->insertWidget(ACCUEIL_CLIENT_PAGE, page_accueil_client);
    stack->insertWidget(AJOUT_TICKET_PAGE, page_ajout_ticket);
    stack->insertWidget(ACCUEIL_PERSONNEL_PAGE, page_accueil_personnel);

    //Set l'index actuelle sur la page de login
    stack->setCurrentIndex(LOGIN_PAGE);
}

MainWindow::~MainWindow()
{
    delete ui;
}

