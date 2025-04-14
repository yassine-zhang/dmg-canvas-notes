//
//  OSXCrashReporterInfo.h
//  OSXCrashReporterInfo
//
//  Created by Seth Willits on 10/26/14.
//  Copyright (c) 2014 Araelium Group. All rights reserved.
//

#import <CoreFoundation/CoreFoundation.h>
#import <Foundation/Foundation.h>

void OSXCrashReporterInfoInitialize(void);
void __attribute__((overloadable)) OSXCrashReporterInfoSet(const char * _Nonnull string, size_t length);
void __attribute__((overloadable)) OSXCrashReporterInfoSet(const char * _Nonnull string);
void __attribute__((overloadable)) OSXCrashReporterInfoSet(NSString * _Nonnull string);
void __attribute__((overloadable)) OSXCrashReporterInfoSet(NSString * _Nonnull format, ...) NS_FORMAT_FUNCTION(1,2);
void OSXCrashReporterInfoClear(void);
