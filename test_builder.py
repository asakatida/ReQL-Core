import re

try:
    import yaml
except:
    print('PyYAML not installed')

from pathlib import Path

def mkdir(path):
    try:
        path.mkdir(parents=True)
    except FileExistsError:
        pass

def test_loop(path, c_path, cpp_path):
    for file in path.glob('**/*.yaml'):
        each_test(path, file, c_path, cpp_path)

def each_test(path, file, c_path, cpp_path):
    with file.open() as istream:
        test = yaml.load(istream)
        test_keys = test.keys()
        try:
            tables = re.findall('([a-zA-Z\d\.\_\-]+)', test['table_variable_name'])
        except KeyError:
            pass
        else:
            test['table_variable_name'] = tables
        test_file = file.relative_to(path)
        c_file = (c_path / test_file).with_suffix('.cpp')
        if not c_file.exists():
            mkdir(c_file)
            c_file.touch()
        with c_file.open('w') as ostream:
            yaml.dump(test, ostream)
        cpp_file = (cpp_path / test_file).with_suffix('.cpp')
        if not cpp_file.exists():
            mkdir(cpp_file)
            cpp_file.touch()
        with cpp_file.open('w') as ostream:
            yaml.dump(test, ostream)

def main():
    cwd_path = Path('.')

    base_path = cwd_path / 'rethinkdb' / 'test'
    polyglot_path = base_path / 'rql_test' / 'src'

    tests_path = cwd_path / 'test'

    new_test_c_path = (tests_path / 'c' / 'polyglot')
    mkdir(new_test_c_path)
    new_test_c_path = new_test_c_path.resolve()

    new_test_cpp_path = (tests_path / 'cpp' / 'polyglot')
    mkdir(new_test_cpp_path)
    new_test_cpp_path = new_test_cpp_path.resolve()

    test_loop(polyglot_path)

main()
