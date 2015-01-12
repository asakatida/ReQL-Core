module RethinkDB
  module VersionDummy
    module Version
      V0_1 = 1063369270
      V0_2 = 1915781601
      V0_3 = 1601562686
    end

    module Protocol
      PROTOBUF = 656407617
      JSON = 2120839367
    end
  end

  module Query
    module QueryType
      START = 1
      CONTINUE = 2
      STOP = 3
      NOREPLY_WAIT = 4
    end

    module AssocPair
    end
  end

  module Frame
    module FrameType
      POS = 1
      OPT = 2
    end
  end

  module Backtrace
  end

  module Response
    module ResponseType
      SUCCESS_ATOM = 1
      SUCCESS_SEQUENCE = 2
      SUCCESS_PARTIAL = 3
      SUCCESS_FEED = 5
      WAIT_COMPLETE = 4
      CLIENT_ERROR = 16
      COMPILE_ERROR = 17
      RUNTIME_ERROR = 18
    end
  end

  module Datum
    module DatumType
      R_NULL = 1
      R_BOOL = 2
      R_NUM = 3
      R_STR = 4
      R_ARRAY = 5
      R_OBJECT = 6
      R_JSON = 7
    end

    module AssocPair
    end
  end

  module Term
    module TermType
      DATUM = 1
      MAKE_ARRAY = 2
      MAKE_OBJ = 3
      VAR = 10
      JAVASCRIPT = 11
      UUID = 169
      HTTP = 153
      ERROR = 12
      IMPLICIT_VAR = 13
      DB = 14
      TABLE = 15
      GET = 16
      GET_ALL = 78
      EQ = 17
      NE = 18
      LT = 19
      LE = 20
      GT = 21
      GE = 22
      NOT = 23
      ADD = 24
      SUB = 25
      MUL = 26
      DIV = 27
      MOD = 28
      APPEND = 29
      PREPEND = 80
      DIFFERENCE = 95
      SET_INSERT = 88
      SET_INTERSECTION = 89
      SET_UNION = 90
      SET_DIFFERENCE = 91
      SLICE = 30
      SKIP = 70
      LIMIT = 71
      INDEXES_OF = 87
      CONTAINS = 93
      GET_FIELD = 31
      KEYS = 94
      OBJECT = 143
      HAS_FIELDS = 32
      WITH_FIELDS = 96
      PLUCK = 33
      WITHOUT = 34
      MERGE = 35
      BETWEEN = 36
      REDUCE = 37
      MAP = 38
      FILTER = 39
      CONCAT_MAP = 40
      ORDER_BY = 41
      DISTINCT = 42
      COUNT = 43
      IS_EMPTY = 86
      UNION = 44
      NTH = 45
      BRACKET = 170
      INNER_JOIN = 48
      OUTER_JOIN = 49
      EQ_JOIN = 50
      ZIP = 72
      RANGE = 173
      INSERT_AT = 82
      DELETE_AT = 83
      CHANGE_AT = 84
      SPLICE_AT = 85
      COERCE_TO = 51
      TYPE_OF = 52
      UPDATE = 53
      DELETE = 54
      REPLACE = 55
      INSERT = 56
      DB_CREATE = 57
      DB_DROP = 58
      DB_LIST = 59
      DB_CONFIG = 178
      TABLE_CREATE = 60
      TABLE_DROP = 61
      TABLE_LIST = 62
      TABLE_CONFIG = 174
      TABLE_STATUS = 175
      TABLE_WAIT = 177
      RECONFIGURE = 176
      REBALANCE = 179
      SYNC = 138
      INDEX_CREATE = 75
      INDEX_DROP = 76
      INDEX_LIST = 77
      INDEX_STATUS = 139
      INDEX_WAIT = 140
      INDEX_RENAME = 156
      FUNCALL = 64
      BRANCH = 65
      ANY = 66
      ALL = 67
      FOR_EACH = 68
      FUNC = 69
      ASC = 73
      DESC = 74
      INFO = 79
      MATCH = 97
      UPCASE = 141
      DOWNCASE = 142
      SAMPLE = 81
      DEFAULT = 92
      JSON = 98
      TO_JSON_STRING = 172
      ISO8601 = 99
      TO_ISO8601 = 100
      EPOCH_TIME = 101
      TO_EPOCH_TIME = 102
      NOW = 103
      IN_TIMEZONE = 104
      DURING = 105
      DATE = 106
      TIME_OF_DAY = 126
      TIMEZONE = 127
      YEAR = 128
      MONTH = 129
      DAY = 130
      DAY_OF_WEEK = 131
      DAY_OF_YEAR = 132
      HOURS = 133
      MINUTES = 134
      SECONDS = 135
      TIME = 136
      MONDAY = 107
      TUESDAY = 108
      WEDNESDAY = 109
      THURSDAY = 110
      FRIDAY = 111
      SATURDAY = 112
      SUNDAY = 113
      JANUARY = 114
      FEBRUARY = 115
      MARCH = 116
      APRIL = 117
      MAY = 118
      JUNE = 119
      JULY = 120
      AUGUST = 121
      SEPTEMBER = 122
      OCTOBER = 123
      NOVEMBER = 124
      DECEMBER = 125
      LITERAL = 137
      GROUP = 144
      SUM = 145
      AVG = 146
      MIN = 147
      MAX = 148
      SPLIT = 149
      UNGROUP = 150
      RANDOM = 151
      CHANGES = 152
      ARGS = 154
      BINARY = 155
      GEOJSON = 157
      TO_GEOJSON = 158
      POINT = 159
      LINE = 160
      POLYGON = 161
      DISTANCE = 162
      INTERSECTS = 163
      INCLUDES = 164
      CIRCLE = 165
      GET_INTERSECTING = 166
      FILL = 167
      GET_NEAREST = 168
      POLYGON_SUB = 171
    end

    module AssocPair
    end
  end
