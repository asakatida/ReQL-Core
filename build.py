import ql2_pb2


term_func_c = '''
_ReQL_Op_t *_reql_{}(_ReQL_arg_t *args, _ReQL_kwarg_t *kwargs) {{
  _ReQL_Op_t *term = _reql_expr_null();
  term->tt = _REQL_{};
  term->dt = _REQL_R_JSON;
  term->args = args;
  term->kwargs = kwargs;
  return term;
}}'''


term_func_cpp = '''
void ReQL::{}() {{
}}'''


term_func_lua = '''
static int _reql_lua_{}(lua_State *L) {{
  return 1;
}}'''


term_func_node = '''
Handle<Value> _reql_node_{}(const Arguments& args) {{
}}'''


term_func_python = '''
static PyObject *_reql_py_{}(PyObject *self, PyObject *args, PyObject *kwargs) {{
}}'''


term_func_ruby = '''
static VALUE _reql_rb_{}(int argn, VALUE *args, VALUE self) {{
}}'''


term_head_c = '_ReQL_Op_t *_reql_{}(_ReQL_arg_t *args, _ReQL_kwarg_t *kwargs);'
term_head_cpp = '    void {}();'
term_head_lua = 'static int _reql_lua_{}(lua_State *L);'
term_head_node = 'Handle<Value> _reql_node_{}(const Arguments& args);'
term_head_python = 'static PyObject *_reql_py_{}(PyObject *self, PyObject *args, PyObject *kwargs);'
term_head_ruby = 'static VALUE _reql_rb_{}(int argn, VALUE *args, VALUE self);'


def make_terms(src, term_func):
    return '\n'.join(
        [
            src[:src.find('/* start generated terms */')] +
            '/* start generated terms */'
        ] + [
            term_func.format(t.lower(), t)
            for t in dir(ql2_pb2.Term.TermType) if not t.startswith('_')
        ] + [
            src[src.find('/* end generated terms */'):]
        ]
    )


def make_header(src, term_head):
    return '\n'.join(
        [
            src[:src.find('/* start generated header */')] +
            '/* start generated header */'
        ] + [
            term_head.format(t.lower(), t)
            for t in dir(ql2_pb2.Term.TermType) if not t.startswith('_')
        ] + [
            src[src.find('/* end generated header */'):]
        ]
    )


def make_enum(enum):
    return ''.join((
        'enum {\n  ',
        ',\n  '.join([
            '_REQL_{} = {}'.format(
                e, getattr(enum, e)
            ) for e in dir(enum) if not e.startswith('_')
        ]),
        '\n};'
    ))


def main():
    with open('ReQL-ast.h', 'r') as io:
        src = io.read()

    start_constants = src.find('/* start generated constants */')
    end_constants = src.find('/* end generated constants */')

    versions = dir(ql2_pb2.VersionDummy.Version)

    versions = [v for v in versions if not v.startswith('_')]

    if len(versions) > 3:
        print('new version found')

    version = 'const int _REQL_VERSION = {};'.format(
        hex(ql2_pb2.VersionDummy.Version.V0_3)
    )

    protocols = dir(ql2_pb2.VersionDummy.Protocol)

    protocols = [p for p in protocols if not p.startswith('_')]

    if len(protocols) > 2:
        print('new protocol found')

    protocol = 'const int _REQL_PROTOCOL = {};'.format(
        hex(ql2_pb2.VersionDummy.Protocol.JSON)
    )

    queries = make_enum(ql2_pb2.Query.QueryType)
    responces = make_enum(ql2_pb2.Response.ResponseType)
    terms = make_enum(ql2_pb2.Term.TermType)
    datums = make_enum(ql2_pb2.Datum.DatumType)

    constants = '\n'.join((
        '/* start generated constants */',
        version, protocol, queries, responces, datums, terms,
        ''
    ))

    src = ''.join((src[:start_constants], constants, src[end_constants:]))

    start_header = src.find('/* start generated header */')
    end_header = src.find('/* end generated header */')

    term_creators = [src[:start_header] + '/* start generated header */'] + [
        '_ReQL_Op_t *_reql_{}(_ReQL_arg_t *args, _ReQL_kwarg_t *kwargs);'
        .format(
            t.lower()
        ) for t in dir(ql2_pb2.Term.TermType) if not t.startswith('_')
    ] + [src[end_header:]]

    src = '\n'.join(term_creators)

    with open('ReQL-ast.h', 'w') as io:
        io.write(src)

    for file_name, term_func in (
            ('ReQL-ast.c', term_func_c),
            ('ReQL-ast-CPP.cpp', term_func_cpp),
            ('ReQL-ast-Lua.c', term_func_lua),
            ('ReQL-ast-Node.cpp', term_func_node),
            ('ReQL-ast-Python.c', term_func_python),
            ('ReQL-ast-Ruby.c', term_func_ruby)):
        with open(file_name, 'r') as io:
            src = io.read()

        src = make_terms(src, term_func)

        with open(file_name, 'w') as io:
            io.write(src)

    for file_name, term_func in (
            ('ReQL-ast.h', term_head_c),
            ('ReQL-ast-CPP.hpp', term_head_cpp),
            ('ReQL-ast-Lua.h', term_head_lua),
            ('ReQL-ast-Node.hpp', term_head_node),
            ('ReQL-ast-Python.h', term_head_python),
            ('ReQL-ast-Ruby.h', term_head_ruby)):
        with open(file_name, 'r') as io:
            src = io.read()

        src = make_header(src, term_func)

        with open(file_name, 'w') as io:
            io.write(src)

if __name__ == '__main__':
    main()
