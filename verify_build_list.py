import re

from pathlib import Path

def main():
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
        Path('.') / 'src' / 'ReQL.hpp',
        Path('.') / 'test' / 'test.hpp'])

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
        Path('.') / 'test' / 'main.cpp',
        Path('.') / 'test' / 'test.cpp'])

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

if __name__ == '__main__':
    main()
