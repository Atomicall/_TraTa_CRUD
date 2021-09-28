/********************************************************************************
** Form generated from reading UI file 'da_window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DA_WINDOW_H
#define UI_DA_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Da_window
{
public:
    QWidget *centralwidget;
    QGroupBox *MainGroupBox;
    QGroupBox *DBGroupBox;
    QTableView *DB_Table;
    QGroupBox *DB_ControlGroupBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Add_Button;
    QPushButton *Delete_Button;
    QSpacerItem *horizontalSpacer;
    QPushButton *Submit_All;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Da_window)
    {
        if (Da_window->objectName().isEmpty())
            Da_window->setObjectName(QString::fromUtf8("Da_window"));
        Da_window->resize(630, 465);
        centralwidget = new QWidget(Da_window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        MainGroupBox = new QGroupBox(centralwidget);
        MainGroupBox->setObjectName(QString::fromUtf8("MainGroupBox"));
        MainGroupBox->setGeometry(QRect(0, 0, 619, 409));
        sizePolicy.setHeightForWidth(MainGroupBox->sizePolicy().hasHeightForWidth());
        MainGroupBox->setSizePolicy(sizePolicy);
        MainGroupBox->setFlat(true);
        DBGroupBox = new QGroupBox(MainGroupBox);
        DBGroupBox->setObjectName(QString::fromUtf8("DBGroupBox"));
        DBGroupBox->setGeometry(QRect(10, 20, 671, 401));
        DBGroupBox->setFlat(true);
        DBGroupBox->setCheckable(false);
        DB_Table = new QTableView(DBGroupBox);
        DB_Table->setObjectName(QString::fromUtf8("DB_Table"));
        DB_Table->setGeometry(QRect(10, 20, 591, 291));
        DB_ControlGroupBox = new QGroupBox(DBGroupBox);
        DB_ControlGroupBox->setObjectName(QString::fromUtf8("DB_ControlGroupBox"));
        DB_ControlGroupBox->setGeometry(QRect(10, 310, 581, 71));
        DB_ControlGroupBox->setFlat(true);
        horizontalLayoutWidget = new QWidget(DB_ControlGroupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 9, 581, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Add_Button = new QPushButton(horizontalLayoutWidget);
        Add_Button->setObjectName(QString::fromUtf8("Add_Button"));

        horizontalLayout->addWidget(Add_Button);

        Delete_Button = new QPushButton(horizontalLayoutWidget);
        Delete_Button->setObjectName(QString::fromUtf8("Delete_Button"));

        horizontalLayout->addWidget(Delete_Button);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Submit_All = new QPushButton(horizontalLayoutWidget);
        Submit_All->setObjectName(QString::fromUtf8("Submit_All"));

        horizontalLayout->addWidget(Submit_All);

        Da_window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Da_window);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 630, 23));
        Da_window->setMenuBar(menubar);
        statusbar = new QStatusBar(Da_window);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Da_window->setStatusBar(statusbar);

        retranslateUi(Da_window);

        QMetaObject::connectSlotsByName(Da_window);
    } // setupUi

    void retranslateUi(QMainWindow *Da_window)
    {
        Da_window->setWindowTitle(QApplication::translate("Da_window", "Da_window", nullptr));
        MainGroupBox->setTitle(QApplication::translate("Da_window", "Main", nullptr));
        DBGroupBox->setTitle(QApplication::translate("Da_window", "DB", nullptr));
        DB_ControlGroupBox->setTitle(QApplication::translate("Da_window", "DB_Buttons", nullptr));
        Add_Button->setText(QApplication::translate("Da_window", "Add Record", nullptr));
        Delete_Button->setText(QApplication::translate("Da_window", "Delete Record", nullptr));
        Submit_All->setText(QApplication::translate("Da_window", "Submit_All", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Da_window: public Ui_Da_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DA_WINDOW_H
