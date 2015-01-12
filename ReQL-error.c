/*
Copyright 2014-2015 Adam Grandquist

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

#include "ReQL-error.h"

#include <pthread.h>
#include <stdlib.h>

static pthread_mutex_t error_lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_once_t init_lock = PTHREAD_ONCE_INIT;

static _ReQL_Error_t _ReQL_Global_Error = {_REQL_E_NO, "", ""};

static void
_reql_init_err(void) {
  pthread_mutexattr_t *attrs = malloc(sizeof(pthread_mutexattr_t));

  pthread_mutexattr_init(attrs);
  pthread_mutexattr_settype(attrs, PTHREAD_MUTEX_ERRORCHECK);

  pthread_mutex_init(&error_lock, attrs);

  pthread_mutexattr_destroy(attrs);

  free(attrs);
}

extern int
_reql_error() {
  return _reql_error_type() != _REQL_E_NO;
}

extern char *
_reql_error_msg() {
  pthread_once(&init_lock, _reql_init_err);

  pthread_mutex_lock(&error_lock);

  char *res = _ReQL_Global_Error.msg;

  pthread_mutex_unlock(&error_lock);

  return res;
}

extern char *
_reql_error_trace() {
  pthread_once(&init_lock, _reql_init_err);

  pthread_mutex_lock(&error_lock);

  char *res = _ReQL_Global_Error.trace;

  pthread_mutex_unlock(&error_lock);

  return res;
}

extern _ReQL_Error_Type_t
_reql_error_type() {
  pthread_once(&init_lock, _reql_init_err);

  pthread_mutex_lock(&error_lock);

  _ReQL_Error_Type_t res = _ReQL_Global_Error.err;

  pthread_mutex_unlock(&error_lock);

  return res;
}

extern void
_reql_error_init(_ReQL_Error_Type_t err, char *msg, char *trace) {
  pthread_once(&init_lock, _reql_init_err);

  pthread_mutex_lock(&error_lock);

  _ReQL_Global_Error.err = err;
  _ReQL_Global_Error.msg = msg;
  _ReQL_Global_Error.trace = trace;

  pthread_mutex_unlock(&error_lock);
}
