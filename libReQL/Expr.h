//
//  Expr.h
//  libReQL
//
//  Created by Adam Grandquist on 5/25/15.
//  Copyright (c) 2015 Adam Grandquist. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Expr : NSObject

-(instancetype)init;
-(instancetype)initWithArray:(NSArray *)val;
-(instancetype)initWithBool:(BOOL)val;
-(instancetype)initWithNumber:(NSNumber *)val;
-(instancetype)initWithObject:(NSDictionary *)val;
-(instancetype)initWithString:(NSString *)val;

@end
