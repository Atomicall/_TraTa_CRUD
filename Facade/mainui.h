#ifndef MAINUI_H
# define MAINUI_H
#include <QDialog>

namespace Ui {
  class MainUI;
}

class DBFacade;

class MainUI : public QDialog {
  Q_OBJECT
public:
  explicit MainUI(QWidget *parent = 0);
  ~MainUI();
public slots:
  void on_carAdd();
  void on_carRem();

  void on_seatAdd();
  void on_seatRem();
private:
  Ui::MainUI *m_ui;
  DBFacade* m_db;
};

#endif // MAINUI_H
