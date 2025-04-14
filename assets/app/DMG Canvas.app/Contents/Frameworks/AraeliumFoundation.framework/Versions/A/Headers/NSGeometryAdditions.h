//
//  NSGeometryAdditions.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 5/21/09.
//  Copyright 2009 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>


#if MAC_OS_X_VERSION_10_4 >= MAC_OS_X_VERSION_MAX_ALLOWED

static inline NSRect NSRectFromCGRect(CGRect cgrect) {
	return (*(NSRect *)(void *)&(cgrect));
}

static inline CGRect NSRectToCGRect(NSRect nsrect) {
	return (*(CGRect *)(void *)&(nsrect));
}

static inline NSPoint NSPointFromCGPoint(CGPoint cgpoint) {
	return (*(NSPoint *)(void *)&(cgpoint));
}

static inline CGPoint NSPointToCGPoint(NSPoint nspoint) {
	return (*(CGPoint *)(void *)&(nspoint));
}

static inline NSSize NSSizeFromCGSize(CGSize cgsize) {
	return (*(NSSize *)(void *)&(cgsize));
}

static inline CGSize NSSizeToCGSize(NSSize nssize) {
	return (*(CGSize *)(void *)&(nssize));
}

static inline NSString * NSStringFromRectArray(NSArray * array)
{
	NSString * string = @"";
	NSEnumerator * enumerator = [array objectEnumerator];
	NSValue * rectValue = nil;
	
	while (rectValue = [enumerator nextObject]) {
		string = [string stringByAppendingString:NSStringFromRect([rectValue rectValue])];
		string = [string stringByAppendingString:@"\n"];
	}
	
	return string;
}

#endif


static inline NSPoint NSRectCenter(NSRect rect)
{
	return NSMakePoint(NSMidX(rect), NSMidY(rect));
}



static inline NSRect NSRectScale(NSRect rect, CGFloat scale)
{
	return NSMakeRect(rect.origin.x * scale, rect.origin.y * scale, rect.size.width * scale, rect.size.height * scale);
}


static inline NSSize NSSizeScale(NSSize size, CGFloat scale)
{
	return NSMakeSize(size.width * scale, size.height * scale);
}


//! outFrom must be in the rect, and is used as the center of scaling
static inline NSRect NSRectScaleAboutPoint(NSRect rect, CGFloat scale, NSPoint outFrom)
{
	assert(NSPointInRect(outFrom, rect));
	
	CGFloat ax = (outFrom.x - NSMinX(rect)) / rect.size.width;
	CGFloat ay = (outFrom.y - NSMinY(rect)) / rect.size.height;
	
	NSRect r = NSMakeRect(0, 0, rect.size.width * scale, rect.size.height * scale);
	
	r.origin.x = outFrom.x - ax * r.size.width;
	r.origin.y = outFrom.y - ay * r.size.height;
	
	return r;
}



static inline NSRect NSRectCenteredOnPoint(NSPoint point, CGFloat width, CGFloat height)
{
	#if CGFLOAT_IS_DOUBLE
	return NSMakeRect(point.x - floor(width / 2.0), point.y - floor(height / 2.0), width, height);
	#else
	return NSMakeRect(point.x - floorf(width / 2.0), point.y - floorf(height / 2.0), width, height);
	#endif
}


static inline NSRect NSRectScaledToFitInRect(NSSize scaleThisSize, NSRect toFitInThisRect)
{
	NSRect maxFrame = toFitInThisRect;
	NSSize size = scaleThisSize;
	CGFloat ratio = size.width / size.height;
	
	// Scale based on width
	if (size.width > maxFrame.size.width) {
		size.width = maxFrame.size.width;
		size.height = floor(size.width / ratio);
	}
	
	// Scale based on height
	if (size.height > maxFrame.size.height) {
		size.height = maxFrame.size.height;
		size.width = floor(size.height * ratio);
	}
	
	return NSMakeRect(toFitInThisRect.origin.x, toFitInThisRect.origin.y, size.width, size.height);
}




static inline NSRect NSRectCenteredInRect(NSRect centerMe, NSRect inThisRect)
{
	return NSRectCenteredOnPoint(NSMakePoint(NSMidX(inThisRect), NSMidY(inThisRect)), centerMe.size.width, centerMe.size.height);
}






