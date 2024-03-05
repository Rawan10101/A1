#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QButtonGroup>
#include <QDate>
#include <QGroupBox>
#include "welcome.h"


namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_ReType_cursorPositionChanged(int arg1, int arg2);
    void on_pushButton_clicked();
    void on_Register_2_clicked();
    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::Register *ui;
    Welcome *dialogWindow1;
    QButtonGroup *genderButtonGroup;
    QButtonGroup *accountButtonGroup;
    QGroupBox *favComboBox;
    void handleRegistration();
};

#endif // REGISTER_H
