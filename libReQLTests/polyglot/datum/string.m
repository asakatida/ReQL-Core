// Copyright 2015 Adam Grandquist

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <libReQL.h>

@interface ObjcTestsOfConverstionToAndFromTheRqlStringType : XCTestCase

@end

@implementation ObjcTestsOfConverstionToAndFromTheRqlStringType


- (void)test0 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSString *var0 = @"str";
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test1 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSString *var0 = @"str";
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test2 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSString *var0 = @"str";
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test3 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSString *var0 = @"\u3053\u3093\u306b\u3061\u306f";
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test4 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSString *var0 = @"STRING";
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test5 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSString *var0 = @"foo";
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test6 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSNumber *var0 = @-1.2;
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
  NSNumber *var0 = @10;
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
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test12 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test13 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSString *var1 = @"";
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test14 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test15 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test16 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:1];
  NSString *var1 = @"";
  [var0 addObject:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test17 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test18 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"bbbb";
  [var0 addObject:var2];
  NSString *var3 = @"cccc";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test19 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"bbbb";
  [var0 addObject:var2];
  NSString *var3 = @"cccc";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test20 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSString *var1 = @"aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"bbbb";
  [var0 addObject:var2];
  NSString *var3 = @"";
  [var0 addObject:var3];
  NSString *var4 = @"cccc";
  [var0 addObject:var4];
  NSString *var5 = @"";
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test21 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:16];
  NSString *var1 = @"a";
  [var0 addObject:var1];
  NSString *var2 = @"a";
  [var0 addObject:var2];
  NSString *var3 = @"a";
  [var0 addObject:var3];
  NSString *var4 = @"a";
  [var0 addObject:var4];
  NSString *var5 = @" ";
  [var0 addObject:var5];
  NSString *var6 = @"b";
  [var0 addObject:var6];
  NSString *var7 = @"b";
  [var0 addObject:var7];
  NSString *var8 = @"b";
  [var0 addObject:var8];
  NSString *var9 = @"b";
  [var0 addObject:var9];
  NSString *var10 = @" ";
  [var0 addObject:var10];
  NSString *var11 = @" ";
  [var0 addObject:var11];
  NSString *var12 = @"c";
  [var0 addObject:var12];
  NSString *var13 = @"c";
  [var0 addObject:var13];
  NSString *var14 = @"c";
  [var0 addObject:var14];
  NSString *var15 = @"c";
  [var0 addObject:var15];
  NSString *var16 = @" ";
  [var0 addObject:var16];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test22 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSString *var1 = @"aaaa ";
  [var0 addObject:var1];
  NSString *var2 = @"";
  [var0 addObject:var2];
  NSString *var3 = @"";
  [var0 addObject:var3];
  NSString *var4 = @"";
  [var0 addObject:var4];
  NSString *var5 = @"  cccc ";
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test23 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"aaaa ";
  [var0 addObject:var1];
  NSString *var2 = @"";
  [var0 addObject:var2];
  NSString *var3 = @"  cccc ";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test24 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSString *var1 = @"aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"cccc ";
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test25 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:6];
  NSString *var1 = @"aaaa ";
  [var0 addObject:var1];
  NSString *var2 = @"";
  [var0 addObject:var2];
  NSString *var3 = @"  cccc b d ";
  [var0 addObject:var3];
  NSString *var4 = @" e ";
  [var0 addObject:var4];
  NSString *var5 = @"";
  [var0 addObject:var5];
  NSString *var6 = @" f";
  [var0 addObject:var6];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test26 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSString *var1 = @"aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"cccc b d bb e bbbb f";
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test27 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"cccc b d bb e";
  [var0 addObject:var2];
  NSString *var3 = @"f";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test28 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"bbbb";
  [var0 addObject:var2];
  NSString *var3 = @"cccc";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test29 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSString *var1 = @"aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"bbbb";
  [var0 addObject:var2];
  NSString *var3 = @"";
  [var0 addObject:var3];
  NSString *var4 = @"cccc";
  [var0 addObject:var4];
  NSString *var5 = @"";
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test30 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:6];
  NSString *var1 = @"a";
  [var0 addObject:var1];
  NSString *var2 = @"a";
  [var0 addObject:var2];
  NSString *var3 = @"a";
  [var0 addObject:var3];
  NSString *var4 = @"a";
  [var0 addObject:var4];
  NSString *var5 = @" ";
  [var0 addObject:var5];
  NSString *var6 = @"bbbb  cccc ";
  [var0 addObject:var6];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test31 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSString *var1 = @"aaaa ";
  [var0 addObject:var1];
  NSString *var2 = @"";
  [var0 addObject:var2];
  NSString *var3 = @"";
  [var0 addObject:var3];
  NSString *var4 = @"";
  [var0 addObject:var4];
  NSString *var5 = @"  cccc ";
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test32 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"aaaa ";
  [var0 addObject:var1];
  NSString *var2 = @"";
  [var0 addObject:var2];
  NSString *var3 = @"  cccc ";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test33 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSString *var1 = @"aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"cccc ";
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test34 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:6];
  NSString *var1 = @"aaaa ";
  [var0 addObject:var1];
  NSString *var2 = @"";
  [var0 addObject:var2];
  NSString *var3 = @"  cccc b d ";
  [var0 addObject:var3];
  NSString *var4 = @" e ";
  [var0 addObject:var4];
  NSString *var5 = @"";
  [var0 addObject:var5];
  NSString *var6 = @" f";
  [var0 addObject:var6];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test35 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSString *var1 = @"aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"cccc b d bb e bbbb f";
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test36 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"cccc b d bb e";
  [var0 addObject:var2];
  NSString *var3 = @"f";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test37 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"bbbb";
  [var0 addObject:var2];
  NSString *var3 = @"cccc ";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test38 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSString *var1 = @"a";
  [var0 addObject:var1];
  NSString *var2 = @"b";
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test39 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSString *var1 = @"aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"bbbb";
  [var0 addObject:var2];
  NSString *var3 = @"";
  [var0 addObject:var3];
  NSString *var4 = @"cccc";
  [var0 addObject:var4];
  NSString *var5 = @"";
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test40 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSString *var1 = @"a";
  [var0 addObject:var1];
  NSString *var2 = @"a";
  [var0 addObject:var2];
  NSString *var3 = @"a";
  [var0 addObject:var3];
  NSString *var4 = @"a";
  [var0 addObject:var4];
  NSString *var5 = @" bbbb  cccc ";
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test41 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSString *var1 = @"aaaa ";
  [var0 addObject:var1];
  NSString *var2 = @"";
  [var0 addObject:var2];
  NSString *var3 = @"";
  [var0 addObject:var3];
  NSString *var4 = @"";
  [var0 addObject:var4];
  NSString *var5 = @"  cccc ";
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test42 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"aaaa ";
  [var0 addObject:var1];
  NSString *var2 = @"";
  [var0 addObject:var2];
  NSString *var3 = @"  cccc ";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test43 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSString *var1 = @"aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"cccc ";
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test44 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:6];
  NSString *var1 = @"aaaa ";
  [var0 addObject:var1];
  NSString *var2 = @"";
  [var0 addObject:var2];
  NSString *var3 = @"  cccc b d ";
  [var0 addObject:var3];
  NSString *var4 = @" e ";
  [var0 addObject:var4];
  NSString *var5 = @"";
  [var0 addObject:var5];
  NSString *var6 = @" f";
  [var0 addObject:var6];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test45 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSString *var1 = @"aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"cccc b d bb e bbbb f";
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test46 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"cccc b d bb e";
  [var0 addObject:var2];
  NSString *var3 = @"f";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test47 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSString *var1 = @"aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"bbbb  cccc ";
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test48 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"bbbb";
  [var0 addObject:var2];
  NSString *var3 = @" cccc ";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test49 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"a";
  [var0 addObject:var1];
  NSString *var2 = @"a";
  [var0 addObject:var2];
  NSString *var3 = @"aa bbbb  cccc ";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test50 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"aaaa ";
  [var0 addObject:var1];
  NSString *var2 = @"";
  [var0 addObject:var2];
  NSString *var3 = @"bb  cccc ";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test51 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"aaaa ";
  [var0 addObject:var1];
  NSString *var2 = @"";
  [var0 addObject:var2];
  NSString *var3 = @"  cccc ";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test52 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSString *var1 = @"aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"cccc ";
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test53 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"aaaa ";
  [var0 addObject:var1];
  NSString *var2 = @"";
  [var0 addObject:var2];
  NSString *var3 = @"  cccc b d bb e bbbb f";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test54 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSString *var1 = @"aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"cccc b d bb e bbbb f";
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test55 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"cccc b d bb e";
  [var0 addObject:var2];
  NSString *var3 = @"f";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test56 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test57 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSArray *var0 = [NSArray array];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test58 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"";
  [var0 addObject:var1];
  NSString *var2 = @"";
  [var0 addObject:var2];
  NSString *var3 = @"";
  [var0 addObject:var3];
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
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"";
  [var0 addObject:var1];
  NSString *var2 = @"";
  [var0 addObject:var2];
  NSString *var3 = @"";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test61 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"bbbb";
  [var0 addObject:var2];
  NSString *var3 = @"cccc";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test62 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"bbbb";
  [var0 addObject:var2];
  NSString *var3 = @"cccc";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test63 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:7];
  NSString *var1 = @"";
  [var0 addObject:var1];
  NSString *var2 = @"";
  [var0 addObject:var2];
  NSString *var3 = @"aaaa";
  [var0 addObject:var3];
  NSString *var4 = @"bbbb";
  [var0 addObject:var4];
  NSString *var5 = @"";
  [var0 addObject:var5];
  NSString *var6 = @"cccc";
  [var0 addObject:var6];
  NSString *var7 = @"";
  [var0 addObject:var7];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test64 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSString *var1 = @"  aaaa ";
  [var0 addObject:var1];
  NSString *var2 = @"";
  [var0 addObject:var2];
  NSString *var3 = @"";
  [var0 addObject:var3];
  NSString *var4 = @"";
  [var0 addObject:var4];
  NSString *var5 = @"  cccc ";
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test65 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"  aaaa ";
  [var0 addObject:var1];
  NSString *var2 = @"";
  [var0 addObject:var2];
  NSString *var3 = @"  cccc ";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test66 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSString *var1 = @"  aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"cccc ";
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test67 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:6];
  NSString *var1 = @"  aaaa ";
  [var0 addObject:var1];
  NSString *var2 = @"";
  [var0 addObject:var2];
  NSString *var3 = @"  cccc b d ";
  [var0 addObject:var3];
  NSString *var4 = @" e ";
  [var0 addObject:var4];
  NSString *var5 = @"";
  [var0 addObject:var5];
  NSString *var6 = @" f";
  [var0 addObject:var6];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test68 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSString *var1 = @"  aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"cccc b d bb e bbbb f";
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test69 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"  aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"cccc b d bb e";
  [var0 addObject:var2];
  NSString *var3 = @"f";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test70 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"bbbb";
  [var0 addObject:var2];
  NSString *var3 = @"cccc";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test71 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:6];
  NSString *var1 = @"";
  [var0 addObject:var1];
  NSString *var2 = @"";
  [var0 addObject:var2];
  NSString *var3 = @"aaaa";
  [var0 addObject:var3];
  NSString *var4 = @"bbbb";
  [var0 addObject:var4];
  NSString *var5 = @"";
  [var0 addObject:var5];
  NSString *var6 = @"cccc ";
  [var0 addObject:var6];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test72 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSString *var1 = @"  aaaa ";
  [var0 addObject:var1];
  NSString *var2 = @"";
  [var0 addObject:var2];
  NSString *var3 = @"";
  [var0 addObject:var3];
  NSString *var4 = @"";
  [var0 addObject:var4];
  NSString *var5 = @"  cccc ";
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test73 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"  aaaa ";
  [var0 addObject:var1];
  NSString *var2 = @"";
  [var0 addObject:var2];
  NSString *var3 = @"  cccc ";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test74 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSString *var1 = @"  aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"cccc ";
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test75 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:6];
  NSString *var1 = @"  aaaa ";
  [var0 addObject:var1];
  NSString *var2 = @"";
  [var0 addObject:var2];
  NSString *var3 = @"  cccc b d ";
  [var0 addObject:var3];
  NSString *var4 = @" e ";
  [var0 addObject:var4];
  NSString *var5 = @"";
  [var0 addObject:var5];
  NSString *var6 = @" f";
  [var0 addObject:var6];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test76 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSString *var1 = @"  aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"cccc b d bb e bbbb f";
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test77 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"  aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"cccc b d bb e";
  [var0 addObject:var2];
  NSString *var3 = @"f";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test78 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"bbbb";
  [var0 addObject:var2];
  NSString *var3 = @"cccc ";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test79 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSString *var1 = @"a";
  [var0 addObject:var1];
  NSString *var2 = @"b";
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test80 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSString *var1 = @"";
  [var0 addObject:var1];
  NSString *var2 = @"";
  [var0 addObject:var2];
  NSString *var3 = @"aaaa";
  [var0 addObject:var3];
  NSString *var4 = @"bbbb";
  [var0 addObject:var4];
  NSString *var5 = @" cccc ";
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test81 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:5];
  NSString *var1 = @"  aaaa ";
  [var0 addObject:var1];
  NSString *var2 = @"";
  [var0 addObject:var2];
  NSString *var3 = @"";
  [var0 addObject:var3];
  NSString *var4 = @"";
  [var0 addObject:var4];
  NSString *var5 = @"  cccc ";
  [var0 addObject:var5];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test82 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"  aaaa ";
  [var0 addObject:var1];
  NSString *var2 = @"";
  [var0 addObject:var2];
  NSString *var3 = @"  cccc ";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test83 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSString *var1 = @"  aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"cccc ";
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test84 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:6];
  NSString *var1 = @"  aaaa ";
  [var0 addObject:var1];
  NSString *var2 = @"";
  [var0 addObject:var2];
  NSString *var3 = @"  cccc b d ";
  [var0 addObject:var3];
  NSString *var4 = @" e ";
  [var0 addObject:var4];
  NSString *var5 = @"";
  [var0 addObject:var5];
  NSString *var6 = @" f";
  [var0 addObject:var6];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test85 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSString *var1 = @"  aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"cccc b d bb e bbbb f";
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test86 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"  aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"cccc b d bb e";
  [var0 addObject:var2];
  NSString *var3 = @"f";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test87 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSString *var1 = @"aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"bbbb  cccc ";
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test88 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"";
  [var0 addObject:var1];
  NSString *var2 = @"";
  [var0 addObject:var2];
  NSString *var3 = @"aaaa bbbb  cccc ";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test89 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"  aaaa ";
  [var0 addObject:var1];
  NSString *var2 = @"";
  [var0 addObject:var2];
  NSString *var3 = @"bb  cccc ";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test90 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"  aaaa ";
  [var0 addObject:var1];
  NSString *var2 = @"";
  [var0 addObject:var2];
  NSString *var3 = @"  cccc ";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test91 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSString *var1 = @"  aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"cccc ";
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test92 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"  aaaa ";
  [var0 addObject:var1];
  NSString *var2 = @"";
  [var0 addObject:var2];
  NSString *var3 = @"  cccc b d bb e bbbb f";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test93 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:2];
  NSString *var1 = @"  aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"cccc b d bb e bbbb f";
  [var0 addObject:var2];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test94 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:3];
  NSString *var1 = @"  aaaa";
  [var0 addObject:var1];
  NSString *var2 = @"cccc b d bb e";
  [var0 addObject:var2];
  NSString *var3 = @"f";
  [var0 addObject:var3];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test95 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSString *var0 = @"ABC-DEF-GHJ";
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test96 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSString *var0 = @"abc-def-ghj";
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test97 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSString *var1 = @"f";
  [var0 addObject:var1];
  NSString *var2 = @"\xe9";
  [var0 addObject:var2];
  NSString *var3 = @"o";
  [var0 addObject:var3];
  NSString *var4 = @"o";
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test98 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:4];
  NSString *var1 = @"f";
  [var0 addObject:var1];
  NSString *var2 = @"e\u0301";
  [var0 addObject:var2];
  NSString *var3 = @"o";
  [var0 addObject:var3];
  NSString *var4 = @"o";
  [var0 addObject:var4];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test99 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:7];
  NSString *var1 = @"foo";
  [var0 addObject:var1];
  NSString *var2 = @"bar";
  [var0 addObject:var2];
  NSString *var3 = @"baz";
  [var0 addObject:var3];
  NSString *var4 = @"quux";
  [var0 addObject:var4];
  NSString *var5 = @"fred";
  [var0 addObject:var5];
  NSString *var6 = @"barney";
  [var0 addObject:var6];
  NSString *var7 = @"wilma";
  [var0 addObject:var7];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test100 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableArray *var0 = [NSMutableArray arrayWithCapacity:7];
  NSString *var1 = @"foo";
  [var0 addObject:var1];
  NSString *var2 = @"bar";
  [var0 addObject:var2];
  NSString *var3 = @"baz\u2060quux";
  [var0 addObject:var3];
  NSString *var4 = @"fred";
  [var0 addObject:var4];
  NSString *var5 = @"barney";
  [var0 addObject:var5];
  NSString *var6 = @"wilma";
  [var0 addObject:var6];
  NSString *var7 = @"betty\u200b";
  [var0 addObject:var7];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

@end
