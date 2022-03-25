QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../src

SOURCES +=  tst_testfilter.cpp \
    ../../src/jiabh/filter.cpp \
    ../../src/jiabh/column.hpp
