#-------------------------------------------------
#
# Project created by QtCreator 2015-11-16T10:03:00
#
#-------------------------------------------------

include(../defaults.pri)
CONFIG -= qt

QT -= core gui

TARGET = ReQL
TEMPLATE = lib

QMAKE_CXXFLAGS += -std=c++14
QMAKE_LFLAGS += -std=c++14

LIBS += -LWs2_32 -lWs2_32

SOURCES += \
  cpp/connection.cpp \
  cpp/cursor.cpp \
  cpp/error.cpp \
  cpp/parser.cpp \
  cpp/query.cpp \

HEADERS += \
  cpp/connection.hpp \
  cpp/cursor.hpp \
  cpp/error.hpp \
  cpp/parser.hpp \
  cpp/query.hpp \
  cpp/types.hpp \
  reql/connection.hpp \
  reql/decode.hpp \
  reql/handshake.hpp \
  reql/protocol.hpp \
  reql/query.hpp \
  reql/socket.hpp \
  ReQL.hpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}