end

def ast_name(lang, name)
  "_reql_#{lang}_#{name.downcase}"
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
  /\A(DELETE|UNION|NOT|DEFAULT|TIMEZONE)\Z/x =~ name
end

def objc_keyword?(name)
  /\A()\Z/x =~ name
end

def lua_keyword?(name)
  /\A(ERROR|NOT)\Z/x =~ name
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

def build(f_name, regex, join_str = "\n", block = Proc.new)
  m = nil

  open(f_name, File::RDONLY, 0644) do |f|
    m = regex.match f.read
  end

  return unless m

  open(f_name, File::RDWR | File::TRUNC, 0644) do |f|
    f.write(m.pre_match)

    f.write((RethinkDB::Term::TermType.constants.sort.map do |term|
      block.call term
    end).join join_str)

    f.write(m.post_match)
  end
end

first_term = 'ADD'
last_term = 'ZIP'

def cpp_term_imp(name)
  Regexp.escape "
/**
 */#{
"
Query AST::#{mangle_cpp_const name}(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(#{c_ast_name name}, this, args, kwargs);
}
Query #{mangle_cpp_const name}(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(#{c_ast_name name}, args, kwargs);
}" if opts? name
}
Query AST::#{mangle_cpp_const name}(std::vector<Query> args) {
  return init(#{c_ast_name name}, this, args);
}
Query #{mangle_cpp_const name}(std::vector<Query> args) {
  return init(#{c_ast_name name}, args);
}"
end

regx = /#{cpp_term_imp first_term}.*#{cpp_term_imp last_term}/m

build('ReQL-ast.cpp', regx) do |name|
  "#{
"
Query
AST::#{mangle_cpp_const name}(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(#{c_ast_name name}, this, args, kwargs);
}
Query
#{mangle_cpp_const name}(std::vector<Query> args, std::map<std::string, Query> kwargs) {
  return init(#{c_ast_name name}, args, kwargs);
}" if opts? name
}
Query
AST::#{mangle_cpp_const name}(std::vector<Query> args) {
  return init(#{c_ast_name name}, this, args);
}
Query
#{mangle_cpp_const name}(std::vector<Query> args) {
  return init(#{c_ast_name name}, args);
}"
end

def cpp_term_class(name)
  Regexp.escape "
  /**
   */#{
      "\n  Query #{
        mangle_cpp_const name
      }(std::vector<Query>, std::map<std::string, Query>);" if opts? name
    }
  Query #{mangle_cpp_const name}(std::vector<Query>);"
end

regx = /#{cpp_term_class first_term}.*#{cpp_term_class last_term}/m

build('ReQL-ast.hpp', regx) do |name|
  "
  /**
   */#{
    "
  Query
  #{
    mangle_cpp_const name
  }(std::vector<Query>, std::map<std::string, Query>);" if opts? name
  }
  Query
  #{mangle_cpp_const name}(std::vector<Query>);"
end

def cpp_term_def(name)
  Regexp.escape "
/**
 */#{
  "\nQuery #{
  mangle_cpp_const name
  }(std::vector<Query>, std::map<std::string, Query>);" if opts? name
}
Query #{mangle_cpp_const name}(std::vector<Query>);"
end

regx = /#{cpp_term_def first_term}.*#{cpp_term_def last_term}/m

build('ReQL-ast.hpp', regx) do |name|
  "
/**
 */#{
  "
Query
#{
  mangle_cpp_const name
}(std::vector<Query>, std::map<std::string, Query>);" if opts? name
}
Query
#{mangle_cpp_const name}(std::vector<Query>);"
end

def lua_term_imp(name)
  Regexp.escape "
/**
 */
int #{lua_ast_name name}(lua_State *L) {
  return _reql_lua_#{
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

regx = /#{lua_term_imp first_term}.*#{lua_term_imp last_term}/m

build('ReQL-ast-Lua.c', regx) do |name|
  "
extern int
#{lua_ast_name name}(lua_State *L) {
  return _reql_lua_#{
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

def lua_term_def(name)
  Regexp.escape "
/**
 */
int #{lua_ast_name name}(lua_State *L);"
end

regx = /#{lua_term_def first_term}.*#{lua_term_def last_term}/m

build('ReQL-ast-Lua.h', regx) do |name|
  "
/**
 */
extern int
#{lua_ast_name name}(lua_State *L);"
end

