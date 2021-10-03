#include "authentication_dialog.h"
#include "ui_authentication_dialog.h"

Authentication_dialog::Authentication_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Authentication_dialog)
{
    ui->setupUi(this);
    authDB = new Auth_dbFacade("D:\\timetable.db", "Auth");
}

Authentication_dialog::~Authentication_dialog()
{
    if (mainwindow) delete mainwindow;
    delete ui;
}

bool Authentication_dialog::check()
{
    Auth_dao tmp;
    tmp.setLogin(ui->login_LineEdit->text());
    tmp.setPassword(ui->pass_LineEdit->text());
    authDB->check(tmp);
    //return 1;

}

void Authentication_dialog::on_DialogButtonBox_accepted()
{
    if (check()){
        mainwindow = new Da_window (this);
        mainwindow->show();
        this->hide();
    }
    else{
        qDebug() << "Auth not ok";
    }
}


void Authentication_dialog::on_DialogButtonBox_rejected()
{
    exit(0);
}


void Authentication_dialog::on_remember_CB_toggled(bool checked)
{

}

