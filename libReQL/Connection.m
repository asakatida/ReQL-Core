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

#import "Connection.h"

#import "Query.h"

#import "./reql/core.h"

@implementation ReQLConnection {
  ReQL_Conn_t *p_conn;
}

-(instancetype)init {
  if (self = [super init]) {
    p_conn = malloc(sizeof(ReQL_Conn_t));
    if (p_conn == NULL) {
      [self release];
      return NULL;
    }
    reql_conn_init(p_conn);
    ReQL_Byte buf[500];
    if (reql_conn_connect(p_conn, buf, 500) != 0) {
      [self release];
      return NULL;
    }
  }
  return self;
}

-(BOOL)isOpen {
  return reql_conn_open(p_conn) == 0 ? NO : YES;
}

-(void)close {
  reql_conn_close(p_conn);
}

-(void)dealloc {
  reql_conn_destroy(p_conn);
  free(p_conn);
  [super dealloc];
}

@end
