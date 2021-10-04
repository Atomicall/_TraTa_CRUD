#include "da_window.h"
#include "ui_da_window.h"

Da_window::Da_window(QWidget *parent, bool isAdmin) : QMainWindow(0), ui(new Ui::Da_window)
{
    ui->setupUi(this);
    this->setWindowTitle("Timetable");
    mIsAdmin = isAdmin;
    ttDb = new TableView_dbFacade<TT_Dao> (this->ui->DB_Table, "D:\\timetable.db", "Timetable", Ui::EditStrategy::OnManualSubmit, this);
    ui->DB_Table->hideColumn(0);
    ui->DB_Table->setEditTriggers(QAbstractItemView::DoubleClicked);
    ui->DB_Table->setSortingEnabled(1);
//    ui->DB_Table->resizeColumnsToContents();
//    ui->DB_Table->horizontalHeader()->setStretchLastSection(1);
    ui->DB_Table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->DB_Table->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->DB_Table->horizontalHeader()->setSortIndicatorShown(0);
    _connect();
    dectivateEdit();
    Sort_By_ComboBox_fill();
    set_DB_Status("Data loaded");
    set_Current_Status("Info loaded");
}

Da_window::~Da_window()
{
    if (ttDb) delete ttDb;
    delete ui;
}

void Da_window::_connect()
{
 connect(this->ui->DB_Table->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(clr_combobox(int)));
}

void Da_window::dectivateEdit()
{
    if (!mIsAdmin){
        ui->Add_Button->setEnabled(0);
        ui->Delete_Button->setEnabled(0);
        ui->Submit_All->setEnabled(0);
        ui->Revert_Button->setEnabled(0);
        ui->DB_Table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
}

void Da_window::addRecord(TT_Dao &w)
{
   ttDb->addRecord(w);
}

void Da_window::Sort_By_ComboBox_fill()
{
    QStringList headers;
    for(int i = 1; i < ui->DB_Table->model()->columnCount(); i++)
    {
      headers.append(ui->DB_Table->model()->headerData(i, Qt::Horizontal).toString());
    }
    ui->Sort_By_ComboBox->addItems(headers);
    ui->Sort_By_ComboBox->setCurrentIndex(-1);
}

void Da_window::set_Current_Status(QString w)
{
    ui->status_LineEdit->setText(w);

}

void Da_window::set_DB_Status(QString w)
{
    ui->DB_Status_LineEdit->setText(w);
}


void Da_window::on_Submit_All_clicked()
{
     ttDb->getMTableModel()->submitAll();
     set_Current_Status("All changes saved");
     set_DB_Status("All changes saved");
}



void Da_window::on_Revert_Button_clicked()
{
    ttDb->getMTableModel()->revertAll();
    set_Current_Status("All changes revert from Database");
    set_DB_Status("Data from DB loaded");
}

void Da_window::on_Add_Button_clicked()
{
    Add_Form* add_f = new Add_Form(this);
    connect(add_f, SIGNAL(tt_dao_ready(TT_Dao)), this, SLOT(recieve_tt_dao(TT_Dao)));    add_f->show();
    add_f->setAttribute(Qt::WA_DeleteOnClose);
    add_f->raise();
    add_f->setFocus();
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
       set_Current_Status("Data Removed");
       set_DB_Status("Changes NOT saved");
   }   
}

void Da_window::recieve_tt_dao(TT_Dao arg1)
{
    addRecord(arg1);
    set_Current_Status("Data Added");
    set_DB_Status("Changes NOT saved");
}

void Da_window::on_Sort_By_ComboBox_currentIndexChanged(int index)
{
    if (-1!=ui->Sort_By_ComboBox->currentIndex()){
    ui->DB_Table->sortByColumn(index+1, Qt::AscendingOrder);
    set_Current_Status("Sorted By: " + ui->Sort_By_ComboBox->currentText());
    }
    else {
       set_Current_Status("Sorted");
    }
}


void Da_window::on_Show_On_clicked()
{
    Show_On_form* s = new Show_On_form (this, ttDb);
    s->setAttribute(Qt::WA_DeleteOnClose);
    s->show();
}

void Da_window::clr_combobox(int i)
{
    ui->Sort_By_ComboBox->setCurrentIndex(-1);
}


