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
//  GTLQueryBooks.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Books API (books/v1)
// Description:
//   Lets you search for books and manage your Google Books library.
// Documentation:
//   https://code.google.com/apis/books/docs/v1/getting_started.html
// Classes:
//   GTLQueryBooks (11 custom class methods, 15 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@interface GTLQueryBooks : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (retain) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (retain) NSString *country;
@property (retain) NSString *download;
@property (retain) NSString *filter;
@property (retain) NSString *langRestrict;
@property (assign) NSUInteger maxResults;
@property (retain) NSString *orderBy;
@property (retain) NSString *printType;
@property (retain) NSString *projection;
@property (retain) NSString *q;
@property (retain) NSString *shelf;
@property (retain) NSString *source;
@property (assign) NSUInteger startIndex;
@property (retain) NSString *userId;
@property (retain) NSString *volumeId;

#pragma mark -
#pragma mark "bookshelves" methods
// These create a GTLQueryBooks object.

// Method: books.bookshelves.get
// Retrieves a specific bookshelf for the specified user.
//  Required:
//   userId: Id of user for whom to retrieve bookshelves.
//   shelf: Id of bookshelf to retrieve.
//  Optional:
//   country: ISO-3166-1 code to override the IP-based location.
//   source: String to identify the originator of this request.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksBookshelf.
+ (id)queryForBookshelvesGetWithUserId:(NSString *)userId
                                 shelf:(NSString *)shelf;

// Method: books.bookshelves.list
// Retrieves a list of public bookshelves for the specified user.
//  Required:
//   userId: Id of user for whom to retrieve bookshelves.
//  Optional:
//   country: ISO-3166-1 code to override the IP-based location.
//   source: String to identify the originator of this request.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksBookshelves.
+ (id)queryForBookshelvesListWithUserId:(NSString *)userId;

#pragma mark -
#pragma mark "bookshelves.volumes" methods
// These create a GTLQueryBooks object.

// Method: books.bookshelves.volumes.list
// Retrieves volumes in a specific bookshelf for the specified user.
//  Required:
//   userId: Id of user for whom to retrieve bookshelf volumes.
//   shelf: Id of bookshelf to retrieve volumes.
//  Optional:
//   country: ISO-3166-1 code to override the IP-based location.
//   source: String to identify the originator of this request.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksVolumes.
+ (id)queryForBookshelvesVolumesListWithUserId:(NSString *)userId
                                         shelf:(NSString *)shelf;

#pragma mark -
#pragma mark "mylibrary.bookshelves" methods
// These create a GTLQueryBooks object.

// Method: books.mylibrary.bookshelves.addVolume
// Adds a volume to a bookshelf.
//  Required:
//   shelf: Id of bookshelf to which to add a volume.
//   volumeId: Id of volume to add.
//  Optional:
//   country: ISO-3166-1 code to override the IP-based location.
//   source: String to identify the originator of this request.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
+ (id)queryForMylibraryBookshelvesAddVolumeWithShelf:(NSString *)shelf
                                            volumeId:(NSString *)volumeId;

// Method: books.mylibrary.bookshelves.clearVolumes
// Clears all volumes from a bookshelf.
//  Required:
//   shelf: Id of bookshelf from which to remove a volume.
//  Optional:
//   country: ISO-3166-1 code to override the IP-based location.
//   source: String to identify the originator of this request.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
+ (id)queryForMylibraryBookshelvesClearVolumesWithShelf:(NSString *)shelf;

// Method: books.mylibrary.bookshelves.get
// Retrieves a specific bookshelf belonging to the authenticated user.
//  Required:
//   shelf: Id of bookshelf to retrieve.
//  Optional:
//   country: ISO-3166-1 code to override the IP-based location.
//   source: String to identify the originator of this request.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksBookshelf.
+ (id)queryForMylibraryBookshelvesGetWithShelf:(NSString *)shelf;

