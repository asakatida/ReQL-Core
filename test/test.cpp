// Copyright 2015 Adam Grandquist

#include "./test.hpp"

void
consume(ReQL::Cursor<ReQL::Result> cursor) {
  std::vector<ReQL::Result>(cursor.begin(), cursor.end());
}

