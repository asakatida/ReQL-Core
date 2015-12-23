include(../defaults.pri)

TARGET = ReQL
TEMPLATE = lib

HEADERS += \
  reql/connection.hpp \
  reql/cursor.hpp \
  reql/error.hpp \
  reql/query.hpp \
  reql/result.hpp \
  reql/core/array.hpp \
  reql/core/connection.hpp \
  reql/core/decode.hpp \
  reql/core/handshake.hpp \
  reql/core/null.hpp \
  reql/core/object.hpp \
  reql/core/protocol.hpp \
  reql/core/query.hpp \
  reql/core/socket.hpp \
  reql/core/string.hpp \
  reql/core/term.hpp \
  ReQL.hpp

unix {
  target.path = /usr/lib
  INSTALLS += target
}
