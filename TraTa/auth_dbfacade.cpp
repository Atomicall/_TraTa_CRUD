#include "auth_dbfacade.h"

Auth_dbFacade::Auth_dbFacade(QString db_path, QString table_name, QObject *parent)
{
    mTableName = table_name;
    qStr = " SELECT * FROM "+ mTableName +
            " WHERE login = '%1'";
    intiDB(db_path);
    initQuery();
}

QVariant Auth_dbFacade::check(Auth_dao w)
{
    QVariant v;
    bool correct = 0;
    bool isAdmin = 0;
    exec(qStr.arg(w.getLogin()));






}

void Auth_dbFacade::addRecord()
{

}


