//
//  AGMenuFilteringMenuItem.h
//  AraeliumAppKit
//
//  Created by Seth Willits on 6/30/14.
//  Copyright (c) 2014 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>
@class AGMenuFilteringMenuItemView;


@interface AGMenuFilteringMenuItem : NSMenuItem

@property (nonatomic, readwrite, copy) NSString * filterString;
@property (nonatomic, readwrite, assign) BOOL alwaysShowsFilterField;

@end


