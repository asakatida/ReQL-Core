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

#import <map>
#import <vector>

namespace ReQL {

struct Result {
  Result();
  Result(const bool value);
  Result(const double value);
  Result(const wchar_t *value, const size_t size);
  Result(const std::vector<Result> &value);
  Result(const std::map<std::wstring, Result> &value);

  Result(const Result &other);
  Result &operator =(const Result &other);

  id p_value;
};

}
