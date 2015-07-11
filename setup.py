from setuptools import setup, Extension

with open('README.md') as istream:
    long_description = istream.read()

tests_require = ['pytest']

libReQL = Extension(
    'libReQL',
    include_dirs=['src'],
    sources=[
        'src/Python/connection.c',
        'src/Python/cursor.c',
        'src/Python/query.c',
        'src/Python/ReQL.c',
        'src/reql/char.c',
        'src/reql/connection.c',
        'src/reql/cursor.c',
        'src/reql/decode.c',
        'src/reql/encode.c',
        'src/reql/error.c',
        'src/reql/query.c'
    ]
)

setup(
    author='Adam Grandquist',
    author_email='grandquista@gmail.com',
    classifiers=[
        'Development Status :: 3 - Alpha',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: Apache Software License',
        'Natural Language :: English',
        'Operating System :: MacOS :: MacOS X',
        'Programming Language :: C',
        'Programming Language :: Python :: 2.7',
        'Programming Language :: Python :: 3.2',
        'Programming Language :: Python :: 3.3',
        'Programming Language :: Python :: 3.4',
        'Programming Language :: Python :: 3.5',
        'Topic :: Database :: Front-Ends'
    ],
    description='A Python driver for RethinkDB.',
    entry_points={
        'console_scripts': [
        ]
    },
    extras_require={
        'testing': tests_require
    },
    ext_modules=[libReQL],
    keywords='',
    license='Apache',
    long_description=long_description,
    name='libReQL',
    package_data={
    },
    tests_require=tests_require,
    url='https://github.com/grandquista/ReQL-Core',
    version='1.0.0',
    zip_safe=True
)
