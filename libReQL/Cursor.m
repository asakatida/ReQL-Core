/*
Copyright 2015 Adam Grandquist

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

#import "Cursor.h"

#import "Query.h"

#import "./reql/core.h"

@implementation ReQLCursor

-(NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state objects:(__unsafe_unretained id [])buffer count:(NSUInteger)len {
  return 0;
}

-(void)stream:(ReQLCursor *)aStream handleEvent:(NSStreamEvent)eventCode {
}

-(BOOL)error:(NSError * __strong *)err {
  if (err != nil) {
    *err = nil;
  }
  return NO;
}

@end
