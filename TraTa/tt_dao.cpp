#include "tt_dao.h"

TT_Dao::TT_Dao() // Timetable dao
{


}

const QString &TT_Dao::getDepartue() const
{
    return departue;
}

void TT_Dao::setDepartue(const QString &newDepartue)
{
    departue = newDepartue;
}

const QString &TT_Dao::getArrival() const
{
    return arrival;
}

void TT_Dao::setArrival(const QString &newArrival)
{
    arrival = newArrival;
}

const QString &TT_Dao::getDate_dep() const
{
    return date_dep;
}

void TT_Dao::setDate_dep(const QString &newDate_dep)
{
    date_dep = newDate_dep;
}

const QString &TT_Dao::getTime_dep() const
{
    return time_dep;
}

void TT_Dao::setTime_dep(const QString &newTime_dep)
{
    time_dep = newTime_dep;
}

const QString &TT_Dao::getTravel_time() const
{
    return travel_time;
}

void TT_Dao::setTravel_time(const QString &newTravel_time)
{
    travel_time = newTravel_time;
}

const QString &TT_Dao::getSeat_amount() const
{
    return seat_amount;
}

void TT_Dao::setSeat_amount(const QString &newSeat_amount)
{
    seat_amount = newSeat_amount;
}

const QString &TT_Dao::getSeat_free() const
{
    return seat_free;
}

void TT_Dao::setSeat_free(const QString &newSeat_free)
{
    seat_free = newSeat_free;
}

bool TT_Dao::checkIsReady()
{
    if (departue.isEmpty()
            || arrival.isEmpty()
            || date_dep.isEmpty()
            ||time_dep.isEmpty()
            || travel_time.isEmpty()
            || seat_amount.isEmpty()
            || seat_free.isEmpty()) return 0;
    else return 1;

}
