// Copyright 2015 Adam Grandquist

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <libReQL.h>

@interface ObjcTestGeoConstructors : XCTestCase

@end

@implementation ObjcTestGeoConstructors


- (void)test0 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:3];
  NSString *var1 = @"$reql_type$";
  NSString *var2 = @"GEOMETRY";
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"coordinates";
  NSMutableArray *var4 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var5 = @0;
  [var4 addObject:var5];
  NSNumber *var6 = @0;
  [var4 addObject:var6];
  [var0 setObject:var4 forKey:var3];
  NSString *var7 = @"type";
  NSString *var8 = @"Point";
  [var0 setObject:var8 forKey:var7];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test1 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:3];
  NSString *var1 = @"$reql_type$";
  NSString *var2 = @"GEOMETRY";
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"coordinates";
  NSMutableArray *var4 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var5 = @0;
  [var4 addObject:var5];
  NSNumber *var6 = @-90;
  [var4 addObject:var6];
  [var0 setObject:var4 forKey:var3];
  NSString *var7 = @"type";
  NSString *var8 = @"Point";
  [var0 setObject:var8 forKey:var7];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test2 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:3];
  NSString *var1 = @"$reql_type$";
  NSString *var2 = @"GEOMETRY";
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"coordinates";
  NSMutableArray *var4 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var5 = @0;
  [var4 addObject:var5];
  NSNumber *var6 = @90;
  [var4 addObject:var6];
  [var0 setObject:var4 forKey:var3];
  NSString *var7 = @"type";
  NSString *var8 = @"Point";
  [var0 setObject:var8 forKey:var7];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test3 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:3];
  NSString *var1 = @"$reql_type$";
  NSString *var2 = @"GEOMETRY";
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"coordinates";
  NSMutableArray *var4 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var5 = @-180;
  [var4 addObject:var5];
  NSNumber *var6 = @0;
  [var4 addObject:var6];
  [var0 setObject:var4 forKey:var3];
  NSString *var7 = @"type";
  NSString *var8 = @"Point";
  [var0 setObject:var8 forKey:var7];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test4 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:3];
  NSString *var1 = @"$reql_type$";
  NSString *var2 = @"GEOMETRY";
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"coordinates";
  NSMutableArray *var4 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var5 = @180;
  [var4 addObject:var5];
  NSNumber *var6 = @0;
  [var4 addObject:var6];
  [var0 setObject:var4 forKey:var3];
  NSString *var7 = @"type";
  NSString *var8 = @"Point";
  [var0 setObject:var8 forKey:var7];
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
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test9 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
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
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:3];
  NSString *var1 = @"$reql_type$";
  NSString *var2 = @"GEOMETRY";
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"coordinates";
  NSMutableArray *var4 = [NSMutableArray arrayWithCapacity:2];
  NSMutableArray *var5 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var6 = @0;
  [var5 addObject:var6];
  NSNumber *var7 = @0;
  [var5 addObject:var7];
  [var4 addObject:var5];
  NSMutableArray *var8 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var9 = @0;
  [var8 addObject:var9];
  NSNumber *var10 = @1;
  [var8 addObject:var10];
  [var4 addObject:var8];
  [var0 setObject:var4 forKey:var3];
  NSString *var11 = @"type";
  NSString *var12 = @"LineString";
  [var0 setObject:var12 forKey:var11];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test13 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test14 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test15 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:3];
  NSString *var1 = @"$reql_type$";
  NSString *var2 = @"GEOMETRY";
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"coordinates";
  NSMutableArray *var4 = [NSMutableArray arrayWithCapacity:3];
  NSMutableArray *var5 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var6 = @0;
  [var5 addObject:var6];
  NSNumber *var7 = @0;
  [var5 addObject:var7];
  [var4 addObject:var5];
  NSMutableArray *var8 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var9 = @0;
  [var8 addObject:var9];
  NSNumber *var10 = @1;
  [var8 addObject:var10];
  [var4 addObject:var8];
  NSMutableArray *var11 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var12 = @0;
  [var11 addObject:var12];
  NSNumber *var13 = @0;
  [var11 addObject:var13];
  [var4 addObject:var11];
  [var0 setObject:var4 forKey:var3];
  NSString *var14 = @"type";
  NSString *var15 = @"LineString";
  [var0 setObject:var15 forKey:var14];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test16 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:3];
  NSString *var1 = @"$reql_type$";
  NSString *var2 = @"GEOMETRY";
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"coordinates";
  NSMutableArray *var4 = [NSMutableArray arrayWithCapacity:3];
  NSMutableArray *var5 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var6 = @0;
  [var5 addObject:var6];
  NSNumber *var7 = @0;
  [var5 addObject:var7];
  [var4 addObject:var5];
  NSMutableArray *var8 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var9 = @0;
  [var8 addObject:var9];
  NSNumber *var10 = @1;
  [var8 addObject:var10];
  [var4 addObject:var8];
  NSMutableArray *var11 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var12 = @0;
  [var11 addObject:var12];
  NSNumber *var13 = @0;
  [var11 addObject:var13];
  [var4 addObject:var11];
  [var0 setObject:var4 forKey:var3];
  NSString *var14 = @"type";
  NSString *var15 = @"LineString";
  [var0 setObject:var15 forKey:var14];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test17 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test18 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test19 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test20 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test21 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test22 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:3];
  NSString *var1 = @"$reql_type$";
  NSString *var2 = @"GEOMETRY";
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"coordinates";
  NSMutableArray *var4 = [NSMutableArray arrayWithCapacity:1];
  NSMutableArray *var5 = [NSMutableArray arrayWithCapacity:4];
  NSMutableArray *var6 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var7 = @0;
  [var6 addObject:var7];
  NSNumber *var8 = @0;
  [var6 addObject:var8];
  [var5 addObject:var6];
  NSMutableArray *var9 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var10 = @0;
  [var9 addObject:var10];
  NSNumber *var11 = @1;
  [var9 addObject:var11];
  [var5 addObject:var9];
  NSMutableArray *var12 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var13 = @1;
  [var12 addObject:var13];
  NSNumber *var14 = @0;
  [var12 addObject:var14];
  [var5 addObject:var12];
  NSMutableArray *var15 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var16 = @0;
  [var15 addObject:var16];
  NSNumber *var17 = @0;
  [var15 addObject:var17];
  [var5 addObject:var15];
  [var4 addObject:var5];
  [var0 setObject:var4 forKey:var3];
  NSString *var18 = @"type";
  NSString *var19 = @"Polygon";
  [var0 setObject:var19 forKey:var18];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test23 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:3];
  NSString *var1 = @"$reql_type$";
  NSString *var2 = @"GEOMETRY";
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"coordinates";
  NSMutableArray *var4 = [NSMutableArray arrayWithCapacity:1];
  NSMutableArray *var5 = [NSMutableArray arrayWithCapacity:4];
  NSMutableArray *var6 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var7 = @0;
  [var6 addObject:var7];
  NSNumber *var8 = @0;
  [var6 addObject:var8];
  [var5 addObject:var6];
  NSMutableArray *var9 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var10 = @0;
  [var9 addObject:var10];
  NSNumber *var11 = @1;
  [var9 addObject:var11];
  [var5 addObject:var9];
  NSMutableArray *var12 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var13 = @1;
  [var12 addObject:var13];
  NSNumber *var14 = @0;
  [var12 addObject:var14];
  [var5 addObject:var12];
  NSMutableArray *var15 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var16 = @0;
  [var15 addObject:var16];
  NSNumber *var17 = @0;
  [var15 addObject:var17];
  [var5 addObject:var15];
  [var4 addObject:var5];
  [var0 setObject:var4 forKey:var3];
  NSString *var18 = @"type";
  NSString *var19 = @"Polygon";
  [var0 setObject:var19 forKey:var18];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test24 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test25 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test26 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test27 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

@end
