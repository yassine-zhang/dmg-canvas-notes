//
//  NSBitmapImageRepAdditions.h
//  Queries
//
//  Created by Seth Willits on 7/14/08.
//  Copyright 2008 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#if MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_5
@interface NSBitmapImageRep (ImageIOAdditions)

- (NSData *)representationOfType:(NSString *)type withOptions:(NSDictionary *)options;

@end
#endif