// Method: books.mylibrary.bookshelves.list
// Retrieves a list of bookshelves belonging to the authenticated user.
//  Optional:
//   country: ISO-3166-1 code to override the IP-based location.
//   source: String to identify the originator of this request.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksBookshelves.
+ (id)queryForMylibraryBookshelvesList;

// Method: books.mylibrary.bookshelves.removeVolume
// Removes a volume from a bookshelf.
//  Required:
//   shelf: Id of bookshelf from which to remove a volume.
//   volumeId: Id of volume to remove.
//  Optional:
//   country: ISO-3166-1 code to override the IP-based location.
//   source: String to identify the originator of this request.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
+ (id)queryForMylibraryBookshelvesRemoveVolumeWithShelf:(NSString *)shelf
                                               volumeId:(NSString *)volumeId;

#pragma mark -
#pragma mark "mylibrary.bookshelves.volumes" methods
// These create a GTLQueryBooks object.

// Method: books.mylibrary.bookshelves.volumes.list
// Gets volume information for volumes on a bookshelf.
//  Optional:
//   shelf: The bookshelf id or name retrieve volumes for.
//   country: ISO-3166-1 code to override the IP-based location.
//   maxResults: Maximum number of results to return
//   projection: Restrict information returned to a set of selected fields.
//     kGTLBooksProjectionFull: Includes all volume data.
//     kGTLBooksProjectionLite: Includes a subset of fields in volumeInfo and
//       accessInfo.
//   source: String to identify the originator of this request.
//   startIndex: Index of the first element to return (starts at 0)
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksVolumes.
+ (id)queryForMylibraryBookshelvesVolumesList;

#pragma mark -
#pragma mark "volumes" methods
// These create a GTLQueryBooks object.

// Method: books.volumes.get
// Gets volume information for a single volume.
//  Required:
//   volumeId: Id of volume to retrieve.
//  Optional:
//   country: ISO-3166-1 code to override the IP-based location.
//   projection: Restrict information returned to a set of selected fields.
//     kGTLBooksProjectionFull: Includes all volume data.
//     kGTLBooksProjectionLite: Includes a subset of fields in volumeInfo and
//       accessInfo.
//   source: String to identify the originator of this request.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksVolume.
+ (id)queryForVolumesGetWithVolumeId:(NSString *)volumeId;

// Method: books.volumes.list
// Performs a book search.
//  Required:
//   q: Full-text search query string.
//  Optional:
//   country: ISO-3166-1 code to override the IP-based location.
//   download: Restrict to volumes by download availability.
//     kGTLBooksDownloadEpub: All volumes with epub.
//   filter: Filter search results.
//     kGTLBooksFilterEbooks: All Google eBooks.
//     kGTLBooksFilterFreeEbooks: Google eBook with full volume text
//       viewability.
//     kGTLBooksFilterFull: Public can view entire volume text.
//     kGTLBooksFilterPaidEbooks: Google eBook with a price.
//     kGTLBooksFilterPartial: Public able to see parts of text.
//   langRestrict: Restrict results to books with this language code.
//   maxResults: Maximum number of results to return.
//   orderBy: Sort search results.
//     kGTLBooksOrderByNewest: Most recently published.
//     kGTLBooksOrderByRelevance: Relevance to search terms.
//   printType: Restrict to books or magazines.
//     kGTLBooksPrintTypeAll: All volume content types.
//     kGTLBooksPrintTypeBooks: Just books.
//     kGTLBooksPrintTypeMagazines: Just magazines.
//   projection: Restrict information returned to a set of selected fields.
//     kGTLBooksProjectionFull: Includes all volume data.
//     kGTLBooksProjectionLite: Includes a subset of fields in volumeInfo and
//       accessInfo.
//   source: String to identify the originator of this request.
//   startIndex: Index of the first result to return (starts at 0)
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksVolumes.
+ (id)queryForVolumesListWithQ:(NSString *)q;

@end
