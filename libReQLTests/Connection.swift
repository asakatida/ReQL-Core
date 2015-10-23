// Copyright 2015 Adam Grandquist

import Cocoa
import Quick
import Nimble
import libReQL

class Connection : QuickSpec {
  override func spec() {
    describe("example") {
      it("of connection") {
        let connection = ReQLConnection()
        expect(connection.isOpen()) == true
        if (connection.isOpen()) {
          let cursor = ReQLQuery.newWithNumber(2)!.add([2])!.run(connection)
          expect(cursor!.isOpen()) == true
          if (cursor!.isOpen()) {
            let res = cursor!.toArray()
            expect(res).to(contain(4))
            expect(res).to(haveCount(1))
          }
          cursor!.close()
        }
        connection.close()
      }
    }
  }
}