require_relative './rethinkdb/drivers/ruby/lib/ql2.pb.rb'

def ast_name(lang, name)
  "reql_#{lang}_#{name.downcase}"
end

def c_ast_name(name)
  ast_name 'ast', name
end

def lua_ast_name(name)
  ast_name 'lua', name
end

def node_ast_name(name)
  ast_name 'node', name
end

def py_ast_name(name)
  ast_name 'py', name
end

def rb_ast_name(name)
  ast_name 'rb', name
end

def opts?(name)
  /\A(CIRCLE|DELETE|DISTINCT|EQ_JOIN|FILTER|GET_ALL|GET_INTERSECTING|
  GET_NEAREST|GROUP|HTTP|INDEX_CREATE|INDEX_RENAME|ISO8601|JAVASCRIPT|ORDER_BY|
  RANDOM|REPLACE|SLICE|TABLE|TABLE_CREATE|UPDATE)\Z/x =~ name
end

def c_keyword?(name)
  /\A()\Z/x =~ name
end

def cpp_keyword?(name)
  /\A(AND|DEFAULT|DELETE|NOT|OR|TIMEZONE|UNION)\Z/x =~ name or c_keyword? name
end

def objc_keyword?(name)
  /\A()\Z/x =~ name or c_keyword? name
end

def lua_keyword?(name)
  /\A(AND|ERROR|NOT|OR)\Z/x =~ name
end

def const_args_w_opts?(name)
  /\A(TABLE)\Z/x =~ name
end

def mangle_const(name, mangle)
  "#{name.downcase}#{'_' if mangle}"
end

def mangle_c_const(name)
  mangle_const name, c_keyword?(name)
end

def mangle_cpp_const(name)
  mangle_const name, cpp_keyword?(name)
end

def mangle_lua_const(name)
  mangle_const name, lua_keyword?(name)
end

def mangle_objc_const(name)
  mangle_const name, objc_keyword?(name)
end

def regx(conv)
  /#{Regexp.escape send(conv, 'ADD')}.*#{Regexp.escape send(conv, 'ZIP')}/m
end

def build_output(f_name, m, join_str, block = Proc.new)
  open(f_name, File::RDWR | File::TRUNC, 0644) do |f|
    f.write(m.pre_match)

    f.write((RethinkDB::Term::TermType.constants.sort.map do |term|
      block.call term
    end).join join_str)

    f.write(m.post_match)
  end
end

def build(f_name, regex, join_str = "\n", block = Proc.new)
  m = nil

  open(f_name, File::RDONLY, 0644) do |f|
    m = regx(regex).match f.read
  end

  return unless m

  build_output(f_name, m, join_str, block)
end

def cpp_term_imp(name)
  "#{
"
Query
Query::#{mangle_cpp_const name}(const Types::array &args, const Types::object &kwargs) const {
  return init(_C::#{c_ast_name name}, this, args, kwargs);
}
Query
#{mangle_cpp_const name}(const Types::array &args, const Types::object &kwargs) {
  return init(_C::#{c_ast_name name}, args, kwargs);
}" if opts? name
}
Query
Query::#{mangle_cpp_const name}(const Types::array &args) const {
  return init(_C::#{c_ast_name name}, this, args);
}
Query
#{mangle_cpp_const name}(const Types::array &args) {
  return init(_C::#{c_ast_name name}, args);
}"
end

build('src/cpp/query.cpp', :cpp_term_imp) do |name|
  cpp_term_imp name
end

def cpp_term_class(name)
  "
  /**
   */#{
    "
  Query
  #{
    mangle_cpp_const name
  }(const Types::array &args, const Types::object &kwargs) const;" if opts? name
  }
  Query
  #{mangle_cpp_const name}(const Types::array &args) const;"
end

build('src/cpp/query.hpp', :cpp_term_class) do |name|
  cpp_term_class name
end

def cpp_term_def(name)
  "
/**
 */#{
  "
Query
#{
  mangle_cpp_const name
}(const Types::array &args, const Types::object &kwargs);" if opts? name
}
Query
#{mangle_cpp_const name}(const Types::array &args);"
end

build('src/cpp/query.hpp', :cpp_term_def) do |name|
  cpp_term_def name
end

def lua_term_imp(name)
  "
extern int
#{lua_ast_name name}(lua_State *L) {
  return reql_lua_#{
    if opts? name
      'get_opts'
    else
      'ast_class'
    end
  }(L, #{c_ast_name name}#{
    if opts? name
      ''
    else
      ', NULL'
    end
  });
}"
end

