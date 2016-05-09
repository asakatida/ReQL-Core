// Copyright 2015 Adam Grandquist

import Cocoa
import Quick
import Nimble
import libReQL

class Cursor : QuickSpec {
  override func spec() {
    describe("example") {
      let connection = ReQLConnection()
      self.verifyQuery(connection, query: ReQLQuery(), result: [])
    }
  }

  func verifyQuery(connection: ReQLConnection, query: ReQLQuery, result: Array<AnyObject>) {
    if (connection.isOpen()) {
      let cursor = query.run(connection);
      if (cursor!.isOpen()) {
        let _ = cursor!.toArray();
      }
    }
  }
}
