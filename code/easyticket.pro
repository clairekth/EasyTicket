QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

INCLUDEPATH = include/

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
# DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/pageajoutticket.cpp \
    src/systeme.cpp \
    src/logiciel.cpp \
    src/mainwindow.cpp \
    src/categorie.cpp \
    src/ticket.cpp \
    src/utilisateur.cpp \
    src/message.cpp \
    src/client.cpp \
    src/admin.cpp \
    src/personnel.cpp \
    src/ingenieur.cpp \
    src/technicien.cpp \
    src/main.cpp \
    src/pagelogin.cpp \
    src/pageaccueilclient.cpp \
    src/gestionnairedialogue.cpp

HEADERS += \
    include/systeme.h \
    include/logiciel.h \
    include/mainwindow.h \
    include/categorie.h \
    include/ticket.h \
    include/utilisateur.h \
    include/message.h \
    include/client.h \
    include/admin.h \
    include/personnel.h \
    include/ingenieur.h \
    include/technicien.h \
    include/constantes.h \
    include/pagelogin.h \
    include/pageaccueilclient.h \
    include/gestionnairedialogue.h \
    include/pageajoutticket.h

FORMS += \
    forms/mainwindow.ui \
    forms/pagelogin.ui \
    forms/pageaccueilclient.ui \
    forms/pageajoutticket.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

