def eval_section(section, tables, lang):
    tables['null'] = None
    try:
        return str(eval(section, None, tables))
    except:
        pass
    return ''
