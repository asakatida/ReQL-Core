import re

import scripting

from pathlib import Path

def gather_c_files(path, *subs):
    cfiles = list()
    hfiles = list()
    for sub in subs:
        cfiles.extend((path / sub).glob('**/*.c'))
        cfiles.extend((path / sub).glob('**/*.cpp'))
        hfiles.extend((path / sub).glob('**/*.h'))
        hfiles.extend((path / sub).glob('**/*.hpp'))
    return sorted(f.relative_to(path).as_posix() for f in cfiles), sorted(f.relative_to(path).as_posix() for f in hfiles)

def write_cmake(path, cextras, hextras):
    cmake_list_path = path / 'CMakeLists.txt'

    with cmake_list_path.open() as istream:
        src = istream.read()

    sources, headers = gather_c_files(path, 'cpp', 'reql')

    src = re.sub(
        'set\(MOC_HEADERS.*?\)',
        lambda m: 'set(MOC_HEADERS\n {}\n)'.format(
            '\n '.join(headers + hextras)),
        re.sub(
            'set\(SOURCES.*?\)',
            lambda m: 'set(SOURCES\n {}\n)'.format(
                '\n '.join(sources + cextras)),
            src, 1, re.S),
        1, re.S)

    with cmake_list_path.open('w') as ostream:
        ostream.write(src)


def main():
    cwd_path = Path('.')

    base_path = cwd_path / 'rethinkdb' / 'test'
    polyglot_path = base_path / 'rql_test' / 'src'

    libreql_test_path = cwd_path / 'test'

    new_test_c_path = libreql_test_path / 'c' / 'polyglot'
    scripting.mkdir(new_test_c_path)

    scripting.test_loop(polyglot_path, new_test_c_path.resolve(), 'c')

    new_test_cpp_path = libreql_test_path / 'cpp' / 'polyglot'
    scripting.mkdir(new_test_cpp_path)

    scripting.test_loop(polyglot_path, new_test_cpp_path.resolve(), 'cpp')

    new_test_objc_path = cwd_path / 'libReQLTests' / 'polyglot'
    scripting.mkdir(new_test_objc_path)

    scripting.test_loop(polyglot_path, new_test_objc_path.resolve(), 'objc')

    libreql_src_path = cwd_path / 'src'

    scripting.assert_c_header_extern_c(libreql_src_path.glob('**/*.h'))

    write_cmake(libreql_src_path, [], ['ReQL.h', 'ReQL.hpp'])
    write_cmake(libreql_test_path, ['main.cpp'], ['catch.hpp'])

    objc_src_path = cwd_path / 'libReQL'

    scripting.build(objc_src_path / 'Query.h', scripting.objc_term_def)
    scripting.build(objc_src_path / 'Query.mm', scripting.objc_term_imp)
    scripting.build(libreql_src_path / 'reql' / 'query.c', scripting.c_term_imp)
    scripting.build(libreql_src_path / 'reql' / 'query.h', scripting.c_term_def)
    scripting.build(libreql_src_path / 'reql' / 'query.hpp', scripting.cpp_term_imp)
    scripting.build(libreql_src_path / 'Lua' / 'query.cpp', scripting.lua_term_imp)
    scripting.build(libreql_src_path / 'Lua' / 'query.hpp', scripting.lua_term_def)
    scripting.build(libreql_src_path / 'Lua' / 'ReQL.cpp', scripting.lua_lib, "\n  ")
    scripting.build(libreql_src_path / 'Node' / 'ast.cpp', scripting.node_term_imp)
    scripting.build(libreql_src_path / 'Node' / 'ast.hpp', scripting.node_term_def)
    scripting.build(libreql_src_path / 'Python' / 'query.c', scripting.py_term_imp)
    scripting.build(libreql_src_path / 'Python' / 'types.c', scripting.py_term_method_imp)
    scripting.build(libreql_src_path / 'Python' / 'query.h', scripting.py_term_def)
    scripting.build(libreql_src_path / 'Python' / 'ReQL.c', scripting.py_lib, "\n  ")
    scripting.build(libreql_src_path / 'reql' / 'core' / 'query.hpp', scripting.enum_def, ",\n  ")
    scripting.build(libreql_src_path / 'Ruby' / 'ast.c', scripting.rb_term_imp)
    scripting.build(libreql_src_path / 'Ruby' / 'ast.h', scripting.rb_term_def)

if __name__ == '__main__':
    main()
