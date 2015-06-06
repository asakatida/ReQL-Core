try:
    import yaml
except:
    print('PyYAML not installed')

try:
    import rethinkdb as r
except:
    print('rethinkdb not installed')

import collections
import numbers
import re
import types

from datetime import datetime
from pathlib import Path
from rethinkdb import ql2_pb2

xrange = range

test_names = set()

test_name_shell = '{} {}'

test_shell_cpp = '''// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("{}", "[cpp][ast]") {{
{}
}}
'''

test_shell_c = '''// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.h"

TEST_CASE("{}", "[c][ast]") {{
{}
}}
'''

test_shell_reql = '''// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./reql/core.h"

#include <memory>

TEST_CASE("{}", "[reql][ast]") {{
{}
}}
'''

section_shell = '''
  SECTION("test{}") {{{}
  }}'''

class ObjectRecursor:
    def recurse(self, obj):
        if isinstance(obj, str):
            return self.string_obj(obj)
        elif isinstance(obj, bytes):
            return self.bytes_obj(obj)
        elif isinstance(obj, collections.Mapping):
            count = len(obj)
            if count == 0:
                return self.empty_map_obj()
            self.map_obj_start(count)
            for k in sorted(obj.keys()):
                v = obj[k]
                self.key_obj(k)
                k = self.recurse(k)
                self.val_obj()
                self.key_val_pair(k, self.recurse(v))
            return self.map_obj_end()
        elif isinstance(obj, collections.Iterable):
            count = len(obj)
            if count == 0:
                return self.empty_array_obj()
            self.array_obj_start(count)
            for e in obj:
                self.elem_start()
                self.elem_end(self.recurse(e))
            return self.array_obj_end()
        elif isinstance(obj, bool):
            return self.bool_obj(obj)
        elif isinstance(obj, numbers.Number):
            return self.number_obj(obj)
        elif isinstance(obj, collections.Callable):
            return self.callable_obj(obj)
        elif obj == None:
            return self.none_obj()
        raise Exception("unknown object type {}".format(type(obj)))

class ResultBuilder(ObjectRecursor):
    def __init__(self):
        self.obj_id = 0
        self.array_stack = {}
        self.elem_id_stack = []
        self.object_stack = {}
        self.key_id_stack = []
        self.val_id_stack = []

    def next_obj_id(self):
        obj_id = self.obj_id
        self.obj_id += 1
        return obj_id

    def append_id(self, stack):
        stack.append(self.obj_id)

    def array_stack_top(self):
        return max(self.array_stack.keys())

    def active_array_append(self, *args):
        top = self.array_stack[self.array_stack_top()]
        for arg in args:
            top.append(arg)

    def object_stack_top(self):
        return max(self.object_stack.keys())

    def active_object_append(self, *args):
        top = self.object_stack[self.object_stack_top()]
        for arg in args:
            top.append(arg)

    def recurse(self, obj):
        if isinstance(obj, r.RqlQuery):
            obj = {'reql_ast_obj': type(obj)}
        elif isinstance(obj, datetime):
            obj = obj.ctime()
        return super().recurse(obj)

    def bytes_obj(self, obj):
        return self.recurse(obj.decode())

    def key_obj(self, key):
        if not isinstance(key, str):
            raise BadKeyError()
        self.append_id(self.key_id_stack)

    def val_obj(self):
        self.append_id(self.val_id_stack)

    def elem_start(self):
        self.append_id(self.elem_id_stack)

    def map_obj_end(self):
        return '\n'.join(self.object_stack.pop(self.object_stack_top()))

    def array_obj_end(self):
        return '\n'.join(self.array_stack.pop(self.array_stack_top()))

    def callable_obj(self, obj):
        if obj == sorted:
            return self.recurse(['func', 'sorted'])
        elif isinstance(obj, types.LambdaType):
            return self.recurse(obj())
        else:
            return self.recurse({'reql_ast_obj': obj.__name__})

    def string_obj(self, obj):
        obj = obj.encode('unicode_escape').replace(b'"', b'\\"')
        return self.shell_string.format(
            self.next_obj_id(), len(obj), obj.decode())

    def empty_map_obj(self):
        return self.shell_empty_map.format(self.next_obj_id())

    def map_obj_start(self, count):
        orig_obj_id = self.next_obj_id()
        self.object_stack[orig_obj_id] = [
            self.shell_map_start.format(orig_obj_id, count)]

    def key_val_pair(self, key, val):
        self.active_object_append(key, val, self.shell_key_val.format(
            self.object_stack_top(),
            self.key_id_stack.pop(),
            self.val_id_stack.pop()))

    def empty_array_obj(self):
        return self.shell_empty_array.format(self.next_obj_id())

    def array_obj_start(self, count):
        orig_obj_id = self.next_obj_id()
        self.array_stack[orig_obj_id] = [
            self.shell_array_start.format(orig_obj_id, count)]

    def elem_end(self, elem):
        self.active_array_append(elem, self.shell_elem.format(
            self.array_stack_top(), self.elem_id_stack.pop()))

    def bool_obj(self, shell, obj):
        return shell.format(self.next_obj_id(), obj)

    def number_obj(self, obj):
        return self.shell_number.format(self.next_obj_id(), obj)

    def none_obj(self):
        return self.shell_none.format(self.next_obj_id())

