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

#import <Cocoa/Cocoa.h>

#import "./reql/core.hpp"

namespace ReQL {

class Result {
public:
  Result(const Result &other) {}
  Result(Result &&other) {}
};

class Event {
};

class Parser {
public:
  typedef Result result_t;
};


typedef _ReQL::Conn_t<Parser, _ReQL::ImmutableString> Connection;
typedef _ReQL::Cur_t<Parser, _ReQL::ImmutableString> Cursor;

}
