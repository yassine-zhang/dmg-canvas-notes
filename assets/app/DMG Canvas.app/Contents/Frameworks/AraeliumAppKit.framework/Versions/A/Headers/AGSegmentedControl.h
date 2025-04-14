//
//  AGSegmentedControl.h
//  AGSegmentedControl
//
//  Created by Seth Willits on 3/1/07.
//  Copyright 2007 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <AraeliumAppKit/AGSegmentedCell.h>
@protocol AGSegmentedStyleDelegate;


typedef enum {
	AGSegmentSwitchTrackingSelectOne = 0,		// only one button can be selected
	AGSegmentSwitchTrackingSelectAny = 1,		// any button can be selected
	AGSegmentSwitchTrackingMomentary = 2,		// only selected while tracking
	AGSegmentSwitchTrackingSelectAtLeastOne = 3	// 
} AGSegmentSwitchTracking;


typedef enum {
	AGSegmentedControlAquaStyle = 0,
	AGSegmentedControlUnifiedStyle = 1,
	AGSegmentedControlMetalStyle = 2,
	AGSegmentedControlSmallGrayStyle = 3,
	AGSegmentedControlSquareGradientStyle = 4,
	AGSegmentedControlToolbarStyle = 5,
	AGSegmentedControlLargeFlatStyle = 6
} AGSegmentedControlStyle;


typedef enum {
	AGSegmentedControlLeftEndCellPosition = -1,
	AGSegmentedControlMiddleCellPosition = 1,
	AGSegmentedControlRightEndCellPosition = 1
} AGSegmentedControlCellPosition;


@class AGSegmentedStyleDelegate, AGSegmentedCell;
@interface AGSegmentedControl : NSView {
	
	// Style
	id<AGSegmentedStyleDelegate> mStyleDelegate;
	AGSegmentedControlStyle mStyle;
	
	// Properties
	id_NotOutlet mTarget;
	SEL mAction;
	NSInteger mTag;
	
	// Segments
	NSMutableArray * mSegments;
	NSMutableIndexSet *	mSelectedSegments;
	AGSegmentSwitchTracking mTrackingMode;
	NSInteger mKeySegment;
	
	// Internal State
	BOOL _needsLayout;
	BOOL _isDeselectingOtherSegments;
	AGSegmentedCell * _mouseDownSegment;
	AGSegmentedCell * _activeSegment;
}


// Action and Target
- (void)setTarget:(id)target;
- (id)target;
- (void)setAction:(SEL)action;
- (SEL)action;

// Properties
- (void)setTag:(NSInteger)tag;
- (NSInteger)tag;

// Apperance
- (void)setStyle:(AGSegmentedControlStyle)style;
- (AGSegmentedControlStyle)style;


// Number of segments
- (void)setSegmentCount:(NSInteger)count;
- (NSInteger)segmentCount;
- (AGSegmentedCell *)segmentAtIndex:(NSInteger)index;
- (NSInteger)indexOfSegment:(AGSegmentedCell *)segment;
- (NSInteger)indexOfSegmentWithTag:(NSInteger)tag;
- (NSArray *)segments;

// Segment Selection
- (void)setTrackingMode:(AGSegmentSwitchTracking)trackingMode;
- (AGSegmentSwitchTracking)trackingMode;
- (void)setSelectedSegment:(NSInteger)selectedSegment;
- (void)setSelected:(BOOL)selected forSegment:(NSInteger)segment;
- (BOOL)selectSegmentWithTag:(NSInteger)tag;
- (BOOL)isSelectedForSegment:(NSInteger)segment;
- (NSInteger)selectedSegment;
- (NSIndexSet *)selectedSegments;

// Segment Target and Actions
- (void)setTarget:(id)target forSegment:(NSInteger)segment;
- (id)targetForSegment:(NSInteger)segment;
- (void)setAction:(SEL)action forSegment:(NSInteger)segment;
- (SEL)actionForSegment:(NSInteger)segment;

// Segment Sizing
- (void)setWidth:(CGFloat)width forSegment:(NSInteger)segment;
- (CGFloat)widthForSegment:(NSInteger)segment;

// Segment State
- (void)setEnabled:(BOOL)enabled forSegment:(NSInteger)segment;
- (BOOL)isEnabledForSegment:(NSInteger)segment;

// Segment Style
- (void)setTitle:(NSString *)title forSegment:(NSInteger)segment;
- (NSString *)titleForSegment:(NSInteger)segment;
- (void)setImage:(NSImage *)image forSegment:(NSInteger)segment;
- (NSImage *)imageForSegment:(NSInteger)segment;
- (void)setMenu:(NSMenu *)menu forSegment:(NSInteger)segment;
- (NSMenu *)menuForSegment:(NSInteger)segment;
- (void)setToolTip:(NSString *)toolTip forSegment:(NSInteger)segment;
- (NSString *)toolTipForSegment:(NSInteger)segment;

// Segment Properties
- (void)setTag:(NSInteger)tag forSegment:(NSInteger)segment;
- (NSInteger)tagForSegment:(NSInteger)segment;
- (void)setIdentifier:(id)identifier forSegment:(NSInteger)segment;
- (id)identifierForSegment:(NSInteger)segment;


// Keyboard Navigation
- (void)makeNextSegmentKey;
- (void)makePreviousSegmentKey;


// Layout and Drawing
- (void)setNeedsLayout:(BOOL)needsLayout;
- (BOOL)needsLayout;
- (void)layoutSegments;
- (void)sizeToFit;

- (void)drawBackgroundInRect:(NSRect)rect;
- (void)drawSegmentsInRect:(NSRect)rect;
- (void)drawSegment:(AGSegmentedCell *)segment position:(NSInteger)position withFrame:(NSRect)frame;

@end



@interface AGSegmentedControl (AGSegmentedControlPrivate)

// Style
- (Class)_styleDelegateClassForStyle:(AGSegmentedControlStyle)apperance;
- (void)_setStyleDelegate:(id<AGSegmentedStyleDelegate>)styleDelegate;
- (id<AGSegmentedStyleDelegate>)_styleDelegate;

// Segment Selection
- (BOOL)_allowsMultipleSelection;
- (void)_checkSegmentSelection;
- (BOOL)_silentlyDeselectAllSegments;
- (NSInteger)_indexOfFirstEnabledSegment;

// Hit Testing
- (AGSegmentedCell *)_segmentAtPoint:(NSPoint)point;

// Layout
- (NSSize)_desiredSize;

@end

