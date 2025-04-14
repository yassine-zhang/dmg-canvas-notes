
#import <Cocoa/Cocoa.h>
NS_ASSUME_NONNULL_BEGIN


typedef NS_CLOSED_ENUM(NSUInteger, AGBezierPathRectCorner) {
	AGBezierPathRectNoCorner = 0,
	AGBezierPathRectMinXMinYCorner = 1,
	AGBezierPathRectMaxXMinYCorner = 2,
	AGBezierPathRectMaxXMaxYCorner = 4,
	AGBezierPathRectMinXMaxYCorner = 8,
	AGBezierPathRectAllCorners = (AGBezierPathRectMinXMinYCorner |
								  AGBezierPathRectMaxXMinYCorner |
								  AGBezierPathRectMinXMaxYCorner |
								  AGBezierPathRectMaxXMaxYCorner)
};



@interface NSBezierPath (AraeliumAdditions)

// --------------------------------------------------------
// CGPath
// --------------------------------------------------------

// NSBezierPath <-> CGPath
+ (NSBezierPath *)ag_bezierPathWithCGPath:(CGPathRef)path;
- (CGPathRef)ag_quartzPath;



// --------------------------------------------------------
// Drawing
// --------------------------------------------------------

// Instead of stroking centered on the path, effectively stroke inside of the path
- (void)strokeInside;

// Stroke the outside of the path
- (void)strokeOutside;

// Draws the shadow in the interior of the path
- (void)drawInnerShadow:(NSShadow *)shadow;

// Draws the shadow outside of the path. Note that typical NSShadow drawing draws the shadow
// both outside and inside the path which can be undesirable if the path will be filled with a
// translucent color which would normally show the shadow underneath as well and alter the color.
- (void)drawOuterShadow:(NSShadow *)shadow;




// --------------------------------------------------------
// Creating Paths
// --------------------------------------------------------


// See AGBezierPathRectCorner for corner values
+ (NSBezierPath *)bezierPathWithRoundedRect:(NSRect)rect corners:(AGBezierPathRectCorner)corners radius:(CGFloat)radius;
+ (NSBezierPath *)bezierPathInset:(CGFloat)inset fromRoundedRect:(NSRect)rect corners:(AGBezierPathRectCorner)corners radius:(CGFloat)radius;


// Makes path a "hole" in a larger rectangular path with the given bounds
+ (NSBezierPath *)bezierPath:(NSBezierPath *)path cutOutOfBounds:(NSRect)frame;


// Get a bezier path for the stroke
// using the current line width, etc
- (NSBezierPath *)strokedPath;



// --------------------------------------------------------
// Path Info
// --------------------------------------------------------

/// The starting point of the first non-MoveTo element
- (NSPoint)firstPoint;

/// The point of the last non-MoveTo element. If ClosePath is the last element, then it returns the first point
- (NSPoint)lastPoint;




// --------------------------------------------------------
// Text Paths
// --------------------------------------------------------


+ (NSBezierPath *)bezierPathWithString:(NSString *)text inFont:(NSFont *)font;
- (void)appendBezierPathWithString:(NSString *)text inFont:(NSFont *)font;


@end


NS_ASSUME_NONNULL_END
