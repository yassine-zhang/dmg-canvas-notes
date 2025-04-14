//
//  NSGradientAdditions.h
//  AraeliumAppKit
//
//  Created by Seth Willits on 6/16/12.
//  Copyright (c) 2012 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>



@interface NSGradient (AraeliumAdditions)
+ (NSGradient *)gradientWithStartingColor:(NSColor *)starting endingColor:(NSColor *)ending;
@end



@interface NSGradient (TableViewGradientsAdditions)
+ (NSGradient *)activeGradientForTigerMailSidebar;
+ (NSGradient *)inactiveGradientForTigerMailSidebar;

+ (NSGradient *)activeGradientForTigerFinderSidebar;
+ (NSGradient *)inactiveGradientForTigerFinderSidebar;

+ (NSGradient *)activeGradientForLeopardFinderSidebar;
+ (NSGradient *)inactiveGradientForLeopardFinderSidebar;

+ (NSGradient *)graphiteGradient;
+ (NSGradient *)darkGraphiteGradient;
@end
