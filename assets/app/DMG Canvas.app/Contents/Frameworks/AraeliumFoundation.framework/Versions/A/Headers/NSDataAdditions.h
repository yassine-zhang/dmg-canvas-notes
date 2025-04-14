//
//  NSDataAdditions.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 6/6/08.
//  Copyright 2008 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSData (HexAdditions)
+ (id)dataFromHexString:(NSString *)hexString;
- (NSString *)hexString;
@end


@interface NSData (HashingAdditions)
- (NSData *)sha1;
- (NSString *)sha1Hex;
@end


@interface NSData (SearchAdditions)
- (NSRange)rangeOfData:(NSData *)data range:(NSRange)searchRange;
- (NSRange)rangeOfBytes:(const void *)bytes length:(NSUInteger)length range:(NSRange)searchRange;

NSRange AGRangeOfBytesInBytes(const void * haystackBytes, const void * needleBytes, NSUInteger needleLength, NSRange searchRange);

@end


@interface NSMutableData (ReplaceAdditions)
- (void)insertData:(NSData *)data atIndex:(NSUInteger)index;
- (NSUInteger)replaceOccurrencesOfData:(NSData *)data withData:(NSData *)replacementData range:(NSRange)searchRange;
- (void)replaceBytesInRanges:(NSRange *)ranges numberOfRanges:(NSUInteger)numberOfRanges
				   withBytes:(const void *)replacementBytes length:(NSUInteger)replacementLength;

- (void)insertBytes:(const void *)bytes length:(NSUInteger)bytesLength atIndex:(NSUInteger)index;
- (NSUInteger)replaceOccurrencesOfBytes:(const void *)bytes length:(NSUInteger)bytesLength
	withBytes:(const void *)replacementBytes length:(NSUInteger)replacementLength range:(NSRange)searchRange;
@end


@interface NSArray (DataAdditions)
- (NSData *)componentsJoinedByData:(NSData *)data;
@end
