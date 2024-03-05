#include "welcome.h"
#include "ui_welcome.h"
#include "login.h"

Welcome::Welcome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Welcome)
{
    //QString agestr=QString::number(ages);
    ui->setupUi(this);
    on_pushButton_clicked(); // Automatically trigger the login button


    //imageLabel = new QLabel(this);
    //imageLabel->setObjectName(QStringLiteral("imageLabel"));

   // imageLabel->setGeometry(QRect(10, 10, 200, 200));
   QPixmap pix("file:///C:/Users/HP/Downloads/360_F_176984023_8I82qQPmKn8TqNAZXIYMCSiwccoUiPBg.jpg");
    int w=ui->image->width();
   int h=ui->image->height();
    ui->image->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));

    //imageLabel->setScaledContents(true);
}

Welcome::~Welcome()
{
    delete ui;
}
void Welcome::setAge(const QString &age)
{
    m_age = age;

}
void Welcome::setName(const QString &name)
{
    m_name = name;

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

void Welcome::on_pushButton_clicked()
{
    close();
}


void Welcome::on_Hello_linkActivated(const QString &link)
{
    ui->Hello->setText("Hello " + m_name + " "+ m_age);

}

