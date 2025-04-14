//
//  AGUserDefaults.h
//  SuiteTest
//
//  Created by Seth Willits on 2/27/12.
//  Copyright (c) 2012 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>


extern NSString * NSUserDefaultsSuiteDidChangeNotification;



@interface AGUserDefaults : NSUserDefaults
{
	NSString * mAppIdentifier;
	NSMutableArray * mSuites;
	NSMutableDictionary * mRegisteredDefaultsBySuite;
}

+ (void)install;

@end



@interface NSUserDefaults (AraeliumSuiteAdditions)

- (void)registerDefaults:(NSDictionary *)registrationDictionary inSuite:(NSString *)suiteName;

- (void)setObject:(id)obj forKey:(id)defaultName inSuite:(NSString *)suiteName;
- (id)objectForKey:(NSString *)defaultName inSuite:(NSString *)suiteName;
- (void)removeObjectForKey:(NSString *)defaultName inSuite:(NSString *)suiteName;

- (void)setInteger:(NSInteger)value forKey:(NSString *)defaultName inSuite:(NSString *)suiteName;
- (NSInteger)integerForKey:(NSString *)defaultName inSuite:(NSString *)suiteName;

- (void)setFloat:(float)value forKey:(NSString *)defaultName inSuite:(NSString *)suiteName;
- (float)floatForKey:(NSString *)defaultName inSuite:(NSString *)suiteName;

- (void)setDouble:(double)value forKey:(NSString *)defaultName inSuite:(NSString *)suiteName;
- (double)doubleForKey:(NSString *)defaultName inSuite:(NSString *)suiteName;

- (void)setBool:(BOOL)value forKey:(NSString *)defaultName inSuite:(NSString *)suiteName;
- (BOOL)boolForKey:(NSString *)defaultName inSuite:(NSString *)suiteName;

@end
