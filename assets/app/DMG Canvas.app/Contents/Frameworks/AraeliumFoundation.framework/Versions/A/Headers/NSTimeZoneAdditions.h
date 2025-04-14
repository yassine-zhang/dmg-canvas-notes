//
//  NSTimeZoneAdditions.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 1/26/09.
//  Copyright 2009 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>


#if MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_5
@interface NSTimeZone (Additions)

+ (NSTimeZone *)timeZoneWithAName:(NSString *)name inLocale:(NSLocale *)locale;

@end
#endif

