// Copyright 2015 Adam Grandquist

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <libReQL.h>

@interface ObjcAccessingPortions : XCTestCase

@end

@implementation ObjcAccessingPortions


- (void)test10 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @1375142400;
  [var0 addObject:var1];
  NSNumber *var2 = @1375142400;
  [var0 addObject:var2];
  NSNumber *var3 = @1375142400;
  [var0 addObject:var3];
  NSNumber *var4 = @2375136000;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test11 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @0;
  [var0 addObject:var1];
  NSNumber *var2 = @0;
  [var0 addObject:var2];
  NSNumber *var3 = @0;
  [var0 addObject:var3];
  NSNumber *var4 = @0;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test12 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSNumber *var1 = @4896.681;
  [var0 addObject:var1];
  NSNumber *var2 = @4896.682;
  [var0 addObject:var2];
  NSNumber *var3 = @4897.681;
  [var0 addObject:var3];
  NSNumber *var4 = @11296.681;
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test13 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSMutableArray *var1 = [NSMutableArray arrayWithCapacity:6];
  NSNumber *var2 = @2013;
  [var1 addObject:var2];
  NSNumber *var3 = @7;
  [var1 addObject:var3];
  NSNumber *var4 = @30;
  [var1 addObject:var4];
  NSNumber *var5 = @1;
  [var1 addObject:var5];
  NSNumber *var6 = @21;
  [var1 addObject:var6];
  NSNumber *var7 = @36.681;
  [var1 addObject:var7];
  [var0 addObject:var1];
  NSMutableArray *var8 = [NSMutableArray arrayWithCapacity:6];
  NSNumber *var9 = @2013;
  [var8 addObject:var9];
  NSNumber *var10 = @7;
  [var8 addObject:var10];
  NSNumber *var11 = @30;
  [var8 addObject:var11];
  NSNumber *var12 = @1;
  [var8 addObject:var12];
  NSNumber *var13 = @21;
  [var8 addObject:var13];
  NSNumber *var14 = @36.682;
  [var8 addObject:var14];
  [var0 addObject:var8];
  NSMutableArray *var15 = [NSMutableArray arrayWithCapacity:6];
  NSNumber *var16 = @2013;
  [var15 addObject:var16];
  NSNumber *var17 = @7;
  [var15 addObject:var17];
  NSNumber *var18 = @30;
  [var15 addObject:var18];
  NSNumber *var19 = @1;
  [var15 addObject:var19];
  NSNumber *var20 = @21;
  [var15 addObject:var20];
  NSNumber *var21 = @37.681;
  [var15 addObject:var21];
  [var0 addObject:var15];
  NSMutableArray *var22 = [NSMutableArray arrayWithCapacity:6];
  NSNumber *var23 = @2045;
  [var22 addObject:var23];
  NSNumber *var24 = @4;
  [var22 addObject:var24];
  NSNumber *var25 = @7;
  [var22 addObject:var25];
  NSNumber *var26 = @3;
  [var22 addObject:var26];
  NSNumber *var27 = @8;
  [var22 addObject:var27];
  NSNumber *var28 = @16.681;
  [var22 addObject:var28];
  [var0 addObject:var22];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test14 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"rts";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test15 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @0;
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test16 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSMutableArray *var1 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var2 = @2;
  [var1 addObject:var2];
  NSNumber *var3 = @211;
  [var1 addObject:var3];
  [var0 addObject:var1];
  NSMutableArray *var4 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var5 = @2;
  [var4 addObject:var5];
  NSNumber *var6 = @211;
  [var4 addObject:var6];
  [var0 addObject:var4];
  NSMutableArray *var7 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var8 = @2;
  [var7 addObject:var8];
  NSNumber *var9 = @211;
  [var7 addObject:var9];
  [var0 addObject:var7];
  NSMutableArray *var10 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var11 = @5;
  [var10 addObject:var11];
  NSNumber *var12 = @97;
  [var10 addObject:var12];
  [var0 addObject:var10];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

@end
