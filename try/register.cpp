#include "register.h"
#include "ui_register.h"
#include <QMessageBox>
#include "welcome.h"
#include "Users.h"
Register::Register(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Register)
{
    ui->setupUi(this);
    dialogWindow1 = new Welcome(this);
    genderButtonGroup = new QButtonGroup(this);
    accountButtonGroup = new QButtonGroup(this);
dialogWindow1->setName(ui->name2->text());
    genderButtonGroup->addButton(ui->Male);
    genderButtonGroup->addButton(ui->Female);
    accountButtonGroup->addButton(ui->Admin);
    accountButtonGroup->addButton(ui->User);
    favComboBox = ui->Fav;
}

Register::~Register()
{
    delete ui;
    delete dialogWindow1;
}

void Register::on_ReType_cursorPositionChanged(int arg1, int arg2)
{
    QString pass = ui->Pass->text();
    QString retype = ui->ReType->text();


    if (pass != retype) {
        ui->reType->setText("Passwords should be equal");
    } else {
        ui->reType->setText("");
    }
}

void Register::on_pushButton_clicked()
{
    QString pass = ui->Pass->text();
    QString retype = ui->ReType->text();

    if (pass != retype) {
        ui->reType->setText("Passwords should be equal");
    } else {
        ui->reType->setText("");
        hide();
        dialogWindow1->setModal(true);
        dialogWindow1->exec();
    }
}

void Register::on_Register_2_clicked()
{
    QString pass = ui->Pass->text();
    QString retype = ui->ReType->text();
    QString birthDate = ui->Date->text();
    int birthMonth = ui->Month->currentIndex() + 1;
    int birthDay = ui->Day->currentText().toInt();
    int birthYear = ui->Year->currentText().toInt();
    QString gender;
    QString account;
    QString age1 = ui->Age->text();

    bool favChecked = false;
    for (QObject *obj : favComboBox->children()) {
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(obj);
        if (checkBox && checkBox->isChecked()) {
            favChecked = true;
            break;
        }
    }

    QDate currentDate = QDate::currentDate();
    int age = currentDate.year() - birthYear;
    if (currentDate.month() < birthMonth || (currentDate.month() == birthMonth && currentDate.day() < birthDay)) {
        age--;
    }

    if (age <= 12) {
        ui->Age->setText("Age should not be less than 12");
        return;
    } else {
        ui->Age->setText("");
        dialogWindow1->setAge(QString::number(age));
    }

    if (pass != retype) {
        ui->reType->setText("Passwords should be equal");
        return;
    } else {
        ui->reType->setText("");
    }

    if (!favChecked) {
        ui->RegisterLabel->setText("All fields must be filled.");
        return;
    } else {
        ui->RegisterLabel->setText("");
    }

    // If all fields are filled, proceed with registration
    handleRegistration();
}




    void Register::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
    {
        QList<QString> names;
        QString name = ui->name2->text();
        bool nameExists = false;
        const int arraySize = 100; // Define the size of the array

        for (int i = 0; i < arraySize; i++) {
            if (name == usernames[i]) {
                nameExists = true;
                break;
            }
        }

        if (nameExists) {
            ui->Username1->setText("Username already exists");
        } else {
            ui->Username1->setText("");
            dialogWindow1->setName(ui->name2->text());
        }

    }
    void Register::handleRegistration()
    {

        dialogWindow1->show();
        hide();
    }
