//
//  CGAdditions.h
//  AraeliumAppKit
//
//  Created by Seth Willits on 10/29/10.
//  Copyright 2010 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>


#define CGColorGenericRGB(r,g,b,a)	(CGColorRef)[(id)CGColorCreateGenericRGB(r,g,b,a) autorelease]


CGImageRef CGImageCreateFromContentsOfFile(NSString * filePath);
CGImageRef CGImageFromNSImage(NSImage * image);
