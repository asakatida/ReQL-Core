// Copyright 2015 Adam Grandquist

import Cocoa
import Quick
import Nimble
import libReQL

class Connection : QuickSpec {
  override func spec() {
    describe("example") {
      it("connects") {
        let connection = ReQLConnection()
        expect(connection.isOpen()) == true
        it("runs") {
          if (connection.isOpen()) {
            let cursor = ReQLQuery.newWithNumber(2)!.add([2])!.run(connection)!
            expect(cursor.isOpen()) == true
            it("gets results") {
              if (cursor.isOpen()) {
                let res = cursor.toArray()
                expect(res).to(contain(4))
                expect(res).to(haveCount(1))
              }
            }
            cursor.close()
          }
        }
        connection.close()
      }
    }
  }
}