/* Copyright (c) 2011 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//
//  GTLQuery.h
//

#import "GTLObject.h"

@protocol GTLQueryProtocol <NSObject, NSCopying>
- (BOOL)isBatchQuery;
- (BOOL)shouldSkipAuthorization;
@end

@interface GTLQuery : NSObject <GTLQueryProtocol> {
 @private
  NSString *methodName_;
  NSMutableDictionary *parameters_;
  GTLObject *bodyObject_;
  NSMutableDictionary *childCache_;
  NSString *requestID_;
  NSDictionary *urlQueryParameters_;
  Class expectedObjectClass_;
  BOOL skipAuthorization_;
}

// The rpc method name.
@property (readonly) NSString *methodName;

// The JSON dictionary of all the parameters set on this query.
@property (retain) NSMutableDictionary *parameters;

// The object set to be uploaded with the query.
@property (retain) GTLObject *bodyObject;

// Each query must have a request ID string. The user may replace the
// default assigned request ID with a custom string, provided that if
// used in a batch query, all request IDs in the batch must be unique.
@property (copy) NSString *requestID;

// Any url query parameters to add to the query (useful for debugging with some
// services).
@property (copy) NSDictionary *urlQueryParameters;

// The GTLObject subclass expected for results (used if the result doesn't
// include a kind attribute).
@property (assign) Class expectedObjectClass;

// Clients may set this to YES to disallow authorization. Defaults to NO.
@property (assign) BOOL shouldSkipAuthorization;

// methodName is the RPC method name to use.
+ (id)queryWithMethodName:(NSString *)methodName;

// methodName is the RPC method name to use.
- (id)initWithMethodName:(NSString *)method;

// If you need to set a parameter that is not listed as a property for a
// query class, you can do so via this api.  If you need to clear it after
// setting, pass nil for obj.
- (void)setCustomParameter:(id)obj forKey:(NSString *)key;

// Auto-generated request IDs
+ (NSString *)nextRequestID;

// Methods for subclasses to override.
+ (NSDictionary *)parameterNameMap;
+ (NSDictionary *)defaultValueMap;
+ (NSDictionary *)arrayPropertyToClassMap;
@end
