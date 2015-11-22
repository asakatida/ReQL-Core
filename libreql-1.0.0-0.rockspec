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
        'src/Lua/connection.cpp',
        'src/Lua/cursor.cpp',
        'src/Lua/query.cpp',
        'src/Lua/ReQL.cpp',
      },
      incdirs = {'src'}
    }
  }
}
