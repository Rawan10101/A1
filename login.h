// login.h
#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "welcome.h"
#include "register.h"

#include "users.h"
QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

private slots:

    void on_Login_clicked();

    void on_Regitster_clicked();


    void on_label_3_linkActivated(const QString &link);

private:
    Ui::login *ui;
    Welcome *dialogWindow;
    Register* registerWindow;

};

#endif // LOGIN_H
