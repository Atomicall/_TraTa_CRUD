#include "auth_dbfacade.h"

Auth_dbFacade::Auth_dbFacade(QString db_path, QString table_name, QObject *parent)
{
    mTableName = table_name;
    qStr = " SELECT * FROM "+ mTableName +
            " WHERE login = '%1'";
    intiDB(db_path);
    initQuery();
}

std::pair<int, int> Auth_dbFacade::checkInfo(Auth_dao w)
{

    exec(qStr.arg(w.getLogin())); // get info from db by login
    //qDebug()<<mRec.value(0)<<" "<<mRec.value(1)<<" "<<mRec.value(2);
    std::pair<int, int> result;

    if (w.getLogin() == mRec.value("login").toString() &&
             w.getPassword() == mRec.value("password").toString()){
        result.first = DB_RESULT::SUCESS;
        result.second = ( (1==mRec.value("isAdmin").toBool()) ? DB_RESULT::ADMIN :
                                                                DB_RESULT::NOTADMIN);
        return result;
    }
    else {
        result.first = DB_RESULT::FAIL;
        result.second = DB_RESULT::NOTADMIN;
        return result;
    }


}

void Auth_dbFacade::addRecord()
{

}


