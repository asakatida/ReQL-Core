try:
    import rethinkdb as r
except:
    print('rethinkdb not installed')

import collections
import numbers
import re
import types

from datetime import datetime

xrange = range

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
    shell_string = ''''''

    shell_empty_map = ''''''

    shell_map_start = ''''''

    shell_key_val = ''''''

    shell_empty_array = ''''''

    shell_array_start = ''''''

    shell_elem = ''''''

    def bool_obj(self, obj):
        return super().bool_obj('''''', 1 if obj else 0)

    shell_number = ''''''

    shell_none = ''''''

class ObjCResultBuilder(ResultBuilder):
    shell_string = '''  NSString *var{0} = @"{2}";'''

    shell_empty_map = '''  NSDictionary *var{} = [NSDictionary dictionary];'''

    shell_map_start = '''  NSMutableDictionary *var{} = [NSMutableDictionary dictionaryWithCapacity:{}];'''

    shell_key_val = '''  [var{0} setObject:var{2} forKey:var{1}];'''

    shell_empty_array = '''  NSArray *var{} = [NSArray array];'''

    shell_array_start = '''  NSMutableArray *var{} = [NSMutableArray arrayWithCapacity:{}];'''

    shell_elem = '''  [var{} addObject:var{}];'''

    def bool_obj(self, obj):
        return super().bool_obj('''  NSNumber *var{} = [NSNumber numberWithBool:{}];''', 'YES' if obj else 'NO')

    shell_number = '''  NSNumber *var{} = @{};'''

    shell_none = '''  NSNull *var{} = [NSNull null];'''

class CPPResultBuilder(ResultBuilder):
    shell_string = '''
    std::string src{0}("{2}", {1});
    Query var{0}(src{0});'''

    shell_empty_map = '''
    Types::object map{0};
    Query var{0}(map{0});'''

    shell_map_start = '''
    Types::object map{};'''

    shell_key_val = '''
    map{}.insert({{src{}, var{}}});'''

    def map_obj_end(self):
        self.active_object_append('''
    Query var{0}(map{0});'''.format(self.object_stack_top()))
        return super().map_obj_end()

    shell_empty_array = '''
    Types::array arr{0};
    Query var{0}(arr{0});'''

    shell_array_start = '''
    Types::array arr{}({});'''

    shell_elem = '''
    arr{0}.insert(arr{0}.end(), var{1});'''

    def array_obj_end(self):
        self.active_array_append('''
    Query var{0}(arr{0});'''.format(self.array_stack_top()))
        return super().array_obj_end()

    def bool_obj(self, obj):
        return super().bool_obj('''
    Query var{}({});''', 'true' if obj else 'false')

    shell_number = '''
    double num{0}({1});
    Query var{0}(num{0});'''

    shell_none = '''
    Query var{};'''

class ReQLResultBuilder(ResultBuilder):
    shell_string = '''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf{0}(new ReQL_Byte[{1}]);
    const ReQL_Byte src{0}[] = "{2}";
    reql_string_init(var{0}.get(), buf{0}.get(), src{0}, {1});'''

    shell_empty_map = '''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    reql_object_init(var{0}.get(), nullptr, 0);'''

    shell_map_start = '''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair{0}(new ReQL_Pair_t[{1}]);
    reql_object_init(var{0}.get(), pair{0}.get(), {1});'''

    shell_key_val = '''
    reql_object_add(var{}.get(), var{}.get(), var{}.get());'''

    shell_empty_array = '''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    reql_array_init(var{0}.get(), nullptr, 0);'''

    shell_array_start = '''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr{0}(new ReQL_Obj_t*[{1}]);
    reql_array_init(var{0}.get(), arr{0}.get(), {1});'''

    shell_elem = '''
    reql_array_append(var{}.get(), var{}.get());'''

    def bool_obj(self, obj):
        return super().bool_obj('''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    reql_bool_init(var{0}.get(), {1});''', 1 if obj else 0)

    shell_number = '''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    reql_number_init(var{0}.get(), {1});'''

    shell_none = '''
    std::unique_ptr<ReQL_Obj_t> var{0}(new ReQL_Obj_t);
    reql_null_init(var{0}.get());'''

class BadKeyError(Exception):
    pass

def recurse_result(res, lang):
    if lang == 'cpp':
        return CPPResultBuilder().recurse(res)
    elif lang == 'c':
        return CResultBuilder().recurse(res)
    elif lang == 'objc':
        return ObjCResultBuilder().recurse(res)
    elif lang == 'reql':
        return ReQLResultBuilder().recurse(res)

def eval_result(result, lang):
    if isinstance(result, str):
        arrlen = lambda *args: {'func': 'arrlen'}
        b = lambda *args: {'func': 'b'}
        bag = lambda *args: {'func': 'bag'}
        Buffer = lambda *args: {'func': 'Buffer'}
        data = TestTable('data')
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
        tableCount = 0
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
