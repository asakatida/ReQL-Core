include(../defaults.pri)

TARGET = ReQL
TEMPLATE = lib

CONFIG += c++14
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -LWs2_32 -lWs2_32

HEADERS += \
  connection.h \
  connection.hpp \
  cursor.h \
  cursor.hpp \
  query.h \
  query.hpp \
  result.hpp \
  types.h \
  core/array.hpp \
  core/connection.hpp \
  core/decode.hpp \
  core/error.hpp \
  core/handshake.hpp \
  core/null.hpp \
  core/object.hpp \
  core/protocol.hpp \
  core/query.hpp \
  core/socket.hpp \
  core/string.hpp \
  core/term.hpp \
  ReQL.h \
  ReQL.hpp

SOURCES += \
  connection.cpp \
  cursor.cpp \
  query.cpp

unix {
  target.path = /usr/lib
  INSTALLS += target
}
