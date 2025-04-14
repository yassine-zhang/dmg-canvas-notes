//
//  NSRegularExpressionAdditions.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 2/22/19.
//  Copyright © 2019 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define NSREGEX(__expr, __options) \
		({ \
NSError * error = nil; 			\
NSRegularExpression * expr = [NSRegularExpression regularExpressionWithPattern:(__expr) options:(__options) error:&error]; \
			if (!expr) AGLog(AGLogError, @"%@", error); \
			assert(expr); \
			expr; \
		})


@interface NSRegularExpression (AraeliumAdditions)

- (nullable NSTextCheckingResult *)firstMatchInString:(NSString *)string options:(NSMatchingOptions)options startingAt:(NSUInteger)location;

- (NSRange)rangeOfFirstMatchInString:(NSString *)string options:(NSMatchingOptions)options startingAt:(NSUInteger)location;

@end



@interface NSTextCheckingResult (AraeliumAdditions) 

- (NSString *)substringAtIndex:(NSUInteger)index in:(NSString *)string;

@end

NS_ASSUME_NONNULL_END
