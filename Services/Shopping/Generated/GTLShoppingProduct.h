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
//  GTLShoppingProduct.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Search API for Shopping (shopping/v1)
// Description:
//   Lets you search over product data
// Documentation:
//   http://code.google.com/apis/shopping/search/v1/getting_started.html
// Classes:
//   GTLShoppingProduct (0 custom class methods, 8 custom properties)
//   GTLShoppingProductRecommendationsItem (0 custom class methods, 2 custom properties)
//   GTLShoppingProductRecommendationsItemRecommendationListItem (0 custom class methods, 1 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLShoppingModelCategory;
@class GTLShoppingModelDebug;
@class GTLShoppingModelProduct;
@class GTLShoppingProductRecommendationsItem;
@class GTLShoppingProductRecommendationsItemRecommendationListItem;

// ----------------------------------------------------------------------------
//
//   GTLShoppingProduct
//

@interface GTLShoppingProduct : GTLObject

// List of categories for product.
@property (retain) NSArray *categories;  // of GTLShoppingModelCategory

// Google internal.
@property (retain) GTLShoppingModelDebug *debug;

// Id of product.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (retain) NSString *identifier;

// The kind of item, always shopping#product.
@property (retain) NSString *kind;

// Product.
@property (retain) GTLShoppingModelProduct *product;

// Recommendations for product.
@property (retain) NSArray *recommendations;  // of GTLShoppingProductRecommendationsItem

// Unique identifier for this request.
@property (retain) NSString *requestId;

// Self link of product.
@property (retain) NSString *selfLink;

@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingProductRecommendationsItem
//

@interface GTLShoppingProductRecommendationsItem : GTLObject

// List of recommendations.
@property (retain) NSArray *recommendationList;  // of GTLShoppingProductRecommendationsItemRecommendationListItem

// Type of recommendation list (one of: all, purchaseToPurchase, visitToVisit,
// visitToPurchase).
@property (retain) NSString *type;

@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingProductRecommendationsItemRecommendationListItem
//

@interface GTLShoppingProductRecommendationsItemRecommendationListItem : GTLObject

// Recommended product.
@property (retain) GTLShoppingModelProduct *product;

@end
