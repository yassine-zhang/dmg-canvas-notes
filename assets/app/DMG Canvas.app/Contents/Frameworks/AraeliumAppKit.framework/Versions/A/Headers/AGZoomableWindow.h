//
//  AGZoomableWindow.h
//  Queries
//
//  Created by Seth Willits on 7/16/08.
//  Copyright 2008 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>


enum {
	AGBottomLeft = 0,
//	AGBottomCenter,
	AGCenter,
};


@class AGZoomableWindowView;
@interface AGZoomableWindow : NSWindow {
	
	NSRect agzw_StartFrame;
	NSRect agzw_TargetFrame;
	NSRect agzw_WindowFrame;
	
	NSImage *  agzw_WindowImage;
	CGImageRef agzw_CGWindowImageRef;
	
	AGZoomableWindowView * agzw_ImageView;
	NSView * agzw_OriginalContentView;
	
	
	NSTimeInterval agzw_zoomInDuration;
	NSTimeInterval agzw_zoomOutDuration;
	BOOL agzw_overshootsWhenZoomingIn;
	BOOL agzw_isZooming;
	int agzw_zoomsFrom;
}

@property (readwrite) NSTimeInterval zoomInDuration;
@property (readwrite) NSTimeInterval zoomOutDuration;
@property (readwrite) BOOL overshootsWhenZoomingIn;
@property (readwrite) int zoomsFrom;

- (void)zoomInFrom:(NSPoint)location to:(NSRect)targetFrame;
- (void)zoomOutFrom:(NSRect)startFrame to:(NSPoint)location;
- (BOOL)agzw_getWindowImage:(BOOL)offscreen;
- (void)agzw_animateIn;
- (void)agzw_animateOut;

@end



@interface AGZoomableWindowView : NSView {
	NSImage * mImage;
}

- (void)setImage:(NSImage *)image;

@end

