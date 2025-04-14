//
//  AGUpdateHost.h
//  AraeliumUpdate
//
//  Created by Seth Willits on 8/17/12.
//  Copyright (c) 2012 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AGUpdateHost : NSObject
{
	NSBundle * _bundle;
	NSString * _systemVersionString;
	NSString * _name;
	NSString * _version;
	NSString * _displayVersion;
}

@property (readonly) NSString * systemVersionString;
@property (readonly) NSBundle * bundle;
@property (readonly) NSString * name;
@property (readonly) NSString * version;
@property (readonly) NSString * displayVersion;
@property (readonly) BOOL isRunningOnReadOnlyVolume;
@property (readonly) BOOL isRunningTranslocated; // always check isRunningOnReadOnlyVolume too
@property (readonly) BOOL isBackgroundApplication;

+ (AGUpdateHost *)host;
+ (AGUpdateHost *)currentHost;

@end
