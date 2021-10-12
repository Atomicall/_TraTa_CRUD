#ifndef DA_WINDOW_H
#define DA_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>
#include <QThread>
#include "tt_dto.h"
#include "tableView_dbFacad.h"
#include "add_form.h"
#include "show_on_form.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Da_window; enum EditStrategy {OnFieldChange, OnRowChange, OnManualSubmit};  }
QT_END_NAMESPACE

class Da_window : public QMainWindow
{
    Q_OBJECT
public:
    explicit Da_window(QWidget *parent = nullptr, bool isAdmin=0);
    ~Da_window();
private:
    Ui::Da_window* ui;


void _connect();
void dectivateEdit();

private:
    TableView_dbFacade<TT_Dao>* ttDb = nullptr;
    bool mIsAdmin;
    void addRecord(TT_Dao& w);
    void Sort_By_ComboBox_fill();
    void set_Current_Status(QString w);
    void set_DB_Status(QString w);
private slots:
    void on_Submit_All_clicked();
    void on_Revert_Button_clicked();
    void on_Add_Button_clicked();
    void on_Delete_Button_clicked();
    void recieve_tt_dao(TT_Dao arg1);
    void on_Sort_By_ComboBox_currentIndexChanged(int index);
    void on_Show_On_clicked();
    void clr_combobox(int i);
};
#endif // DA_WINDOW_H