class CResultBuilder(ResultBuilder):
    shell_string = ''''''

    shell_empty_map = ''''''

    shell_map_start = ''''''

    shell_key_val = ''''''

    shell_empty_array = ''''''

    shell_array_start = ''''''

    shell_elem = ''''''

    def bool_obj(self, obj):
        return super().bool_obj('''''', 1 if obj else 0)

    shell_number = ''''''

    shell_none = ''''''

class CPPResultBuilder(ResultBuilder):
    shell_string = '''
    std::string src{0}("{2}", {1});
    Query var{0}(src{0});'''

    shell_empty_map = '''
    Types::object map{0};
    Query var{0}(map{0});'''

    shell_map_start = '''
    Types::object map{};'''

    shell_key_val = '''
    map{}.insert({{src{}, var{}}});'''

    def map_obj_end(self):
        self.active_object_append('''
    Query var{0}(map{0});'''.format(self.object_stack_top()))
        return super().map_obj_end()

    shell_empty_array = '''
    Types::array arr{0};
    Query var{0}(arr{0});'''

    shell_array_start = '''
    Types::array arr{}({});'''

    shell_elem = '''
    arr{0}.insert(arr{0}.end(), var{1});'''

    def array_obj_end(self):
        self.active_array_append('''
    Query var{0}(arr{0});'''.format(self.array_stack_top()))
        return super().array_obj_end()

    def bool_obj(self, obj):
        return super().bool_obj('''
    Query var{}({});''', 'true' if obj else 'false')

    shell_number = '''
    double num{0}({1});
    Query var{0}(num{0});'''

    shell_none = '''
    Query var{};'''

class ReQLResultBuilder(ResultBuilder):
    shell_string = '''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf{0}(new uint8_t[{1}]);
    const uint8_t src{0}[] = "{2}";
    reql_string_init(var{0}.get(), buf{0}.get(), {1});
    reql_string_append(var{0}.get(), src{0}, {1});'''

    shell_empty_map = '''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    reql_object_init(var{0}.get(), nullptr, 0);'''

    shell_map_start = '''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair{0}(new ReQL_Pair_t[{1}]);
    reql_object_init(var{0}.get(), pair{0}.get(), {1});'''

    shell_key_val = '''
    reql_object_add(var{}.get(), var{}.get(), var{}.get());'''

    shell_empty_array = '''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    reql_array_init(var{0}.get(), nullptr, 0);'''

    shell_array_start = '''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr{0}(new ReQL_Obj_t*[{1}]);
    reql_array_init(var{0}.get(), arr{0}.get(), {1});'''

    shell_elem = '''
    reql_array_append(var{}.get(), var{}.get());'''

    def bool_obj(self, obj):
        return super().bool_obj('''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    reql_bool_init(var{0}.get(), {1});''', 1 if obj else 0)

    shell_number = '''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    reql_number_init(var{0}.get(), {1});'''

    shell_none = '''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    reql_null_init(var{0}.get());'''

