#ifndef PAGELOGIN_H
#define PAGELOGIN_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

namespace Ui {
class PageLogin;
}

class PageLogin : public QWidget
{
    Q_OBJECT

protected:
    QPushButton *validation_boutton;
    QLineEdit *id;
    QLineEdit *mdp;

public:
    explicit PageLogin(QWidget *parent = nullptr);
    ~PageLogin();

public slots:
    void handle_validation();

private:
    Ui::PageLogin *ui;
};

#endif // PAGELOGIN_H
