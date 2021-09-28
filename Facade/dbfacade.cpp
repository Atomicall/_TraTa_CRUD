#include "dbfacade.h"
#include <QTableView>
/////////////////////////////////SEAT
void DBFacade::addSeat(QString num, QString carID) {
  exec(tr("SELECT * FROM cars WHERE id = ") + carID);
  m_query->first();
  if (m_query->value(m_rec.indexOf("nseat")).toString().toInt() < num.toInt())
    return;
  try {
    exec(tr("INSERT INTO seats (carID, nseat) VALUES(") + carID + "," + num + ")");
  }
  catch(...) {
    return;
  }
  m_seatsModel->select();
}

void DBFacade::remSeat(QString carID, QString num) {
  exec(tr("DELETE FROM seats WHERE carID = ") + carID + " AND nseat = " + num);
  m_seatsModel->select();
}

/////////////////////////////////CAR
void DBFacade::addCar(QString id, QString nSeats) {
  try {
    exec(tr("INSERT INTO cars (id, nseat) VALUES (")
      + id + ',' + nSeats + ")");
    m_carsModel->select();
  }
  catch(...) { return; }
}

void DBFacade::remCar(QString id) {
  exec(tr("DELETE FROM seats WHERE carID = ") + id);
  exec(tr("DELETE FROM cars WHERE id = ") + id);
  m_carsModel->select();
  m_seatsModel->select();
}

////////////////////////////////////////////
DBFacade::DBFacade(QTableView* cars, QTableView* seats, QObject *parent)
  : QObject(parent) {
  m_db = QSqlDatabase::addDatabase("QSQLITE");
  m_db.setDatabaseName("projectsDB");

  if (false == m_db.open())
    throw "can't open/create DB";

  m_query = new QSqlQuery(m_db);
  if (false == m_db.tables().contains("seats"))
    exec("CREATE TABLE seats ("  // таблица посадочных мест
      "carID INTEGER, " // серийный номер вагона
      "nseat INTEGER, " // номер посадочного места
      "PRIMARY KEY (carID, nseat)"
      ");"
    );
  if (false == m_db.tables().contains("cars"))
    exec("CREATE TABLE cars ("  // таблица вагонов
      "id INTEGER PRIMARY KEY, " // серийный номер вагона
      "nseat INTEGER" // количество посадочных мест
      ");"
    );

  m_carsModel = new QSqlTableModel(this, m_db);
  m_carsModel->setTable("cars");
  m_carsModel->select();
  m_carsModel->setEditStrategy(QSqlTableModel::OnFieldChange);
  cars->setModel(m_carsModel);

  m_seatsModel = new QSqlTableModel(this, m_db);
  m_seatsModel->setTable("seats");
  m_seatsModel->select();
  m_seatsModel->setEditStrategy(QSqlTableModel::OnFieldChange);
  seats->setModel(m_seatsModel);
}

DBFacade::~DBFacade() {
  delete m_query;
}

QString DBFacade::qs(QString str) {
  return "'" + str + "'";
}

void DBFacade::exec(QString str) {
  m_query->clear();
  if (false == m_query->exec(str))
    throw tr("DBFacade Error: can't exec : ") + str;
  m_rec = m_query->record();
}
