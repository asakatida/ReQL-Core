import ql2_pb2

from itertools import starmap


term_func_c = '''
/**
 */
_ReQL_Op_t *_reql_{}(_ReQL_Op_t *args, _ReQL_Op_t *kwargs) {{
  _ReQL_Op_t *term = _reql_expr_null();
  term->tt = _REQL_{};
  term->dt = _REQL_R_JSON;
  term->child = args;
  term->next = kwargs;
  return term;
}}'''
term_func_cpp = '''
/**
 */
void ReQL_ast::{}() {{
}}'''
term_func_lua = '''
/**
 */
static int _reql_lua_{}(lua_State *L) {{
  return 1;
}}'''
term_func_node = '''
/**
 */
Handle<Value> _reql_node_{}(const Arguments& args) {{
}}'''
term_func_objc = '''
/**
 */
-(instancetype) {} {{
  return self;
}}'''
term_func_python = '''
/**
 */
static PyObject *_reql_py_{}(PyObject *self, PyObject *args, PyObject *kwargs) {{
}}'''
term_func_ruby = '''
/**
 */
static VALUE _reql_rb_{}(int argn, VALUE *args, VALUE self) {{
}}'''
term_head_c = '''
/**
 */
_ReQL_Op_t *_reql_{}(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);'''
term_head_cpp = '''
/**
 */
  void {}();'''
term_head_lua = '''
/**
 */
static int _reql_lua_{}(lua_State *L);'''
term_head_node = '''
/**
 */
Handle<Value> _reql_node_{}(const Arguments& args);'''
term_head_objc = '''
/**
 */
-(instancetype){};'''
term_head_python = '''
/**
 */
static PyObject *_reql_py_{}(PyObject *self, PyObject *args, PyObject *kwargs);'''
term_head_ruby = '''
/**
 */
static VALUE _reql_rb_{}(int argn, VALUE *args, VALUE self);'''


def filter_names(obj):
    return filter(lambda v: not v.startswith('_'), dir(obj))


def write_terms(file_name, term_func):
    with open(file_name, 'r') as io:
        src = io.read()

    src = '\n'.join(
        [
            src[:src.find('/* start generated terms */')] +
            '/* start generated terms */'
        ] + [
            term_func.format(t.lower(), t)
            for t in filter_names(ql2_pb2.Term.TermType)
        ] + [
            src[src.find('/* end generated terms */'):]
        ]
    )

    with open(file_name, 'w') as io:
        io.write(src)


def write_header(file_name, term_head):
    with open(file_name, 'r') as io:
        src = io.read()

    src = '\n'.join(
        [
            src[:src.find('/* start generated header */')] +
            '/* start generated header */'
        ] + [
            term_head.format(t.lower(), t)
            for t in filter_names(ql2_pb2.Term.TermType)
        ] + [
            src[src.find('/* end generated header */'):]
        ]
    )

    with open(file_name, 'w') as io:
        io.write(src)


def make_enum(enum):
    return ''.join((
        'enum {\n  ',
        ',\n  '.join([
            '_REQL_{} = {}'.format(
                e, getattr(enum, e)
            ) for e in filter_names(enum)
        ]),
        '\n};'
    ))


def main():
    with open('ReQL-ast.h', 'r') as io:
        src = io.read()

    start_constants = src.find('/* start generated constants */')
    end_constants = src.find('/* end generated constants */')

    if len(tuple(filter_names(ql2_pb2.VersionDummy.Version))) > 3:
        print('new version found')

    if len(tuple(filter_names(ql2_pb2.VersionDummy.Protocol))) > 2:
        print('new protocol found')

    version = '''
enum {{
  _REQL_VERSION = {},
  _REQL_PROTOCOL = {}
}};'''.format(
        hex(ql2_pb2.VersionDummy.Version.V0_3),
        hex(ql2_pb2.VersionDummy.Protocol.JSON)
    )

    queries = make_enum(ql2_pb2.Query.QueryType)
    responces = make_enum(ql2_pb2.Response.ResponseType)
    terms = make_enum(ql2_pb2.Term.TermType)
    datums = make_enum(ql2_pb2.Datum.DatumType)

    constants = '\n'.join((
        '/* start generated constants */',
        version, queries, responces, datums, terms,
        ''
    ))

    src = ''.join((src[:start_constants], constants, src[end_constants:]))

    with open('ReQL-ast.h', 'w') as io:
        io.write(src)

    tuple(starmap(
        write_terms,
        (
            ('ReQL-ast.c', term_func_c),
            ('ReQL-ast-CPP.cpp', term_func_cpp),
            ('ReQL-ast-Lua.c', term_func_lua),
            ('ReQL-ast-Node.cpp', term_func_node),
            ('ReQL-ast-ObjC.m', term_func_objc),
            ('ReQL-ast-Python.c', term_func_python),
            ('ReQL-ast-Ruby.c', term_func_ruby)
        )
    ))
    tuple(starmap(
        write_header,
        (
            ('ReQL-ast.h', term_head_c),
            ('ReQL-ast-CPP.hpp', term_head_cpp),
            ('ReQL-ast-Lua.h', term_head_lua),
            ('ReQL-ast-Node.hpp', term_head_node),
            ('ReQL-ast-ObjC.h', term_head_objc),
            ('ReQL-ast-Python.h', term_head_python),
            ('ReQL-ast-Ruby.h', term_head_ruby)
        )
    ))


if __name__ == '__main__':
    main()
