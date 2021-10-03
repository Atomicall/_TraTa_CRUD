#ifndef AUTHENTICATION_DIALOG_H
#define AUTHENTICATION_DIALOG_H

#include <QDialog>
#include "auth_dao.h"
#include "dbfacade.h"
#include "da_window.h"

namespace Ui {
class Authentication_dialog;
enum ISADMIN{
    NOTADMIN = 0,
    ADMIN
};
}

class Authentication_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Authentication_dialog(QWidget *parent = nullptr);
    ~Authentication_dialog();


private:
    Ui::Authentication_dialog *ui;
protected:
    DBFacade<Auth_dao>* authDB;
    Auth_dao mAuthInfo;
    Da_window* mainwindow = nullptr;


    bool check();

private slots:
    void on_DialogButtonBox_accepted();
    void on_DialogButtonBox_rejected();
    void on_remember_CB_toggled(bool checked);
};

#endif // AUTHENTICATION_DIALOG_H
