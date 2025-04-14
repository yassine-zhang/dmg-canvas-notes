//
//  NSApplicationAdditions.h
//  Queries
//
//  Created by Seth Willits on 1/25/08.
//  Copyright 2008 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface NSApplication (AraeliumSupportPathAdditions)

+ (NSString *)applicationSupportDirectory:(NSSearchPathDomainMask)domain;
+ (NSString *)directoryInApplicationSupportDirectory:(NSString *)folderName domain:(NSSearchPathDomainMask)domain createDirectories:(BOOL)createDirectories;
+ (NSString *)pathInApplicationSupportDirectory:(NSString *)pathName domain:(NSSearchPathDomainMask)domain createDirectories:(BOOL)createDirectories;



+ (NSString *)ag_applicationSupportFolderName;
+ (NSString *)ag_applicationSupportDirectory:(NSSearchPathDomainMask)domain;
+ (NSString *)ag_pathInApplicationSupportDirectory:(NSString *)pathName domain:(NSSearchPathDomainMask)domain isDirectory:(BOOL)isDirectory createDirectories:(BOOL)createDirectories;


@end

