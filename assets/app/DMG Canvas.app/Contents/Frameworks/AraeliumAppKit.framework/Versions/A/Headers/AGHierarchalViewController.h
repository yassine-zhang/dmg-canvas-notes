//
//  AGHierarchalViewController.h
//  ViewControllerResponderChain
//
//  Created by Seth Willits on 2/11/14.
//  Copyright (c) 2014 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>



@interface AGHierarchalViewController : NSViewController
{
	AGHierarchalViewController * _parentViewController;
	NSArray * _childViewControllers;
	BOOL _useYosemiteImplementation;
}


@property (readonly) AGHierarchalViewController * parentViewController;
@property (readonly) NSArray * childViewControllers;

- (void)addChildViewController:(AGHierarchalViewController *)child;
- (void)removeChildViewController:(AGHierarchalViewController *)child;

@end
