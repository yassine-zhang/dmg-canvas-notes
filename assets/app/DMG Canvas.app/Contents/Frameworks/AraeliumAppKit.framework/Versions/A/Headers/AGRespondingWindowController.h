//
//  AGRespondingWindowController.h
//  ViewControllerResponderChain
//
//  Created by Seth Willits on 2/12/14.
//  Copyright (c) 2014 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <AraeliumAppKit/AGHierarchalWindowController.h>


@interface AGRespondingWindowController : AGHierarchalWindowController

- (id)descendingSupplementalTargetForAction:(SEL)action sender:(id)sender;

@end
