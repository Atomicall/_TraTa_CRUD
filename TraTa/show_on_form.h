#ifndef SHOW_ON_FORM_H
#define SHOW_ON_FORM_H

#include <QWidget>
#include "TableView_dbFacade.h"
#include "tt_dao.h"

namespace Ui {
class Show_On_form;
}

class Show_On_form : public QWidget
{
    Q_OBJECT

public:
    explicit Show_On_form(QWidget *parent, TableView_dbFacade<TT_Dao>* = nullptr);
    ~Show_On_form();
private slots:
    void on_dateEdit_dateChanged(const QDate &date);
    void on_timeEdit_timeChanged(const QTime &time);
    void on_pushButton_clicked();
private:
    Ui::Show_On_form *ui;
    QString mDate;
    QString mTime;
    QString q_str;
    QSqlQueryModel* mTableModel= nullptr;
    TableView_dbFacade<TT_Dao>* mainDB_facade;

};

#endif // SHOW_ON_FORM_H
