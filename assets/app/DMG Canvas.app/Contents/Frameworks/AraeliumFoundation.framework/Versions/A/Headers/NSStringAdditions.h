//
//  NSStringAdditions.h
//  AraeliumFoundation
//
//  Created by iSeth on 11/25/04.
//  Copyright 2004 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>


#if MAC_OS_X_VERSION_MAX_ALLOWED < MAC_OS_X_VERSION_10_5
typedef NSUInteger NSStringCompareOptions;
#endif


typedef enum {
	AGLineEndingMacintosh	= 1,
	AGLineEndingUnix		= 0,
	AGLineEndingWindows		= 2
} AGLineEnding;


@interface NSString (WordLineCounter)

- (NSInteger)lineEnding; // **
- (NSUInteger)wordCount; // **
- (NSUInteger)lineCount; // **
- (NSUInteger)lineCountWithLineEnding:(AGLineEnding)lineEnding; // **
- (NSUInteger)indexOfLine:(NSUInteger)line;
- (NSUInteger)indexOfLine:(NSUInteger)line withLineEnding:(AGLineEnding)lineEnding; // **

- (NSUInteger)lineCountAtIndex:(NSUInteger)matchIndex;
- (NSUInteger)lineCountAtIndex:(NSUInteger)matchIndex withLineEnding:(AGLineEnding)lineEnding; // **

- (NSRange)lineAndCharacterPositionAtIndex:(NSUInteger)matchIndex withTabLength:(NSUInteger)tabLength;
- (NSRange)lineAndCharacterPositionAtIndex:(NSUInteger)matchIndex withLineEnding:(AGLineEnding)lineEnding; // **
- (NSRange)lineAndCharacterPositionAtIndex:(NSUInteger)matchIndex withTabLength:(NSUInteger)tabLength withLineEnding:(AGLineEnding)lineEnding;

@end


@interface NSString (Modifying)
- (NSString *)stringByPrefixingLinesWith:(NSString *)prefix;
- (NSString *)ag_stringByRemovingPrefix:(NSString *)prefix options:(NSStringCompareOptions)options;
- (NSString *)ag_stringByRemovingSuffix:(NSString *)suffix options:(NSStringCompareOptions)options;
@end


@interface NSString (Searching)
- (NSUInteger)numberOfOccurrencesOfString:(NSString *)string options:(NSUInteger)options;
- (NSArray *)occurrencesOfString:(NSString *)string options:(unsigned)options;
@end


@interface NSString (Replacement)
- (NSString *)stringBySqueezingOccurrencesOfString:(NSString *)target options:(NSStringCompareOptions)options;
- (NSString *)stringByReplacingOccurrencesOfString:(NSString *)target options:(NSStringCompareOptions)options range:(NSRange)searchRange withHandler:(NSString * (^)(NSString * occurrence, NSRange rangeOfString))replaceBlock;
@end


@interface NSString (CharacterStuff)
- (NSString *)ag_stringByDeletingCharactersInSet:(NSCharacterSet *)set;
- (NSString *)ag_stringByRemovingCharactersInSet:(NSCharacterSet *)set;
- (NSString *)stringByDeletingCharactersInSet:(NSCharacterSet *)set;
- (NSString *)stringByRemovingCharactersInString:(NSString *)chars;
- (NSString *)stringByNormalizingLineEndings:(NSInteger)lineEndings;
- (NSArray *)componentsSeparatedByCharactersInString:(NSString *)chars;
@end


@interface NSString (CompTrimming)
- (NSArray *)componentsSeparatedByString:(NSString *)separator trimmingCharactersInSet:(NSCharacterSet *)characterSet;
@end


@interface NSArray (TrimmingStrings)
- (NSArray *)stringsByTrimmingCharactersInSet:(NSCharacterSet *)characterSet;
@end



@interface NSMutableString (CharacterStuff)

- (void)deleteCharactersInSet:(NSCharacterSet *)set;

@end



@interface NSString (EscapingAdditions)

- (NSString *)stringByUnescapingString;

@end



@interface NSString (ExtraPathUtilities)

