//
//  AGFlatTabStyle.h
//  AGTabBarControl
//
//  Created by Seth Willits on Aug 16, 2014
//  Copyright 2014 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <AraeliumAppKit/AGTabStyle.h>

@interface AGFlatTabStyle : NSObject <AGTabStyle> {
	NSGradient * AWActiveTabGradient;
	NSGradient * AWInactiveTabGradient;
	NSGradient * AWHoveredTabGradient;
	NSGradient * AWBackgroundGradient;
	NSColor * AWActiveTabCloseButtonBackgroundColor;
	NSColor * AWActiveTabCloseButtonBackgroundClickedColor;
	NSColor * AWInactiveTabCloseButtonBackgroundColor;
	NSColor * AWInactiveTabCloseButtonBackgroundClickedColor;
	NSColor * AWBordersColor;
	NSColor * AWBottomBorderColor;
	
	NSGradient * IWActiveTabGradient;
	NSGradient * IWInactiveTabGradient;
	NSGradient * IWHoveredTabGradient;
	NSGradient * IWBackgroundGradient;
	NSColor * IWActiveTabCloseButtonBackgroundColor;
	NSColor * IWActiveTabCloseButtonBackgroundClickedColor;
	NSColor * IWInactiveTabCloseButtonBackgroundColor;
	NSColor * IWInactiveTabCloseButtonBackgroundClickedColor;
	NSColor * IWBordersColor;
	NSColor * IWBottomBorderColor;
	
	NSImage * overflowIcon;
	NSImage * overflowIconPressed;
	
	BOOL _isDark;
}

@end
