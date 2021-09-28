#ifndef DBFACADE_H
# define DBFACADE_H
# include <QtSql/QtSql>
# include <QObject>

class QTableView;
class QSqlTableModel;
class DBFacade : public QObject {
  Q_OBJECT
public:
  DBFacade(QTableView* cars, QTableView* seats, QObject *parent = 0);
  virtual ~DBFacade();

  void addCar(QString snum, QString nSeats);
          //!< добавляет вагон
  void remCar(QString snum);
          //!< удаляет вагон
  void addSeat(QString num, QString snCar);
          //!< добавляет место
  void remSeat(QString snCar, QString num);
          //!< удаляет место
protected:
  void exec(QString);
        //!< пытается выполнить запрос
  QString qs(QString);
        //!< выделяет строку одинарными кавычками

  QSqlDatabase m_db;
        //!< база данных
  QSqlQuery *m_query;
        //!< запрос к базе
  QSqlRecord m_rec;
        //!< строка таблицы (ответ на запрос)
  QSqlTableModel *m_carsModel;
        //!< модель таблицы автомобилей
  QSqlTableModel *m_seatsModel;
         //!< модель таблицы посадочных мест
};

#endif // DBFACADE_H
