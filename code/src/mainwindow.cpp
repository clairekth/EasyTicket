#include "mainwindow.h"
#include "ui_mainwindow.h"
<<<<<<< HEAD
=======
#include "include/constantes.h"
>>>>>>> 6659fb35b76d3156d828a44ed8fad442682fca6d

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Initialisation des données
    stack = ui->stackedWidget;
    page_login = new PageLogin;

    //Insertion des différentes pages
    stack->insertWidget(LOGIN_PAGE, page_login);

    //Set l'index actuelle sur la page de login
    stack->setCurrentIndex(LOGIN_PAGE);

}

MainWindow::~MainWindow()
{
    delete ui;
}

