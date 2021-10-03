#include "dbfacade_int.h"

DBFacade_int::DBFacade_int(QObject* parent) {
    qDebug()<<"parent";
}

DBFacade_int::~DBFacade_int()
{
    qDebug()<<"parent dest";
    mDB.close();
    mDB.removeDatabase(mDB.defaultConnection);
    if (mQuery) delete mQuery;
}

void DBFacade_int::exec(QString w)
{
    mQuery->clear();
    mRec.clear();

    if (false == mQuery->exec(w))
      qDebug() << "Unable to execute query - exiting" << mQuery->lastError() << " : " << mQuery->lastQuery();
    mRec = mQuery->record();
}


QString DBFacade_int::qs(QString w)
{
    return "'" + w + "'";
}

void DBFacade_int::intiDB(QString db_path)
{
    mDB = QSqlDatabase::addDatabase("QSQLITE");
    mDB.setDatabaseName(db_path);
    if (!mDB.open()) {
        qDebug()<<mDB.lastError();
        qDebug()<<"not open";
        throw "db" + db_path +  " failed to open";
    }
}

void DBFacade_int::initQuery()
{
    mQuery = new QSqlQuery(mDB);
}
