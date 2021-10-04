#ifndef AUTH_DBFACADE_H
#define AUTH_DBFACADE_H

#include "dbfacade_int.h"
#include "auth_dao.h"
enum DB_RESULT{
    NOTADMIN = 0,
    ADMIN,
    SUCESS,
    FAIL
};

class Auth_dbFacade : public DBFacade_int
{
public:
    explicit Auth_dbFacade(QString db_path, QString table_name, QObject *parent = nullptr);
    std::pair<int, int> checkInfo(Auth_dao w);
protected:
    virtual void addRecord() override;
    QString mTableName;
    Auth_dao auth_storage;
    QString qStr;
};

#endif // AUTH_DBFACADE_H
