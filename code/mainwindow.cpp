#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Initialisation des données
    stack = ui->stackedWidget;
    page_login = new PageLogin(stack);
    page_accueil_client = new PageAccueilClient(stack);

    //Insertion des différentes pages
    stack->insertWidget(LOGIN_PAGE, page_login);
    stack->insertWidget(ACCUEIL_CLIENT_PAGE, page_accueil_client);

    //Set l'index actuelle sur la page de login
    stack->setCurrentIndex(LOGIN_PAGE);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete page_accueil_client;
    delete page_login;
    qDebug() << "Destruction  mainWindow\n";
}

