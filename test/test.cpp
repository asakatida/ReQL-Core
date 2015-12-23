// Copyright 2015 Adam Grandquist

#include "./test.hpp"

#include "./ReQL.hpp"

void
consume(ReQL::Cursor<ReQL::Result> cursor) {
  for (auto &&_ : cursor) {}
}

