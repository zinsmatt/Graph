#-------------------------------------------------
#
# Project created by QtCreator 2015-09-21T22:31:58
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Graph
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    src/edge.cpp \
    src/element.cpp \
    src/main.cpp \
    src/node.cpp \
    src/matrix.cpp \
    src/squarematrix.cpp

SUBDIRS += \
    src/Graph.pro

DISTFILES += \
    src/Graph.pro.user

HEADERS += \
    src/edge.h \
    src/element.h \
    src/node.h \
    src/matrix.h \
    src/squarematrix.h
