#include "da_window.h"
#include "ui_da_window.h"

Da_window::Da_window(QWidget *parent) : QMainWindow(0), ui(new Ui::Da_window)
{
    //setupUi (this);
    //retranslateUi(this);
    ui->setupUi(this);

    ttDb = new DBFacade<TT_Dao> (this->ui->DB_Table, "D:\\timetable.db", "Timetable", Ui::EditStrategy::OnManualSubmit, this);
    ui->DB_Table->hideColumn(0);
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
//  connect(this->ui->Add_Button, SIGNAL(clicked()), this, SLOT(on_Add_Button_clicked()));
//  connect(this->ui->Submit_All, SIGNAL(clicked()), this, SLOT(on_Submit_All_clicked()));
//  connect(this->ui->Delete_Button, SIGNAL(clicked()), this, SLOT(on_Delete_Button_clicked()));

//  connect(this->ui->Revert_Button, SIGNAL(clicked()), this, SLOT(on_Revert_Button_clicked()));

}

void Da_window::activateButtons()
{

}

void Da_window::addRecord(TT_Dao &w)
{
   ttDb->addRecord(w);

}


void Da_window::on_Submit_All_clicked()
{
     ttDb->getMTableModel()->submitAll();
}



void Da_window::on_Revert_Button_clicked()
{
    ttDb->getMTableModel()->revertAll();
}


void Da_window::on_Add_Button_clicked()
{
    Add_Form* add_f = new Add_Form(this);
    connect(add_f, SIGNAL(tt_dao_ready(TT_Dao)), this, SLOT(recieve_tt_dao(TT_Dao)));    add_f->show();
    add_f->raise();
    //this->hide();
    add_f->setFocus();

   // connect(add_f, SIGNAL(Quit))
}


void Da_window::on_Delete_Button_clicked()
{
   QModelIndexList indexes = ui->DB_Table->selectionModel()->selectedRows();
//   if (indexes.size() == ttDb->getMTableModel()->rowCount()) {
//       qDebug()<<"Unable to delete all rows";
//       return;
//   }
   while (!indexes.isEmpty()) {
       ui->DB_Table->model()->removeRows(indexes.last().row(), 1);
       indexes.removeLast();
   }
}

void Da_window::recieve_tt_dao(TT_Dao arg1)
{
    qDebug()<<"tt_dao recieved";
    addRecord(arg1);
}

