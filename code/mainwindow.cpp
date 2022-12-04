#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Initialisation des données
    stack = ui->stackedWidget;
    page_login = new PageLogin(stack, &gestionnaire_dialogue);
    page_accueil_client = new PageAccueilClient(stack, &gestionnaire_dialogue);
    page_ajout_ticket = new PageAjoutTicket(stack, &gestionnaire_dialogue);
    page_accueil_personnel = new PageAccueilPersonnel(stack, &gestionnaire_dialogue);
    page_resolution_ticket = new PageResolutionTicket(stack, &gestionnaire_dialogue);

    //Insertion des différentes pages
    stack->insertWidget(LOGIN_PAGE, page_login);
    stack->insertWidget(ACCUEIL_CLIENT_PAGE, page_accueil_client);
    stack->insertWidget(AJOUT_TICKET_PAGE, page_ajout_ticket);
    stack->insertWidget(ACCUEIL_PERSONNEL_PAGE, page_accueil_personnel);
    stack->insertWidget(RESOLUTION_TICKET_PAGE, page_resolution_ticket);

    //Set l'index actuel sur la page de login
    stack->setCurrentIndex(LOGIN_PAGE);
}

MainWindow::~MainWindow()
{
    delete page_ajout_ticket;
    delete page_accueil_client;
    delete page_login;
    delete page_accueil_personnel;
    delete ui;
    //qDebug() << "Destruction  mainWindow\n";
}

