package = 'libReQL'
version = '0.1.0'
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
    libReQL = 'ReQL-Lua.c'
  }
}
