//
//  AGVersionNumber.h
//  AraeliumUpdate
//
//  Created by Seth Willits on 12/8/16.
//  Copyright © 2016 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef NS_ENUM(NSUInteger, AGVersionNumberFormat) {
	
	//! 2.3.7fc4   ----   pure integer numbers are parse as <integer>.0.0
	AGVersionNumberFormatMajorMinorPatch,
	
	//! Purely string comparison
	AGVersionNumberFormatString,
};



//! Note that this are in order of comparison.
typedef NS_ENUM(NSUInteger, AGVersionNumberSuffix) {
	
	//! Any other string. Assumed to be the earliest development stage 
	AGVersionNumberSuffixUnknown,
	
	//! "d"
	AGVersionNumberSuffixDevelopment,
	
	//! "a"
	AGVersionNumberSuffixAlpha,
	
	//! "b"
	AGVersionNumberSuffixBeta,
	
	//! "fc" or "rc"
	AGVersionNumberSuffixFinalCandidate,
	
	//! A final release version.
	AGVersionNumberSuffixNone,
};



@interface AGVersionNumber : NSObject
{
	AGVersionNumberFormat _format;
	NSString * _stringValue;
	
	NSUInteger _majorVersion; 
	NSUInteger _minorVersion;
	NSUInteger _patchVersion;
	AGVersionNumberSuffix _suffix;
	NSString * _suffixString;
	NSUInteger _suffixVersion;
}



+ (instancetype)versionNumberWithString:(NSString *)string;


@property (readonly) AGVersionNumberFormat format;
@property (readonly) NSString * stringValue;


// For use when the format is AGVersionNumberFormatMajorMinorPatch
// Example: 2.3.7fc4   or    1776
@property (readonly) NSUInteger majorVersion;       // 2 
@property (readonly) NSUInteger minorVersion;       // 3
@property (readonly) NSUInteger patchVersion;       // 7
@property (readonly) NSString * suffixString;       // fc
@property (readonly) AGVersionNumberSuffix suffix;  // AGVersionNumberSuffixFinalCandidate
@property (readonly) NSUInteger suffixVersion;      // 4



- (NSComparisonResult)compare:(AGVersionNumber *)otherVersion;


@end
