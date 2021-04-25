QT       += core gui
QT += sql
QT       += core gui charts
QT       += serialport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    cong.cpp \
    connexion.cpp \
    employe.cpp \
    main.cpp \
    mainwindow.cpp \
    statelivrec.cpp

HEADERS += \
    arduino.h \
    cong.h \
    connexion.h \
    employe.h \
    mainwindow.h \
    statelivrec.h

FORMS += \
    mainwindow.ui \
    statelivrec.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
