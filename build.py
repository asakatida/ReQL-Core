import re

import scripting

from pathlib import Path

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

    new_test_reql_path = libreql_test_path / 'reql' / 'polyglot'
    scripting.mkdir(new_test_reql_path)

    scripting.test_loop(polyglot_path, new_test_reql_path.resolve(), 'reql')

    new_test_objc_path = cwd_path / 'libReQLTests' / 'polyglot'
    scripting.mkdir(new_test_objc_path)

    scripting.test_loop(polyglot_path, new_test_objc_path.resolve(), 'objc')

    libreql_src_path = cwd_path / 'src'

    scripting.assert_c_header_extern_c(libreql_src_path.glob('**/*.h'))

    headers = list((libreql_src_path / 'c').glob('**/*.h'))
    headers.extend((libreql_src_path / 'cpp').glob('**/*.h'))
    headers.extend((libreql_src_path / 'reql').glob('**/*.h'))
    headers.extend((libreql_src_path / 'c').glob('**/*.hpp'))
    headers.extend((libreql_src_path / 'cpp').glob('**/*.hpp'))
    headers.extend((libreql_src_path / 'reql').glob('**/*.hpp'))
    headers.extend((libreql_test_path / 'c').glob('**/*.h'))
    headers.extend((libreql_test_path / 'cpp').glob('**/*.h'))
    headers.extend((libreql_test_path / 'reql').glob('**/*.h'))
    headers.extend((libreql_test_path / 'c').glob('**/*.hpp'))
    headers.extend((libreql_test_path / 'cpp').glob('**/*.hpp'))
    headers.extend((libreql_test_path / 'reql').glob('**/*.hpp'))
    headers.extend([libreql_src_path / 'ReQL.h', libreql_src_path / 'ReQL.hpp'])

    headers = [path.relative_to(cwd_path).as_posix() for path in headers]
    headers = sorted(headers)

    sources = list((libreql_src_path / 'c').glob('**/*.c'))
    sources.extend((libreql_src_path / 'cpp').glob('**/*.c'))
    sources.extend((libreql_src_path / 'reql').glob('**/*.c'))
    sources.extend((libreql_src_path / 'c').glob('**/*.cpp'))
    sources.extend((libreql_src_path / 'cpp').glob('**/*.cpp'))
    sources.extend((libreql_src_path / 'reql').glob('**/*.cpp'))
    sources.extend((libreql_test_path / 'c').glob('**/*.c'))
    sources.extend((libreql_test_path / 'cpp').glob('**/*.c'))
    sources.extend((libreql_test_path / 'reql').glob('**/*.c'))
    sources.extend((libreql_test_path / 'c').glob('**/*.cpp'))
    sources.extend((libreql_test_path / 'cpp').glob('**/*.cpp'))
    sources.extend((libreql_test_path / 'reql').glob('**/*.cpp'))
    sources.extend([libreql_test_path / 'main.cpp'])

    sources = sorted(path.relative_to(cwd_path).as_posix() for path in sources)

    cmake_list_path = cwd_path / 'CMakeLists.txt'

    with cmake_list_path.open() as istream:
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

    with cmake_list_path.open('w') as ostream:
        ostream.write(src)

    objc_src_path = cwd_path / 'libReQL'

    scripting.build(objc_src_path / 'Query.h', scripting.objc_term_def)
    scripting.build(objc_src_path / 'Query.m', scripting.objc_term_imp)
    scripting.build(libreql_src_path / 'c' / 'query.c', scripting.c_term_imp)
    scripting.build(libreql_src_path / 'c' / 'query.h', scripting.c_term_def)
    scripting.build(libreql_src_path / 'cpp' / 'query.cpp', scripting.cpp_term_imp)
    scripting.build(libreql_src_path / 'cpp' / 'query.hpp', scripting.cpp_term_def)
    scripting.build(libreql_src_path / 'cpp' / 'query.hpp', scripting.cpp_term_class)
    scripting.build(libreql_src_path / 'Lua' / 'ast.c', scripting.lua_term_imp)
    scripting.build(libreql_src_path / 'Lua' / 'ast.h', scripting.lua_term_def)
    scripting.build(libreql_src_path / 'Lua' / 'ReQL.c', scripting.lua_lib, "\n  ")
    scripting.build(libreql_src_path / 'Node' / 'ast.cpp', scripting.node_term_imp)
    scripting.build(libreql_src_path / 'Node' / 'ast.hpp', scripting.node_term_def)
    scripting.build(libreql_src_path / 'Python' / 'query.c', scripting.py_term_imp)
    scripting.build(libreql_src_path / 'Python' / 'query.c', scripting.py_term_method_def)
    scripting.build(libreql_src_path / 'Python' / 'query.c', scripting.py_term_method_imp)
    scripting.build(libreql_src_path / 'Python' / 'query.h', scripting.py_term_def)
    scripting.build(libreql_src_path / 'Python' / 'ReQL.c', scripting.py_lib, "\n  ")
    scripting.build(libreql_src_path / 'reql' / 'query.c', scripting.enum_def, ",\n  ")
    scripting.build(libreql_src_path / 'reql' / 'query.c', scripting.term_imp)
    scripting.build(libreql_src_path / 'reql' / 'query.h', scripting.term_def)
    scripting.build(libreql_src_path / 'Ruby' / 'ast.c', scripting.rb_term_imp)
    scripting.build(libreql_src_path / 'Ruby' / 'ast.h', scripting.rb_term_def)

if __name__ == '__main__':
    main()
