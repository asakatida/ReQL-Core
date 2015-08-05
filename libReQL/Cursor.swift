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

@objc public class ReQLError: ErrorType {
  public var nsError: NSError {
    return NSError()
  }
}

@objc public class Cursor {
  let (signal, sink) = Signal<AnyObject, ReQLError>.pipe()
  var disposable: Disposable?
  public class func new() -> Cursor {
    return Cursor()
  }
  public func next (value: AnyObject) {
    sendNext(sink, value)
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
  public func observe (error: (ReQLError -> ())?, completed: (() -> ())?, interrupted: (() -> ())?, next: (AnyObject -> ())?) {
    disposable = signal.observe(error: error, completed: completed, interrupted: interrupted, next: next)
  }
  public func close () {
    disposable?.dispose()
  }
}
