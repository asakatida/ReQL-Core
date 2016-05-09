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
  init(error: NSError) {
  }
  var nsError: NSError {
    return NSError(domain: "", code: 0, userInfo: nil)
  }
}

public class Cursor: NSObject {
  let (signal, sink) = Signal<AnyObject, ReQLError>.pipe()
  public func next (value: AnyObject) {
    sink.sendNext(value)
  }
  public func fail (error: NSError) {
    sink.sendFailed(ReQLError(error: error))
  }
  public func complete () {
    sink.sendCompleted()
  }
  public func observeNext (next: (AnyObject -> ())) {
    signal.observeNext { next($0) }
  }
  public func observeFailed (error: (NSError -> ())) {
    signal.observeFailed { error($0.nsError) }
  }
  public func observeCompleted (completed: (() -> ())) {
    signal.observeCompleted { completed() }
  }
  public func toArray () -> Array<AnyObject> {
    var array: Array<AnyObject> = []
    let cond = NSCondition()
    cond.lock()
    signal.collect().observe({
      $0.map({ array = $0 })
      cond.lock()
      cond.broadcast()
      cond.unlock()
    })
    cond.wait()
    cond.unlock()
    return array
  }
}
