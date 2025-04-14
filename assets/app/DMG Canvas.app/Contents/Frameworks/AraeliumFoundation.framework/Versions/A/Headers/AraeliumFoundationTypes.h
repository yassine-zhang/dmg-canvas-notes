//
//  AraeliumFoundationTypes.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 5/21/09.
//  Copyright 2009 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>

#if MAC_OS_X_VERSION_MAX_ALLOWED < MAC_OS_X_VERSION_10_5
	typedef int NSInteger;
	typedef unsigned int NSUInteger;
	typedef float CGFloat;
#endif


#define AGRandomUnit() ((double)arc4random() / (double)UINT32_MAX)
#define AGRandomBetweenDouble(A, B) (AGRandomUnit() * (B-A) + A)
#define AGRandomBetween(A, B) ((int)AGRandom(A, B))


// Includes location == NSMaxRange
NS_INLINE BOOL NSLocationInRangeInclusive(NSUInteger loc, NSRange range)
{
	return ((loc == range.location + range.length) ||
			(!(loc < range.location) && (loc - range.location) < range.length)) ? YES : NO;
}


