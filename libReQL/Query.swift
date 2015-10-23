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

public class ReQLBool: NSObject {
  let value: Bool
  init(val: Bool) {
    value = val
  }

  public func boolValue () -> Bool {
    return value
  }
}

public class Parser: NSObject {
  public var stack: Array<AnyObject>

  override init () {
    stack = []
  }

  func push (val: AnyObject) {
    stack.append(val)
  }

  func pop () -> AnyObject {
    return stack.popLast()!
  }

  func rot (val: (val: AnyObject) -> AnyObject) {
    push(val(val: pop()))
  }

  public func addBool (val: Bool) {
    push(ReQLBool(val: val))
  }

  public func addNull () {
    push(NSNull())
  }

  public func addNumber (val: Double) {
    push(val)
  }

  public func addString (val: UnsafePointer<Void>, length: Int) {
    push(NSString(bytes: val, length: length, encoding: NSUTF8StringEncoding)!)
  }

  public func endElement () {
    let last = pop()
    var array = stack.last as! Array<AnyObject>
    array.append(last)
  }

  public func endKeyValue (val: UnsafePointer<Void>, length: Int) {
    let value = pop()
    let key = pop() as! String
    var dict = stack.last as! Dictionary<String, AnyObject>
    dict[key] = value
  }

  public func startArray () {
    push(Array<AnyObject>())
  }

  public func startObject () {
    push(Dictionary<String, AnyObject>())
  }
}
