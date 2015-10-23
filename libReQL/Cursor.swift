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

class ReQLError: NSObject, ErrorType {
  var nsError: NSError {
    return NSError(domain: "", code: 0, userInfo: nil)
  }
}

public class Cursor: NSObject {
  let (signal, sink) = Signal<AnyObject, ReQLError>.pipe()
  var disposable: Disposable?
  public func next (value: AnyObject) {
    self.sink.sendNext(value)
  }
  func error (error: ReQLError) {
    sink.sendError(error)
  }
  public func completed () {
    sink.sendCompleted()
  }
  public func interupted () {
    sink.sendInterrupted()
  }
  public func observeNext (next: (AnyObject -> ())) {
    disposable = signal.observeNext { next($0) }
  }
  public func observeError (error: (NSError -> ())) {
    disposable = signal.observeError { error($0.nsError) }
  }
  public func observeCompleted (completed: (() -> ())) {
    disposable = signal.observeCompleted { completed() }
  }
  public func toArray () -> Array<AnyObject> {
    var array: Array<AnyObject> = []
    signal.collect().observeNext { array = $0 }
    return array
  }
  public func close () {
    disposable?.dispose()
  }
}
