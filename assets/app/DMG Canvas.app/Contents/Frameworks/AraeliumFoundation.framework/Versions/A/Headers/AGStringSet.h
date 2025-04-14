//
//  AGStringSet.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 10/29/17.
//  Copyright © 2017 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef NS_OPTIONS(NSUInteger, AGStringSetOptions) {
	AGStringSetOptionCaseSensitive = 1,
	
	//! When not set, uses full Unicode case insensitivity. Otherwise, will case insensitively match based exclusively on A-Z, without any Unicode smartness.
	AGStringSetOptionAssumeASCII = 2
};



@interface AGStringSet : NSObject <NSCopying>

@property (readonly) BOOL isCaseSensitive;

- (BOOL)containsString:(NSString *)string;
- (NSArray *)allStrings;
- (NSUInteger)count;

@end




@interface AGMutableStringSet : AGStringSet <NSMutableCopying>
{
	BOOL _isCaseSensitive;
	CFMutableSetRef _set;
}

- (instancetype)initWithOptions:(AGStringSetOptions)options NS_DESIGNATED_INITIALIZER;

//! Case insensitive and unicode.
- (instancetype)init;

- (void)addStrings:(NSArray<NSString *> *)strings;
- (void)addString:(NSString *)string;
- (void)removeAllStrings;

@end
