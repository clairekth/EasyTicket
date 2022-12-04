#ifndef PAGEACCUEILPERSONNEL_H
#define PAGEACCUEILPERSONNEL_H

#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>
#include <QLabel>

#include "gestionnairedialogue.h"

namespace Ui {
class PageAccueilPersonnel;
}

class PageAccueilPersonnel : public QWidget
{
    Q_OBJECT

public:
    explicit PageAccueilPersonnel(QStackedWidget *parent = nullptr, GestionnaireDialogue *gestionnaire = nullptr);
    ~PageAccueilPersonnel();
    void setPersonnel(Personnel *pers);

private:
    GestionnaireDialogue *gestionnaire_dialogue;
    QStackedWidget *stack;
    Ui::PageAccueilPersonnel *ui;
    QPushButton *demander_ticket_bouton;
    QPushButton *voir_ticket_bouton;
    QLabel *label;
    Personnel *personnel;
};

#endif // PAGEACCUEILPERSONNEL_H
