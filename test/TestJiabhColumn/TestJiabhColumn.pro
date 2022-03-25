QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../src

SOURCES +=  tst_testcolumn.cpp \
    ../../src/jiabh/column.hpp \
    ../../src/jiabh/filter.cpp
