import re

try:
    import yaml
except:
    print('PyYAML not installed')

from pathlib import Path

xrange = range

test_shell = '''// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("{1} {0}", "[{1}][ast]") {{
{2}
}}
'''

section_shell = '''
  SECTION("test{}") {{{}
  }}'''

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

r = TestTable('r')

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

def convert_tests(tests, lang):
    lang_tests = []
    tables = {table: TestTable(table) for table in get_tables(tests)}
    for i, test in enumerate(tests['tests']):
        lang_test = []
        definitions = test.get('def')
        if definitions:
            lang_test.append(eval_section(definitions, tables))
        section = test.get('py', test.get('cd'))
        if section:
            if isinstance(section, str):
                lang_test.append(eval_section(section, tables))
            elif isinstance(section, list):
                lang_test.append('\n'.join([eval_section(s, tables) for s in section]))
        result = test.get('ot')
        if result:
            lang_test.append(eval_section(result, tables))
        lang_tests.append(section_shell.format(i, '\n'.join(lang_test)))
    return lang_tests

def test_loop(path, c_path, cpp_path):
    for file in path.glob('**/*.yaml'):
        each_test(path, file, c_path, cpp_path)
    for file in path.glob('**/*.test'):
        each_test(path, file, c_path, cpp_path)

def each_test(path, file, c_path, cpp_path):
    with file.open() as istream:
        tests = yaml.load(istream)

    test_file = file.relative_to(path)

    with touch((c_path / test_file).with_suffix('.cpp')) as ostream:
        ostream.write(test_shell.format(
            tests['desc'],
            'c',
            '\n'.join(convert_tests(tests, 'c'))
        ))

    with touch((cpp_path / test_file).with_suffix('.cpp')) as ostream:
        ostream.write(test_shell.format(
            tests['desc'],
            'cpp',
            '\n'.join(convert_tests(tests, 'cpp'))
        ))

def main():
    cwd_path = Path('.')

    base_path = cwd_path / 'rethinkdb' / 'test'
    polyglot_path = base_path / 'rql_test' / 'src'

    tests_path = cwd_path / 'test'

    new_test_c_path = tests_path / 'c' / 'polyglot'
    mkdir(new_test_c_path)

    new_test_cpp_path = tests_path / 'cpp' / 'polyglot'
    mkdir(new_test_cpp_path)

    test_loop(polyglot_path, new_test_c_path.resolve(), new_test_cpp_path.resolve())

if __name__ == '__main__':
    main()
