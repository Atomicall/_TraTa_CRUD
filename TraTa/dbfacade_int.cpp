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


QString DBFacade_int::qs(QString w)
{
   return "'" + w + "'";
}
