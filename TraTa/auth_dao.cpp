#include "auth_dao.h"

Auth_dao::Auth_dao()
{

}

const QString &Auth_dao::getLogin() const
{
    return login;
}

void Auth_dao::setLogin(const QString &newLogin)
{
    login = newLogin;
}

const QString &Auth_dao::getPassword() const
{
    return password;
}

void Auth_dao::setPassword(const QString &newPassword)
{
    password = newPassword;
}
