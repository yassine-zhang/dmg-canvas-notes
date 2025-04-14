//
//  AGRespondingViewController.h
//  ViewControllerResponderChain
//
//  Created by Seth Willits on 2/11/14.
//  Copyright (c) 2014 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <AraeliumAppKit/AGHierarchalViewController.h>


@interface AGRespondingViewController : AGHierarchalViewController
{
	// Need to avoid circular loadView/setView: nonsense,
	// so we're just keeping around our own ref in parallel.
	NSView * _theView;
	
	// When using the 10.10 SDK and running on 10.10+ we don't need
	// to insert the VC into the chain because AppKit now does that
	BOOL _manuallyInstallIntoTheResponderChain;
}


- (id)descendingSupplementalTargetForAction:(SEL)action sender:(id)sender;

@end
