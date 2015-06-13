// Copyright 2015 Adam Grandquist

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <libReQL.h>

@interface ObjcTestGeometricPrimitiveConstructors : XCTestCase

@end

@implementation ObjcTestGeometricPrimitiveConstructors


- (void)test0 {
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
  NSNumber *var8 = @-9.04369477050382e-06;
  [var6 addObject:var8];
  [var5 addObject:var6];
  NSMutableArray *var9 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var10 = @-7.779638566553426e-06;
  [var9 addObject:var10];
  NSNumber *var11 = @4.5218473852518965e-06;
  [var9 addObject:var11];
  [var5 addObject:var9];
  NSMutableArray *var12 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var13 = @7.779638566553426e-06;
  [var12 addObject:var13];
  NSNumber *var14 = @4.5218473852518965e-06;
  [var12 addObject:var14];
  [var5 addObject:var12];
  NSMutableArray *var15 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var16 = @0;
  [var15 addObject:var16];
  NSNumber *var17 = @-9.04369477050382e-06;
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

- (void)test1 {
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
  NSNumber *var8 = @-9.04369477050382e-06;
  [var6 addObject:var8];
  [var5 addObject:var6];
  NSMutableArray *var9 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var10 = @-7.779638566553426e-06;
  [var9 addObject:var10];
  NSNumber *var11 = @4.5218473852518965e-06;
  [var9 addObject:var11];
  [var5 addObject:var9];
  NSMutableArray *var12 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var13 = @7.779638566553426e-06;
  [var12 addObject:var13];
  NSNumber *var14 = @4.5218473852518965e-06;
  [var12 addObject:var14];
  [var5 addObject:var12];
  NSMutableArray *var15 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var16 = @0;
  [var15 addObject:var16];
  NSNumber *var17 = @-9.04369477050382e-06;
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

- (void)test2 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:3];
  NSString *var1 = @"$reql_type$";
  NSString *var2 = @"GEOMETRY";
  [var0 setObject:var2 forKey:var1];
  NSString *var3 = @"coordinates";
  NSMutableArray *var4 = [NSMutableArray arrayWithCapacity:4];
  NSMutableArray *var5 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var6 = @0;
  [var5 addObject:var6];
  NSNumber *var7 = @-9.04369477050382e-06;
  [var5 addObject:var7];
  [var4 addObject:var5];
  NSMutableArray *var8 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var9 = @-7.779638566553426e-06;
  [var8 addObject:var9];
  NSNumber *var10 = @4.5218473852518965e-06;
  [var8 addObject:var10];
  [var4 addObject:var8];
  NSMutableArray *var11 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var12 = @7.779638566553426e-06;
  [var11 addObject:var12];
  NSNumber *var13 = @4.5218473852518965e-06;
  [var11 addObject:var13];
  [var4 addObject:var11];
  NSMutableArray *var14 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var15 = @0;
  [var14 addObject:var15];
  NSNumber *var16 = @-9.04369477050382e-06;
  [var14 addObject:var16];
  [var4 addObject:var14];
  [var0 setObject:var4 forKey:var3];
  NSString *var17 = @"type";
  NSString *var18 = @"LineString";
  [var0 setObject:var18 forKey:var17];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test3 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"func";
  NSString *var2 = @"err";
  [var0 setObject:var2 forKey:var1];
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
  NSMutableArray *var4 = [NSMutableArray arrayWithCapacity:1];
  NSMutableArray *var5 = [NSMutableArray arrayWithCapacity:4];
  NSMutableArray *var6 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var7 = @0;
  [var6 addObject:var7];
  NSNumber *var8 = @-9.04369477050382e-06;
  [var6 addObject:var8];
  [var5 addObject:var6];
  NSMutableArray *var9 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var10 = @-7.779638566553426e-06;
  [var9 addObject:var10];
  NSNumber *var11 = @4.5218473852518965e-06;
  [var9 addObject:var11];
  [var5 addObject:var9];
  NSMutableArray *var12 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var13 = @7.779638566553426e-06;
  [var12 addObject:var13];
  NSNumber *var14 = @4.5218473852518965e-06;
  [var12 addObject:var14];
  [var5 addObject:var12];
  NSMutableArray *var15 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var16 = @0;
  [var15 addObject:var16];
  NSNumber *var17 = @-9.04369477050382e-06;
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
  NSNumber *var8 = @-5.729577951308232;
  [var6 addObject:var8];
  [var5 addObject:var6];
  NSMutableArray *var9 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var10 = @-4.966092947444857;
  [var9 addObject:var10];
  NSNumber *var11 = @2.861205754495701;
  [var9 addObject:var11];
  [var5 addObject:var9];
  NSMutableArray *var12 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var13 = @4.966092947444857;
  [var12 addObject:var13];
  NSNumber *var14 = @2.861205754495701;
  [var12 addObject:var14];
  [var5 addObject:var12];
  NSMutableArray *var15 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var16 = @0;
  [var15 addObject:var16];
  NSNumber *var17 = @-5.729577951308232;
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

- (void)test7 {
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
  NSNumber *var8 = @-9.04369477050382e-06;
  [var6 addObject:var8];
  [var5 addObject:var6];
  NSMutableArray *var9 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var10 = @-7.779638566553426e-06;
  [var9 addObject:var10];
  NSNumber *var11 = @4.5218473852518965e-06;
  [var9 addObject:var11];
  [var5 addObject:var9];
  NSMutableArray *var12 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var13 = @7.779638566553426e-06;
  [var12 addObject:var13];
  NSNumber *var14 = @4.5218473852518965e-06;
  [var12 addObject:var14];
  [var5 addObject:var12];
  NSMutableArray *var15 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var16 = @0;
  [var15 addObject:var16];
  NSNumber *var17 = @-9.04369477050382e-06;
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

- (void)test8 {
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
  NSNumber *var8 = @-9.04369477050382e-06;
  [var6 addObject:var8];
  [var5 addObject:var6];
  NSMutableArray *var9 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var10 = @-7.779638566553426e-06;
  [var9 addObject:var10];
  NSNumber *var11 = @4.5218473852518965e-06;
  [var9 addObject:var11];
  [var5 addObject:var9];
  NSMutableArray *var12 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var13 = @7.779638566553426e-06;
  [var12 addObject:var13];
  NSNumber *var14 = @4.5218473852518965e-06;
  [var12 addObject:var14];
  [var5 addObject:var12];
  NSMutableArray *var15 = [NSMutableArray arrayWithCapacity:2];
  NSNumber *var16 = @0;
  [var15 addObject:var16];
  NSNumber *var17 = @-9.04369477050382e-06;
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

@end
