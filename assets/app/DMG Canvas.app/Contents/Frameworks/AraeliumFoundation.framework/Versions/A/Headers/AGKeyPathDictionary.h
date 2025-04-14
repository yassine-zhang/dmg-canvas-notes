//
//  AGKeyPathDictionary.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 2/5/14.
//  Copyright (c) 2014 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>




@interface AGMutableKeyPathDictionary : NSObject
{
	Class _dictClass;
	id _rootDict;
}


- (void)setObject:(id)object forKeyPath:(NSArray *)keys;
- (void)setObject:(id)object forKeys:(id)firstKey, ... NS_REQUIRES_NIL_TERMINATION;

- (id)objectForKeyPath:(NSArray *)keys;
- (id)objectForKeys:(id)firstKey, ... NS_REQUIRES_NIL_TERMINATION;

- (void)removeObjectForKeyPath:(NSArray *)keys;
- (void)removeObjectForKeys:(id)firstKey, ... NS_REQUIRES_NIL_TERMINATION;

//! Top-level keys
- (NSArray *)allKeys;

@end







// Uses AGCaseInsensitiveStringDictionary instead of NSDictionary for case insensitivity of the keys
@interface AGMutableCaseInsensitiveKeyPathDictionary : AGMutableKeyPathDictionary

@end
