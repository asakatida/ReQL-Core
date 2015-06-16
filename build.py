import re

import scripting

from pathlib import Path

def main():
    cwd_path = Path('.')

    base_path = cwd_path / 'rethinkdb' / 'test'
    polyglot_path = base_path / 'rql_test' / 'src'

    tests_path = cwd_path / 'test'

    new_test_c_path = tests_path / 'c' / 'polyglot'
    scripting.mkdir(new_test_c_path)

    scripting.test_loop(polyglot_path, new_test_c_path.resolve(), 'c')

    new_test_cpp_path = tests_path / 'cpp' / 'polyglot'
    scripting.mkdir(new_test_cpp_path)

    scripting.test_loop(polyglot_path, new_test_cpp_path.resolve(), 'cpp')

    new_test_reql_path = tests_path / 'reql' / 'polyglot'
    scripting.mkdir(new_test_reql_path)

    scripting.test_loop(polyglot_path, new_test_reql_path.resolve(), 'reql')

    new_test_objc_path = cwd_path / 'libReQLTests' / 'polyglot'
    scripting.mkdir(new_test_objc_path)

    scripting.test_loop(polyglot_path, new_test_objc_path.resolve(), 'objc')

    scripting.assert_c_header_extern_c((Path('.') / 'src').glob('**/*.h'))

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

    scripting.build('libReQL/Query.h', scripting.objc_term_def)
    scripting.build('libReQL/Query.m', scripting.objc_term_imp)
    scripting.build('src/c/query.c', scripting.c_term_imp)
    scripting.build('src/c/query.h', scripting.c_term_def)
    scripting.build('src/cpp/query.cpp', scripting.cpp_term_imp)
    scripting.build('src/cpp/query.hpp', scripting.cpp_term_def)
    scripting.build('src/cpp/query.hpp', scripting.cpp_term_class)
    scripting.build('src/Lua/ast.c', scripting.lua_term_imp)
    scripting.build('src/Lua/ast.h', scripting.lua_term_def)
    scripting.build('src/Lua/ReQL.c', scripting.lua_lib, "\n  ")
    scripting.build('src/Node/ast.cpp', scripting.node_term_imp)
    scripting.build('src/Node/ast.hpp', scripting.node_term_def)
    scripting.build('src/Python/ast.c', scripting.py_term_imp)
    scripting.build('src/Python/ast.h', scripting.py_term_def)
    scripting.build('src/reql/query.c', scripting.enum_def, ",\n  ")
    scripting.build('src/reql/query.c', scripting.term_imp)
    scripting.build('src/reql/query.h', scripting.term_def)
    scripting.build('src/Ruby/ast.c', scripting.rb_term_imp)
    scripting.build('src/Ruby/ast.h', scripting.rb_term_def)

if __name__ == '__main__':
    main()
