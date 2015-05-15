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

test_names = set()

test_name_shell = '{} {}'

test_shell = '''// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("{}", "[{}][ast]") {{
{}
}}
'''

section_shell = '''
  SECTION("test{}") {{{}
  }}'''

class ObjectRecursor:
    def recurse(self, obj):
        if isinstance(obj, str):
            return self.string_obj(obj)
        elif isinstance(obj, bytes):
            return self.bytes_obj(obj)
        elif isinstance(obj, collections.Mapping):
            if len(obj) == 0:
                return self.empty_map_obj()
            self.map_obj_start(len(obj))
            for k in sorted(obj.keys()):
                v = obj[k]
                self.key_obj(k)
                k = self.recurse(k)
                self.val_obj()
                self.key_val_pair(k, self.recurse(v))
            return self.map_obj_end()
        elif isinstance(obj, collections.Iterable):
            if len(obj) == 0:
                return self.empty_array_obj()
            self.array_obj_start(len(obj))
            for e in obj:
                self.elem_start()
                self.elem_end(self.recurse(e))
            return self.array_obj_end()
        elif isinstance(obj, bool):
            return self.bool_obj(obj)
        elif isinstance(obj, numbers.Number):
            return self.number_obj(obj)
        elif isinstance(obj, collections.Callable):
            return self.callable_obj(obj)
        elif obj == None:
            return self.none_obj()
        else:
            return self.recurse({'reql_ast_obj': type(obj)})
        raise Exception("unknown object type {}".format(type(obj)))

class ResultBuilder(ObjectRecursor):
    def __init__(self):
        self.obj_id = 0
        self.array_stack = []
        self.array_id_stack = []
        self.elem_id_stack = []
        self.object_stack = []
        self.object_id_stack = []
        self.key_id_stack = []
        self.val_id_stack = []

    def next_obj_id(self):
        obj_id = self.obj_id
        self.obj_id += 1
        return obj_id

    def append_id(self, stack):
        stack.append(self.obj_id)

    def recurse(self, res):
        if isinstance(res, r.RqlQuery):
            res = {'reql_ast_obj': type(res)}
        return super().recurse(res)

    def bytes_obj(self, obj):
        return self.recurse(obj.decode())

    def key_obj(self, key):
        if not isinstance(key, str):
            raise BadKeyError()
        self.append_id(self.key_id_stack)

    def val_obj(self):
        self.append_id(self.val_id_stack)

    def elem_start(self):
        self.append_id(self.elem_id_stack)

    def map_obj_end(self):
        self.object_id_stack.pop()
        return '\n'.join(self.object_stack.pop())

    def array_obj_end(self):
        self.array_id_stack.pop()
        return '\n'.join(self.array_stack.pop())

    def callable_obj(self, obj):
        if obj == sorted:
            return self.recurse(['func', 'sorted'])
        elif isinstance(obj, types.LambdaType):
            return self.recurse(obj())
        else:
            return self.recurse({'reql_ast_obj': obj.__name__})

class CResultBuilder(ResultBuilder):
    def string_obj(self, obj):
        obj = obj.encode('unicode_escape').replace(b'"', b'\\"')
        return '''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf{0}(new uint8_t[{1}]);
    const uint8_t src{0}[] = "{2}";
    reql_string_init(var{0}.get(), buf{0}.get(), {1});
    reql_string_append(var{0}.get(), src{0}, {1});'''.format(
            self.next_obj_id(), len(obj), obj.decode())

    def empty_map_obj(self):
        return '''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    reql_object_init(var{0}.get(), nullptr, 0);'''.format(self.next_obj_id())

    def map_obj_start(self, count):
        orig_obj_id = self.next_obj_id()
        self.object_id_stack.append(orig_obj_id)
        self.object_stack.append(['''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair{0}(new ReQL_Pair_t[{1}]);
    reql_object_init(var{0}.get(), pair{0}.get(), {1});'''.format(
            orig_obj_id, count)])

    def key_val_pair(self, key, val):
        self.object_stack[-1].append(key)
        self.object_stack[-1].append(val)
        key_id = self.key_id_stack.pop()
        val_id = self.val_id_stack.pop()
        self.object_stack[-1].append('''
    reql_object_add(var{}.get(), var{}.get(), var{}.get());'''.format(
            self.object_id_stack[-1], key_id, val_id))

    def empty_array_obj(self):
        return '''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    reql_array_init(var{0}.get(), nullptr, 0);'''.format(self.next_obj_id())

    def array_obj_start(self, count):
        orig_obj_id = self.next_obj_id()
        self.array_id_stack.append(orig_obj_id)
        self.array_stack.append(['''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr{0}(new ReQL_Obj_t*[{1}]);
    reql_array_init(var{0}.get(), arr{0}.get(), {1});'''.format(
            orig_obj_id, count)])

    def elem_end(self, elem):
        self.array_stack[-1].append(elem)
        elem_id = self.elem_id_stack.pop()
        self.array_stack[-1].append('''
    reql_array_append(var{}.get(), var{}.get());'''.format(
            self.array_id_stack[-1], elem_id))

    def bool_obj(self, obj):
        return '''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    reql_bool_init(var{0}.get(), {1});'''.format(
            self.next_obj_id(), 1 if obj else 0)

    def number_obj(self, obj):
        return '''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    reql_number_init(var{0}.get(), {1});'''.format(
            self.next_obj_id(), obj)

    def none_obj(self):
        return '''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    reql_null_init(var{0}.get());'''.format(
            self.next_obj_id())

