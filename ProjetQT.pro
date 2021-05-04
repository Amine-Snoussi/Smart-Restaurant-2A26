#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT+= core gui printsupport
QT+= sql
QT += core gui charts
QT += core gui network
QT += network
QT += serialport




greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GestionClient
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

DEFINES += SMTP_BUILD
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    arduino.cpp \
    arduino_emp_conge.cpp \
    client_reservation.cpp \
    comd.cpp \
    cong.cpp \
    connexion.cpp \
    dialogsou.cpp \
    dialogstatemp.cpp \
    employe.cpp \
    employe_conge.cpp \
    fourn.cpp \
    fournisseur_commande.cpp \
    gestioningredient.cpp \
    gestionmenu.cpp \
    homepage.cpp \
    livraison.cpp \
        main.cpp\
        client.cpp\
    connection.cpp\
    menu_ingredient.cpp \
    reclamation.cpp \
    src/emailaddress.cpp \
    src/mimeattachment.cpp \
    src/mimecontentformatter.cpp \
    src/mimefile.cpp \
    src/mimehtml.cpp \
    src/mimeinlinefile.cpp \
    src/mimemessage.cpp \
    src/mimemultipart.cpp \
    src/mimepart.cpp \
    src/mimetext.cpp \
    src/quotedprintable.cpp \
    src/smtpclient.cpp \
    reservation.cpp \
    statelivrec.cpp \
    statemp.cpp

HEADERS += \
    arduino.h \
    arduino_emp_conge.h \
        client.h \
    client_reservation.h \
    comd.h \
    cong.h \
    connection.h\
    connexion.h \
    dialogsou.h \
    dialogstatemp.h \
    employe.h \
    employe_conge.h \
    fourn.h \
    fournisseur_commande.h \
    gestioningredient.h \
    gestionmenu.h \
    homepage.h \
    livraison.h \
    menu_ingredient.h \
    reclamation.h \
    src/emailaddress.h \
    src/mimeattachment.h \
    src/mimecontentformatter.h \
    src/mimefile.h \
    src/mimehtml.h \
    src/mimeinlinefile.h \
    src/mimemessage.h \
    src/mimemultipart.h \
    src/mimepart.h \
    src/mimetext.h \
    src/quotedprintable.h \
    src/smtpclient.h \
    src/smtpexports.h \
    src/SmtpMime \
    reservation.h \
    statelivrec.h \
    statemp.h

FORMS += \
    client_reservation.ui \
    dialogsou.ui \
    dialogstatemp.ui \
    employe_conge.ui \
    fournisseur_commande.ui \
    homepage.ui \
    menu_ingredient.ui \
    statelivrec.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc


