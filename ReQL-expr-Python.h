/**
 * @author Adam Grandquist
 */

#include <Python.h>

#include "ReQL.h"

#ifndef _REQL_EXPR_PYTHON
#define _REQL_EXPR_PYTHON

static PyObject *_reql_py_expr(PyObject *self, PyObject *args);
static _ReQL_Op_t *_reql_from_py(PyObject *query);
static PyObject *_reql_to_py(_ReQL_Op_t *query);

#endif
