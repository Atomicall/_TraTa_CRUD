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
#include "tt_dao.h"
#include "TableView_dbFacade.h"
#include "add_form.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Da_window; enum EditStrategy {OnFieldChange, OnRowChange, OnManualSubmit};  }
QT_END_NAMESPACE

class Da_window : public QMainWindow
{
    Q_OBJECT
public:
    explicit Da_window(QWidget *parent = nullptr);
    ~Da_window();
private:
    Ui::Da_window* ui;


void _connect();
void activateButtons();

private:
    TableView_dbFacade<TT_Dao>* ttDb = nullptr;
    bool isAdmin=0;

    void addRecord(TT_Dao& w);


private slots:
     void on_Submit_All_clicked();
    void on_Revert_Button_clicked();
    void on_Add_Button_clicked();
    void on_Delete_Button_clicked();
    void recieve_tt_dao(TT_Dao arg1);
};
#endif // DA_WINDOW_H






