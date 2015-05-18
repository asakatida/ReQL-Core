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
using namespace _C;

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
            count = len(obj)
            if count == 0:
                return self.empty_map_obj()
            self.map_obj_start(count)
            for k in sorted(obj.keys()):
                v = obj[k]
                self.key_obj(k)
                k = self.recurse(k)
                self.val_obj()
                self.key_val_pair(k, self.recurse(v))
            return self.map_obj_end()
        elif isinstance(obj, collections.Iterable):
            count = len(obj)
            if count == 0:
                return self.empty_array_obj()
            self.array_obj_start(count)
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
        raise Exception("unknown object type {}".format(type(obj)))

class ResultBuilder(ObjectRecursor):
    def __init__(self):
        self.obj_id = 0
        self.array_stack = {}
        self.elem_id_stack = []
        self.object_stack = {}
        self.key_id_stack = []
        self.val_id_stack = []

    def next_obj_id(self):
        obj_id = self.obj_id
        self.obj_id += 1
        return obj_id

    def append_id(self, stack):
        stack.append(self.obj_id)

    def array_stack_top(self):
        return max(self.array_stack.keys())

    def active_array_append(self, *args):
        top = self.array_stack[self.array_stack_top()]
        for arg in args:
            top.append(arg)

    def object_stack_top(self):
        return max(self.object_stack.keys())

    def active_object_append(self, *args):
        top = self.object_stack[self.object_stack_top()]
        for arg in args:
            top.append(arg)

    def recurse(self, obj):
        if isinstance(obj, r.RqlQuery):
            obj = {'reql_ast_obj': type(obj)}
        elif isinstance(obj, datetime):
            obj = obj.ctime()
        return super().recurse(obj)

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
        return '\n'.join(self.object_stack.pop(self.object_stack_top()))

    def array_obj_end(self):
        return '\n'.join(self.array_stack.pop(self.array_stack_top()))

    def callable_obj(self, obj):
        if obj == sorted:
            return self.recurse(['func', 'sorted'])
        elif isinstance(obj, types.LambdaType):
            return self.recurse(obj())
        else:
            return self.recurse({'reql_ast_obj': obj.__name__})

    def string_obj(self, obj):
        obj = obj.encode('unicode_escape').replace(b'"', b'\\"')
        return self.shell_string.format(
            self.next_obj_id(), len(obj), obj.decode())

    def empty_map_obj(self):
        return self.shell_empty_map.format(self.next_obj_id())

    def map_obj_start(self, count):
        orig_obj_id = self.next_obj_id()
        self.object_stack[orig_obj_id] = [
            self.shell_map_start.format(orig_obj_id, count)]

    def key_val_pair(self, key, val):
        self.active_object_append(key, val, self.shell_key_val.format(
            self.object_stack_top(),
            self.key_id_stack.pop(),
            self.val_id_stack.pop()))

    def empty_array_obj(self):
        return self.shell_empty_array.format(self.next_obj_id())

    def array_obj_start(self, count):
        orig_obj_id = self.next_obj_id()
        self.array_stack[orig_obj_id] = [
            self.shell_array_start.format(orig_obj_id, count)]

    def elem_end(self, elem):
        self.active_array_append(elem, self.shell_elem.format(
            self.array_stack_top(), self.elem_id_stack.pop()))

    def bool_obj(self, shell, obj):
        return shell.format(self.next_obj_id(), obj)

    def number_obj(self, obj):
        return self.shell_number.format(self.next_obj_id(), obj)

    def none_obj(self):
        return self.shell_none.format(self.next_obj_id())

class CResultBuilder(ResultBuilder):
    shell_string = '''
    ReQL_Obj_c var{0};
    std::unique_ptr<uint8_t[]> buf{0}(new uint8_t[{1}]);
    const uint8_t src{0}[] = "{2}";
    reql_string_init(var{0}.get(), buf{0}.get(), {1});
    reql_string_append(var{0}.get(), src{0}, {1});'''

    shell_empty_map = '''
    ReQL_Obj_c var{0};
    reql_object_init(var{0}.get(), nullptr, 0);'''

    shell_map_start = '''
    ReQL_Obj_c var{0};
    std::unique_ptr<ReQL_Pair_t[]> pair{0}(new ReQL_Pair_t[{1}]);
    reql_object_init(var{0}.get(), pair{0}.get(), {1});'''

    shell_key_val = '''
    reql_object_add(var{}.get(), var{}.get(), var{}.get());'''

    shell_empty_array = '''
    ReQL_Obj_c var{0};
    reql_array_init(var{0}.get(), nullptr, 0);'''

    shell_array_start = '''
    ReQL_Obj_c var{0};
    std::unique_ptr<ReQL_Obj_t*[]> arr{0}(new ReQL_Obj_t*[{1}]);
    reql_array_init(var{0}.get(), arr{0}.get(), {1});'''

    shell_elem = '''
    reql_array_append(var{}.get(), var{}.get());'''

    def bool_obj(self, obj):
        return super().bool_obj('''
    ReQL_Obj_c var{0};
    reql_bool_init(var{0}.get(), {1});''', 1 if obj else 0)

    shell_number = '''
    ReQL_Obj_c var{0};
    reql_number_init(var{0}.get(), {1});'''

    shell_none = '''
    ReQL_Obj_c var{0};
    reql_null_init(var{0}.get());'''

class CPPResultBuilder(ResultBuilder):
    shell_string = '''
    std::string src{0}("{2}", {1});
    Result var{0}(src{0});'''

    shell_empty_map = '''
    std::map<std::string, Result> map{0};
    Result var{0}(map{0});'''

    shell_map_start = '''
    std::map<std::string, Result> map{};'''

    shell_key_val = '''
    map{}.insert({{src{}, var{}}});'''

    def map_obj_end(self):
        self.active_object_append('''
    Result var{0}(map{0});'''.format(self.object_stack_top()))
        return super().map_obj_end()

    shell_empty_array = '''
    std::vector<Result> arr{0};
    Result var{0}(arr{0});'''

    shell_array_start = '''
    std::vector<Result> arr{}({});'''

    shell_elem = '''
    arr{0}.insert(arr{0}.end(), var{1});'''

    def array_obj_end(self):
        self.active_array_append('''
    Result var{0}(arr{0});'''.format(self.array_stack_top()))
        return super().array_obj_end()

    def bool_obj(self, obj):
        return super().bool_obj('''
    Result var{}({});''', 'true' if obj else 'false')

    shell_number = '''
    double num{0}({1});
    Result var{0}(num{0});'''

    shell_none = '''
    Result var{};'''

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

        true = True
        false = False
        nil = null = None

        result = result.replace('=>', ':')
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
        return recurse_result(result, lang)
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

def eval_definition(definition, tables, lang):
    try:
        exec(definition, None, tables)
    except:
        pass
    else:
        return str(definition)
    return str(definition)

def convert_tests(tests, lang):
    lang_tests = []
    tables = {table: TestTable(table) for table in get_tables(tests)}
    for i, test in enumerate(tests['tests']):
        lang_test = []
        definitions = test.get('def')
        if definitions:
            definitions = eval_definition(definitions, tables, lang)
#            lang_tests.append(definitions)
        section = test.get('py', test.get('cd'))
        if section:
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
