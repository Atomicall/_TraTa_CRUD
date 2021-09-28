#include "mainui.h"
#include "ui_mainui.h"
#include "dbfacade.h"

MainUI::MainUI(QWidget *parent)
  : QDialog(parent), m_ui(new Ui::MainUI) {
  m_ui->setupUi(this);

  m_db = new DBFacade(m_ui->carView, m_ui->seatView, this);

  connect(m_ui->carAdd, SIGNAL(clicked()), SLOT(on_carAdd()));
  connect(m_ui->carRem, SIGNAL(clicked()), SLOT(on_carRem()));

  connect(m_ui->seatAdd, SIGNAL(clicked()), SLOT(on_seatAdd()));
  connect(m_ui->seatRem, SIGNAL(clicked()), SLOT(on_seatRem()));
}

void MainUI::on_seatRem() {
  if (m_ui->seatCarID->text().isEmpty() || m_ui->seatNum->text().isEmpty())
    return;
  m_db->remSeat(m_ui->seatCarID->text(), m_ui->seatNum->text());
}

void MainUI::on_seatAdd() {
  if (m_ui->seatCarID->text().isEmpty() || m_ui->seatNum->text().isEmpty())
    return;
  m_db->addSeat(m_ui->seatNum->text(), m_ui->seatCarID->text());
}

void MainUI::on_carRem() {
  if (m_ui->carID->text().isEmpty())
    return;
  m_db->remCar(m_ui->carID->text());
}

void MainUI::on_carAdd() {
  if (m_ui->carID->text().isEmpty() || m_ui->carNSeats->text().isEmpty())
    return;
  m_db->addCar(m_ui->carID->text(), m_ui->carNSeats->text());
}

MainUI::~MainUI() {
  delete m_ui;
}
