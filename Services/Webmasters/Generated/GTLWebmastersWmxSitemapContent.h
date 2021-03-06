/* Copyright (c) 2014 Google Inc.
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
//  GTLWebmastersWmxSitemapContent.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Webmaster Tools API (webmasters/v3)
// Description:
//   Lets you view Google Webmaster Tools data for your verified sites.
// Documentation:
//   https://developers.google.com/webmaster-tools/v3/welcome
// Classes:
//   GTLWebmastersWmxSitemapContent (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLWebmastersWmxSitemapContent
//

// Information about the various content types in the sitemap.

@interface GTLWebmastersWmxSitemapContent : GTLObject

// The number of URLs from the sitemap that were indexed (of the content type).
@property (retain) NSNumber *indexed;  // longLongValue

// The number of URLs in the sitemap (of the content type).
@property (retain) NSNumber *submitted;  // longLongValue

// The specific type of content in this sitemap (for example "web", "images").
@property (copy) NSString *type;

@end
