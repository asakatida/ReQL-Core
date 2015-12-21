// Copyright 2015 Adam Grandquist

#include "./test.hpp"

void
consume(ReQL::Cursor cursor) {
  std::vector<ReQL::Result>(cursor.begin(), cursor.end());
}

