#-------------------------------------------------
#
# Project created by QtCreator 2015-05-21T11:59:43
#
#-------------------------------------------------

QT       += core gui
CFLAGS        = -Wall -O2 -D=HAVE_CONFIG_H
CXXFLAGS      = --Wall -O2 -D=HAVE_CONFIG_H
INCPATH = -I/usr/include -I/usr/local/thrift-0.9.0/include/thrift
LIBS          = -L/usr/lib -L/usr/thrift-0.9.0/lib -lthrift
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Servicio1Ecodi
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gen-cpp/Calculator.cpp \
    gen-cpp/shared_constants.cpp \
    gen-cpp/shared_types.cpp \
    gen-cpp/SharedService.cpp \
    gen-cpp/tutorial_constants.cpp \
    gen-cpp/tutorial_types.cpp \
    CppServer.cpp

HEADERS  += mainwindow.h \
    gen-cpp/Calculator.h \
    gen-cpp/shared_constants.h \
    gen-cpp/shared_types.h \
    gen-cpp/SharedService.h \
    gen-cpp/tutorial_constants.h \
    gen-cpp/tutorial_types.h

FORMS    += mainwindow.ui
