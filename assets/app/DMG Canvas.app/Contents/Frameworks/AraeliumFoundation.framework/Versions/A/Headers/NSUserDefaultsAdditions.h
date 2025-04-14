//
//  NSUserDefaultsAdditions.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 2/26/12.
//  Copyright (c) 2012 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSUserDefaults (AraeliumPersistentDomainAdditions)

- (void)setObject:(id)obj forKey:(id)defaultName inPersistentDomain:(NSString *)domain;
- (id)objectForKey:(NSString *)defaultName inPersistentDomain:(NSString *)domain;
- (void)removeObjectForKey:(NSString *)defaultName inPersistentDomain:(NSString *)domain;

- (NSInteger)integerForKey:(NSString *)defaultName inPersistentDomain:(NSString *)domain;
- (float)floatForKey:(NSString *)defaultName inPersistentDomain:(NSString *)domain;
- (double)doubleForKey:(NSString *)defaultName inPersistentDomain:(NSString *)domain;
- (BOOL)boolForKey:(NSString *)defaultName inPersistentDomain:(NSString *)domain;

- (void)setInteger:(NSInteger)value forKey:(NSString *)defaultName inPersistentDomain:(NSString *)domain;
- (void)setFloat:(float)value forKey:(NSString *)defaultName inPersistentDomain:(NSString *)domain;
- (void)setDouble:(double)value forKey:(NSString *)defaultName inPersistentDomain:(NSString *)domain;
- (void)setBool:(BOOL)value forKey:(NSString *)defaultName inPersistentDomain:(NSString *)domain;


@end
