package = 'libReQL'
version = '0.1.0-1'
source = {
  url = 'git://github.com/grandquista/ReQL-Core',
  tag = 'v0.1.0'
}
description = {
  summary = 'A Lua driver for RethinkDB.',
  homepage = 'https://github.com/grandquista/ReQL-Core/wiki',
  license = 'Apache'
}
dependencies = {'lua ~> 5'}
build = {
  type = 'builtin',
  modules = {
    libReQL = {
      libraries = {'pthread'},
      sources = {
        'ReQL-ast-Lua.c',
        'ReQL-ast.c',
        'ReQL-expr-Lua.c',
        'ReQL-expr.c',
        'ReQL-json.c',
        'ReQL-new-Lua.c',
        'ReQL-Lua.c',
        'ReQL.c'
      }
    }
  }
}
