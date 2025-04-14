//
//  AGToolbarMenuButtonItem.h
//  Araelium Edit 2.1
//
//  Created by Seth Willits on 8/18/07.
//  Copyright 2007 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>



@class AGToolbarMenuButton;
@interface AGToolbarMenuButtonItem : NSToolbarItem {
	AGToolbarMenuButton * mMenuButton;
}

- (void)setMenuDelay:(NSTimeInterval)delay;
- (void)setMenu:(NSMenu *)menu;

- (void)setShowsMenuIndicator:(BOOL)shows;
- (BOOL)showsMenuIndicator;

@end


// Validation uses the method below on the toolbar's delegate
@protocol AGToolbarMenuButtonItemValidation <NSObject>
- (BOOL)validateCustomToolbarItem:(NSToolbarItem *)toolbarItem;
@end







@interface AGToolbarMenuButton : NSButton {
	BOOL _timerShowsMenu;
	id _delegate;
	NSTimeInterval mMenuDelay;
	BOOL _showsMenuIndicator;
}

- (void)setDelegate:(id)delegate;
- (id)delegate;

- (void)setMenuDelay:(NSTimeInterval)delay;
- (void)setMenu:(NSMenu *)menu;

- (void)setShowsMenuIndicator:(BOOL)shows;
- (BOOL)showsMenuIndicator;

@end


@interface AGToolbarMenuButton (Private)
- (void)showMenu;
- (void)showMenuTimer:(NSTimer *)timer;
@end



@protocol AGToolbarMenuButtonDelegate <NSObject>
- (void)updateToolbarMenuButton:(AGToolbarMenuButton *)button menu:(NSMenu *)menu;
@end




