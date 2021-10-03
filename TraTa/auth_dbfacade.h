#ifndef AUTH_DBFACADE_H
#define AUTH_DBFACADE_H

#include "dbfacade_int.h"
#include "auth_dao.h"

class Auth_dbFacade : public DBFacade_int
{
public:
    explicit Auth_dbFacade(QString db_path, QString table_name, QObject *parent = nullptr);
    QVariant check (Auth_dao w);
protected:
    virtual void addRecord() override;
    QString mTableName;
    Auth_dao auth_storage;
    QString qStr;


};

#endif // AUTH_DBFACADE_H
