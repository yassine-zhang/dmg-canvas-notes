//
//  NSShadowAdditions.h
//  AraeliumAppKit
//
//  Created by Seth Willits on 5/21/09.
//  Copyright 2009 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface NSShadow (Additions)

+ (NSShadow *)shadowWithColor:(NSColor *)color blurRadius:(CGFloat)radius offset:(NSSize)offset;

@end