class TestTable:
    def __init__(self, name):
        self.name = name

    def __getattr__(self, name):
        return self

    def __getitem__(self, idx):
        return self

    def __call__(self, *args, **kwargs):
        return self

    def __eq__(self, other):
        return self

    def __ne__(self, other):
        return self

    def __lt__(self, other):
        return self

    def __le__(self, other):
        return self

    def __gt__(self, other):
        return self

    def __ge__(self, other):
        return self

    def __invert__(self):
        return self

    def __add__(self, other):
        return self

    def __radd__(self, other):
        return self

    def __sub__(self, other):
        return self

    def __rsub__(self, other):
        return self

    def __mul__(self, other):
        return self

    def __rmul__(self, other):
        return self

    def __div__(self, other):
        return self

    def __rdiv__(self, other):
        return self

    def __truediv__(self, other):
        return self

    def __rtruediv__(self, other):
        return self

    def __mod__(self, other):
        return self

    def __rmod__(self, other):
        return self

    def __and__(self, other):
        return self

    def __rand__(self, other):
        return self

    def __or__(self, other):
        return self

    def __ror__(self, other):
        return self

    def __str__(self):
        return '\nint table = 0;'

class BadKeyError(Exception):
    pass

def recurse_result(res, lang):
    if lang == 'cpp':
        return CPPResultBuilder().recurse(res)
    elif lang == 'c':
        return CResultBuilder().recurse(res)
    elif lang == 'reql':
        return ReQLResultBuilder().recurse(res)

def eval_result(result, lang):
    if isinstance(result, str):
        arrlen = lambda *args: {'func': 'arrlen'}
        b = lambda *args: {'func': 'b'}
        bag = lambda *args: {'func': 'bag'}
        Buffer = lambda *args: {'func': 'Buffer'}
        err = lambda *args: {'func': 'err'}
        err_regex = lambda *args: {'func': 'err_regex'}
        errmsg = lambda *args: {'func': 'errmsg'}
        erroredres = lambda *args: {'func': 'erroredres'}
        float_cmp = lambda *args: {'func': 'float_cmp'}
        int_cmp = lambda *args: {'func': 'int_cmp'}
        mid = lambda *args: {'func': 'mid'}
        partial = lambda *args: {'func': 'partial'}
        post = lambda *args: {'func': 'post'}
        pre = lambda *args: {'func': 'pre'}
        rows = r.row
        rt1 = lambda *args: {'func': 'rt1'}
        rt2 = lambda *args: {'func': 'rt2'}
        rt3 = lambda *args: {'func': 'rt3'}
        rt4 = lambda *args: {'func': 'rt4'}
        rts = lambda *args: {'func': 'rts'}
        s = lambda *args: {'func': 's'}
        uuid = lambda *args: {'func': 'uuid'}

        true = True
        false = False
        nil = null = None

        result = result.replace('=>', ':')
        try:
            result = eval(result)
        except:
            print(result)
            raise
        else:
            return recurse_result(result, lang)
    elif isinstance(result, collections.Mapping):
        res = result.get('js')
        if res:
            try:
                return eval_result(res, lang)
            except BadKeyError:
                pass
        res = result.get('py')
        if res:
            try:
                return eval_result(res, lang)
            except BadKeyError:
                pass
        res = result.get('rb')
        if res:
            try:
                return eval_result(res, lang)
            except BadKeyError:
                pass
        res = result.get('cd')
        if res:
            try:
                return eval_result(res, lang)
            except BadKeyError:
                pass
        return recurse_result(result, lang)
    elif isinstance(result, (collections.Iterable, numbers.Number, type(None))):
        return recurse_result(result, lang)
    else:
        return recurse_result({'reql_ast_obj': type(result)}, lang)

