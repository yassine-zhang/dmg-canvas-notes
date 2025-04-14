//
//  NSColorAdditions.h
//  AraeliumAppKit4
//
//  Created by Seth Willits on 1/26/12.
//  Copyright (c) 2012 Araelium Group. All rights reserved.
//

#import <AppKit/AppKit.h>

@interface NSColor (Additions)

- (NSColor *)colorWithHueComponent:(CGFloat)value;
- (NSColor *)colorWithSaturationComponent:(CGFloat)value;
- (NSColor *)colorWithBrightnessComponent:(CGFloat)value;

@end
