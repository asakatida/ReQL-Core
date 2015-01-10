from setuptools import setup, Extension

setup(
    ext_modules=[Extension('libReQL', [
        'ReQL-json.c',
        'ReQL-expr.c',
        'ReQL-encode.c',
        'ReQL-decode.c',
        'ReQL-cursor.c',
        'ReQL-char.c',
        'ReQL-ast.c',
        'ReQL.c',
        'ReQL-new-Python.c',
        'ReQL-expr-Python.c',
        'ReQL-ast-Python.c',
        'ReQL-Python.c'
    ])],
    maintainer='Adam Grandquist',
    maintainer_email='grandquista@gmail.com',
    name='libReQL',
    url='https://github.com/grandquista/ReQL-Core',
    version='0.1.0',
    zip_safe=False
)
