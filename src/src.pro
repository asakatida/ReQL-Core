include(../defaults.pri)

TARGET = ReQL
TEMPLATE = lib

CONFIG += c++14
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -LWs2_32 -lWs2_32

HEADERS += \
  reql/connection.h \
  reql/connection.hpp \
  reql/cursor.h \
  reql/cursor.hpp \
  reql/query.h \
  reql/query.hpp \
  reql/result.hpp \
  reql/types.h \
  reql/core/array.hpp \
  reql/core/connection.hpp \
  reql/core/decode.hpp \
  reql/core/error.hpp \
  reql/core/handshake.hpp \
  reql/core/null.hpp \
  reql/core/object.hpp \
  reql/core/protocol.hpp \
  reql/core/query.hpp \
  reql/core/socket.hpp \
  reql/core/string.hpp \
  reql/core/term.hpp \
  ReQL.h \
  ReQL.hpp

SOURCES += \
  reql/connection.cpp \
  reql/cursor.cpp \
  reql/query.cpp

unix {
  target.path = /usr/lib
  INSTALLS += target
}
