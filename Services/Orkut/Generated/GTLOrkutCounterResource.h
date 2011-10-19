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
//  GTLOrkutCounterResource.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Orkut API (orkut/v2)
// Description:
//   Lets you manage activities, comments and badges in Orkut. More stuff coming
//   in time.
// Documentation:
//   http://code.google.com/apis/orkut/v2/reference.html
// Classes:
//   GTLOrkutCounterResource (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLOrkutLinkResource;

// ----------------------------------------------------------------------------
//
//   GTLOrkutCounterResource
//

@interface GTLOrkutCounterResource : GTLObject

// Link to the collection being counted.
@property (retain) GTLOrkutLinkResource *link;

// The name of the counted collection. Currently supported collections are: -
// scraps - The scraps of the user. - photos - The photos of the user. - videos
// - The videos of the user.
@property (retain) NSString *name;

// The number of resources on the counted collection.
@property (retain) NSNumber *total;  // intValue

@end
