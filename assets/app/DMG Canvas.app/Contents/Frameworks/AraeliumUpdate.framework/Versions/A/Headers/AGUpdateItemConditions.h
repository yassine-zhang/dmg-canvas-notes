//
//  AGUpdateItemConditions.h
//  AraeliumUpdate
//
//  Created by Seth Willits on 3/12/24.
//  Copyright © 2024 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSUInteger, AGUpdateConditionRegistration) {
	AGUpdateConditionRegistrationDefault = 0,
	AGUpdateConditionRegistrationRegistered = 1,
	AGUpdateConditionRegistrationUnregistered = 2,
};


typedef NS_ENUM(NSUInteger, AGUpdateConditionLaunch) {
	AGUpdateConditionLaunchDefault = 0,
	AGUpdateConditionLaunchFirstLaunch = 1,
	AGUpdateConditionLaunchNotFirstLaunch = 2,
};


BOOL AGUpdateConditionRegistrationSatisfied(AGUpdateConditionRegistration required, AGUpdateConditionRegistration current);
BOOL AGUpdateConditionLaunchSatisfied(AGUpdateConditionLaunch required, AGUpdateConditionLaunch current);



/// Not all conditions would apply to Updates,
/// nor might all conditions apply to Posts.
@interface AGUpdateItemConditions : NSObject

// ------ Automatically filtered by the AGUpdateFeed -------
@property (readonly, copy, nullable) NSString * minimumAppBuild;
@property (readonly, copy, nullable) NSString * maximumAppBuild;
@property (readonly, copy, nullable) NSString * minimumSystemVersion;
@property (readonly, copy, nullable) NSString * maximumSystemVersion;

// ------ Applications must scrutinize manually -------
@property (readonly) AGUpdateConditionRegistration registration;
@property (readonly) AGUpdateConditionLaunch launch;

@end

NS_ASSUME_NONNULL_END
