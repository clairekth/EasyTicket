#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constantes.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Initialisation des données
    stack = ui->stackedWidget;
    page_login = new PageLogin;

    //Insertion des différentes pages
    stack->insertWidget(PAGE_LOGIN , page_login);

    //Set l'index actuelle sur la page de login
    stack->setCurrentIndex(PAGE_LOGIN);

}

MainWindow::~MainWindow()
{
    delete ui;
}

