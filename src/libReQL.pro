#-------------------------------------------------
#
# Project created by QtCreator 2015-11-16T10:03:00
#
#-------------------------------------------------

QT       -= core gui

TARGET = libReQL
TEMPLATE = lib

DEFINES += LIBREQL_LIBRARY

QMAKE_CXXFLAGS += -std=c++14
QMAKE_LFLAGS += -std=c++14

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
  reql/btree.hpp \
  reql/connection.hpp \
  reql/core.hpp \
  reql/cursor.hpp \
  reql/decode.hpp \
  reql/handshake.hpp \
  reql/parser.hpp \
  reql/pipe.hpp \
  reql/protocol.hpp \
  reql/query.hpp \
  reql/response.hpp \
  reql/socket.hpp \
  reql/stream.hpp \
  reql/string.hpp \
  reql/types.hpp \
  ReQL.hpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}
