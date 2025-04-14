//
//  AGCaseInsensitiveStringDictionary.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 2/6/14.
//  Copyright (c) 2014 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>


//
//  Newer implementation
//  Created by Seth Willits on 10/29/17.
//



//! This custom dictionary uses strings as keys, with a case insensitive lookup. The keys
//! @"foo" and @"Foo" will both return the same value set using the key @"FOO".
//! This implementation retains the keys as-is, so it's as memory efficient as a normal dictionary.
//! The only performance hit is the case insensitive hashing and comparison, which are still done
//! efficiently, mostly so for ASCII strings.
//! Is also thread-safe.
@interface AGMutableCaseInsensitiveStringDictionary : NSObject <NSMutableCopying>
{
	CFMutableDictionaryRef _dict;
}


//! Uses full Unicode case insensitivity
- (instancetype)init;

//! Will case insensitively match based exclusively on A-Z, without any Unicode smartness.
- (instancetype)initForASCIIStrings;

- (void)setObject:(id)value forKey:(NSString *)key;
- (id)objectForKey:(NSString *)key;
- (void)removeObjectForKey:(NSString *)key;
- (void)removeAllObjects;

- (NSArray *)allValues;

//! Will return just the lowercase variants of all keys
- (NSArray *)allKeys;

@end

















//! This custom dictionary uses strings as keys, with a case insensitive lookup. The keys
//! @"foo" and @"Foo" will both return the same value set using the key @"FOO".
//! The performance of the lookup in this class is 6 times faster than using a normal dictionary
//! with key.lowercaseString. Insert of a non-existent key and removal are both about 3x slower.
//! The best use of this dictionary is one in mutation is infrequent, and lookups occur in great
//! numbers.
//! Is also thread-safe.
//
// This version by choice was not memory efficient for storage, but had very fast lookup.
// Deprecating it in favor of the newer implementation which has no memory cost and not-much-slower lookup.
//

/*
@interface AGMutableCaseInsensitiveStringDictionary : NSObject <NSMutableCopying>
{
	NSMutableDictionary * _dict;
	NSMutableDictionary * _lowerToVariants;
	NSMutableDictionary * _variantToLower;
}

- (void)setObject:(id)value forKey:(NSString *)key;
- (id)objectForKey:(NSString *)key;
- (void)removeObjectForKey:(NSString *)key;
- (void)removeAllObjects;

- (NSArray *)allValues;

//! Will return just the lowercase variants of all keys
- (NSArray *)allKeys;

@end
*/
