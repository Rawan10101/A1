// login.cpp
#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "users.h"

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    dialogWindow = new Welcome(this);
    registerWindow = new Register(this);
}

login::~login()
{
    delete ui;
    delete dialogWindow;
}

void login::on_Login_clicked()
{
    QString name = ui->name->text();
    QString password = ui->password->text();


    bool nameExists = false;
    bool passwordExists = false;
    const int arraySize = usersCount;

    for (int i = 0; i < arraySize; i++) {
        if (usernames[i] == name) {
            nameExists = true;
            if (passwords[i] == password) {
                passwordExists = true;
                break;
            }
        }
    }

    if (nameExists && passwordExists) {
       // dialogWindow->setName(name);
       // dialogWindow->setPassword(password);
        dialogWindow->show();
        this->hide();
    } else {
        ui->label_3->setText("Register");
    }
}


void login::on_Regitster_clicked()
{
    QString name = ui->name->text();
    QString password = ui->password->text();

    bool nameExists = false;
    bool passwordExists = false;
    const int arraySize = usersCount;

    for (int i = 0; i < arraySize; i++) {
        if (usernames[i] == name) {
            nameExists = true;
            if (passwords[i] == password) {
                passwordExists = true;
                break;
            }
        }
    }

    if (!nameExists && !passwordExists) {
        registerWindow->show();
        this->hide();
        dialogWindow->setName(ui->name->text());
    }
    else
        ui->label_3->setText("Login");
}


void login::on_label_3_linkActivated(const QString &link)
{

}