def mkdir(path):
    try:
        path.mkdir(parents=True)
    except FileExistsError:
        pass

def touch(path):
    if not path.exists():
        mkdir(path.parent)
        path.touch()
    return path.open('w')

def get_tables(test):
    try:
        return re.findall('([a-zA-Z\d\.\_\-]+)', test['table_variable_name'])
    except KeyError:
        pass
    return ['tbl']

def eval_section(section, tables):
    tables['null'] = None
    try:
        return str(eval(section, None, tables))
    except:
        pass
    return ''

def eval_definition(definition, tables, lang):
    try:
        exec(definition, None, tables)
    except:
        pass
    else:
        return str(definition)
    return str(definition)

def convert_tests(tests, lang):
    lang_tests = []
    tables = {table: TestTable(table) for table in get_tables(tests)}
    for i, test in enumerate(tests['tests']):
        lang_test = []
        definitions = test.get('def')
        if definitions:
            definitions = eval_definition(definitions, tables, lang)
#            lang_tests.append(definitions)
        section = test.get('py', test.get('cd'))
        if section:
#            if isinstance(section, str):
#                lang_test.append(eval_section(section, tables))
#            elif isinstance(section, list):
#                lang_test.append('\n'.join([eval_section(s, tables) for s in section]))
            try:
                lang_test.append(eval_result(test.get('ot', {'result': 'blank'}), lang))
            except BadKeyError:
                lang_test.append(eval_result({'result': 'error'}, lang))
            lang_tests.append(section_shell.format(i, '\n'.join(lang_test)))
    return lang_tests

def test_loop(path, lang_path, lang):
    for file in path.glob('**/*.yaml'):
        each_test(path, file, lang_path, lang)
    for file in path.glob('**/*.test'):
        each_test(path, file, lang_path, lang)

def each_test(path, file, lang_path, lang):
    with file.open() as istream:
        tests = yaml.load(istream)

    test_file = file.relative_to(path)

    with touch((lang_path / test_file).with_suffix('.cpp')) as ostream:
        test_name = test_name_shell.format(lang, tests['desc'])
        if test_name in test_names:
            test_name = ' '.join([test_name, str(len(test_names))])
        test_names.add(test_name)
        ostream.write({
            'c': test_shell_c,
            'cpp': test_shell_cpp,
            'reql': test_shell_reql
        }[lang].format(
            test_name,
            '\n'.join(convert_tests(tests, lang))
        ))

def ast_name(lang, name):
    return "reql_{}_{}".format(lang, name.lower())

def has_opts(name):
    return name.upper() in (
        'CIRCLE', 'DELETE', 'DISTINCT', 'EQ_JOIN', 'FILTER', 'GET_ALL',
        'GET_INTERSECTING', 'GET_NEAREST', 'GROUP', 'HTTP', 'INDEX_CREATE',
        'INDEX_RENAME', 'ISO8601', 'JAVASCRIPT', 'ORDER_BY', 'RANDOM',
        'REPLACE', 'SLICE', 'TABLE', 'TABLE_CREATE', 'UPDATE')

def is_c_keyword(name):
    return name.upper() in ()

def is_cpp_keyword(name):
    return name.upper() in (
        'AND', 'DEFAULT', 'DELETE', 'NOT', 'OR', 'TIMEZONE', 'UNION'
        ) or is_c_keyword(name)

def is_objc_keyword(name):
    return name.upper() in () or is_c_keyword(name)

def is_lua_keyword(name):
    return name.upper() in ('AND', 'ERROR', 'NOT', 'OR')

