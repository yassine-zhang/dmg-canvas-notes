//
//  AGWindowController.h
//  ViewControllerResponderChain
//
//  Created by Seth Willits on 2/12/14.
//  Copyright (c) 2014 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>
@class AGHierarchalViewController;


@interface AGHierarchalWindowController : NSWindowController
{
	NSArray * _childViewControllers;
}


@property (readonly) NSArray * childViewControllers;

- (void)addChildViewController:(AGHierarchalViewController *)child;
- (void)removeChildViewController:(AGHierarchalViewController *)child;

@end
