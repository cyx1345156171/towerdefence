#-------------------------------------------------
#
# Project created by QtCreator 2020-04-28T12:35:33
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tafang
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    taposition.cpp \
    start.cpp \
    ta.cpp \
    diren.cpp \
    diyiguan.cpp \
    choice.cpp \
    commontower.cpp \
    fouranniu.cpp \
    slowtower.cpp \
    powertower.cpp \
    speedtower.cpp

HEADERS += \
    taposition.h \
    start.h \
    ta.h \
    diren.h \
    bulletzu.h \
    wayzu.h \
    diyiguan.h \
    choice.h \
    commontower.h \
    fouranniu.h \
    slowtower.h \
    powertower.h \
    speedtower.h

FORMS += \
    start.ui \
    diyiguan.ui \
    diyiguan.ui


RESOURCES += \
    Resource.qrc

DISTFILES +=