def node_term_imp(name)
  Regexp.escape "
/**
 */
v8::Handle<v8::Value> #{node_ast_name name}(const v8::Arguments& args) {
  v8::HandleScope scope;

  v8::Local<v8::Object> obj = v8::Object::New();

  if (!args[0]->IsUndefined()) {
  }

  return scope.Close(obj);
}"
end

regx = /#{node_term_imp first_term}.*#{node_term_imp last_term}/m

build('ReQL-ast-Node.cpp', regx) do |name|
  "
extern v8::Handle<v8::Value>
#{node_ast_name name}(const v8::Arguments& args) {
  v8::HandleScope scope;

  v8::Local<v8::Object> obj = v8::Object::New();

  if (!args[0]->IsUndefined()) {
  }

  return scope.Close(obj);
}"
end

def node_term_def(name)
  Regexp.escape "
/**
 */
v8::Handle<v8::Value> #{node_ast_name name}(const v8::Arguments& args);"
end

regx = /#{node_term_def first_term}.*#{node_term_def last_term}/m

build('ReQL-ast-Node.hpp', regx) do |name|
  "
/**
 */
extern v8::Handle<v8::Value>
#{node_ast_name name}(const v8::Arguments& args);"
end

def objc_term_def(name)
  Regexp.escape "
/**
 */
-(instancetype)#{mangle_objc_const name};"
end

regx = /#{objc_term_def first_term}.*#{objc_term_def last_term}/m

build('ReQL-ast-ObjC.h', regx) do |name|
  "
/**
 */
-(instancetype)
#{mangle_objc_const name};"
end

def objc_term_imp(name)
  Regexp.escape "
/**
 */
-(instancetype) #{mangle_objc_const name} {
  return self;
}"
end

regx = /#{objc_term_imp first_term}.*#{objc_term_imp last_term}/m

build('ReQL-ast-ObjC.m', regx) do |name|
  "
-(instancetype)
#{mangle_objc_const name} {
  return self;
}"
end

def py_term_imp(name)
  Regexp.escape "
/**
 */
static PyObject *#{py_ast_name name}(PyObject *self, PyObject *args, PyObject *kwargs) {
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

regx = /#{py_term_imp first_term}.*#{py_term_imp last_term}/m

build('ReQL-ast-Python.c', regx) do |name|
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

def py_term_def(name)
  Regexp.escape "
/**
 */
static PyObject *#{py_ast_name name}(PyObject *self, PyObject *args, PyObject *kwargs);"
end

regx = /#{py_term_def first_term}.*#{py_term_def last_term}/m

build('ReQL-ast-Python.h', regx) do |name|
  "
/**
 */
extern PyObject *
#{py_ast_name name}(PyObject *self, PyObject *args, PyObject *kwargs);"
end

def rb_term_imp(name)
  Regexp.escape "
/**
 */
static VALUE #{rb_ast_name name}(int argn, VALUE *args, VALUE self) {
  return self;
}"
end

regx = /#{rb_term_imp first_term}.*#{rb_term_imp last_term}/m

build('ReQL-ast-Ruby.c', regx) do |name|
  "
extern VALUE
#{rb_ast_name name}(int argn, VALUE *args, VALUE self) {
  return self;
}"
end

def rb_term_def(name)
  Regexp.escape "
/**
 */
static VALUE #{rb_ast_name name}(int argn, VALUE *args, VALUE self);"
end

regx = /#{rb_term_def first_term}.*#{rb_term_def last_term}/m

build('ReQL-ast-Ruby.h', regx) do |name|
  "
/**
 */
extern VALUE
#{rb_ast_name name}(int argn, VALUE *args, VALUE self);"
end

def term_imp(name)
  Regexp.escape "
/**
 */
void #{c_ast_name name}(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term->tt = _REQL_#{name};
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
}"
end

regx = /#{term_imp first_term}.*#{term_imp last_term}/m

build('ReQL-ast.c', regx) do |name|
  "
extern void
#{c_ast_name name}(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs) {
  term->tt = _REQL_#{name};
  term->obj.args.args = args;
  term->obj.args.kwargs = kwargs;
}"
end

def term_def(name)
  Regexp.escape "
/**
 */
void #{c_ast_name name}(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);"
end

regx = /#{term_def first_term}.*#{term_def last_term}/m

build('ReQL-ast.h', regx) do |name|
  "
/**
 */
extern void
#{c_ast_name name}(_ReQL_Op term, _ReQL_Op args, _ReQL_Op kwargs);"
end

def enum_def(name)
  "_REQL_#{name} = #{RethinkDB::Term::TermType.const_get name}"
end

regx = /#{Regexp.escape enum_def first_term}.*#{Regexp.escape enum_def last_term}/m

build('ReQL-json.h', regx, ",\n  ") do |name|
  enum_def name
end

def lua_lib(name)
  "{\"#{mangle_lua_const name}\", #{lua_ast_name name}},"
end

regx = /#{Regexp.escape lua_lib first_term}.*#{Regexp.escape lua_lib last_term}/m

build('ReQL-Lua.c', regx, "\n  ") do |name|
  lua_lib name
end
