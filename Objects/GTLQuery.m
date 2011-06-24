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
//  GTLQuery.m
//

#include <objc/runtime.h>

#import "GTLQuery.h"
#import "GTLRuntimeCommon.h"
#import "GTLUtilities.h"

@interface GTLQuery () <GTLRuntimeCommon>
- (NSString *)defaultValueForName:(NSString *)name;
+ (NSDictionary *)defaultValueMapForClass:(Class)aClass;
@end


@implementation GTLQuery

// Implementation Note: bodyObject could be done as a dynamic property and map
// it to the key "resource".  But we expose the object on the ServiceTicket
// for developers, and so sending it through the plumbing already in the
// parameters and outside of that gets into a grey area.  For requests sent
// via this class, we don't need to touch the JSON, but for developers that
// have to use the lower level apis for something we'd need to know to add
// it to the JSON.

@synthesize methodName = methodName_,
  parameters = parameters_,
  bodyObject = bodyObject_,
  requestID = requestID_,
  urlQueryParameters = urlQueryParameters_,
  expectedObjectClass = expectedObjectClass_,
  shouldSkipAuthorization = skipAuthorization_;

+ (id)queryWithMethodName:(NSString *)methodName {
  return [[[self alloc] initWithMethodName:methodName] autorelease];
}

- (id)initWithMethodName:(NSString *)methodName {
  self = [super init];
  if (self) {
    requestID_ = [[[self class] nextRequestID] retain];

    methodName_ = [methodName copy];
    if ([methodName_ length] == 0) {
      [self release];
      self = nil;
    }
  }
  return self;
}

- (void)dealloc {
  [methodName_ release];
  [childCache_ release];
  self.parameters = nil;
  self.bodyObject = nil;
  self.requestID = nil;
  self.urlQueryParameters = nil;
  self.expectedObjectClass = nil;
  [super dealloc];
}


- (id)copyWithZone:(NSZone *)zone {
  GTLQuery *query =
    [[[self class] allocWithZone:zone] initWithMethodName:self.methodName];

  if ([parameters_ count] > 0) {
    // Deep copy the parameters
    CFPropertyListRef ref = CFPropertyListCreateDeepCopy(kCFAllocatorDefault,
                                                         parameters_, kCFPropertyListMutableContainers);
    [NSMakeCollectable(ref) autorelease];
    query.parameters = (NSMutableDictionary*)ref;
  }
  query.bodyObject = self.bodyObject;
  query.requestID = self.requestID;
  query.urlQueryParameters = self.urlQueryParameters;
  query.expectedObjectClass = self.expectedObjectClass;
  query.shouldSkipAuthorization = self.shouldSkipAuthorization;
  return query;
}

- (NSString *)description {
  NSArray *keys = [self.parameters allKeys];
  NSArray *params = [keys sortedArrayUsingSelector:@selector(compare:)];
  NSString *paramsSummary = @"";
  if ([params count] > 0) {
    paramsSummary = [NSString stringWithFormat:@" params:(%@)",
                     [params componentsJoinedByString:@","]];
  }

  keys = [self.urlQueryParameters allKeys];
  NSArray *urlQParams = [keys sortedArrayUsingSelector:@selector(compare:)];
  NSString *urlQParamsSummary = @"";
  if ([urlQParams count] > 0) {
    urlQParamsSummary = [NSString stringWithFormat:@" urlQParams:(%@)",
                        [urlQParams componentsJoinedByString:@","]];
  }
  
  GTLObject *bodyObj = self.bodyObject;
  NSString *bodyObjSummary = @"";
  if (bodyObj != nil) {
    bodyObjSummary = [NSString stringWithFormat:@" bodyObject:%@", [bodyObj class]];
  }

  return [NSString stringWithFormat:@"%@ %p: {method:%@%@%@%@}",
          [self class], self, self.methodName,
          paramsSummary, urlQParamsSummary, bodyObjSummary];
}

- (void)setCustomParameter:(id)obj forKey:(NSString *)key {
  [self setJSONValue:obj forKey:key];
}

- (BOOL)isBatchQuery {
  return NO;
}

+ (NSString *)nextRequestID {
  static unsigned long lastRequestID = 0;
  NSString *result;

  @synchronized([GTLQuery class]) {
    ++lastRequestID;
    result = [NSString stringWithFormat:@"gtl_%lu",
              (unsigned long) lastRequestID];
  }
  return result;
}

#pragma mark GTLRuntimeCommon Support

