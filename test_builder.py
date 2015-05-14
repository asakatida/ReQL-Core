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

class BadKeyError(Exception):
    pass

def recurse_result_c(res, obj_id):
    if isinstance(res, r.RqlQuery):
        return recurse_result_c({'reql_ast_obj': type(res)}, obj_id)
    elif isinstance(res, str):
        res = res.encode('unicode_escape').replace(b'"', b'\\"')
        return '''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf{0}(new uint8_t[{1}]);
    const uint8_t src{0}[] = "{2}";
    reql_string_init(var{0}.get(), buf{0}.get(), {1});
    reql_string_append(var{0}.get(), src{0}, {1});'''.format(obj_id, len(res), res.decode()), obj_id + 1
    elif isinstance(res, bytes):
        return recurse_result_c(res.decode(), obj_id)
    elif isinstance(res, collections.Mapping):
        if len(res) == 0:
            return '''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    reql_object_init(var{0}.get(), nullptr, 0);'''.format(obj_id), obj_id + 1
        obj = ['''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair{0}(new ReQL_Pair_t[{1}]);
    reql_object_init(var{0}.get(), pair{0}.get(), {1});'''.format(obj_id, len(res))]
        orig_obj_id = obj_id
        obj_id += 1
        for k, v in res.items():
            if not isinstance(k, str):
                raise BadKeyError()
            key_id = obj_id
            src, obj_id = recurse_result_c(k, obj_id)
            obj.append(src)
            val_id = obj_id
            src, obj_id = recurse_result_c(v, obj_id)
            obj.append(src)
            obj.append('''
    reql_object_add(var{}.get(), var{}.get(), var{}.get());'''.format(orig_obj_id, key_id, val_id))
        return '\n'.join(obj), obj_id
    elif isinstance(res, collections.Iterable):
        if len(res) == 0:
            return '''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    reql_array_init(var{0}.get(), nullptr, 0);'''.format(obj_id), obj_id + 1
        obj = ['''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr{0}(new ReQL_Obj_t*[{1}]);
    reql_array_init(var{0}.get(), arr{0}.get(), {1});'''.format(obj_id, len(res))]
        orig_obj_id = obj_id
        obj_id += 1
        for e in res:
            elem_id = obj_id
            src, obj_id = recurse_result_c(e, obj_id)
            obj.append(src)
            obj.append('''
    reql_array_append(var{}.get(), var{}.get());'''.format(orig_obj_id, elem_id))
        return '\n'.join(obj), obj_id
    elif isinstance(res, bool):
        return '''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    reql_bool_init(var{0}.get(), {1});'''.format(obj_id, 1 if res else 0), obj_id + 1
    elif isinstance(res, numbers.Number):
        return '''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    reql_number_init(var{0}.get(), {1});'''.format(obj_id, res), obj_id + 1
    elif isinstance(res, collections.Callable):
        if res == range:
            return recurse_result_c(['func', 'range'], obj_id)
        elif res == map:
            return recurse_result_c(['func', 'map'], obj_id)
        elif res == sorted:
            return recurse_result_c(['func', 'sorted'], obj_id)
        elif isinstance(res, types.LambdaType):
            return recurse_result_c(res(), obj_id)
        else:
            return recurse_result_c({'reql_ast_obj': res.__name__}, obj_id)
    elif res == None:
        return '''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    reql_null_init(var{0}.get());'''.format(obj_id), obj_id + 1
    else:
        return recurse_result_c({'reql_ast_obj': type(res)}, obj_id)

def recurse_result_cpp(res, obj_id):
    if isinstance(res, r.RqlQuery):
        return recurse_result_cpp({'reql_ast_obj': type(res)}, obj_id)
    elif isinstance(res, str):
        res = res.encode('unicode_escape').replace(b'"', b'\\"')
        return '''
    std::string src{0}("{2}", {1});
    Result var{0}(src{0});'''.format(obj_id, len(res), res.decode()), obj_id + 1
    elif isinstance(res, bytes):
        return recurse_result_cpp(res.decode(), obj_id)
    elif isinstance(res, collections.Mapping):
        if len(res) == 0:
            return '''
    std::map<std::string, Result> map{0};
    Result var{0}(map{0});'''.format(obj_id), obj_id + 1
        obj = ['''
    std::map<std::string, Result> map{};'''.format(obj_id)]
        orig_obj_id = obj_id
        obj_id += 1
        for k, v in res.items():
            if not isinstance(k, str):
                raise BadKeyError()
            key_id = obj_id
            src, obj_id = recurse_result_cpp(k, obj_id)
            obj.append(src)
            val_id = obj_id
            src, obj_id = recurse_result_cpp(v, obj_id)
            obj.append(src)
            obj.append('''
    map{}.insert({{src{}, var{}}});'''.format(orig_obj_id, key_id, val_id))
        obj.append('''
    Result var{0}(map{0});'''.format(orig_obj_id))
        return '\n'.join(obj), obj_id
    elif isinstance(res, collections.Iterable):
        if len(res) == 0:
            return '''
    std::vector<Result> arr{0};
    Result var{0}(arr{0});'''.format(obj_id), obj_id + 1
        obj = ['''
    std::vector<Result> arr{}({});'''.format(obj_id, len(res))]
        orig_obj_id = obj_id
        obj_id += 1
        for e in res:
            elem_id = obj_id
            src, obj_id = recurse_result_cpp(e, obj_id)
            obj.append(src)
            obj.append('''
    arr{0}.insert(arr{0}.end(), var{1});'''.format(orig_obj_id, elem_id))
        obj.append('''
    Result var{0}(arr{0});'''.format(orig_obj_id))
        return '\n'.join(obj), obj_id
    elif isinstance(res, bool):
        return '''
    Result var{}({});'''.format(obj_id, 'true' if res else 'false'), obj_id + 1
    elif isinstance(res, numbers.Number):
        return '''
    double num{0}({1});
    Result var{0}(num{0});'''.format(obj_id, res), obj_id + 1
    elif isinstance(res, collections.Callable):
        if res == sorted:
            return recurse_result_cpp(['func', 'sorted'], obj_id)
        elif isinstance(res, types.LambdaType):
            return recurse_result_cpp(res(), obj_id)
        else:
            return recurse_result_cpp({'reql_ast_obj': res.__name__}, obj_id)
    elif res == None:
        return '''
    Result var{};'''.format(obj_id), obj_id + 1
    else:
        return recurse_result_cpp({'reql_ast_obj': type(res)}, obj_id)

def recurse_result(res, lang):
    if lang == 'cpp':
        return recurse_result_cpp(res, 0)[0]
    elif lang == 'c':
        return recurse_result_c(res, 0)[0]

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

        result = result.replace('=>', ':')
        result = result.replace('true', 'True')
        result = result.replace('false', 'False')
        result = result.replace('null', 'None')
        result = result.replace('nil', 'None')
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
        return recurse_result(res, lang)
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

def convert_tests(tests, lang):
    lang_tests = []
    tables = {table: TestTable(table) for table in get_tables(tests)}
    for i, test in enumerate(tests['tests']):
        lang_test = []
        section = test.get('py', test.get('cd'))
        if section:
#            definitions = test.get('def')
#            if definitions:
#                lang_test.append(eval_section(definitions, tables))
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
