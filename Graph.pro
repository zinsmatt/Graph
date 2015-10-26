#-------------------------------------------------
#
# Project created by QtCreator 2015-09-21T22:31:58
#
#-------------------------------------------------

QT       += core \
            widgets

QT       -= gui

TARGET = Graph
CONFIG   += console \
            c++11
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    src/edge.cpp \
    src/element.cpp \
    src/main.cpp \
    src/node.cpp \
    src/matrix.cpp \
    src/squarematrix.cpp \
    src/mainwindow.cpp \
    src/graph.cpp \
    src/graphcontainer.cpp \
    src/adjacencymatrix.cpp \
    src/incidencematrix.cpp \
    src/successorlist.cpp \
    src/node2d.cpp \
    src/edge2d.cpp \
    src/algorithm.cpp

SUBDIRS += \
    src/Graph.pro

DISTFILES += \
    src/Graph.pro.user

HEADERS += \
    src/edge.h \
    src/element.h \
    src/node.h \
    src/matrix.h \
    src/squarematrix.h \
    src/mainwindow.h \
    src/graph.h \
    src/graphcontainer.h \
    src/adjacencymatrix.h \
    src/incidencematrix.h \
    src/successorlist.h \
    src/node2d.h \
    src/edge2d.h \
    src/algorithm.h

FORMS += \
    src/mainwindow.ui
