/*
Copyright 2015 Adam Grandquist

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
 */
/**
 * @author Adam Grandquist
 * @copyright Apache
 */

#define Py_LIMITED_API
#include "Python.h"
#include "structmember.h"

#include "./Python/cursor.h"

#include "./Python/types.h"
#include "./reql/core.h"

#include <stdlib.h>

extern void
Cursor_dealloc(ReQLCursor* self) {
  reql_cur_destroy(self->reql_cursor);
  reql_py_dealloc((PyObject*)self);
}

extern PyObject *
Cursor_new(PyTypeObject *type, PyObject *args, PyObject *kwargs) {
  ReQLCursor *self = (ReQLCursor *)PyType_GenericNew(type, args, kwargs);

  if (self != NULL) {
    self->reql_cursor = NULL;
  }

  return (PyObject *)self;
}

extern int
Cursor_init(ReQLCursor *self, PyObject *args, PyObject *kwargs) {
  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "", kwlist)) {
    return -1;
  }

  return 0;
}

