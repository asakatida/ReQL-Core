#include "ReQL.hpp"

namespace ReQL {
extern "C" {

#include "ReQL-char.h"
#include "ReQL-decode.h"
#include "ReQL-encode.h"
#include "ReQL-error.h"

}
}

#ifndef REQL_TEST_HPP
#define REQL_TEST_HPP

std::string inspect(ReQL::ReQL_Obj_t *query);

#endif
