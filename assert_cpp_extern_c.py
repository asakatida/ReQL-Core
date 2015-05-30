import re

from pathlib import Path

def main():
    start_guard = re.compile(r'''
\#ifndef\s+(\w+)\s+
\#define\s+\1
(?P<cpp>
    \s+
    \#ifdef\s+__cplusplus\s+
    extern\s+"C"\s+{\s+
    \#endif
)?
''',
        re.I | re.X)
    end_guard = re.compile(r'''
(?P<cpp>
    \#ifdef\s+__cplusplus\s+
    }\s+
    \#endif\s+
)?
\#endif(\s*//\s*\w+)?.*\s*$
''',
        re.I | re.X)

    for file in (Path('.') / 'src').glob('**/*.h'):
        src = None
        with file.open() as istream:
            src = istream.read()
            start = start_guard.search(src)
            if start:
                end = end_guard.search(src)
                if end:
                    if start.group('cpp') and end.group('cpp'):
                        src = None
                    else:
                        guard = start.group(1)
                        src = ''.join([
                            src[:start.start()],
                            '#ifndef {0}\n#define {0}\n\n'.format(guard),
                            '#ifdef __cplusplus\nextern "C" {\n#endif',
                            src[start.end():end.start()],
                            '#ifdef __cplusplus\n}\n#endif\n\n',
                            '#endif  // {}\n'.format(guard)
                            ])
                else:
                    print('no header guard close found in', file)
                    src = None
            else:
                print('no header guard found in', file)
                src = None
        if src:
            with file.open('w') as ostream:
                ostream.write(src)

if __name__ == '__main__':
    main()
