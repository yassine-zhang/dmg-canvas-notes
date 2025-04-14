//
//  AGSimpleColoredView.h
//  Screenflick
//
//  Created by Seth Willits on 9/29/07.
//  Copyright 2007 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>


typedef enum {
    AGMinXEdge = 1 << 0,
    AGMinYEdge = 1 << 1,
    AGMaxXEdge = 1 << 2,
    AGMaxYEdge = 1 << 3
} AGRectEdge;


@interface AGSimpleColoredView : NSView {
	NSColor * mBackgroundColor;
	NSColor * mBorderColor;
	BOOL mDrawsBackground;
	BOOL mDrawsBorder;
	NSUInteger mBorderSides;
}

- (void)setBackgroundColor:(NSColor *)backgroundColor;
- (NSColor *)backgroundColor;
- (void)setBorderColor:(NSColor *)borderColor;
- (NSColor *)borderColor;
- (void)setDrawsBackground:(BOOL)drawsBackground;
- (BOOL)drawsBackground;
- (void)setDrawsBorder:(BOOL)drawsBorder;
- (BOOL)drawsBorder;

- (void)setBorderSides:(NSUInteger)sides; // use AGRectEdge
- (NSUInteger)borderSides;

@end
