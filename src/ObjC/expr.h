/*
Copyright 2014-2015 Adam Grandquist

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
 */
/**
 * @author Adam Grandquist
 * @copyright Apache
 */

#ifndef REQL_EXPR_OBJC_H_
#define REQL_EXPR_OBJC_H_

#ifdef __cplusplus
extern "C" {
#endif

#import <Foundation/Foundation.h>

@interface libReQL_Connection : NSObject<NSCopying>

-(void)close;

@end

@interface libReQL_expr : NSObject<NSCopying>

+(instancetype)ReQLWithString:(NSString *)string;

@end

#ifdef __cplusplus
}
#endif

#endif  // REQL_EXPR_OBJC_H_