static inline NSRect NSRectScaledToCoverRect(NSSize scaleThisSize, NSRect toCoverThisRect)
{
	// First, scale it to fit in the rect. If it doesn't cover the rect, then using the smaller dimension, scale to cover
	NSRect rect = NSRectScaledToFitInRect(scaleThisSize, toCoverThisRect);
	rect = NSRectCenteredInRect(rect, toCoverThisRect);
	
	if (rect.size.width < toCoverThisRect.size.width) {
		CGFloat scale = toCoverThisRect.size.width / rect.size.width; 
		rect = NSRectScaleAboutPoint(rect, scale, NSRectCenter(rect));
		
	} else if (rect.size.height < toCoverThisRect.size.height) {
		CGFloat scale = toCoverThisRect.size.height / rect.size.height;
		rect = NSRectScaleAboutPoint(rect, scale, NSRectCenter(rect));
	}
	
	return rect;
}



static inline NSRect NSRectFitInRect(NSRect child, NSRect parent)
{
	// No bigger than the screen
	if (child.size.width  > parent.size.width)  child.size.width  = parent.size.width;
	if (child.size.height > parent.size.height) child.size.height = parent.size.height;
	
	// Move on to screen
	if (NSMinX(child) < NSMinX(parent)) child.origin.x += NSMinX(parent) - NSMinX(child);
	if (NSMinY(child) < NSMinY(parent)) child.origin.y += NSMinY(parent) - NSMinY(child);
	if (NSMaxX(child) > NSMaxX(parent)) child.origin.x -= NSMaxX(child) - NSMaxX(parent);
	if (NSMaxY(child) > NSMaxY(parent)) child.origin.y -= NSMaxY(child) - NSMaxY(parent);
	
	return child;
}



// Rounds each element to the nearest number (used to be NSRectIntegerized)
static inline NSRect NSRoundRectNearest(NSRect rect)
{
	return NSMakeRect(round(rect.origin.x), round(rect.origin.y), round(rect.size.width), round(rect.size.height));
}


// Rounds each element to the nearest number
static inline NSPoint NSRoundPointNearest(NSPoint point)
{
	return NSMakePoint(round(point.x), round(point.y));
}



static inline BOOL NSSharesRectEdge(NSRect a, NSRect b, NSRectEdge edge)
{
	switch (edge) {
		case NSMinXEdge: return ((NSMinX(a) == NSMaxX(b)) && (NSMinY(a) == NSMinY(b)) && (NSMaxY(a) == NSMaxY(b)));
		case NSMaxXEdge: return ((NSMaxX(a) == NSMinX(b)) && (NSMinY(a) == NSMinY(b)) && (NSMaxY(a) == NSMaxY(b)));
		case NSMinYEdge: return ((NSMinY(a) == NSMaxY(b)) && (NSMinX(a) == NSMinX(b)) && (NSMaxX(a) == NSMaxX(b)));
		case NSMaxYEdge: return ((NSMaxY(a) == NSMinY(b)) && (NSMinX(a) == NSMinX(b)) && (NSMaxX(a) == NSMaxX(b)));
		default: return NO;
	}
}



static inline BOOL NSOverlapsRectEdge(NSRect a, NSRect b, NSRectEdge edge)
{
	switch (edge) {
		case NSMinXEdge: return ((NSMinX(a) < NSMinX(b)) && (NSMaxX(a) > NSMinX(b)));
		case NSMaxXEdge: return ((NSMinX(a) < NSMaxX(b)) && (NSMaxX(a) > NSMaxX(b)));
		case NSMinYEdge: return ((NSMinY(a) < NSMinY(b)) && (NSMaxY(a) > NSMinY(b)));
		case NSMaxYEdge: return ((NSMinY(a) < NSMaxY(b)) && (NSMaxY(a) > NSMaxY(b)));
		default: return NO;
	}
}



BOOL NSBreakOverlappingRects(NSRect rect1, NSRect rect2, NSArray ** newRects);

// Will union rects if they can be unioned without growing in size at all.
NSArray * NSReduceRects(NSArray * inRects);

// Takes a list of overlapping rects and will break them up to produce a list
// of rects which do not overlap, and covers the exact same area.
NSArray * NSMergeRects(NSArray * inRects);

// Clips the bounds of all rects to fit within the clip rect
NSArray * NSClipRects(NSArray * inRects, NSRect clipToRect);

// Will union intersecting rects
NSArray * NSUnionIntersectingRects(NSArray * inRects);

// Array version of NSOffsetRect. origin += delta;
NSArray * NSOffsetRects(NSArray * inRects, CGFloat dX, CGFloat dY);


NSRect NSFlipRect(NSRect toFlip, CGFloat containingRectHeight);

