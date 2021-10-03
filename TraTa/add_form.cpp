#include "add_form.h"
#include "ui_add_form.h"

Add_Form::Add_Form(QWidget *parent) :
    QWidget(parent, Qt::Dialog),
    ui(new Ui::Add_Form)
{
    ui->setupUi(this);
    connect(ui->Save_Button, SIGNAL(clicked), this, SLOT(on_Save_Button_clicked));
    connect(ui->Discard_Button, SIGNAL(clicked), this, SLOT(on_Discard_Button_clicked));
}

Add_Form::~Add_Form()
{
    delete ui;
}

void Add_Form::on_Dep_LineEdit_textChanged(const QString &arg1)
{
    tt_storage.setDepartue(arg1);
}


void Add_Form::on_Arrival_LineEdit_textChanged(const QString &arg1)
{
    tt_storage.setArrival(arg1);
}



void Add_Form::on_Trave_lTime_LineEdit_textChanged(const QString &arg1)
{
    tt_storage.setTravel_time(arg1);
}


void Add_Form::on_Seat_Amount_LineEdit_textChanged(const QString &arg1)
{
    tt_storage.setSeat_amount(arg1);
}


void Add_Form::on_Seat_Free_Lineedit_textChanged(const QString &arg1)
{
    tt_storage.setSeat_free(arg1);
}


void Add_Form::on_Dep_Date_dateEdit_dateChanged(const QDate &date)
{
    tt_storage.setDate_dep(date.toString(Qt::ISODate));
}


void Add_Form::on_Dep_Time_LineEdit_timeChanged(const QTime &time)
{
    tt_storage.setTime_dep(time.toString(Qt::ISODate));
}




void Add_Form::on_Save_Button_clicked()
{
    if (tt_storage.checkIsReady()) {
        qDebug()<<"TT READY";
        emit tt_dao_ready(tt_storage);
        on_Discard_Button_clicked();
    };
}


void Add_Form::on_Discard_Button_clicked()
{
    this->close();
}

