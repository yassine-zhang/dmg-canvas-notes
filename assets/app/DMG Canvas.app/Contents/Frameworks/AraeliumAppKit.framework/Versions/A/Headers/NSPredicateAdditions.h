//
//  NSPredicateAdditions.h
//  AraeliumAppKit
//
//  Created by Seth Willits on 6/26/19.
//  Copyright © 2019 Araelium Group. All rights reserved.
//

#import <AppKit/AppKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSPredicate (AraeliumAdditions)

+ (instancetype)predicateForFuzzyMatchOfString:(NSString *)search caseInsensitive:(BOOL)caseInsensitive;

@end

@interface NSString (AGFuzzyMatching)

+ (BOOL)fuzzyMatchOfString:(NSString *)searchFor inString:(NSString *)fullText caseInsensitive:(BOOL)caseInsensitive;

@end

NS_ASSUME_NONNULL_END
