/*
Copyright 2014 Adam Grandquist

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

#include "ruby.h"

#include "ReQL.h"

#ifndef _REQL_EXPR_RUBY
#define _REQL_EXPR_RUBY

static VALUE _reql_rb_expr(int argn, VALUE *args, VALUE self);
static _ReQL_Op_t *_reql_from_rb(VALUE obj, long nesting_depth);
static VALUE _reql_to_rb(_ReQL_Op_t *query);

#endif
