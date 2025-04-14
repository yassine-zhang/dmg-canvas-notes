//
//  NSScreenAdditions.h
//  Screenflick
//
//  Created by Seth Willits on 4/3/09.
//  Copyright 2009 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface NSScreen (Additions)
+ (NSScreen *)screenWithMenubar; // the REAL main screen
+ (NSScreen *)screenWithPoint:(NSPoint)point;
+ (NSScreen *)screenWithDisplayID:(CGDirectDisplayID)displayID;
- (CGDirectDisplayID)displayID;
@end


@interface NSScreen (Geometry)
+ (NSPoint)convertPointFromCGDisplayToNSScreen:(CGPoint)cgPoint;
+ (CGPoint)convertPointFromNSScreenToCGDisplay:(NSPoint)nsPoint;
+ (NSRect)convertRectFromCGDisplayToNSScreen:(CGRect)cgRect;
+ (CGRect)convertRectFromNSScreenToCGDisplay:(NSRect)nsRect;

- (NSPoint)convertPointFromCGDisplayToNSScreen:(CGPoint)cgPoint;
- (CGPoint)convertPointFromNSScreenToCGDisplay:(NSPoint)nsPoint;
- (NSRect)convertRectFromCGDisplayToNSScreen:(CGRect)cgRect;
- (CGRect)convertRectFromNSScreenToCGDisplay:(NSRect)nsRect;
@end



@interface NSScreen (Screenshots)
- (NSImage *)screenshotExcludingPID:(pid_t)pid;
- (NSImage *)screenshot;
@end