- (void)setJSONValue:(id)obj forKey:(NSString *)key {
  NSString *defaultValue = [self defaultValueForName:key];
  if (defaultValue != nil && [obj isEqual:defaultValue]) {
    // It's the default, clear it from the parameters.
    obj = nil;
  }

  NSMutableDictionary *dict = self.parameters;
  if (dict == nil && obj != nil) {
    dict = [NSMutableDictionary dictionaryWithCapacity:1];
    self.parameters = dict;
  }
  [dict setValue:obj forKey:key];
}

- (id)JSONValueForKey:(NSString *)key {
  id obj = [self.parameters objectForKey:key];
  if (obj == nil) {
    obj = [self defaultValueForName:key];
  }
  return obj;
}

// There is no property for childCache_ as there shouldn't be KVC/KVO
// support for it, it's an implementation detail.

- (void)setCacheChild:(id)obj forKey:(NSString *)key {
  if (childCache_ == nil && obj != nil) {
    childCache_ =
      [[NSMutableDictionary alloc] initWithObjectsAndKeys:obj, key, nil];
  } else {
    [childCache_ setValue:obj forKey:key];
  }
}

- (id)cacheChildForKey:(NSString *)key {
  id obj = [childCache_ objectForKey:key];
  return obj;
}

#pragma mark Methods for Subclasses to Override

+ (NSDictionary *)parameterNameMap {
  return nil;
}

+ (NSDictionary *)defaultValueMap {
  return nil;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  return nil;
}

#pragma mark Runtime Utilities

static NSMutableDictionary *gParameterNameMapCache = nil;
static NSMutableDictionary *gDefaultValueMapCache = nil;
static NSMutableDictionary *gArrayPropertyToClassMapCache = nil;

+ (void)initialize {
  // note that initialize is guaranteed by the runtime to be called in a
  // thread-safe manner
  if (gParameterNameMapCache == nil) {
    gParameterNameMapCache = [GTLUtilities createStaticDictionary];
  }
  if (gDefaultValueMapCache == nil) {
    gDefaultValueMapCache = [GTLUtilities createStaticDictionary];
  }
  if (gArrayPropertyToClassMapCache == nil) {
    gArrayPropertyToClassMapCache = [GTLUtilities createStaticDictionary];
  }
}

- (NSString *)defaultValueForName:(NSString *)name {
  NSString *result = nil;

  // This makes use of the fact that we know we don't make a tree of query
  // classes.  If we did, then the dictionary tree would need to be merged in
  // these sub dictionaries; right now, they replace.

  NSDictionary *defaultValueMap =
    [GTLQuery defaultValueMapForClass:[self class]];

  NSDictionary *dict = [defaultValueMap objectForKey:self.methodName];
  result = [dict objectForKey:name];

  if (result == nil) {
    // The defaults for all methods is stored under the key "***".
    dict = [defaultValueMap objectForKey:@"***"];
    result = [dict objectForKey:name];
  }
  
  // NSNull is used to mark when some method have a default and some don't, so
  // map it back to no default here.
  if (result) {
    if ([result isEqual:[NSNull null]]) {
      result = nil;
    }
  }

  return result;
}

+ (NSDictionary *)propertyToJSONKeyMapForClass:(Class<GTLRuntimeCommon>)aClass {
  NSDictionary *resultMap =
  [GTLUtilities mergedClassDictionaryForSelector:@selector(parameterNameMap)
                                      startClass:aClass
                                   ancestorClass:[GTLQuery class]
                                           cache:gParameterNameMapCache];
  return resultMap;
}

+ (NSDictionary *)defaultValueMapForClass:(Class)aClass {
  NSDictionary *resultMap =
    [GTLUtilities mergedClassDictionaryForSelector:@selector(defaultValueMap)
                                        startClass:aClass
                                     ancestorClass:[GTLQuery class]
                                             cache:gDefaultValueMapCache];
  return resultMap;
}

+ (NSDictionary *)arrayPropertyToClassMapForClass:(Class<GTLRuntimeCommon>)aClass {
  NSDictionary *resultMap =
    [GTLUtilities mergedClassDictionaryForSelector:@selector(arrayPropertyToClassMap)
                                        startClass:aClass
                                     ancestorClass:[GTLQuery class]
                                             cache:gArrayPropertyToClassMapCache];
  return resultMap;
}

#pragma mark Runtime Support

- (NSDictionary *)surrogates {
  // Stub method just needed for RumtimeCommon, query doesn't use surrogates.
  return nil;
}

+ (Class<GTLRuntimeCommon>)ancestorClass {
  return [GTLQuery class];
}

+ (BOOL)resolveInstanceMethod:(SEL)sel {
  BOOL resolved = [GTLRuntimeCommon resolveInstanceMethod:sel onClass:self];
  if (resolved)
    return YES;
  
  return [super resolveInstanceMethod:sel];
}

@end
