QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    TableView_dbFacade.cpp \
    add_form.cpp \
    auth_dao.cpp \
    auth_dbfacade.cpp \
    authentication_dialog.cpp \
    dbfacade_int.cpp \
    main.cpp \
    da_window.cpp \
    show_on_form.cpp \
    tt_dao.cpp

HEADERS += \
    TableView_dbFacade.h \
    add_form.h \
    auth_dao.h \
    auth_dbfacade.h \
    authentication_dialog.h \
    da_window.h \
    dbfacade_int.h \
    show_on_form.h \
    tt_dao.h

FORMS += \
    add_form.ui \
    authentication_dialog.ui \
    da_window.ui \
    show_on_form.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
