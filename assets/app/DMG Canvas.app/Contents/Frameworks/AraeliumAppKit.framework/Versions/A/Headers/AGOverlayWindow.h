//
//  AGOverlayWindow.h
//  
//
//  Created by Seth Willits on 4/21/06.
//  Copyright 2006 Araelium Group. All rights reserved.
//


#import <Cocoa/Cocoa.h>

@interface AGOverlayWindow : NSWindow
{
	BOOL _canBecomeKeyWindow;
	BOOL _canBecomeMainWindow;
}

+ (id)overlayWindowWithContentRect:(NSRect)contentRect;

- (void)setCanBecomeKeyWindow:(BOOL)can;
- (void)setCanBecomeMainWindow:(BOOL)can;

@end
