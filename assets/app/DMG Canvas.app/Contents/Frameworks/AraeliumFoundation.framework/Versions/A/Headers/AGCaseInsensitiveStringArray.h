//
//  AGCaseInsensitiveStringArray.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 6/22/23.
//  Copyright © 2023 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AGCaseInsensitiveStringArray : NSObject

- (instancetype)initWithStrings:(NSArray<NSString*> *)strings;

/// Case insensitive
- (BOOL)containsString:(NSString *)string;

/// Case insensitive
- (NSUInteger)indexOfString:(NSString *)string;

/// Use objectAtIndex.

@end



@interface NSArray (CaseInsensitiveHelpers)

/// Asserts if called on an array with an object that is not an NSString
- (AGCaseInsensitiveStringArray *)caseInsensitiveCopy NS_RETURNS_RETAINED;

/// Asserts if called on an array with an object that is not an NSString
- (BOOL)caseInsensitiveContainsString:(NSString *)string;

- (NSUInteger)indexOfCaseInsensitiveString:(NSString *)string;

@end

NS_ASSUME_NONNULL_END
