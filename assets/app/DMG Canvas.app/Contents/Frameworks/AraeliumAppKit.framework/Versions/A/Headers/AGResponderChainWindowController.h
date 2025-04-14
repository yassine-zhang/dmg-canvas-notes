//
//  AGResponderChainWindowController.h
//  AGResponderChain
//
//  Created by Seth Willits on 9/6/13.
//  Copyright (c) 2013 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface AGResponderChainWindowController : NSWindowController
{
	NSArray * _responderChain;
	NSTimer * _timer;
}


@property (readonly) NSArray * responderChain;

+ (AGResponderChainWindowController *)sharedInstance;
- (IBAction)refresh:(id)sender;

@end
