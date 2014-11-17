/**
 * @author Adam Grandquist
 */

#include "ruby.h"

#include "ReQL.h"

#ifndef _REQL_EXPR_RUBY
#define _REQL_EXPR_RUBY

static VALUE _reql_rb_expr(int argn, VALUE *args, VALUE self);
static _ReQL_Op_t *_reql_from_rb(VALUE obj, long nesting_depth);
static VALUE _reql_to_rb(_ReQL_Op_t *query);

#endif
