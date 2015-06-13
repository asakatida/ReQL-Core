// Copyright 2015 Adam Grandquist

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <libReQL.h>

@interface ObjcRegressionTestForIssue : XCTestCase

@end

@implementation ObjcRegressionTestForIssue


- (void)test0 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"reql_ast_obj";
  NSMutableDictionary *var2 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var3 = @"reql_ast_obj";
  NSString *var4 = @"TableListTL";
  [var2 setObject:var4 forKey:var3];
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test1 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"reql_ast_obj";
  NSMutableDictionary *var2 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var3 = @"reql_ast_obj";
  NSString *var4 = @"TableCreateTL";
  [var2 setObject:var4 forKey:var3];
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test2 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"reql_ast_obj";
  NSMutableDictionary *var2 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var3 = @"reql_ast_obj";
  NSString *var4 = @"TableDropTL";
  [var2 setObject:var4 forKey:var3];
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test3 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"reql_ast_obj";
  NSMutableDictionary *var2 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var3 = @"reql_ast_obj";
  NSString *var4 = @"TableList";
  [var2 setObject:var4 forKey:var3];
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test4 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"reql_ast_obj";
  NSMutableDictionary *var2 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var3 = @"reql_ast_obj";
  NSString *var4 = @"TableCreate";
  [var2 setObject:var4 forKey:var3];
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

- (void)test5 {
  ReQLConnection *connection = [ReQLConnection new];
  XCTAssert([connection isOpen]);
  NSMutableDictionary *var0 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var1 = @"reql_ast_obj";
  NSMutableDictionary *var2 = [NSMutableDictionary dictionaryWithCapacity:1];
  NSString *var3 = @"reql_ast_obj";
  NSString *var4 = @"TableDrop";
  [var2 setObject:var4 forKey:var3];
  [var0 setObject:var2 forKey:var1];
  XCTAssert([var0 isEqualTo:var0]);
  [connection close];
}

@end