def is_const_args_w_opts(name):
    return name.upper() in ('TABLE',)

def mangle_const(name, mangle):
    if mangle:
        return "{}{}".format(name.lower(), '_')
    return name.lower()

def mangle_c_const(name):
    return mangle_const(name, is_c_keyword(name))

def mangle_cpp_const(name):
    return mangle_const(name, is_cpp_keyword(name))

def mangle_lua_const(name):
    return mangle_const(name, is_lua_keyword(name))

def mangle_objc_const(name):
    return mangle_const(name, is_objc_keyword(name))

def regx(conv):
    return re.compile(
        "{}.*{}".format(re.escape(conv('ADD')), re.escape(conv('ZIP'))), re.S)

def build_output(f_name, m, join_str, regex):
    with open(f_name, 'w') as f:
        f.write(m.string[:m.start()])
        f.write(join_str.join(map(RethinkDB.Term.TermType.constants.sort(), regex)))
        f.write(m.string[m.end():])

def build(f_name, regex, join_str = "\n"):
    m = None

    with open(f_name) as f:
        m = regx(regex).match(f.read())

    if m:
        build_output(f_name, m, join_str, regex)

def cpp_term_imp(name):
    return """{2}
Query
Query::{0}(const Types::array &args) const {{
  return init(_C::{1}, this, args);
}}
Query
{0}(const Types::array &args) {{
  return init(_C::{1}, args);
}}""".format(
        mangle_cpp_const(name), c_ast_name(name),
        """
Query
Query::{0}(const Types::array &args, const Types::object &kwargs) const {{
  return init(_C::{1}, this, args, kwargs);
}}
Query
{0}(const Types::array &args, const Types::object &kwargs) {{
  return init(_C::{1}, args, kwargs);
}}""".format(
        mangle_cpp_const(name), c_ast_name(name)
    ) if has_opts(name) else '')

def cpp_term_class(name):
    return """
/**
 */{}
Query
{}(const Types::array &args) const;""".format("""
Query
{}(const Types::array &args, const Types::object &kwargs) const;
""".format(
        mangle_cpp_const(name)) if has_opts(name) else '',
        mangle_cpp_const(name))

def cpp_term_def(name):
    return """
/**
 */#{
  "
Query
#{
  mangle_cpp_const name
}(const Types::array &args, const Types::object &kwargs);" if opts? name
}
Query
#{mangle_cpp_const name}(const Types::array &args);"""

def lua_term_imp(name):
    return """
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
}"""

def lua_term_def(name):
    return """
/**
 */
extern int
#{lua_ast_name name}(lua_State *L);"""

def node_term_imp(name):
    return """
v8::Handle<v8::Value>
#{node_ast_name name}(const v8::Arguments& args) {
  v8::HandleScope scope;

  v8::Local<v8::Object> obj = v8::Object::New();

  if (!args[0]->IsUndefined()) {
  }

  return scope.Close(obj);
}"""

def node_term_def(name):
    return """
/**
 */
v8::Handle<v8::Value>
#{node_ast_name name}(const v8::Arguments& args);"""

def objc_term_def(name):
    return """
/**
 */
-(instancetype)
#{mangle_objc_const name}:(NSArray *)args#{' :(NSDictionary *)kwargs' if opts? name};"""

def objc_term_imp(name):
    return """
-(instancetype)
#{mangle_objc_const name}:(NSArray *)args#{' :(NSDictionary *)kwargs' if opts? name} {
  return self;
}"""

def py_term_imp(name):
    return """
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
}"""

def py_term_def(name):
    return """
/**
 */
extern PyObject *
#{py_ast_name name}(PyObject *self, PyObject *args, PyObject *kwargs);"""

def rb_term_imp(name):
    return """
extern VALUE
#{rb_ast_name name}(int argn, VALUE *args, VALUE self) {
  return self;
}"""

