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

#import <Cocoa/Cocoa.h>

@interface ReQLCursor : NSObject

-(BOOL)isOpen;

-(nonnull ReQLCursor *)observeNext:(void (^ _Nonnull)(id  _Nonnull))cb;

-(nonnull ReQLCursor *)observeError:(void (^ _Nonnull)(NSError *  _Nonnull))cb;

-(nonnull ReQLCursor *)observeCompleted:(void (^ _Nonnull)())cb;

-(nonnull NSArray *)toArray;

-(void)close;

@end
