#ifndef TABLEVIEW_DBFACADE_H
#define TABLEVIEW_DBFACADE_H

#include "dbfacade_int.h"

#include <QTableView>

template <typename T>
class TableView_dbFacade : public DBFacade_int
{
public:
    TableView_dbFacade(QTableView* tableview, QString db_path, QString table_name, uint8_t edit_strategy, QObject* parent);
    void initTableModelAndView(QTableView* tableview, uint8_t edit_strategy);
    virtual ~TableView_dbFacade();
    virtual void addRecord (T& m);  // virtual void addRecord (TT_Dao m) override
    QSqlTableModel* getMTableModel(){return mTableModel;}
protected:

    QTableView* mTableview;
    QString mTableName;
    virtual void addRecord() override;
};

template<typename T>
TableView_dbFacade<T>::TableView_dbFacade(QTableView* tableview, QString db_path, QString table_name, uint8_t edit_strategy, QObject* parent)
{
    qDebug()<<"DBFacade child";
    //this->parent()->setParent(parent);
    mTableName = table_name;
    intiDB(db_path);
    initQuery();
    qDebug() << "Tables::" <<mDB.tables();
    if (false == mDB.tables().contains(mTableName))
    {
        qDebug()<<"No such table in " +db_path;
        return;
    }
    initTableModelAndView(tableview, edit_strategy);
}



template<typename T>
void TableView_dbFacade<T>::initTableModelAndView(QTableView* tableview, uint8_t edit_strategy)
{
    mTableModel = new QSqlTableModel (this, mDB);
    mTableModel->setTable(mTableName);
    mTableModel->select();
    mTableModel->setEditStrategy(static_cast<QSqlTableModel::EditStrategy>(edit_strategy));
    mTableview = tableview;
    mTableview->setModel(mTableModel);
    //mTableModel->removeColumn(0);
}


template<typename T>
TableView_dbFacade<T>::~TableView_dbFacade()
{
    qDebug()<<"child destru";

}

template<typename T>
void TableView_dbFacade<T>::addRecord(T& m)
{
    mRec.clear();
    mRec = mTableModel->record();
    mRec.setValue(1, m.getDepartue());
    mRec.setValue(2, m.getArrival());
    mRec.setValue(3, m.getDate_dep());
    mRec.setValue(4, m.getTime_dep());
    mRec.setValue(5, m.getTravel_time());
    mRec.setValue(6, m.getSeat_amount());
    mRec.setValue(7, m.getSeat_free());
    if (mTableModel->insertRecord(-1, mRec)) {
            qDebug() << "New record inserted";
        }
    else {
        qDebug()<< "Failed to insert new record";
    }
}

template<typename T>
void TableView_dbFacade<T>::addRecord()
{

}

#endif // TABLEVIEW_DBFACADE_H