def rb_term_def(name):
    return """
/**
 */
extern VALUE
#{rb_ast_name name}(int argn, VALUE *args, VALUE self);"""

def c_term_imp(name):
    return """
extern ReQL_t *
reql_#{name.downcase}(ReQL_t **args#{', ReQL_t **kwargs' if opts? name}) {
  return reql_term(REQL_#{name}, args, #{if opts? name then 'kwargs' else 'NULL' end});
}"""

def c_term_def(name):
    return """
/**
 */
extern ReQL_t *
reql_#{name.downcase}(ReQL_t **args#{', ReQL_t **kwargs' if opts? name});"""

def term_imp(name):
    return """
extern void
#{c_ast_name name}(ReQL_Obj_t *t, ReQL_Obj_t *a#{', ReQL_Obj_t *k' if opts? name}) {
  reql_term_init(t, REQL_#{name}, a, #{if opts? name then 'k' else 'NULL' end});
}"""

def term_def(name):
    return """
/**
 */
extern void
#{c_ast_name name}(ReQL_Obj_t *t, ReQL_Obj_t *a#{', ReQL_Obj_t *k' if opts? name});"""

def enum_def(name):
    return "REQL_#{name} = #{RethinkDB::Term::TermType.const_get name}"

def lua_lib(name):
    return "{\"#{mangle_lua_const name}\", #{lua_ast_name name}},"

