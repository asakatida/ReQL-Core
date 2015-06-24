def eval_definition(definition, tables, lang):
    try:
        exec(definition, None, tables)
    except:
        pass
    else:
        return str(definition)
    return str(definition)
