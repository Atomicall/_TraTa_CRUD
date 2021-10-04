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
    QSqlQuery execAndGetQuery(QString& w);
    QSqlTableModel* getMTableModel(){return mTableModel;}
    QString get_mTableName (){return mTableName;};
protected:
    QTableView* mTableview;
    QString mTableName;
    virtual void addRecord() override;
};

template<typename T>
TableView_dbFacade<T>::TableView_dbFacade(QTableView* tableview, QString db_path, QString table_name, uint8_t edit_strategy, QObject* parent)
{
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
    mTableModel->setHeaderData(1, Qt::Horizontal, tr("Departue Place"));
    mTableModel->setHeaderData(2, Qt::Horizontal, tr("Arrival Place"));
    mTableModel->setHeaderData(3, Qt::Horizontal, tr("Departue Date"));
    mTableModel->setHeaderData(4, Qt::Horizontal, tr("Departue Time"));
    mTableModel->setHeaderData(5, Qt::Horizontal, tr("Trip Time"));
    mTableModel->setHeaderData(6, Qt::Horizontal, tr("Seats Amount"));
    mTableModel->setHeaderData(7, Qt::Horizontal, tr("Seats Free"));
    mTableModel->setHeaderData(8, Qt::Horizontal, tr("Cost"));
    mTableModel->setEditStrategy(static_cast<QSqlTableModel::EditStrategy>(edit_strategy));
    mTableview = tableview;
    mTableview->setModel(mTableModel);

    //mTableModel->removeColumn(0);
}


template<typename T>
TableView_dbFacade<T>::~TableView_dbFacade()
{
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
    mRec.setValue(8, m.getCost());
    if (mTableModel->insertRecord(-1, mRec)) {
        }
    else {
        qDebug()<< "Failed to insert new record";
    }
}

template<typename T>
void TableView_dbFacade<T>::addRecord(){}
template<typename T>
QSqlQuery TableView_dbFacade<T>::execAndGetQuery(QString& w)
{
    mQuery->clear();
    mRec.clear();
    if (false == mQuery->exec(w))
      qDebug() << "Unable to execute query - exiting" << mQuery->lastError() << " : " << mQuery->lastQuery();
    if (!mQuery->isActive()){
        qDebug() << "Query is inactive after executing";
    }
    mQuery->next();
    return *mQuery;
}

#endif // TABLEVIEW_DBFACADE_H