def main():
    cwd_path = Path('.')

    base_path = cwd_path / 'rethinkdb' / 'test'
    polyglot_path = base_path / 'rql_test' / 'src'

    tests_path = cwd_path / 'test'

    new_test_c_path = tests_path / 'c' / 'polyglot'
    mkdir(new_test_c_path)

    test_loop(polyglot_path, new_test_c_path.resolve(), 'c')

    new_test_cpp_path = tests_path / 'cpp' / 'polyglot'
    mkdir(new_test_cpp_path)

    test_loop(polyglot_path, new_test_cpp_path.resolve(), 'cpp')

    new_test_reql_path = tests_path / 'reql' / 'polyglot'
    mkdir(new_test_reql_path)

    test_loop(polyglot_path, new_test_reql_path.resolve(), 'reql')

    start_guard = re.compile(r'''
\#ifndef\s+(\w+)\s+
\#define\s+\1
(?P<cpp>
    \s+
    \#ifdef\s+__cplusplus\s+
    extern\s+"C"\s+{\s+
    \#endif
)?
''',
        re.I | re.X)
    end_guard = re.compile(r'''
(?P<cpp>
    \#ifdef\s+__cplusplus\s+
    }\s+
    \#endif\s+
)?
\#endif(\s*//\s*\w+)?.*\s*$
''',
        re.I | re.X)

    for file in (Path('.') / 'src').glob('**/*.h'):
        src = None
        with file.open() as istream:
            src = istream.read()
            start = start_guard.search(src)
            if start:
                end = end_guard.search(src)
                if end:
                    if start.group('cpp') and end.group('cpp'):
                        src = None
                    else:
                        guard = start.group(1)
                        src = ''.join([
                            src[:start.start()],
                            '#ifndef {0}\n#define {0}\n\n'.format(guard),
                            '#ifdef __cplusplus\nextern "C" {\n#endif',
                            src[start.end():end.start()],
                            '#ifdef __cplusplus\n}\n#endif\n\n',
                            '#endif  // {}\n'.format(guard)
                            ])
                else:
                    print('no header guard close found in', file)
                    src = None
            else:
                print('no header guard found in', file)
                src = None
        if src:
            with file.open('w') as ostream:
                ostream.write(src)

    headers = list((Path('.') / 'src' / 'c').glob('**/*.h'))
    headers.extend((Path('.') / 'src' / 'cpp').glob('**/*.h'))
    headers.extend((Path('.') / 'src' / 'reql').glob('**/*.h'))
    headers.extend((Path('.') / 'src' / 'c').glob('**/*.hpp'))
    headers.extend((Path('.') / 'src' / 'cpp').glob('**/*.hpp'))
    headers.extend((Path('.') / 'src' / 'reql').glob('**/*.hpp'))
    headers.extend((Path('.') / 'test' / 'c').glob('**/*.h'))
    headers.extend((Path('.') / 'test' / 'cpp').glob('**/*.h'))
    headers.extend((Path('.') / 'test' / 'reql').glob('**/*.h'))
    headers.extend((Path('.') / 'test' / 'c').glob('**/*.hpp'))
    headers.extend((Path('.') / 'test' / 'cpp').glob('**/*.hpp'))
    headers.extend((Path('.') / 'test' / 'reql').glob('**/*.hpp'))
    headers.extend([
        Path('.') / 'src' / 'ReQL.h',
        Path('.') / 'src' / 'ReQL.hpp'])

    headers = [path.relative_to(Path('.')).as_posix() for path in headers]
    headers = sorted(headers)

    sources = list((Path('.') / 'src' / 'c').glob('**/*.c'))
    sources.extend((Path('.') / 'src' / 'cpp').glob('**/*.c'))
    sources.extend((Path('.') / 'src' / 'reql').glob('**/*.c'))
    sources.extend((Path('.') / 'src' / 'c').glob('**/*.cpp'))
    sources.extend((Path('.') / 'src' / 'cpp').glob('**/*.cpp'))
    sources.extend((Path('.') / 'src' / 'reql').glob('**/*.cpp'))
    sources.extend((Path('.') / 'test' / 'c').glob('**/*.c'))
    sources.extend((Path('.') / 'test' / 'cpp').glob('**/*.c'))
    sources.extend((Path('.') / 'test' / 'reql').glob('**/*.c'))
    sources.extend((Path('.') / 'test' / 'c').glob('**/*.cpp'))
    sources.extend((Path('.') / 'test' / 'cpp').glob('**/*.cpp'))
    sources.extend((Path('.') / 'test' / 'reql').glob('**/*.cpp'))
    sources.extend([
        Path('.') / 'test' / 'main.cpp'])

    sources = [path.relative_to(Path('.')).as_posix() for path in sources]
    sources = sorted(sources)

    with (Path('.') / 'CMakeLists.txt').open() as istream:
        src = istream.read()


    src = re.sub(
        'set\(MOC_HEADERS.*?\)',
        lambda m: 'set(MOC_HEADERS\n {}\n)'.format(
            '\n '.join(headers)),
        re.sub(
            'set\(SOURCES.*?\)',
            lambda m: 'set(SOURCES\n {}\n)'.format(
                '\n '.join(sources)),
            src, 1, re.S),
        1, re.S)

    with (Path('.') / 'CMakeLists.txt').open('w') as ostream:
        ostream.write(src)

    return

    build('src/Lua/ReQL.c', lua_lib, "\n  ")
    build('src/reql/expr.h', enum_def, ",\n  ")
    build('src/reql/ast.h', term_def)
    build('src/reql/ast.c', term_imp)
    build('src/c/query.h', c_term_def)
    build('src/c/query.c', c_term_imp)
    build('src/Ruby/ast.h', rb_term_def)
    build('src/Ruby/ast.c', rb_term_imp)
    build('src/Python/ast.h', py_term_def)
    build('src/Python/ast.c', py_term_imp)
    build('libReQL/Query.m', objc_term_imp)
    build('libReQL/Query.h', objc_term_def)
    build('src/Node/ast.hpp', node_term_def)
    build('src/Node/ast.cpp', node_term_imp)
    build('src/Lua/ast.h', lua_term_def)
    build('src/Lua/ast.c', lua_term_imp)
    build('src/cpp/query.hpp', cpp_term_def)
    build('src/cpp/query.hpp', cpp_term_class)
    build('src/cpp/query.cpp', cpp_term_imp)

if __name__ == '__main__':
    main()
