#include "show_on_form.h"
#include "ui_show_on_form.h"

Show_On_form::Show_On_form(QWidget *parent, TableView_dbFacade<TT_Dao>* mdbF) :
    QWidget(parent, Qt::Dialog),
    ui(new Ui::Show_On_form)
{
    ui->setupUi(this);
    this->setWindowTitle("Show on special day and time");
    mTableModel = new QSqlQueryModel (this);
    mainDB_facade = mdbF;
    ui->tableView->setModel(mTableModel);
    ui->tableView->hideColumn(0);
//    ui->tableView->resizeColumnsToContents();
//    ui->tableView->horizontalHeader()->setStretchLastSection(1);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}


Show_On_form::~Show_On_form()
{
    if (mTableModel) delete mTableModel;
    delete ui;
}

void Show_On_form::on_dateEdit_dateChanged(const QDate &date)
{
    mDate = date.toString(Qt::ISODate);
}


void Show_On_form::on_timeEdit_timeChanged(const QTime &time)
{
    mTime = time.toString(Qt::ISODate);
}


void Show_On_form::on_pushButton_clicked()
{
    if (mDate.isEmpty() || mTime.isEmpty()) return;
    mTableModel->clear();
    q_str = " SELECT * FROM "+ mainDB_facade->get_mTableName() +
            " WHERE date_dep = '%1' AND time_dep = '%2'";
    q_str = q_str.arg(mDate);
    q_str = q_str.arg(mTime);
    qDebug()<< q_str;
    QSqlQuery q = mainDB_facade->execAndGetQuery(q_str);
    if (!q.isValid()) return;
    mTableModel->setQuery(q);
}

