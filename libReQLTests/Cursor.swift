// Copyright 2015 Adam Grandquist

import Cocoa
import Quick
import libReQL

class Cursor : QuickSpec {
  var connection: ReQLConnection?
  var cursor: ReQLCursor?

  override func setUp() {
    super.setUp()
    connection = ReQLConnection()
    cursor = nil
  }

  override func tearDown() {
    cursor?.close()
    connection?.close()
    super.tearDown()
  }

  func verifyQuery(query: ReQLQuery, result: Array<AnyObject>) {
    if (connection!.isOpen()) {
      let cursor = query.run(connection!);
      if (cursor!.isOpen()) {
        let _ = cursor!.toArray();
      }
    }
  }

  func testExample() {
    verifyQuery(ReQLQuery.newWithNumber(2)!.add([2])!, result:[4])
  }

  func testPerformanceExample() {
  }
}
