/**
 * @author Adam Grandquist
 */

#include <stdlib.h>

#include "ReQL-ast-Python.h"

#include "ReQL.h"

static PyMethodDef libReQLMethods[] = {
  {"expr", _reql_py_expr, METH_VARARGS, NULL},
  REQL_PY_AST_METHODS
  {NULL, NULL, 0, NULL}
};

static struct PyModuleDef libReQLModule = {
  PyModuleDef_HEAD_INIT,
  "libReQL",
  NULL,
  -1,
  libReQLMethods
};

PyMODINIT_FUNC
PyInit_libreql(void) {
  PyObject* m;
  m = PyModule_Create(&libReQLModule);

  if (!m) {
    return NULL;
  }

  return m;
}
