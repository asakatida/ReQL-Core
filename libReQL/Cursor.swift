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

import ReactiveCocoa

import Foundation

public class ReQLError: NSObject, ErrorType {
  public var nsError: NSError {
    return NSError(domain: "", code: 0, userInfo: nil)
  }
}

public class Cursor: NSObject {
  let (signal, sink) = Signal<AnyObject, ReQLError>.pipe()
  var disposable: Disposable?
  public func next (value: AnyObject) -> Int {
    sendNext(sink, value)
    return 0;
  }
  public func error (error: ReQLError) {
    sendError(sink, error)
  }
  public func completed () {
    sendCompleted(sink)
  }
  public func interupted () {
    sendInterrupted(sink)
  }
  public func observe (next: (Event<AnyObject, ReQLError> -> ())) {
    disposable = signal.observe(next)
  }
  public func close () {
    disposable?.dispose()
  }
}
