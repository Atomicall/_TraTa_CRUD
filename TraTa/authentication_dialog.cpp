#include "authentication_dialog.h"
#include "ui_authentication_dialog.h"

Authentication_dialog::Authentication_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Authentication_dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Authentification");
    authDB = new Auth_dbFacade("D:\\timetable.db", "Auth");
}

Authentication_dialog::~Authentication_dialog()
{
    if (mainwindow) delete mainwindow;
    delete ui;

}

void Authentication_dialog::on_DialogButtonBox_accepted()
{
    if (ui->login_LineEdit->text().isEmpty() || ui->pass_LineEdit->text().isEmpty()) return;
    Auth_dao tmp;
    tmp.setLogin(ui->login_LineEdit->text());
    tmp.setPassword(ui->pass_LineEdit->text());
    std::pair<int, int> result = authDB->checkInfo(tmp);
    if (DB_RESULT::SUCESS == result.first){
        mainwindow = new Da_window (this, (DB_RESULT::ADMIN==result.second)? 1:0 );
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


