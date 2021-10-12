#ifndef AUTHENTICATION_DIALOG_H
#define AUTHENTICATION_DIALOG_H

#include <QDialog>
#include "auth_dto.h"
#include "auth_dbfacade.h"
#include "da_window.h"

namespace Ui {
class Authentication_dialog;
enum DB_RESULT{
    NOTADMIN = 0,
    ADMIN,
    SUCESS,
    FAIL
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
    Auth_dbFacade* authDB;
    Auth_dao mAuthInfo;
    Da_window* mainwindow = nullptr;

private slots:
    void on_DialogButtonBox_accepted();
    void on_DialogButtonBox_rejected();
};

#endif // AUTHENTICATION_DIALOG_H
