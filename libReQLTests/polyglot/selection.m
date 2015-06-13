// Copyright 2015 Adam Grandquist

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <libReQL.h>

@interface ObjcTestsThatManipulationDataInTables377 : XCTestCase

@end

@implementation ObjcTestsThatManipulationDataInTables377


- (void)test0 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"partial";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test1 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"partial";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test2 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:6];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @0.0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @0.0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"inserted";
  NSNumber *var6 = @100;
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"replaced";
  NSNumber *var8 = @0.0;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"skipped";
  NSNumber *var10 = @0.0;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"unchanged";
  NSNumber *var12 = @0.0;
  [var0 setObject:var12 forKey:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test3 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:6];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @0.0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @0.0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"inserted";
  NSNumber *var6 = @100;
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"replaced";
  NSNumber *var8 = @0.0;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"skipped";
  NSNumber *var10 = @0.0;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"unchanged";
  NSNumber *var12 = @0.0;
  [var0 setObject:var12 forKey:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test4 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSString *var0 = @"TABLE";
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test5 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test6 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test7 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:6];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @0.0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @0.0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"inserted";
  NSNumber *var6 = @1;
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"replaced";
  NSNumber *var8 = @0.0;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"skipped";
  NSNumber *var10 = @0.0;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"unchanged";
  NSNumber *var12 = @0.0;
  [var0 setObject:var12 forKey:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test8 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"result";
  NSString *var2 = @"blank";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test9 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"result";
  NSString *var2 = @"blank";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test10 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test11 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test12 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @100;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test13 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @100;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test15 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var1 = @"a";
  NSNumber *var2 = @0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"id";
  NSNumber *var4 = @20;
  [var0 setObject:var4 forKey:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test16 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNull *var0 = [NSNull null];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test19 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"partial";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test20 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:6];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @0.0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @0.0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"inserted";
  NSNumber *var6 = @1;
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"replaced";
  NSNumber *var8 = @0.0;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"skipped";
  NSNumber *var10 = @0.0;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"unchanged";
  NSNumber *var12 = @0.0;
  [var0 setObject:var12 forKey:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test21 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var1 = @"a";
  NSNumber *var2 = @10;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"foo";
  NSNumber *var4 = @10;
  [var0 setObject:var4 forKey:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test22 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSString *var0 = @"TABLE_SLICE";
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test23 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSString *var0 = @"TABLE_SLICE";
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test24 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSString *var0 = @"TABLE_SLICE";
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test25 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSString *var0 = @"TABLE_SLICE";
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test26 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSString *var0 = @"TABLE_SLICE";
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test27 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @9;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test28 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @9;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test29 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @20;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test30 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @100;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test31 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @10;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test32 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @10;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test33 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @20;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test34 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @100;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test35 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @8;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test36 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @9;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test37 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @19;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test38 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @100;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test39 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test40 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @2;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test41 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @3;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test42 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @2;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test43 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @98;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test45 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test46 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @1;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test47 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @0;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test48 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @25;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test49 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @100;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test50 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @4;
  [var0 addObject:var1];
  NSNumber *var2 = @5;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test52 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSMutableArray *var1 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var2 = @3;
  [var1 addObject:var2];
  NSNumber *var3 = @4;
  [var1 addObject:var3];
  [var0 addObject:var1];
  NSMutableArray *var4 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var5 = @5;
  [var4 addObject:var5];
  NSNumber *var6 = @6;
  [var4 addObject:var6];
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test53 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSMutableArray *var1 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var2 = @3;
  [var1 addObject:var2];
  NSNumber *var3 = @4;
  [var1 addObject:var3];
  [var0 addObject:var1];
  NSMutableArray *var4 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var5 = @5;
  [var4 addObject:var5];
  NSNumber *var6 = @6;
  [var4 addObject:var6];
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test54 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test55 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test56 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:3];
  NSString *var2 = @"a";
  NSNumber *var3 = @1;
  [var1 setObject:var3 forKey:var2];
  NSString *var4 = @"b";
  NSNumber *var5 = @2;
  [var1 setObject:var5 forKey:var4];
  NSString *var6 = @"c";
  NSNumber *var7 = @3;
  [var1 setObject:var7 forKey:var6];
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test57 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:3];
  NSString *var2 = @"a";
  NSNumber *var3 = @1;
  [var1 setObject:var3 forKey:var2];
  NSString *var4 = @"b";
  NSNumber *var5 = @1;
  [var1 setObject:var5 forKey:var4];
  NSString *var6 = @"c";
  NSNumber *var7 = @3;
  [var1 setObject:var7 forKey:var6];
  [var0 addObject:var1];
  NSMutableDictionary *var8 = [NSMutableDictionary dictionaryWithCapacity:3];
  NSString *var9 = @"a";
  NSNumber *var10 = @1;
  [var8 setObject:var10 forKey:var9];
  NSString *var11 = @"b";
  NSNumber *var12 = @2;
  [var8 setObject:var12 forKey:var11];
  NSString *var13 = @"c";
  NSNumber *var14 = @3;
  [var8 setObject:var14 forKey:var13];
  [var0 addObject:var8];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test58 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:3];
  NSString *var2 = @"a";
  NSNumber *var3 = @1;
  [var1 setObject:var3 forKey:var2];
  NSString *var4 = @"b";
  NSNumber *var5 = @1;
  [var1 setObject:var5 forKey:var4];
  NSString *var6 = @"c";
  NSNumber *var7 = @3;
  [var1 setObject:var7 forKey:var6];
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test59 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test60 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @25;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test62 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @2;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test63 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @2;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test64 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test65 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"partial";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

@end
