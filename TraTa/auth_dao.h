#ifndef AUTH_DAO_H
#define AUTH_DAO_H
#include <QString>

class Auth_dao
{
public:
    Auth_dao();
    const QString &getLogin() const;
    void setLogin(const QString &newLogin);
    const QString &getPassword() const;
    void setPassword(const QString &newPassword);
private:
QString login;
QString password;
};

#endif // AUTH_DAO_H
