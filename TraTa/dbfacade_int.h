#ifndef DBFACADE_INT_H
#define DBFACADE_INT_H


#include <QObject>
#include <QtSql/QtSql>

class DBFacade_int : public QObject
{
    Q_OBJECT
public:
    DBFacade_int(QObject* parent = nullptr);
    virtual ~DBFacade_int();
protected:
    virtual void exec(QString w) = 0;
    QString qs(QString w);
    virtual void addRecord() = 0;

    QSqlDatabase mDB;
    QSqlQuery* mQuery = nullptr;
    QSqlRecord mRec;
    QSqlTableModel* mTableModel;

};











#endif // DBFACADE_INT_H
