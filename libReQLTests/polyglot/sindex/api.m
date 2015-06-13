// Copyright 2015 Adam Grandquist

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <libReQL.h>

@interface ObjcSindexApi602 : XCTestCase

@end

@implementation ObjcSindexApi602


- (void)test1 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:6];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"inserted";
  NSNumber *var6 = @4;
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"replaced";
  NSNumber *var8 = @0;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"skipped";
  NSNumber *var10 = @0;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"unchanged";
  NSNumber *var12 = @0;
  [var0 setObject:var12 forKey:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test2 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"created";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test3 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"created";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test4 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err_regex";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test5 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err_regex";
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
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test8 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"renamed";
  NSNumber *var2 = @0;
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test9 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"renamed";
  NSNumber *var2 = @0;
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test10 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"renamed";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test11 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"renamed";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test12 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"renamed";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test13 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"created";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test14 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"created";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test15 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"bag";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test16 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @3;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test17 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @0;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test18 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @0;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test19 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @0;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test20 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"created";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test21 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"index";
  NSString *var3 = @"rename-last-dup";
  [var1 setObject:var3 forKey:var2];
  NSString *var4 = @"ready";
  NSNumber *var5 = [NSNumber numberWithBool:YES];
  [var1 setObject:var5 forKey:var4];
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test22 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @3;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test23 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"dropped";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test24 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSString *var1 = @"rename-last";
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test25 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"dropped";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test26 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"created";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test27 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err_regex";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test28 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"created";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test29 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"created";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test30 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"created";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test31 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"created";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test32 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"created";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test33 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"created";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test34 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"result";
  NSString *var2 = @"blank";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test35 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"result";
  NSString *var2 = @"blank";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test36 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNull *var0 = [NSNull null];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test37 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNull *var0 = [NSNull null];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test38 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @1;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test39 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSString *var0 = @"SELECTION<OBJECT>";
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test40 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:6];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"inserted";
  NSNumber *var6 = @0;
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"replaced";
  NSNumber *var8 = @0;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"skipped";
  NSNumber *var10 = @0;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"unchanged";
  NSNumber *var12 = @1;
  [var0 setObject:var12 forKey:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test41 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test42 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"result";
  NSString *var2 = @"blank";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test43 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test44 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test45 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
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
  NSNumber *var0 = @1;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test48 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @1;
  [var0 addObject:var1];
  NSNumber *var2 = @2;
  [var0 addObject:var2];
  NSNumber *var3 = @3;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test49 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @1;
  [var0 addObject:var1];
  NSNumber *var2 = @2;
  [var0 addObject:var2];
  NSNumber *var3 = @3;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test50 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSString *var0 = @"SELECTION<STREAM>";
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test51 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSString *var0 = @"SELECTION<STREAM>";
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test52 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:6];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"inserted";
  NSNumber *var6 = @0;
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"replaced";
  NSNumber *var8 = @0;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"skipped";
  NSNumber *var10 = @0;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"unchanged";
  NSNumber *var12 = @1;
  [var0 setObject:var12 forKey:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test53 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:6];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"inserted";
  NSNumber *var6 = @0;
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"replaced";
  NSNumber *var8 = @0;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"skipped";
  NSNumber *var10 = @0;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"unchanged";
  NSNumber *var12 = @1;
  [var0 setObject:var12 forKey:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test54 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:6];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"inserted";
  NSNumber *var6 = @0;
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"replaced";
  NSNumber *var8 = @0;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"skipped";
  NSNumber *var10 = @0;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"unchanged";
  NSNumber *var12 = @3;
  [var0 setObject:var12 forKey:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test55 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:6];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"inserted";
  NSNumber *var6 = @0;
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"replaced";
  NSNumber *var8 = @0;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"skipped";
  NSNumber *var10 = @0;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"unchanged";
  NSNumber *var12 = @3;
  [var0 setObject:var12 forKey:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test56 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err_regex";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test57 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test58 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test59 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"result";
  NSString *var2 = @"blank";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test60 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test61 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"result";
  NSString *var2 = @"blank";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test62 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test63 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @1;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test64 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @1;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test65 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test66 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSNumber *var1 = @3;
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test67 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test68 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test69 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @2;
  [var0 addObject:var1];
  NSNumber *var2 = @3;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test70 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSString *var0 = @"SELECTION<STREAM>";
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test71 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:6];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"inserted";
  NSNumber *var6 = @0;
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"replaced";
  NSNumber *var8 = @0;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"skipped";
  NSNumber *var10 = @0;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"unchanged";
  NSNumber *var12 = @2;
  [var0 setObject:var12 forKey:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test72 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test73 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var2 = @"reql_ast_obj";
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var4 = @"reql_ast_obj";
  NSString *var5 = @"Bracket";
  [var3 setObject:var5 forKey:var4];
  [var1 setObject:var3 forKey:var2];
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test74 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var2 = @"reql_ast_obj";
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var4 = @"reql_ast_obj";
  NSString *var5 = @"Bracket";
  [var3 setObject:var5 forKey:var4];
  [var1 setObject:var3 forKey:var2];
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test75 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var2 = @"reql_ast_obj";
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var4 = @"reql_ast_obj";
  NSString *var5 = @"Bracket";
  [var3 setObject:var5 forKey:var4];
  [var1 setObject:var3 forKey:var2];
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test76 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var2 = @"reql_ast_obj";
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var4 = @"reql_ast_obj";
  NSString *var5 = @"Bracket";
  [var3 setObject:var5 forKey:var4];
  [var1 setObject:var3 forKey:var2];
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test77 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err_regex";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test78 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test79 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"left";
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var4 = @"reql_ast_obj";
  NSMutableDictionary *var5 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var6 = @"reql_ast_obj";
  NSString *var7 = @"Bracket";
  [var5 setObject:var7 forKey:var6];
  [var3 setObject:var5 forKey:var4];
  [var1 setObject:var3 forKey:var2];
  NSString *var8 = @"right";
  NSMutableDictionary *var9 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var10 = @"reql_ast_obj";
  NSMutableDictionary *var11 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var12 = @"reql_ast_obj";
  NSString *var13 = @"Bracket";
  [var11 setObject:var13 forKey:var12];
  [var9 setObject:var11 forKey:var10];
  [var1 setObject:var9 forKey:var8];
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test80 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"left";
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var4 = @"reql_ast_obj";
  NSMutableDictionary *var5 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var6 = @"reql_ast_obj";
  NSString *var7 = @"Bracket";
  [var5 setObject:var7 forKey:var6];
  [var3 setObject:var5 forKey:var4];
  [var1 setObject:var3 forKey:var2];
  NSString *var8 = @"right";
  NSMutableDictionary *var9 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var10 = @"reql_ast_obj";
  NSMutableDictionary *var11 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var12 = @"reql_ast_obj";
  NSString *var13 = @"Bracket";
  [var11 setObject:var13 forKey:var12];
  [var9 setObject:var11 forKey:var10];
  [var1 setObject:var9 forKey:var8];
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test81 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"left";
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var4 = @"reql_ast_obj";
  NSMutableDictionary *var5 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var6 = @"reql_ast_obj";
  NSString *var7 = @"Bracket";
  [var5 setObject:var7 forKey:var6];
  [var3 setObject:var5 forKey:var4];
  [var1 setObject:var3 forKey:var2];
  NSString *var8 = @"right";
  NSMutableDictionary *var9 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var10 = @"reql_ast_obj";
  NSMutableDictionary *var11 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var12 = @"reql_ast_obj";
  NSString *var13 = @"Bracket";
  [var11 setObject:var13 forKey:var12];
  [var9 setObject:var11 forKey:var10];
  [var1 setObject:var9 forKey:var8];
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test82 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"left";
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var4 = @"reql_ast_obj";
  NSMutableDictionary *var5 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var6 = @"reql_ast_obj";
  NSString *var7 = @"Bracket";
  [var5 setObject:var7 forKey:var6];
  [var3 setObject:var5 forKey:var4];
  [var1 setObject:var3 forKey:var2];
  NSString *var8 = @"right";
  NSMutableDictionary *var9 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var10 = @"reql_ast_obj";
  NSMutableDictionary *var11 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var12 = @"reql_ast_obj";
  NSString *var13 = @"Bracket";
  [var11 setObject:var13 forKey:var12];
  [var9 setObject:var11 forKey:var10];
  [var1 setObject:var9 forKey:var8];
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test83 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"left";
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var4 = @"reql_ast_obj";
  NSMutableDictionary *var5 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var6 = @"reql_ast_obj";
  NSString *var7 = @"Bracket";
  [var5 setObject:var7 forKey:var6];
  [var3 setObject:var5 forKey:var4];
  [var1 setObject:var3 forKey:var2];
  NSString *var8 = @"right";
  NSMutableDictionary *var9 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var10 = @"reql_ast_obj";
  NSMutableDictionary *var11 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var12 = @"reql_ast_obj";
  NSString *var13 = @"Bracket";
  [var11 setObject:var13 forKey:var12];
  [var9 setObject:var11 forKey:var10];
  [var1 setObject:var9 forKey:var8];
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test84 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"left";
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var4 = @"reql_ast_obj";
  NSMutableDictionary *var5 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var6 = @"reql_ast_obj";
  NSString *var7 = @"Bracket";
  [var5 setObject:var7 forKey:var6];
  [var3 setObject:var5 forKey:var4];
  [var1 setObject:var3 forKey:var2];
  NSString *var8 = @"right";
  NSMutableDictionary *var9 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var10 = @"reql_ast_obj";
  NSMutableDictionary *var11 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var12 = @"reql_ast_obj";
  NSString *var13 = @"Bracket";
  [var11 setObject:var13 forKey:var12];
  [var9 setObject:var11 forKey:var10];
  [var1 setObject:var9 forKey:var8];
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test85 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"left";
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var4 = @"reql_ast_obj";
  NSMutableDictionary *var5 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var6 = @"reql_ast_obj";
  NSString *var7 = @"Bracket";
  [var5 setObject:var7 forKey:var6];
  [var3 setObject:var5 forKey:var4];
  [var1 setObject:var3 forKey:var2];
  NSString *var8 = @"right";
  NSMutableDictionary *var9 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var10 = @"reql_ast_obj";
  NSMutableDictionary *var11 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var12 = @"reql_ast_obj";
  NSString *var13 = @"Bracket";
  [var11 setObject:var13 forKey:var12];
  [var9 setObject:var11 forKey:var10];
  [var1 setObject:var9 forKey:var8];
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test86 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"left";
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var4 = @"reql_ast_obj";
  NSMutableDictionary *var5 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var6 = @"reql_ast_obj";
  NSString *var7 = @"Bracket";
  [var5 setObject:var7 forKey:var6];
  [var3 setObject:var5 forKey:var4];
  [var1 setObject:var3 forKey:var2];
  NSString *var8 = @"right";
  NSMutableDictionary *var9 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var10 = @"reql_ast_obj";
  NSMutableDictionary *var11 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var12 = @"reql_ast_obj";
  NSString *var13 = @"Bracket";
  [var11 setObject:var13 forKey:var12];
  [var9 setObject:var11 forKey:var10];
  [var1 setObject:var9 forKey:var8];
  [var0 addObject:var1];
  NSMutableDictionary *var14 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var15 = @"left";
  NSMutableDictionary *var16 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var17 = @"reql_ast_obj";
  NSMutableDictionary *var18 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var19 = @"reql_ast_obj";
  NSString *var20 = @"Bracket";
  [var18 setObject:var20 forKey:var19];
  [var16 setObject:var18 forKey:var17];
  [var14 setObject:var16 forKey:var15];
  NSString *var21 = @"right";
  NSMutableDictionary *var22 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var23 = @"reql_ast_obj";
  NSMutableDictionary *var24 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var25 = @"reql_ast_obj";
  NSString *var26 = @"Bracket";
  [var24 setObject:var26 forKey:var25];
  [var22 setObject:var24 forKey:var23];
  [var14 setObject:var22 forKey:var21];
  [var0 addObject:var14];
  NSMutableDictionary *var27 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var28 = @"left";
  NSMutableDictionary *var29 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var30 = @"reql_ast_obj";
  NSMutableDictionary *var31 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var32 = @"reql_ast_obj";
  NSString *var33 = @"Bracket";
  [var31 setObject:var33 forKey:var32];
  [var29 setObject:var31 forKey:var30];
  [var27 setObject:var29 forKey:var28];
  NSString *var34 = @"right";
  NSMutableDictionary *var35 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var36 = @"reql_ast_obj";
  NSMutableDictionary *var37 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var38 = @"reql_ast_obj";
  NSString *var39 = @"Bracket";
  [var37 setObject:var39 forKey:var38];
  [var35 setObject:var37 forKey:var36];
  [var27 setObject:var35 forKey:var34];
  [var0 addObject:var27];
  NSMutableDictionary *var40 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var41 = @"left";
  NSMutableDictionary *var42 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var43 = @"reql_ast_obj";
  NSMutableDictionary *var44 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var45 = @"reql_ast_obj";
  NSString *var46 = @"Bracket";
  [var44 setObject:var46 forKey:var45];
  [var42 setObject:var44 forKey:var43];
  [var40 setObject:var42 forKey:var41];
  NSString *var47 = @"right";
  NSMutableDictionary *var48 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var49 = @"reql_ast_obj";
  NSMutableDictionary *var50 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var51 = @"reql_ast_obj";
  NSString *var52 = @"Bracket";
  [var50 setObject:var52 forKey:var51];
  [var48 setObject:var50 forKey:var49];
  [var40 setObject:var48 forKey:var47];
  [var0 addObject:var40];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test87 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"left";
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var4 = @"reql_ast_obj";
  NSMutableDictionary *var5 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var6 = @"reql_ast_obj";
  NSString *var7 = @"Bracket";
  [var5 setObject:var7 forKey:var6];
  [var3 setObject:var5 forKey:var4];
  [var1 setObject:var3 forKey:var2];
  NSString *var8 = @"right";
  NSMutableDictionary *var9 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var10 = @"reql_ast_obj";
  NSMutableDictionary *var11 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var12 = @"reql_ast_obj";
  NSString *var13 = @"Bracket";
  [var11 setObject:var13 forKey:var12];
  [var9 setObject:var11 forKey:var10];
  [var1 setObject:var9 forKey:var8];
  [var0 addObject:var1];
  NSMutableDictionary *var14 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var15 = @"left";
  NSMutableDictionary *var16 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var17 = @"reql_ast_obj";
  NSMutableDictionary *var18 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var19 = @"reql_ast_obj";
  NSString *var20 = @"Bracket";
  [var18 setObject:var20 forKey:var19];
  [var16 setObject:var18 forKey:var17];
  [var14 setObject:var16 forKey:var15];
  NSString *var21 = @"right";
  NSMutableDictionary *var22 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var23 = @"reql_ast_obj";
  NSMutableDictionary *var24 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var25 = @"reql_ast_obj";
  NSString *var26 = @"Bracket";
  [var24 setObject:var26 forKey:var25];
  [var22 setObject:var24 forKey:var23];
  [var14 setObject:var22 forKey:var21];
  [var0 addObject:var14];
  NSMutableDictionary *var27 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var28 = @"left";
  NSMutableDictionary *var29 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var30 = @"reql_ast_obj";
  NSMutableDictionary *var31 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var32 = @"reql_ast_obj";
  NSString *var33 = @"Bracket";
  [var31 setObject:var33 forKey:var32];
  [var29 setObject:var31 forKey:var30];
  [var27 setObject:var29 forKey:var28];
  NSString *var34 = @"right";
  NSMutableDictionary *var35 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var36 = @"reql_ast_obj";
  NSMutableDictionary *var37 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var38 = @"reql_ast_obj";
  NSString *var39 = @"Bracket";
  [var37 setObject:var39 forKey:var38];
  [var35 setObject:var37 forKey:var36];
  [var27 setObject:var35 forKey:var34];
  [var0 addObject:var27];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test88 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"left";
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var4 = @"reql_ast_obj";
  NSMutableDictionary *var5 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var6 = @"reql_ast_obj";
  NSString *var7 = @"Bracket";
  [var5 setObject:var7 forKey:var6];
  [var3 setObject:var5 forKey:var4];
  [var1 setObject:var3 forKey:var2];
  NSString *var8 = @"right";
  NSMutableDictionary *var9 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var10 = @"reql_ast_obj";
  NSMutableDictionary *var11 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var12 = @"reql_ast_obj";
  NSString *var13 = @"Bracket";
  [var11 setObject:var13 forKey:var12];
  [var9 setObject:var11 forKey:var10];
  [var1 setObject:var9 forKey:var8];
  [var0 addObject:var1];
  NSMutableDictionary *var14 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var15 = @"left";
  NSMutableDictionary *var16 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var17 = @"reql_ast_obj";
  NSMutableDictionary *var18 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var19 = @"reql_ast_obj";
  NSString *var20 = @"Bracket";
  [var18 setObject:var20 forKey:var19];
  [var16 setObject:var18 forKey:var17];
  [var14 setObject:var16 forKey:var15];
  NSString *var21 = @"right";
  NSMutableDictionary *var22 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var23 = @"reql_ast_obj";
  NSMutableDictionary *var24 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var25 = @"reql_ast_obj";
  NSString *var26 = @"Bracket";
  [var24 setObject:var26 forKey:var25];
  [var22 setObject:var24 forKey:var23];
  [var14 setObject:var22 forKey:var21];
  [var0 addObject:var14];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test89 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test90 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:8];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"left";
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var4 = @"reql_ast_obj";
  NSMutableDictionary *var5 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var6 = @"reql_ast_obj";
  NSString *var7 = @"Bracket";
  [var5 setObject:var7 forKey:var6];
  [var3 setObject:var5 forKey:var4];
  [var1 setObject:var3 forKey:var2];
  NSString *var8 = @"right";
  NSMutableDictionary *var9 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var10 = @"reql_ast_obj";
  NSMutableDictionary *var11 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var12 = @"reql_ast_obj";
  NSString *var13 = @"Bracket";
  [var11 setObject:var13 forKey:var12];
  [var9 setObject:var11 forKey:var10];
  [var1 setObject:var9 forKey:var8];
  [var0 addObject:var1];
  NSMutableDictionary *var14 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var15 = @"left";
  NSMutableDictionary *var16 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var17 = @"reql_ast_obj";
  NSMutableDictionary *var18 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var19 = @"reql_ast_obj";
  NSString *var20 = @"Bracket";
  [var18 setObject:var20 forKey:var19];
  [var16 setObject:var18 forKey:var17];
  [var14 setObject:var16 forKey:var15];
  NSString *var21 = @"right";
  NSMutableDictionary *var22 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var23 = @"reql_ast_obj";
  NSMutableDictionary *var24 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var25 = @"reql_ast_obj";
  NSString *var26 = @"Bracket";
  [var24 setObject:var26 forKey:var25];
  [var22 setObject:var24 forKey:var23];
  [var14 setObject:var22 forKey:var21];
  [var0 addObject:var14];
  NSMutableDictionary *var27 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var28 = @"left";
  NSMutableDictionary *var29 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var30 = @"reql_ast_obj";
  NSMutableDictionary *var31 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var32 = @"reql_ast_obj";
  NSString *var33 = @"Bracket";
  [var31 setObject:var33 forKey:var32];
  [var29 setObject:var31 forKey:var30];
  [var27 setObject:var29 forKey:var28];
  NSString *var34 = @"right";
  NSMutableDictionary *var35 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var36 = @"reql_ast_obj";
  NSMutableDictionary *var37 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var38 = @"reql_ast_obj";
  NSString *var39 = @"Bracket";
  [var37 setObject:var39 forKey:var38];
  [var35 setObject:var37 forKey:var36];
  [var27 setObject:var35 forKey:var34];
  [var0 addObject:var27];
  NSMutableDictionary *var40 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var41 = @"left";
  NSMutableDictionary *var42 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var43 = @"reql_ast_obj";
  NSMutableDictionary *var44 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var45 = @"reql_ast_obj";
  NSString *var46 = @"Bracket";
  [var44 setObject:var46 forKey:var45];
  [var42 setObject:var44 forKey:var43];
  [var40 setObject:var42 forKey:var41];
  NSString *var47 = @"right";
  NSMutableDictionary *var48 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var49 = @"reql_ast_obj";
  NSMutableDictionary *var50 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var51 = @"reql_ast_obj";
  NSString *var52 = @"Bracket";
  [var50 setObject:var52 forKey:var51];
  [var48 setObject:var50 forKey:var49];
  [var40 setObject:var48 forKey:var47];
  [var0 addObject:var40];
  NSMutableDictionary *var53 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var54 = @"left";
  NSMutableDictionary *var55 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var56 = @"reql_ast_obj";
  NSMutableDictionary *var57 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var58 = @"reql_ast_obj";
  NSString *var59 = @"Bracket";
  [var57 setObject:var59 forKey:var58];
  [var55 setObject:var57 forKey:var56];
  [var53 setObject:var55 forKey:var54];
  NSString *var60 = @"right";
  NSMutableDictionary *var61 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var62 = @"reql_ast_obj";
  NSMutableDictionary *var63 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var64 = @"reql_ast_obj";
  NSString *var65 = @"Bracket";
  [var63 setObject:var65 forKey:var64];
  [var61 setObject:var63 forKey:var62];
  [var53 setObject:var61 forKey:var60];
  [var0 addObject:var53];
  NSMutableDictionary *var66 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var67 = @"left";
  NSMutableDictionary *var68 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var69 = @"reql_ast_obj";
  NSMutableDictionary *var70 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var71 = @"reql_ast_obj";
  NSString *var72 = @"Bracket";
  [var70 setObject:var72 forKey:var71];
  [var68 setObject:var70 forKey:var69];
  [var66 setObject:var68 forKey:var67];
  NSString *var73 = @"right";
  NSMutableDictionary *var74 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var75 = @"reql_ast_obj";
  NSMutableDictionary *var76 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var77 = @"reql_ast_obj";
  NSString *var78 = @"Bracket";
  [var76 setObject:var78 forKey:var77];
  [var74 setObject:var76 forKey:var75];
  [var66 setObject:var74 forKey:var73];
  [var0 addObject:var66];
  NSMutableDictionary *var79 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var80 = @"left";
  NSMutableDictionary *var81 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var82 = @"reql_ast_obj";
  NSMutableDictionary *var83 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var84 = @"reql_ast_obj";
  NSString *var85 = @"Bracket";
  [var83 setObject:var85 forKey:var84];
  [var81 setObject:var83 forKey:var82];
  [var79 setObject:var81 forKey:var80];
  NSString *var86 = @"right";
  NSMutableDictionary *var87 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var88 = @"reql_ast_obj";
  NSMutableDictionary *var89 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var90 = @"reql_ast_obj";
  NSString *var91 = @"Bracket";
  [var89 setObject:var91 forKey:var90];
  [var87 setObject:var89 forKey:var88];
  [var79 setObject:var87 forKey:var86];
  [var0 addObject:var79];
  NSMutableDictionary *var92 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var93 = @"left";
  NSMutableDictionary *var94 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var95 = @"reql_ast_obj";
  NSMutableDictionary *var96 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var97 = @"reql_ast_obj";
  NSString *var98 = @"Bracket";
  [var96 setObject:var98 forKey:var97];
  [var94 setObject:var96 forKey:var95];
  [var92 setObject:var94 forKey:var93];
  NSString *var99 = @"right";
  NSMutableDictionary *var100 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var101 = @"reql_ast_obj";
  NSMutableDictionary *var102 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var103 = @"reql_ast_obj";
  NSString *var104 = @"Bracket";
  [var102 setObject:var104 forKey:var103];
  [var100 setObject:var102 forKey:var101];
  [var92 setObject:var100 forKey:var99];
  [var0 addObject:var92];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test91 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test92 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"created";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test93 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"created";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test94 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"result";
  NSString *var2 = @"blank";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test95 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @2;
  [var0 addObject:var1];
  NSNumber *var2 = @3;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test96 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test97 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"created";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test98 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"result";
  NSString *var2 = @"blank";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test99 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test100 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:6];
  NSString *var1 = @"deleted";
  NSNumber *var2 = @0;
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"errors";
  NSNumber *var4 = @0;
  [var0 setObject:var4 forKey:var3];
  NSString *var5 = @"inserted";
  NSNumber *var6 = @1;
  [var0 setObject:var6 forKey:var5];
  NSString *var7 = @"replaced";
  NSNumber *var8 = @0;
  [var0 setObject:var8 forKey:var7];
  NSString *var9 = @"skipped";
  NSNumber *var10 = @0;
  [var0 setObject:var10 forKey:var9];
  NSString *var11 = @"unchanged";
  NSNumber *var12 = @0;
  [var0 setObject:var12 forKey:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test102 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"left";
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var4 = @"reql_ast_obj";
  NSMutableDictionary *var5 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var6 = @"reql_ast_obj";
  NSString *var7 = @"Bracket";
  [var5 setObject:var7 forKey:var6];
  [var3 setObject:var5 forKey:var4];
  [var1 setObject:var3 forKey:var2];
  NSString *var8 = @"right";
  NSMutableDictionary *var9 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var10 = @"reql_ast_obj";
  NSMutableDictionary *var11 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var12 = @"reql_ast_obj";
  NSString *var13 = @"Bracket";
  [var11 setObject:var13 forKey:var12];
  [var9 setObject:var11 forKey:var10];
  [var1 setObject:var9 forKey:var8];
  [var0 addObject:var1];
  NSMutableDictionary *var14 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var15 = @"left";
  NSMutableDictionary *var16 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var17 = @"reql_ast_obj";
  NSMutableDictionary *var18 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var19 = @"reql_ast_obj";
  NSString *var20 = @"Bracket";
  [var18 setObject:var20 forKey:var19];
  [var16 setObject:var18 forKey:var17];
  [var14 setObject:var16 forKey:var15];
  NSString *var21 = @"right";
  NSMutableDictionary *var22 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var23 = @"reql_ast_obj";
  NSMutableDictionary *var24 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var25 = @"reql_ast_obj";
  NSString *var26 = @"Bracket";
  [var24 setObject:var26 forKey:var25];
  [var22 setObject:var24 forKey:var23];
  [var14 setObject:var22 forKey:var21];
  [var0 addObject:var14];
  NSMutableDictionary *var27 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var28 = @"left";
  NSMutableDictionary *var29 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var30 = @"reql_ast_obj";
  NSMutableDictionary *var31 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var32 = @"reql_ast_obj";
  NSString *var33 = @"Bracket";
  [var31 setObject:var33 forKey:var32];
  [var29 setObject:var31 forKey:var30];
  [var27 setObject:var29 forKey:var28];
  NSString *var34 = @"right";
  NSMutableDictionary *var35 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var36 = @"reql_ast_obj";
  NSMutableDictionary *var37 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var38 = @"reql_ast_obj";
  NSString *var39 = @"Bracket";
  [var37 setObject:var39 forKey:var38];
  [var35 setObject:var37 forKey:var36];
  [var27 setObject:var35 forKey:var34];
  [var0 addObject:var27];
  NSMutableDictionary *var40 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var41 = @"left";
  NSMutableDictionary *var42 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var43 = @"reql_ast_obj";
  NSMutableDictionary *var44 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var45 = @"reql_ast_obj";
  NSString *var46 = @"Bracket";
  [var44 setObject:var46 forKey:var45];
  [var42 setObject:var44 forKey:var43];
  [var40 setObject:var42 forKey:var41];
  NSString *var47 = @"right";
  NSMutableDictionary *var48 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var49 = @"reql_ast_obj";
  NSMutableDictionary *var50 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var51 = @"reql_ast_obj";
  NSString *var52 = @"Bracket";
  [var50 setObject:var52 forKey:var51];
  [var48 setObject:var50 forKey:var49];
  [var40 setObject:var48 forKey:var47];
  [var0 addObject:var40];
  NSMutableDictionary *var53 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var54 = @"left";
  NSMutableDictionary *var55 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var56 = @"reql_ast_obj";
  NSMutableDictionary *var57 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var58 = @"reql_ast_obj";
  NSString *var59 = @"Bracket";
  [var57 setObject:var59 forKey:var58];
  [var55 setObject:var57 forKey:var56];
  [var53 setObject:var55 forKey:var54];
  NSString *var60 = @"right";
  NSMutableDictionary *var61 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var62 = @"reql_ast_obj";
  NSMutableDictionary *var63 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var64 = @"reql_ast_obj";
  NSString *var65 = @"Bracket";
  [var63 setObject:var65 forKey:var64];
  [var61 setObject:var63 forKey:var62];
  [var53 setObject:var61 forKey:var60];
  [var0 addObject:var53];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test103 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSMutableDictionary *var1 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var2 = @"left";
  NSMutableDictionary *var3 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var4 = @"reql_ast_obj";
  NSMutableDictionary *var5 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var6 = @"reql_ast_obj";
  NSString *var7 = @"Bracket";
  [var5 setObject:var7 forKey:var6];
  [var3 setObject:var5 forKey:var4];
  [var1 setObject:var3 forKey:var2];
  NSString *var8 = @"right";
  NSMutableDictionary *var9 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var10 = @"reql_ast_obj";
  NSMutableDictionary *var11 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var12 = @"reql_ast_obj";
  NSString *var13 = @"Bracket";
  [var11 setObject:var13 forKey:var12];
  [var9 setObject:var11 forKey:var10];
  [var1 setObject:var9 forKey:var8];
  [var0 addObject:var1];
  NSMutableDictionary *var14 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var15 = @"left";
  NSMutableDictionary *var16 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var17 = @"reql_ast_obj";
  NSMutableDictionary *var18 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var19 = @"reql_ast_obj";
  NSString *var20 = @"Bracket";
  [var18 setObject:var20 forKey:var19];
  [var16 setObject:var18 forKey:var17];
  [var14 setObject:var16 forKey:var15];
  NSString *var21 = @"right";
  NSMutableDictionary *var22 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var23 = @"reql_ast_obj";
  NSMutableDictionary *var24 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var25 = @"reql_ast_obj";
  NSString *var26 = @"Bracket";
  [var24 setObject:var26 forKey:var25];
  [var22 setObject:var24 forKey:var23];
  [var14 setObject:var22 forKey:var21];
  [var0 addObject:var14];
  NSMutableDictionary *var27 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var28 = @"left";
  NSMutableDictionary *var29 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var30 = @"reql_ast_obj";
  NSMutableDictionary *var31 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var32 = @"reql_ast_obj";
  NSString *var33 = @"Bracket";
  [var31 setObject:var33 forKey:var32];
  [var29 setObject:var31 forKey:var30];
  [var27 setObject:var29 forKey:var28];
  NSString *var34 = @"right";
  NSMutableDictionary *var35 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var36 = @"reql_ast_obj";
  NSMutableDictionary *var37 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var38 = @"reql_ast_obj";
  NSString *var39 = @"Bracket";
  [var37 setObject:var39 forKey:var38];
  [var35 setObject:var37 forKey:var36];
  [var27 setObject:var35 forKey:var34];
  [var0 addObject:var27];
  NSMutableDictionary *var40 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var41 = @"left";
  NSMutableDictionary *var42 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var43 = @"reql_ast_obj";
  NSMutableDictionary *var44 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var45 = @"reql_ast_obj";
  NSString *var46 = @"Bracket";
  [var44 setObject:var46 forKey:var45];
  [var42 setObject:var44 forKey:var43];
  [var40 setObject:var42 forKey:var41];
  NSString *var47 = @"right";
  NSMutableDictionary *var48 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var49 = @"reql_ast_obj";
  NSMutableDictionary *var50 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var51 = @"reql_ast_obj";
  NSString *var52 = @"Bracket";
  [var50 setObject:var52 forKey:var51];
  [var48 setObject:var50 forKey:var49];
  [var40 setObject:var48 forKey:var47];
  [var0 addObject:var40];
  NSMutableDictionary *var53 = [NSMutableDictionary dictionaryWithCapacity:2];
  NSString *var54 = @"left";
  NSMutableDictionary *var55 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var56 = @"reql_ast_obj";
  NSMutableDictionary *var57 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var58 = @"reql_ast_obj";
  NSString *var59 = @"Bracket";
  [var57 setObject:var59 forKey:var58];
  [var55 setObject:var57 forKey:var56];
  [var53 setObject:var55 forKey:var54];
  NSString *var60 = @"right";
  NSMutableDictionary *var61 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var62 = @"reql_ast_obj";
  NSMutableDictionary *var63 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var64 = @"reql_ast_obj";
  NSString *var65 = @"Bracket";
  [var63 setObject:var65 forKey:var64];
  [var61 setObject:var63 forKey:var62];
  [var53 setObject:var61 forKey:var60];
  [var0 addObject:var53];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test104 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test105 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test106 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test107 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test108 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test109 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test110 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test111 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test112 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test113 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test114 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test115 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test116 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test117 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test118 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test119 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test120 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test121 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test122 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test123 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test124 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test125 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test126 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test127 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test128 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test129 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test130 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test131 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test132 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test133 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test134 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test135 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test136 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test137 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test138 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test139 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test140 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test141 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test142 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test143 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test144 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test145 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test146 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test147 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test148 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test149 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test150 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test151 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test152 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test153 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test154 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test155 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test156 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test157 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test158 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test159 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test160 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test161 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test162 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test163 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test164 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test165 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test166 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test167 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test168 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test169 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test170 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test171 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test172 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test173 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test174 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test175 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test176 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test177 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test178 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test179 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test180 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test181 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSNumber *var1 = @4;
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test182 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test183 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test184 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test185 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test186 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test187 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSNumber *var1 = @4;
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test188 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test189 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test190 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test191 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test192 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test193 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test194 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test195 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test196 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test197 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test198 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @2;
  [var0 addObject:var1];
  NSNumber *var2 = @3;
  [var0 addObject:var2];
  NSNumber *var3 = @4;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test199 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test200 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test201 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test202 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test203 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test204 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test205 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test206 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @2;
  [var0 addObject:var1];
  NSNumber *var2 = @3;
  [var0 addObject:var2];
  NSNumber *var3 = @4;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test207 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @2;
  [var0 addObject:var1];
  NSNumber *var2 = @3;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test208 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"created";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test209 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"created";
  NSNumber *var2 = @1;
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test210 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"result";
  NSString *var2 = @"blank";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test211 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test212 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test213 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test214 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test215 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test216 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test217 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test218 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test219 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test220 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test221 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test222 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test223 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test224 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test225 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test226 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test227 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test228 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test229 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test230 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test231 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test232 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test233 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test234 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test235 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test236 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test237 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test238 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test239 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test240 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test241 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test242 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test243 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test244 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test245 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test246 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test247 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test248 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test249 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test250 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @1;
  [var0 addObject:var2];
  NSNumber *var3 = @2;
  [var0 addObject:var3];
  NSNumber *var4 = @3;
  [var0 addObject:var4];
  NSNumber *var5 = @4;
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test251 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test252 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test253 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test254 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test255 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSNumber *var1 = @2;
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test256 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test257 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSNumber *var1 = @2;
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test258 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSNumber *var1 = @2;
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test259 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @2;
  [var0 addObject:var1];
  NSNumber *var2 = @3;
  [var0 addObject:var2];
  NSNumber *var3 = @4;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test260 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @2;
  [var0 addObject:var1];
  NSNumber *var2 = @3;
  [var0 addObject:var2];
  NSNumber *var3 = @4;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test261 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test262 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test263 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSNumber *var1 = @2;
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test264 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test265 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSNumber *var1 = @2;
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test266 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSNumber *var1 = @2;
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test267 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @2;
  [var0 addObject:var1];
  NSNumber *var2 = @3;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test268 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @2;
  [var0 addObject:var1];
  NSNumber *var2 = @3;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test269 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @2;
  [var0 addObject:var1];
  NSNumber *var2 = @3;
  [var0 addObject:var2];
  NSNumber *var3 = @4;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test270 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @2;
  [var0 addObject:var1];
  NSNumber *var2 = @3;
  [var0 addObject:var2];
  NSNumber *var3 = @4;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test271 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test272 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test273 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test274 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test275 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test276 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test277 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test278 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSNumber *var1 = @2;
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test279 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @3;
  [var0 addObject:var1];
  NSNumber *var2 = @4;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test280 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @2;
  [var0 addObject:var1];
  NSNumber *var2 = @3;
  [var0 addObject:var2];
  NSNumber *var3 = @4;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test281 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test282 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test283 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test284 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test285 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test286 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSNumber *var1 = @2;
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test287 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSNumber *var1 = @3;
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test288 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @2;
  [var0 addObject:var1];
  NSNumber *var2 = @3;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test289 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @3;
  [var0 addObject:var1];
  NSNumber *var2 = @4;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test290 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @2;
  [var0 addObject:var1];
  NSNumber *var2 = @3;
  [var0 addObject:var2];
  NSNumber *var3 = @4;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test291 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test292 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test293 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test294 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test295 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test296 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test297 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test298 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test299 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @3;
  [var0 addObject:var1];
  NSNumber *var2 = @4;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test300 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @3;
  [var0 addObject:var1];
  NSNumber *var2 = @4;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test301 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test302 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test303 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test304 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test305 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test306 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test307 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSNumber *var1 = @3;
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test308 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSNumber *var1 = @3;
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test309 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @3;
  [var0 addObject:var1];
  NSNumber *var2 = @4;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test310 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var1 = @3;
  [var0 addObject:var1];
  NSNumber *var2 = @4;
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test311 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @0;
  [var0 addObject:var2];
  NSNumber *var3 = @0;
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test312 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:13];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @0;
  [var0 addObject:var2];
  NSNumber *var3 = @0;
  [var0 addObject:var3];
  NSNumber *var4 = @1;
  [var0 addObject:var4];
  NSNumber *var5 = @1;
  [var0 addObject:var5];
  NSNumber *var6 = @1;
  [var0 addObject:var6];
  NSNumber *var7 = @2;
  [var0 addObject:var7];
  NSNumber *var8 = @3;
  [var0 addObject:var8];
  NSNumber *var9 = @3;
  [var0 addObject:var9];
  NSNumber *var10 = @3;
  [var0 addObject:var10];
  NSNumber *var11 = @4;
  [var0 addObject:var11];
  NSNumber *var12 = @4;
  [var0 addObject:var12];
  NSNumber *var13 = @4;
  [var0 addObject:var13];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test313 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:13];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @0;
  [var0 addObject:var2];
  NSNumber *var3 = @0;
  [var0 addObject:var3];
  NSNumber *var4 = @1;
  [var0 addObject:var4];
  NSNumber *var5 = @1;
  [var0 addObject:var5];
  NSNumber *var6 = @1;
  [var0 addObject:var6];
  NSNumber *var7 = @2;
  [var0 addObject:var7];
  NSNumber *var8 = @3;
  [var0 addObject:var8];
  NSNumber *var9 = @3;
  [var0 addObject:var9];
  NSNumber *var10 = @3;
  [var0 addObject:var10];
  NSNumber *var11 = @4;
  [var0 addObject:var11];
  NSNumber *var12 = @4;
  [var0 addObject:var12];
  NSNumber *var13 = @4;
  [var0 addObject:var13];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

@end