class CPPResultBuilder(ResultBuilder):
    def string_obj(self, obj):
        obj = obj.encode('unicode_escape').replace(b'"', b'\\"')
        return '''
    std::string src{0}("{2}", {1});
    Result var{0}(src{0});'''.format(
            self.next_obj_id(), len(obj), obj.decode())

    def empty_map_obj(self):
        return '''
    std::map<std::string, Result> map{0};
    Result var{0}(map{0});'''.format(self.next_obj_id())

    def map_obj_start(self, count):
        orig_obj_id = self.next_obj_id()
        self.object_id_stack.append(orig_obj_id)
        self.object_stack.append(['''
    std::map<std::string, Result> map{};'''.format(
            orig_obj_id)])

    def key_val_pair(self, key, val):
        self.object_stack[-1].append(key)
        self.object_stack[-1].append(val)
        key_id = self.key_id_stack.pop()
        val_id = self.val_id_stack.pop()
        self.object_stack[-1].append('''
    map{}.insert({{src{}, var{}}});'''.format(
            self.object_id_stack[-1], key_id, val_id))

    def map_obj_end(self):
        self.object_stack[-1].append('''
    Result var{0}(map{0});'''.format(
            self.object_id_stack[-1]))
        return super().map_obj_end()

    def empty_array_obj(self):
        return '''
    std::vector<Result> arr{0};
    Result var{0}(arr{0});'''.format(self.next_obj_id())

    def array_obj_start(self, count):
        orig_obj_id = self.next_obj_id()
        self.array_id_stack.append(orig_obj_id)
        self.array_stack.append(['''
    std::vector<Result> arr{}({});'''.format(
            orig_obj_id, count)])

    def elem_end(self, elem):
        self.array_stack[-1].append(elem)
        elem_id = self.elem_id_stack.pop()
        self.array_stack[-1].append('''
    arr{0}.insert(arr{0}.end(), var{1});'''.format(
            self.array_id_stack[-1], elem_id))

    def array_obj_end(self):
        self.array_stack[-1].append('''
    Result var{0}(arr{0});'''.format(
            self.array_id_stack[-1]))
        return super().array_obj_end()

    def bool_obj(self, obj):
        return '''
    Result var{}({});'''.format(
            self.next_obj_id(), 'true' if obj else 'false')

    def number_obj(self, obj):
        return '''
    double num{0}({1});
    Result var{0}(num{0});'''.format(
            self.next_obj_id(), obj)

    def none_obj(self):
        return '''
    Result var{};'''.format(
            self.next_obj_id())

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

def recurse_result(res, lang):
    if lang == 'cpp':
        return CPPResultBuilder().recurse(res)
    elif lang == 'c':
        return CResultBuilder().recurse(res)

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
        test_name = test_name_shell.format('c', tests['desc'])
        if test_name in test_names:
            test_name = ' '.join([test_name, str(len(test_names))])
        test_names.add(test_name)
        ostream.write(test_shell.format(
            test_name,
            'c',
            '\n'.join(convert_tests(tests, 'c'))
        ))

    with touch((cpp_path / test_file).with_suffix('.cpp')) as ostream:
        test_name = test_name_shell.format('cpp', tests['desc'])
        if test_name in test_names:
            test_name = ' '.join([test_name, str(len(test_names))])
        test_names.add(test_name)
        ostream.write(test_shell.format(
            test_name,
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
