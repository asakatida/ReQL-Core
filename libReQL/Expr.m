//
//  Expr.m
//  libReQL
//
//  Created by Adam Grandquist on 5/25/15.
//  Copyright (c) 2015 Adam Grandquist. All rights reserved.
//

#import "Expr.h"

#import "./reql/core.h"

@implementation Expr {
  NSArray *array;
  NSDictionary *dict;
}

-(instancetype)init {
  if (self = [super init]) {
  }
  return self;
}

-(instancetype)initWithArray:(NSArray *)val {
  if (self = [super init]) {
  }
  return self;
}

-(instancetype)initWithBool:(BOOL)val {
  if (self = [super init]) {
  }
  return self;
}

-(instancetype)initWithNumber:(NSNumber *)val {
  if (self = [super init]) {
  }
  return self;
}

-(instancetype)initWithObject:(NSDictionary *)val {
  if (self = [super init]) {
  }
  return self;
}

-(instancetype)initWithString:(NSString *)val {
  if (self = [super init]) {
  }
  return self;
}

@end
