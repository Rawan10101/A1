#include "welcome.h"
#include "ui_welcome.h"
#include "login.h"
#include<QPixmap>
#include<QVBoxLayout>
#include<QLabel>

Welcome::Welcome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Welcome)
{


    ui->setupUi(this);
    ui->Hello->setText("Hello admin 20");
    QPixmap pix("C:/Users/HP/Downloads/8728.jpg");
    backgroundLabel = new QLabel(this);
    backgroundLabel->setPixmap(pix);
    backgroundLabel->setScaledContents(true);
    backgroundLabel->setGeometry(110, 70,170 ,170);
    backgroundLabel->lower();
    on_pushButton_clicked();

}
void Welcome::setAge(const QString &age)
{
    m_age = age;

}
void Welcome::setName(const QString &name)
{
    m_name = name;


}


Welcome::~Welcome()
{
    delete ui;
}





void Welcome::setPassword(const QString &password)
{
    m_password = password;

}



void Welcome::on_label_linkActivated(const QString &link)
{

}

void Welcome::on_image_linkActivated(const QString &link)
{
    QPixmap pix("file:///C:/Users/HP/Downloads/360_F_176984023_8I82qQPmKn8TqNAZXIYMCSiwccoUiPBg.jpg");
    int w=ui->image->width();
    int h=ui->image->height();
    ui->image->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));
}


void Welcome::on_Welcome_accepted()
{

}

void Welcome::handleRegistration()
{

}
void Welcome::on_Hello_linkActivated(const QString &link)
{
    ui->Hello->setText("Hello " + m_name + " "+ m_age);
    ui->Hello->show();

}
void Welcome::on_pushButton_clicked()
{
    close();
}




