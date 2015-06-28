package = 'libreql'
version = '1.0.0-0'

source = {
  url = 'git://github.com/grandquista/ReQL-Core'
}

description = {
  detailed = [[
  ]],
  homepage = '',
  license = 'Apache',
  maintainer = 'Adam Grandquist <grandquista@gmail.com>',
  summary = 'A Lua driver for RethinkDB.'
}

dependencies = {
  'lua >= 5.1'
}

build = {
  type = 'builtin',
  modules = {
    libReQL = {
      sources = {
        'src/Lua/ast.c',
        'src/Lua/expr.c',
        'src/Lua/new.c',
        'src/Lua/ReQL.c',
        'src/reql/char.c',
        'src/reql/connection.c',
        'src/reql/cursor.c',
        'src/reql/decode.c',
        'src/reql/encode.c',
        'src/reql/error.c',
        'src/reql/query.c'
      },
      incdirs = {'src'}
    }
  }
}
