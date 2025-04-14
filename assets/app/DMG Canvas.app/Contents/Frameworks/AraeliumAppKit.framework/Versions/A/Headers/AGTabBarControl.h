//
//  AGTabBarControl.h
//  AGTabBarControl
//
//  Created by Seth Willits on 4/28/10.
//  Copyright 2010 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>
@class AGTabBarCell;
@class AGTabBarAddTabButton;
@class AGTabBarOverflowButton;
@protocol AGTabStyle;


/*
	
	Each NSTabView item's identifier should be an NSObjectController.
	That NSObjectController's content should whatever you want.
	The content object should optionally respond to
		- isProcessing
	
	
	To Do:
		- Add double-clicking in empty space to add new tab
		- When an overflow tab is selected, swap it to simply be
		  drawn as the last visible tab. It does not swap indexes,
		  it just draws in place of the last tab.
*/




extern NSString * AGTabBarCellPboardType;


typedef struct __AGTBCTilingState {
	CGFloat availableWidth;
	CGFloat	suggestedWidth;
	NSArray * visibleCells;
	NSArray * overflowCells;
} _AGTBCTilingState;



// AGTabBarControl is an NSControl subclass because
// using -[NSCell setControlView:] requires it to
// be one, despite it taking an NSView parameter.
// The tab bar doesn't have an action though.
@interface AGTabBarControl : NSControl
#if MAC_OS_X_VERSION_MAX_ALLOWED > MAC_OS_X_VERSION_10_5
<NSTabViewDelegate>
#endif
{
	
	// Control
	id							mDelegate;
	NSTabView *					mTabView;
	NSMutableArray *			mCells;
	AGTabBarOverflowButton *	mOverflowButton;
	AGTabBarAddTabButton *		mAddTabButton;
	
	// Style and Behavior
	id<AGTabStyle>				mStyle;
	BOOL						mCanCloseOnlyTab;
	
	// Cell Sizing
	NSInteger					mCellMinWidth;
	NSInteger					mCellMaxWidth;
	
	// Drag and Drop
	BOOL                        mIgnoreMouseDraggedEvents;
	AGTabBarCell *				mCellBeingDragged;
	NSTimer	*					mRedrawDuringDragTimer;
	NSEvent *					mCurrentMouseDownEvent;
	NSPoint						mMouseDownPointInCell;
	AGTabBarCell *				mMouseDownCell;
	BOOL                        mWindowIsHiddenBecauseItIsDragSource;
	NSRect                      mWindowFrameBeforeHiddenBecauseItIsDragSource;
	
	AGTabBarCell *				mCellTornOff;
	NSTabViewItem *				mTabViewItemTornOff;
	NSImage *                   mWindowImageForAnimation;
	
	NSArray *					mCellOrderBeforeDrag;
	BOOL						mExternalDraggingValidated;
	NSImage *					mImageOfWindow;
	
	_AGTBCTilingState			mState;
}

@property (readwrite, retain)	IBOutlet NSTabView *		tabView;
@property (readwrite, assign)	IBOutlet id					delegate;
@property (readwrite, retain)	id<AGTabStyle>				style;
@property (readwrite, assign)	BOOL						canCloseOnlyTab;
@property (readwrite, assign)	NSInteger					cellMinWidth;
@property (readwrite, assign)	NSInteger					cellMaxWidth;
@property (readonly)			AGTabBarOverflowButton *	overflowButton;
@property (readonly)			AGTabBarAddTabButton *		addTabButton;

- (void)tile;

- (IBAction)selectNextTab:(id)sender;
- (IBAction)selectPreviousTab:(id)sender;

- (void)moveTabToNewWindow:(NSTabViewItem *)tabViewItem;

/// Verifies with the delegate and then closes the tab.
/// Used when clicking on the close button, for instance.
- (void)closeTabViewItem:(NSTabViewItem *)tabViewItem;

@end



@protocol AGTabBarControlDelegate <NSObject>

// Called on dragging source
- (id)tabView:(NSTabView *)tabView contextForTabViewItem:(NSTabViewItem *)tabViewItem;
- (void)tabView:(NSTabView *)tabView willRemoveTabViewItem:(NSTabViewItem *)tabViewItem context:(id)context fromWindow:(NSWindow *)window;
- (NSWindow *)untitledWindowForTabView:(NSTabView *)tabView tabView:(NSTabView **)newTabView;
- (NSWindow *)tabView:(NSTabView *)tabView createWindowForTabViewItem:(NSTabViewItem *)tabViewItem context:(id)context;
- (void)tabView:(NSTabView *)tabView didDisplayWindow:(NSWindow *)window forTabViewItem:(NSTabViewItem *)tabViewItem context:(id)context;

// Called on dragging destination
- (BOOL)tabView:(NSTabView *)tabView validateDrop:(id <NSDraggingInfo>)info tabViewItem:(NSTabViewItem *)tabViewItem context:(id)context fromWindow:(NSWindow *)window;
- (void)tabView:(NSTabView *)tabView willInsertTabViewItem:(NSTabViewItem *)tabViewItem context:(id)context fromWindow:(NSWindow *)window;
- (void)tabView:(NSTabView *)tabView didInsertTabViewItem:(NSTabViewItem *)tabViewItem context:(id)context fromWindow:(NSWindow *)window;


@optional

// Creating a new tab
- (void)addNewTabInTabView:(NSTabView *)tabView;

// Misc
- (void)tabViewDidChangeNumberOfTabViewItems:(NSTabView *)tabView;
- (void)tabViewDidReorderTabs:(NSTabView *)tabView;
- (NSString *)tabView:(NSTabView *)tabView alternateTitleForTabViewItem:(NSTabViewItem *)tabViewItem;
- (NSMenu *)tabView:(NSTabView *)tabView menuForClickingOnTab:(NSTabViewItem *)tabViewItem;

// Selection
- (BOOL)tabView:(NSTabView *)tabView shouldSelectTabViewItem:(NSTabViewItem *)tabViewItem;
- (void)tabView:(NSTabView *)tabView willSelectTabViewItem:(NSTabViewItem *)tabViewItem;
- (void)tabView:(NSTabView *)tabView didSelectTabViewItem:(NSTabViewItem *)tabViewItem;

// Closing
- (BOOL)tabView:(NSTabView *)tabView shouldCloseTabViewItem:(NSTabViewItem *)tabViewItem;
- (void)tabView:(NSTabView *)tabView willCloseTabViewItem:(NSTabViewItem *)tabViewItem;
- (void)tabView:(NSTabView *)tabView didCloseTabViewItem:(NSTabViewItem *)tabViewItem;

@end



@protocol AGTabBarControlTabBarItemObjectControllerProtocol
- (id)content;
- (BOOL)isProcessing;
@end
