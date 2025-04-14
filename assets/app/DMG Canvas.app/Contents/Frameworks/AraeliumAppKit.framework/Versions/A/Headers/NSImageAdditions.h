//
//  NSImageAdditions.h
//  AraeliumAppKit
//
//  Created by Seth Willits on 2/26/12.
//  Copyright (c) 2012 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface NSImage (AraeliumAdditions)

+ (id)imageNamed:(NSString *)name inBundle:(NSBundle *)bundle;
+ (id)imageNamed:(NSString *)name inBundleForClass:(Class)aclass;

- (BOOL)hasRetinaRepresentation;

- (NSBitmapImageRep *)smallestBitmapRep;
- (NSBitmapImageRep *)largestBitmapRep;

- (NSImage *)imageWithSolidFillColor:(NSColor *)color;

@end
