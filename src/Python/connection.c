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

#include "./Python/connection.h"

#include "./reql/core.h"

#include <stdlib.h>

typedef struct {
  PyObject_HEAD
  ReQL_Conn_t *reql_connection;
} ReQLConnection;

static void
Connection_dealloc(ReQLConnection* self) {
  reql_conn_destroy(self->reql_connection);
  Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject *
Connection_new(PyTypeObject *type, PyObject *args, PyObject *kwargs) {
  ReQLConnection *self;

  self = (ReQLConnection *)type->tp_alloc(type, 0);
  if (self != NULL) {
    self->reql_connection = NULL;
  }

  return (PyObject *)self;
}

static int
Connection_init(ReQLConnection *self, PyObject *args, PyObject *kwargs) {
  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "", kwlist)) {
    return -1;
  }

  return 0;
}

static PyObject *
Connection_name(ReQLConnection* self) {
  return NULL;
}

static PyMemberDef Connection_members[] = {
  {"data", T_OBJECT_EX, offsetof(ReQLConnection, reql_connection), 0, ""},
  {NULL}  /* Sentinel */
};

static PyMethodDef Connection_methods[] = {
  {"name", (PyCFunction)Connection_name, METH_NOARGS, ""},
  {NULL}  /* Sentinel */
};

static PyTypeObject ReQLConnectionType = {
  PyObject_HEAD_INIT(NULL)
  0,                         /*ob_size*/
  "libReQL.Connection",      /*tp_name*/
  sizeof(ReQLConnection),    /*tp_basicsize*/
  0,                         /*tp_itemsize*/
  (destructor)Connection_dealloc, /*tp_dealloc*/
  0,                         /*tp_print*/
  0,                         /*tp_getattr*/
  0,                         /*tp_setattr*/
  0,                         /*tp_compare*/
  0,                         /*tp_repr*/
  0,                         /*tp_as_number*/
  0,                         /*tp_as_sequence*/
  0,                         /*tp_as_mapping*/
  0,                         /*tp_hash */
  0,                         /*tp_call*/
  0,                         /*tp_str*/
  0,                         /*tp_getattro*/
  0,                         /*tp_setattro*/
  0,                         /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, /*tp_flags*/
  "",                        /* tp_doc */
  0,                         /* tp_traverse */
  0,                         /* tp_clear */
  0,                         /* tp_richcompare */
  0,                         /* tp_weaklistoffset */
  0,                         /* tp_iter */
  0,                         /* tp_iternext */
  Connection_methods,        /* tp_methods */
  Connection_members,        /* tp_members */
  0,                         /* tp_getset */
  0,                         /* tp_base */
  0,                         /* tp_dict */
  0,                         /* tp_descr_get */
  0,                         /* tp_descr_set */
  0,                         /* tp_dictoffset */
  (initproc)Connection_init, /* tp_init */
  0,                         /* tp_alloc */
  Connection_new,            /* tp_new */
};

extern PyObject *
reql_py_connect(PyObject *args, PyObject *kwargs) {
  return (PyObject *)PyObject_New(ReQLConnection, &ReQLConnectionType);
}
