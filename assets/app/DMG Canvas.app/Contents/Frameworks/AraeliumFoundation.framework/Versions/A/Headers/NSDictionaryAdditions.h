//
//  NSDictionaryAdditions.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 1/2/07.
//  Copyright 2007 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface NSDictionary (Additions)
//- (BOOL)writeToURL:(NSURL *)aURL options:(NSUInteger)mask error:(NSError **)errorPtr;

- (BOOL)boolForKey:(id)key;
- (NSInteger)integerForKey:(id)key;
- (NSUInteger)unsignedIntegerForKey:(id)key;
- (double)doubleForKey:(id)key;
- (float)floatForKey:(id)key;
- (NSRect)rectForKey:(id)key;
- (NSPoint)pointForKey:(id)key;
- (NSSize)sizeForKey:(id)key;

- (NSDictionary *)ag_dictionaryBySettingObject:(id)object forKey:(id<NSCopying>)key;
- (NSDictionary *)ag_dictionaryByRemovingObjectForKey:(id<NSCopying>)key;

@end


@interface NSMutableDictionary (Additions)

// If object is nil, removes object for key from receiver if present
- (void)safeSetObject:(id)object forKey:(id)key;

- (void)setBool:(BOOL)value forKey:(id)key;
- (void)setInteger:(NSInteger)value forKey:(id)key;
- (void)setUnsignedInteger:(NSUInteger)value forKey:(id)key;
- (void)setDouble:(double)value forKey:(id)key;
- (void)setFloat:(float)value forKey:(id)key;
- (void)setRect:(NSRect)rect forKey:(id)key;
- (void)setPoint:(NSPoint)point forKey:(id)key;
- (void)setSize:(NSSize)size forKey:(id)key;
@end
