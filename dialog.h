#ifndef WELCOME_H
#define WELCOME_H

#include <QDialog>
#include <QLabel>

namespace Ui {
class Welcome;
}

class Welcome : public QDialog
{
    Q_OBJECT

public:
    explicit Welcome(QWidget *parent = nullptr);
    ~Welcome();

    void setName(const QString &name);
    void setPassword(const QString &password);
    void setAge(const QString &age);

private slots:
    void on_label_linkActivated(const QString &link);
    void on_image_linkActivated(const QString &link);
    void on_pushButton_clicked();
    void on_Welcome_accepted();
    void handleRegistration();

private:
    Ui::Welcome *ui;
    QLabel *imageLabel;
    QString m_name;
    QString m_password;
    QString m_age;
};

#endif // WELCOME_H
