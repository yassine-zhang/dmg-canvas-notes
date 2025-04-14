//
//  AGSegmentedControlStyles.h
//  AGSegmentedControl
//
//  Created by Seth Willits on June 30, 2007.
//  Copyright 2007 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>
@class AGSegmentedControl, AGSegmentedCell;



@protocol AGSegmentedStyleDelegate <NSObject>

// Required
- (BOOL)autoresizes;
- (void)drawSegment:(AGSegmentedCell *)segment position:(NSInteger)segmentIndex withFrame:(NSRect)frame inControl:(AGSegmentedControl *)control;

// Optional
@optional
- (NSSize)minimumSize;
- (NSSize)desiredSizeOfControl:(AGSegmentedControl *)control;
- (void)layoutSegments:(NSArray *)segments inControl:(AGSegmentedControl *)control;
- (void)drawBackgroundInRect:(NSRect)rect inControl:(AGSegmentedControl *)control;
- (void)drawSegmentsInRect:(NSRect)rect inControl:(AGSegmentedControl *)control;
- (NSAttributedString *)attributedStringForSegment:(AGSegmentedCell *)segment inControl:(AGSegmentedControl *)control;

@end


@interface AGSegmentedSmallGrayStyle : NSObject <AGSegmentedStyleDelegate>
{
	NSGradient * normalFillGradient;
	NSGradient * pressedFillGradient;
	NSColor * disabledTopStrokeColor;
	NSColor * disabledBottomStrokeColor;
	NSColor * enabledTopStrokeColor;
	NSColor * enabledBottomStrokeColor;
	NSColor * pressedTopStrokeColor;
	NSColor * pressedBottomStrokeColor;
	NSColor * separatorStrokeColor;
}

@end



@interface AGSegmentedMetalStyle : NSObject <AGSegmentedStyleDelegate>
{
	NSImage * mLeft;
	NSImage * mMiddle;
	NSImage * mRight;
	NSImage * mLeftDown;
	NSImage * mMiddleDown;
	NSImage * mRightDown;
	NSImage * mLeftDisabled;
	NSImage * mMiddleDisabled;
	NSImage * mRightDisabled;
	NSImage * mSeparator;
	NSImage * mSeparatorDown;
}

@end




@interface AGSegmentedAquaStyle : NSObject <AGSegmentedStyleDelegate>
@end





// DMG Canvas Sidebar (icon only)
@interface AGSegmentedSquareGradientStyle : NSObject <AGSegmentedStyleDelegate>
{
	NSGradient * mNormalDisabledBottomHalfGradient;
	
	NSGradient * mNormalTopHalfGradient;
	NSGradient * mNormalBottomHalfGradient;
	NSGradient * mSelectedTopHalfGradient;
	NSGradient * mSelectedBottomHalfGradient;
	NSGradient * mHighlightedTopHalfGradient;
	NSGradient * mHighlightedBottomHalfGradient;
}

@end




// Querious, Screenflick 2 export sheet
@interface AGSegmentedToolbarStyle : NSObject <AGSegmentedStyleDelegate>
{
	NSColor * backgroundColor;
	NSColor * selectedBackgroundColor;
	NSColor * selectedBorderColor;
	NSColor * borderColor;
}

@end




// New Querious 2.0 export style
@interface AGSegmentedLargeFlatStyle : NSObject <AGSegmentedStyleDelegate>
{
	
}

@end

