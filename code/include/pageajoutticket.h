#ifndef PAGEAJOUTTICKET_H
#define PAGEAJOUTTICKET_H

#include <QWidget>

namespace Ui {
class PageAjoutTicket;
}

class PageAjoutTicket : public QWidget
{
    Q_OBJECT

public:
    explicit PageAjoutTicket(QWidget *parent = nullptr);
    ~PageAjoutTicket();

private slots:
    void on_bouton_ajout_ticket_clicked();

private:
    Ui::PageAjoutTicket *ui;
};

#endif // PAGEAJOUTTICKET_H
