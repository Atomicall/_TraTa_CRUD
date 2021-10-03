#ifndef DBFACADE_H
#define DBFACADE_H

#include "dbfacade_int.h"

#include <QTableView>

template <typename T>
class DBFacade : public DBFacade_int
{
public:
    DBFacade(QTableView* tableview, QString db_path, QString table_name, uint8_t edit_strategy, QObject* parent);
    void intiDB(QString db_path);
    void initQuery();
    void initTableModelAndView(QTableView* tableview, uint8_t edit_strategy);
    virtual ~DBFacade();
    virtual void addRecord (T m); // ТУТ ХЗ ПОКА // virtual void addRecord (TT_Dao m) override
    virtual void exec(QString w) override;
    QSqlTableModel* getMTableModel(){return mTableModel;}
protected:
    QTableView* mTableview;
    QString mTableName;
    virtual void addRecord() override;
};

template<typename T>
DBFacade<T>::DBFacade(QTableView* tableview, QString db_path, QString table_name, uint8_t edit_strategy, QObject* parent)
{
    qDebug()<<"DBFacade child";
    //this->parent()->setParent(parent);
    mTableName = table_name;
    intiDB(db_path);
    initQuery();
    if (false == mDB.tables().contains(mTableName))
    {
        //            exec("CREATE TABLE seats ("  // таблица посадочных мест
        //              "carID INTEGER, " // серийный номер вагона
        //              "nseat INTEGER, " // номер посадочного места
        //              "PRIMARY KEY (carID, nseat)"
        //              ");"
        //          );
        qDebug()<<"No such table in " +db_path;
        return;
    }
    initTableModelAndView(tableview, edit_strategy);
}

template<typename T>
void DBFacade<T>::intiDB(QString db_path)
{
    mDB = QSqlDatabase::addDatabase("QSQLITE");
    mDB.setDatabaseName(db_path);
    if (!mDB.open()) {
        qDebug()<<mDB.lastError();
        qDebug()<<"not open";
        throw "db" + db_path + "  " + mTableName + " failed to open";
    }
}

template<typename T>
void DBFacade<T>::initQuery()
{
 mQuery = new QSqlQuery(mDB);
}

template<typename T>
void DBFacade<T>::initTableModelAndView(QTableView* tableview, uint8_t edit_strategy)
{
    mTableModel = new QSqlTableModel (this, mDB);
    mTableModel->setTable(mTableName);
    mTableModel->select();
    mTableModel->setEditStrategy(static_cast<QSqlTableModel::EditStrategy>(edit_strategy));
    mTableview = tableview;
    mTableview->setModel(mTableModel);
}


template<typename T>
void DBFacade<T>::exec(QString w){
    mQuery->clear();
    if (false == mQuery->exec(w))
      throw tr("DBFacade Error: can't exec : ") + w;
    mRec = mQuery->record();
}

template<typename T>
DBFacade<T>::~DBFacade()
{
    qDebug()<<"child destru";

}

template<typename T>
void DBFacade<T>::addRecord(T m)
{

}

template<typename T>
void DBFacade<T>::addRecord()
{

}

#endif // DBFACADE_H
