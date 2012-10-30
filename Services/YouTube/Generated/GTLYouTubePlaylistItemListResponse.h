/* Copyright (c) 2012 Google Inc.
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
//  GTLYouTubePlaylistItemListResponse.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   YouTube API (youtube/v3)
// Description:
//   Programmatic access to YouTube features.
// Documentation:
//   https://developers.google.com/youtube
// Classes:
//   GTLYouTubePlaylistItemListResponse (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLYouTubePageInfo;
@class GTLYouTubePlaylistItem;

// ----------------------------------------------------------------------------
//
//   GTLYouTubePlaylistItemListResponse
//

// A paginated list of playlist items returned as the response to a
// youtube.playlistItems.list call.

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLYouTubePlaylistItemListResponse : GTLCollectionObject

// The eTag of the response.
@property (copy) NSString *ETag;

// List of playlist items matching the request criteria.
@property (retain) NSArray *items;  // of GTLYouTubePlaylistItem

// The type of this API response.
@property (copy) NSString *kind;

// Token to the next page.
@property (copy) NSString *nextPageToken;

// Paging information for the list result.
@property (retain) GTLYouTubePageInfo *pageInfo;

// Token to the previous page.
@property (copy) NSString *prevPageToken;

@end
