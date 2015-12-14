include(../defaults.pri)
TEMPLATE = app

CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -LWs2_32 -lWs2_32
LIBS += -L../src -lReQL

SOURCES += \
  cpp/connection.cpp \
  main.cpp \
  test.cpp

HEADERS += \
  test.hpp \
  catch.hpp

SUBDIRS += \
    ../src/
