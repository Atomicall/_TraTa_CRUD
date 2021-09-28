#include <QApplication>
#include <QDebug>
#include "mainui.h"
int main(int argc, char *argv[]) {
  try {
    QApplication a(argc, argv);
    MainUI w;

    w.show();
    return a.exec();
  }
  catch (QString err) {
    qDebug() << err;
  }
}
