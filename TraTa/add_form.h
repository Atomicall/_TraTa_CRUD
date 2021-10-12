#ifndef ADD_FORM_H
#define ADD_FORM_H

#include <QWidget>
#include <QAbstractButton>
#include "tt_dto.h"

namespace Ui {
class Add_Form;
}

class Add_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Add_Form(QWidget *parent = nullptr);
    ~Add_Form();

signals:
    void tt_dao_ready(TT_Dao tt_storage);

private slots:
    void on_Dep_LineEdit_textChanged(const QString &arg1);
    void on_Arrival_LineEdit_textChanged(const QString &arg1);
    void on_Trave_lTime_LineEdit_textChanged(const QString &arg1);
    void on_Seat_Amount_LineEdit_textChanged(const QString &arg1);
    void on_Seat_Free_Lineedit_textChanged(const QString &arg1);
    void on_Dep_Date_dateEdit_dateChanged(const QDate &date);
    void on_Dep_Time_LineEdit_timeChanged(const QTime &time);
    void on_Cost_LineEdit_textChanged(const QString &arg1);
    void on_Discard_Button_clicked();
    void on_Save_Button_clicked();
private:
    Ui::Add_Form *ui;
    TT_Dao tt_storage;
};

#endif // ADD_FORM_H
