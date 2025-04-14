//
//  AGSegmentedCell.h
//  AGSegmentedControl
//
//  Created by Seth Willits on 3/1/07.
//  Copyright 2007 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#define id_NotOutlet id

@class AGSegmentedControl;
@interface AGSegmentedCell : NSObject {
	AGSegmentedControl * mSegmentedControl;
	
	// Properties
	NSInteger mTag;
	id_NotOutlet mIdentifier;
	
	// Target and Action
	id_NotOutlet mTarget;
	SEL mAction;
	
	// Style
	NSImage * mImage;
	NSString * mTitle;
	NSMenu * mMenu;
	
	// State
	BOOL mIsEnabled;
	BOOL mIsHighlighted;
	NSInteger mState;
	
	// Sizing
	CGFloat mWidth;
	CGFloat mMinimumWidth;
	NSRect mCellFrame;
	
	// Tool Tip
	NSString * mToolTip;
}

- (id)initWithSegmentedControl:(AGSegmentedControl *)segmentedControl;

// Segmented Control
- (void)setSegmentedControl:(AGSegmentedControl *)segmentedControl;
- (id)segmentedControl;

// Target and Action
- (void)setTarget:(id)target;
- (id)target;
- (void)setAction:(SEL)action;
- (SEL)action;

// State
- (void)setEnabled:(BOOL)isEnabled;
- (BOOL)isEnabled;
- (void)setHighlighted:(BOOL)isHighlighted;
- (BOOL)isHighlighted;
- (void)setState:(NSInteger)state;
- (NSInteger)state;

// Style
- (void)setImage:(NSImage *)image;
- (NSImage *)image;
- (void)setTitle:(NSString *)title;
- (NSString *)title;
- (void)setMenu:(NSMenu *)menu;
- (NSMenu *)menu;

// Properties
- (void)setTag:(NSInteger)tag;
- (NSInteger)tag;
- (void)setIdentifier:(id)identifier;
- (id)identifier;

// Sizing
- (void)setWidth:(CGFloat)width;
- (CGFloat)width;
- (void)setMinimumWidth:(CGFloat)width;
- (CGFloat)minimumWidth;
- (void)setCellFrame:(NSRect)cellFrame;
- (NSRect)cellFrame;
- (CGFloat)desiredCellWidth;
- (NSSize)minimumCellSize;

// Tool Tip
- (void)setToolTip:(NSString *)tip;
- (NSString *)toolTip;

@end


@interface AGSegmentedCell (AGSegmentedCellPrivate)

// Drawing
- (BOOL)_cellAutoresizes;

@end
