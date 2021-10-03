#include "da_window.h"


Da_window::Da_window(QWidget *parent) : QMainWindow(0)
{
    setupUi (this);
    retranslateUi(this);
    ttDb = new DBFacade<TT_Dao> (this->DB_Table, "D:\\timetable.db", "Timetable", Ui::EditStrategy::OnFieldChange, this);
    _connect();
    activateButtons();
}

Da_window::~Da_window()
{
    if (ttDb) delete ttDb;
    // To do: delete ui
}

void Da_window::_connect()
{
  connect(this->Add_Button, SIGNAL(clicked()), this, SLOT(on_Add_clicked()));
  connect(this->Submit_All, SIGNAL(clicked()), this, SLOT(on_Sybmit_All_clicked()));
  connect(this->Delete_Button, SIGNAL(clicked()), this, SLOT(on_Delete_clicked()));
}

void Da_window::activateButtons()
{

}

void Da_window::on_Add_clicked()
{

}

void Da_window::on_Submit_All_clicked()
{
    ttDb->getMTableModel()->submitAll();
}


void Da_window::on_Delete_clicked()
{

}