build('src/Lua/ast.c', :lua_term_imp) do |name|
  lua_term_imp name
end

def lua_term_def(name)
  "
/**
 */
extern int
#{lua_ast_name name}(lua_State *L);"
end

build('src/Lua/ast.h', :lua_term_def) do |name|
  lua_term_def name
end

def node_term_imp(name)
  "
v8::Handle<v8::Value>
#{node_ast_name name}(const v8::Arguments& args) {
  v8::HandleScope scope;

  v8::Local<v8::Object> obj = v8::Object::New();

  if (!args[0]->IsUndefined()) {
  }

  return scope.Close(obj);
}"
end

build('src/Node/ast.cpp', :node_term_imp) do |name|
  node_term_imp name
end

def node_term_def(name)
  "
/**
 */
v8::Handle<v8::Value>
#{node_ast_name name}(const v8::Arguments& args);"
end

build('src/Node/ast.hpp', :node_term_def) do |name|
  node_term_def name
end

def objc_term_def(name)
  "
/**
 */
-(instancetype)
#{mangle_objc_const name}:(NSArray *)args#{' :(NSDictionary *)kwargs' if opts? name};"
end

build('libReQL/Query.h', :objc_term_def) do |name|
  objc_term_def name
end

def objc_term_imp(name)
  "
-(instancetype)
#{mangle_objc_const name}:(NSArray *)args#{' :(NSDictionary *)kwargs' if opts? name} {
  return self;
}"
end

build('libReQL/Query.m', :objc_term_imp) do |name|
  objc_term_imp name
end

def py_term_imp(name)
  "
extern PyObject *
#{py_ast_name name}(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, \"o:r.#{
        name.downcase
      }\", kwlist, &val)) {
    return self;
  }

  return val;
}"
end

build('src/Python/ast.c', :py_term_imp) do |name|
  py_term_imp name
end

def py_term_def(name)
  "
/**
 */
extern PyObject *
#{py_ast_name name}(PyObject *self, PyObject *args, PyObject *kwargs);"
end

build('src/Python/ast.h', :py_term_def) do |name|
  py_term_def name
end

def rb_term_imp(name)
  "
extern VALUE
#{rb_ast_name name}(int argn, VALUE *args, VALUE self) {
  return self;
}"
end

build('src/Ruby/ast.c', :rb_term_imp) do |name|
  rb_term_imp name
end

def rb_term_def(name)
  "
/**
 */
extern VALUE
#{rb_ast_name name}(int argn, VALUE *args, VALUE self);"
end

build('src/Ruby/ast.h', :rb_term_def) do |name|
  rb_term_def name
end

def c_term_imp(name)
  "
extern ReQL_t *
reql_#{name.downcase}(ReQL_t **args#{', ReQL_t **kwargs' if opts? name}) {
  return reql_term(REQL_#{name}, args, #{if opts? name then 'kwargs' else 'NULL' end});
}"
end

build('src/c/query.c', :c_term_imp) do |name|
  c_term_imp name
end

def c_term_def(name)
  "
/**
 */
extern ReQL_t *
reql_#{name.downcase}(ReQL_t **args#{', ReQL_t **kwargs' if opts? name});"
end

build('src/c/query.h', :c_term_def) do |name|
  c_term_def name
end

def term_imp(name)
  "
extern void
#{c_ast_name name}(ReQL_Obj_t *t, ReQL_Obj_t *a#{', ReQL_Obj_t *k' if opts? name}) {
  reql_term_init(t, REQL_#{name}, a, #{if opts? name then 'k' else 'NULL' end});
}"
end

build('src/reql/ast.c', :term_imp) do |name|
  term_imp name
end

def term_def(name)
  "
/**
 */
extern void
#{c_ast_name name}(ReQL_Obj_t *t, ReQL_Obj_t *a#{', ReQL_Obj_t *k' if opts? name});"
end

build('src/reql/ast.h', :term_def) do |name|
  term_def name
end

def enum_def(name)
  "REQL_#{name} = #{RethinkDB::Term::TermType.const_get name}"
end

build('src/reql/expr.h', :enum_def, ",\n  ") do |name|
  enum_def name
end

def lua_lib(name)
  "{\"#{mangle_lua_const name}\", #{lua_ast_name name}},"
end

build('src/Lua/ReQL.c', :lua_lib, "\n  ") do |name|
  lua_lib name
end
