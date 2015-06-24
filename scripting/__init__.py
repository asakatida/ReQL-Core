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

from . import test_results

test_names = set()

test_name_shell = '{} {}'

test_shell_objc = '''// Copyright 2015 Adam Grandquist

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <libReQL.h>

@interface {0} : XCTestCase

@end

@implementation {0}

{1}

@end
'''

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

section_shell_objc = '''
- (void)test{} {{
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
{}
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}}'''

section_shell = '''
  SECTION("test{}") {{{}
  }}'''

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
    tables = {table: test_results.TestTable(table) for table in get_tables(tests)}
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
                lang_test.append(test_results.eval_result(test.get('ot', {'result': 'blank'}), lang))
            except test_results.BadKeyError:
                lang_test.append(test_results.eval_result({'result': 'error'}, lang))
            if lang == 'objc':
                lang_tests.append(section_shell_objc.format(i, '\n'.join(lang_test)))
            else:
                lang_tests.append(section_shell.format(i, '\n'.join(lang_test)))
    return lang_tests

def test_loop(path, lang_path, lang):
    for file in path.glob('**/*.yaml'):
        each_test(path, file, lang_path, lang)
    for file in path.glob('**/*.test'):
        each_test(path, file, lang_path, lang)

def convert_objc_test_name(name):
    return ''.join(s for s in name.title() if s.isalnum())

def each_test(path, file, lang_path, lang):
    with file.open() as istream:
        tests = yaml.load(istream)

    test_file = file.relative_to(path)

    with touch((lang_path / test_file).with_suffix('.m' if lang == 'objc' else '.cpp')) as ostream:
        test_name = test_name_shell.format(lang, tests['desc'])
        if test_name in test_names:
            test_name = ' '.join([test_name, str(len(test_names))])
        test_names.add(test_name)
        ostream.write({
            'c': test_shell_c,
            'objc': test_shell_objc,
            'cpp': test_shell_cpp,
            'reql': test_shell_reql
        }[lang].format(
            convert_objc_test_name(test_name) if lang == 'objc' else test_name,
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

def regx(regex):
    return "{}.*{}".format(re.escape(regex('ADD')), re.escape(regex('ZIP')))

REQL_TERM_TYPES = [e for e in dir(ql2_pb2.Term.TermType) if not e.startswith('_')]
REQL_TERM_TYPES.sort()

def build_output(f_name, m, join_str, regex):
    with f_name.open('w') as f:
        f.write(m.string[:m.start()])
        f.write(join_str.join(map(regex, REQL_TERM_TYPES)))
        f.write(m.string[m.end():])

def build(f_name, regex, join_str = "\n"):
    m = None

    with f_name.open() as f:
        m = re.search(regx(regex), f.read(), re.S)

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
        mangle_cpp_const(name), ast_name('ast', name),
        """
Query
Query::{0}(const Types::array &args, const Types::object &kwargs) const {{
  return init(_C::{1}, this, args, kwargs);
}}
Query
{0}(const Types::array &args, const Types::object &kwargs) {{
  return init(_C::{1}, args, kwargs);
}}""".format(
        mangle_cpp_const(name), ast_name('ast', name)
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
 */{}
Query
{}(const Types::array &args);""".format("""
Query
{}(const Types::array &args, const Types::object &kwargs);""".format(
    mangle_cpp_const(name)) if has_opts(name) else '',
    mangle_cpp_const(name))

def lua_term_imp(name):
    return """
extern int
{}(lua_State *L) {{
  return reql_lua_{}(L, {}{});
}}""".format(
    ast_name('lua', name),
    'get_opts' if has_opts(name) else 'ast_class',
    ast_name('ast', name),
    '' if has_opts(name) else ', NULL')

def lua_term_def(name):
    return """
/**
 */
extern int
{}(lua_State *L);""".format(ast_name('lua', name))

def node_term_imp(name):
    return """
v8::Handle<v8::Value>
{}(const v8::Arguments& args) {{
  v8::HandleScope scope;

  v8::Local<v8::Object> obj = v8::Object::New();

  if (!args[0]->IsUndefined()) {{
  }}

  return scope.Close(obj);
}}""".format(ast_name('node', name))

def node_term_def(name):
    return """
/**
 */
v8::Handle<v8::Value>
{}(const v8::Arguments& args);""".format(ast_name('node', name))

def objc_term_def(name):
    return """
/**
 */
+(instancetype)
{0}:(NSArray *)args{1};
-(instancetype)
{0}:(NSArray *)args{1};""".format(
    mangle_objc_const(name),
    ' :(NSDictionary *)kwargs' if has_opts(name) else '')

def objc_term_imp(name):
    return """
+(instancetype)
{0}:(NSArray *)args{1} {{
  return [self newTerm:{2} :args{3}];
}}

-(instancetype)
{0}:(NSArray *)args{1} {{
  return [self newTerm:{2} :args{3}];
}}""".format(
    mangle_objc_const(name),
    ' :(NSDictionary *)kwargs' if has_opts(name) else '',
    ast_name('ast', name),
    ' :kwargs' if has_opts(name) else '')

def py_term_imp(name):
    return """
extern PyObject *
{}(PyObject *self, PyObject *args, PyObject *kwargs) {{
  PyObject *val;

  static char *kwlist[] = {{NULL}};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, \"o:r.{}\", kwlist, &val)) {{
    return self;
  }}

  return val;
}}""".format(ast_name('py', name), name.lower())

def py_term_def(name):
    return """
/**
 */
extern PyObject *
{}(PyObject *self, PyObject *args, PyObject *kwargs);""".format(ast_name('py', name))

def rb_term_imp(name):
    return """
extern VALUE
{}(int argn, VALUE *args, VALUE self) {{
  return self;
}}""".format(ast_name('rb', name))

def rb_term_def(name):
    return """
/**
 */
extern VALUE
{}(int argn, VALUE *args, VALUE self);""".format(ast_name('rb', name))

def c_term_imp(name):
    return """
extern ReQL_t *
reql_{}(ReQL_t **args{}) {{
  return reql_term{}({}, args{});
}}""".format(
    name.lower(),
    ', ReQL_t **kwargs' if has_opts(name) else '',
    '_kwargs' if has_opts(name) else '',
    ast_name('ast', name),
    ', kwargs' if has_opts(name) else '')

def c_term_def(name):
    return """
/**
 */
extern ReQL_t *
reql_{}(ReQL_t **args{});""".format(
    name.lower(),
    ', ReQL_t **kwargs' if has_opts(name) else '')

def term_imp(name):
    return """
extern void
{}(ReQL_Obj_t *t, ReQL_Obj_t *a{}) {{
  reql_term_init(t, REQL_{}, a, {});
}}""".format(
    ast_name('ast', name),
    ', ReQL_Obj_t *k' if has_opts(name) else '',
    name,
    'k' if has_opts(name) else 'NULL')

def term_def(name):
    return """
/**
 */
extern void
{}(ReQL_Obj_t *t, ReQL_Obj_t *a{});""".format(
    ast_name('ast', name),
    ', ReQL_Obj_t *k' if has_opts(name) else '')

def enum_def(name):
    return "REQL_{} = {}".format(name, getattr(ql2_pb2.Term.TermType, name))

def lua_lib(name):
    return "{{\"{}\", {}}},".format(mangle_lua_const(name), ast_name('lua', name))

def assert_c_header_extern_c(paths):
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

    for file in paths:
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
