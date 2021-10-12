#ifndef TT_DTO_H
#define TT_DTO_H
#include <QString>


class TT_Dao
{
public:
    TT_Dao();

    const QString &getDepartue() const;
    void setDepartue(const QString &newDepartue);
    const QString &getArrival() const;
    void setArrival(const QString &newArrival);
    const QString &getDate_dep() const;
    void setDate_dep(const QString &newDate_dep);
    const QString &getTime_dep() const;
    void setTime_dep(const QString &newTime_dep);
    const QString &getTravel_time() const;
    void setTravel_time(const QString &newTravel_time);
    const QString &getSeat_amount() const;
    void setSeat_amount(const QString &newSeat_amount);
    const QString &getSeat_free() const;
    void setSeat_free(const QString &newSeat_free);
    bool checkIsReady();
    const QString &getCost() const;
    void setCost(const QString &newCost);
protected:
    QString departue;
    QString arrival;
    QString date_dep;
    QString time_dep;
    QString travel_time;
    QString seat_amount;
    QString seat_free;
    QString cost;
};

#endif // TT_DTO_H
