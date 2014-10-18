import ql2_pb2


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
    with open('ReQL.h', 'r') as io:
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

    with open('ReQL.h', 'w') as io:
        io.write(src)

    with open('ReQL.c', 'r') as io:
        src = io.read()

    start_terms = src.find('/* start generated terms */')
    end_terms = src.find('/* end generated terms */')

    term_creators = [src[:start_terms] + '/* start generated terms */'] + [
'''_ReQL_Op_t *_reql_{}(_ReQL_arg_t *args, _ReQL_kwarg_t *kwargs) {{
  _ReQL_Op_t *term = _reql_expr_null();
  term->tt = _REQL_{};
  term->dt = _REQL_R_JSON;
  term->args = args;
  term->kwargs = kwargs;
  return term;
}}'''.format(t.lower(), t)
        for t in dir(ql2_pb2.Term.TermType) if not t.startswith('_')
    ] + [src[end_terms:]]

    src = '\n'.join(term_creators)

    with open('ReQL.c', 'w') as io:
        io.write(src)


if __name__ == '__main__':
    main()
