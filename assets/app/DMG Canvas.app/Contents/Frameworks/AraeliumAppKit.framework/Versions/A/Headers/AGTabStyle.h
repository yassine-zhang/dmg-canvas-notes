//
//  AGTabStyle.h
//  AGTabBarControl
//
//  Created by Seth Willits on 4/28/10.
//  Copyright 2010 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <AraeliumAppKit/AGTabBarControl.h>
@class AGTabBarCell;
@class AGTabBarAddTabButton;
@class AGTabBarOverflowButton;



@protocol AGTabStyle <NSObject>

// Control layout
- (CGFloat)leftMarginForTabBar;
- (CGFloat)rightMarginForTabBar;
- (CGFloat)overflowButtonWidth;
- (NSRect)overflowButtonFrame:(NSRect)tabBarControlFrame;
- (NSRect)addTabButtonFrame:(NSRect)tabBarControlFrame;

// Cell layout
- (NSRect)titleRectForTabCell:(AGTabBarCell *)cell;
- (NSRect)closeButtonRectForTabCell:(AGTabBarCell *)cell;
- (NSRect)progressIndicatorRectForTabCell:(AGTabBarCell *)cell;
//- (NSRect)iconRectForTabCell:(AGTabBarCell *)cell;
//- (NSRect)objectCounterRectForTabCell:(AGTabBarCell *)cell;

// Cell values
//- (NSAttributedString *)attributedObjectCountValueForTabCell:(AGTabBarCell *)cell;
- (NSAttributedString *)attributedStringValueForTabCell:(AGTabBarCell *)cell;

// Drawing
- (void)drawTabCell:(AGTabBarCell *)cell inTabBar:(AGTabBarControl *)tabBarControl;
- (void)drawTabCellInterior:(AGTabBarCell *)cell inTabBar:(AGTabBarControl *)tabBarControl;
- (void)drawTabBar:(AGTabBarControl *)bar inRect:(NSRect)rect;
- (void)tabBar:(AGTabBarControl *)tabBar addTabButton:(AGTabBarAddTabButton *)button drawRect:(NSRect)rect;
- (BOOL)tabBar:(AGTabBarControl *)tabBar overflowButton:(AGTabBarOverflowButton *)button drawRect:(NSRect)rect;

// Images
- (NSImage *)pulledImageForTabCell:(AGTabBarCell *)cell;



@end


@interface AGTabBarControl (PrivateCellAccess)
- (NSArray *)cells;
- (AGTabBarCell *)lastVisibleTabCell;
- (NSInteger)numberOfVisibleTabCells;
+ (NSImage *)pulledImageForWindow:(NSWindow *)window;
@end
