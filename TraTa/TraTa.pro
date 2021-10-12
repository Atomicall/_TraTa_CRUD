QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_form.cpp \
    auth_dbfacade.cpp \
    auth_dto.cpp \
    authentication_dialog.cpp \
    dbfacade_int.cpp \
    main.cpp \
    da_window.cpp \
    show_on_form.cpp \
    tableView_dbFacad.cpp \
    tt_dto.cpp

HEADERS += \
    add_form.h \
    auth_dbfacade.h \
    auth_dto.h \
    authentication_dialog.h \
    da_window.h \
    dbfacade_int.h \
    show_on_form.h \
    tableView_dbFacad.h \
    tt_dto.h

FORMS += \
    add_form.ui \
    authentication_dialog.ui \
    da_window.ui \
    show_on_form.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
