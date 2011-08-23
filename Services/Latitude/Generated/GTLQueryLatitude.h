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
//  GTLQueryLatitude.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Latitude API (latitude/v1)
// Description:
//   Lets you read and update your current location and work with your location
//   history
// Documentation:
//   http://code.google.com/apis/latitude/v1/using_rest.html
// Classes:
//   GTLQueryLatitude (7 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLLatitudeLocation;

@interface GTLQueryLatitude : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (retain) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (retain) NSString *granularity;
@property (retain) NSString *locationId;
@property (retain) NSString *maxResults;
@property (retain) NSString *maxTime;
@property (retain) NSString *minTime;

#pragma mark -
#pragma mark "currentLocation" methods
// These create a GTLQueryLatitude object.

// Method: latitude.currentLocation.delete
// Deletes the authenticated user's current location.
+ (id)queryForCurrentLocationDelete;

// Method: latitude.currentLocation.get
// Returns the authenticated user's current location.
//  Optional:
//   granularity: Granularity of the requested location.
// Fetches a GTLLatitudeLocation.
+ (id)queryForCurrentLocationGet;

// Method: latitude.currentLocation.insert
// Updates or creates the user's current location.
// Fetches a GTLLatitudeLocation.
+ (id)queryForCurrentLocationInsertWithObject:(GTLLatitudeLocation *)object;

#pragma mark -
#pragma mark "location" methods
// These create a GTLQueryLatitude object.

// Method: latitude.location.delete
// Deletes a location from the user's location history.
//  Required:
//   locationId: Timestamp of the location to delete (ms since epoch).
+ (id)queryForLocationDeleteWithLocationId:(NSString *)locationId;

// Method: latitude.location.get
// Reads a location from the user's location history.
//  Required:
//   locationId: Timestamp of the location to read (ms since epoch).
//  Optional:
//   granularity: Granularity of the location to return.
// Fetches a GTLLatitudeLocation.
+ (id)queryForLocationGetWithLocationId:(NSString *)locationId;

// Method: latitude.location.insert
// Inserts or updates a location in the user's location history.
// Fetches a GTLLatitudeLocation.
+ (id)queryForLocationInsertWithObject:(GTLLatitudeLocation *)object;

// Method: latitude.location.list
// Lists the user's location history.
//  Optional:
//   granularity: Granularity of the requested locations.
//   maxResults: Maximum number of locations to return.
//   maxTime: Maximum timestamp of locations to return (ms since epoch).
//   minTime: Minimum timestamp of locations to return (ms since epoch).
// Fetches a GTLLatitudeLocationFeed.
+ (id)queryForLocationList;

@end