- (NSString *)stringByAppendingStringBeforePathExtension:(NSString *)string;
- (NSString *)stringByMakingRelativeToPath:(NSString *)rootPath;
- (NSString *)stringByMakingSubpathOfPath:(NSString *)rootPath;
- (NSString *)stringByAppendingPathSeparator;
- (NSString *)stringByDeletingLeadingPathSeparator;
- (NSString *)stringByDeletingTrailingPathSeparator;
- (NSString *)stringByTrimmingPathSeparators;
- (BOOL)isEqualToPath:(NSString *)otherPath;
- (BOOL)isAnAncestorOfPath:(NSString *)otherPath;

@end



@interface NSString (EncodingStuff)

//! Looks for a BOM and returns kCFStringEncodingInvalidId if it doesn't find one.
+ (CFStringEncoding)quicklyGuessStringEncodingForData:(NSData *)data;

//! Looks for a BOM. Failing that it tries to create a valid NSString and returns the successful encoding.
+ (CFStringEncoding)guessStringEncodingForData:(NSData *)data;

+ (NSString *)stringWithData:(NSData *)data encoding:(NSStringEncoding)encoding;
- (NSUInteger)lengthOfBOMForEncoding:(CFStringEncoding)textEncoding;
- (BOOL)BOMForEncoding:(CFStringEncoding)textEncoding buffer:(UInt8 *)buffer;
- (NSData *)dataUsingCFStringEncoding:(CFStringEncoding)textEncoding addBOM:(BOOL)bom;
- (NSString *)convertStringFromEncoding:(CFStringEncoding)fromEncoding toEncoding:(CFStringEncoding)toEncoding;
- (NSString *)reinterpretStringWithEncoding:(CFStringEncoding)encoding fromEncoding:(CFStringEncoding)fromEncoding;

@end




@interface NSString (SearchComparision)

- (BOOL)ag_caseInsensitiveContainsString:(NSString *)string;


- (NSString *)stringByDeletingSuffix:(NSString *)suffix;

- (BOOL)hasPrefix:(NSString *)string options:(NSStringCompareOptions)options;
- (BOOL)hasSuffix:(NSString *)string options:(NSStringCompareOptions)options;
- (BOOL)containsString:(NSString *)string options:(NSStringCompareOptions)options;

- (BOOL)hasCaseInsensitivePrefix:(NSString *)string;
- (BOOL)hasCaseInsensitiveSuffix:(NSString *)string;

// The first word is ONLY surrounded by whitespace. There are no restrictions
// on characters that can be in a word except "not whitespace".
// We're not trying to be fancy with punctuation etc or anything like that.
- (NSString *)firstWord;

@end



@interface NSString (Comparision)

- (BOOL)isCaseInsensitiveEqual:(NSString *)string;

@end



@interface NSString (Regex)
- (NSString *)ag_matchedStringForRegex:(NSString *)regexString groupAtIndex:(NSUInteger)index options:(NSRegularExpressionOptions)options;
- (NSString *)ag_stringByReplacingRegex:(NSString *)regexString groupAtIndex:(NSUInteger)index options:(NSRegularExpressionOptions)options withString:(NSString *)replacement;
- (NSString *)ag_stringByReplacingOccurrencesOfRegex:(NSString *)regexString groupAtIndex:(NSUInteger)index options:(NSRegularExpressionOptions)options withString:(NSString *)replacement;
@end





@interface NSString (HexAdditions)

- (NSData *)dataFromHexString;

@end


@interface NSString (Base32Additions)

+ (NSString *)stringFromBase32Data:(NSData *)data;
- (NSData *)base32Data;

@end



@interface NSString (HashingAdditions)
- (NSData *)utf8_sha1;
- (NSString *)utf8_sha1Hex;
@end




#if MAC_OS_X_VERSION_MAX_ALLOWED < MAC_OS_X_VERSION_10_5
@interface NSString (AppleAdditionsAddedInLeopard)
- (NSString *)stringByReplacingOccurrencesOfString:(NSString *)target withString:(NSString *)replacement;
@end
#endif



NSString * AGStringForOSType(OSType type);
NSString * NSStringUUID(void);


